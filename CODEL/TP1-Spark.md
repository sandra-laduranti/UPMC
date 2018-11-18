# TME CODEL 2018–2019
Codage sous Spark
Par *Jonathan Lejeune*

**note perso: attention je ne peux pas tester et il n'y a pas eu de correction donc je ne suis sûre d'aucune des réponses ici**

### Objectifs
Ce document a pour objectif de vous familiariser avec la programmation Spark sur
des exercices de calcul matriciel simple.

### Pré-requis
Vous devez avoir installé la plate-forme Spark et avoir configuré Eclipse correctement
pour coder et compiler vos programmes scala avec l’API de Spark.

## Exercice 1 – Last.fm en spark

Last.fm est un site web de radio en ligne et de musique communautaire offrant différents services à ses utilisateurs comme par exemple l’écoute ou le téléchargement gratuit
de musiques. Il existe plus de 25 millions d’utilisateurs qui utilisent Last.fm tous les mois générant ainsi beaucoup de données à traiter. L’analyse de données la plus courante se
fait sur les informations que les utilisateurs transmettent au site lorsqu’ils écoutent une musique. Grâce à ces informations, il possible de produire entre autres des hit-parades.
Un titre peut être écouté de deux manières différentes par un utilisateur :
- soit en local sur son propre ordinateur et les informations d’écoute sont envoyées directement au serveur de Last.fm
- soit via une web radio sur le site même. Dans ce cas, l’utilisateur a la possibilité de passer le titre sans l’écouter.
Le système logue pour chaque couple utilisateur-titre :
- le nombre de fois où l’utilisateur a écouté le titre en local
- le nombre de fois où l’utilisateur a écouté le titre en ligne
- le nombre de fois où l’utilisateur a passé le titre sans l’écouter entièrement (=skip).
Le tableau ci-dessous donne un exemple des données maintenues par le système

UserId  | TrackId  | LocalListening  | RadioListening | Skip
--|---|---|---|--
111115  | 222 | 0  | 1  | 0
111113  | 225 | 3  | 0  | 0
111117  | 223 | 0  | 1  | 1
111115  | 225 | 2  | 0  | 0
111120  | 221 | 0  | 0  | 1

Grâce à la plateforme Spark, nous souhaitons calculer pour chaque titre :
  1. le nombre de personnes qui l’ont écouté au moins une fois (en local ou en radio)
  2. le nombre de fois où il a été écouté et passé sans écoute.
On souhaite que le résultat soit trié selon un critère x.
Dans le cadre de cet exercice on prendra x = nb_ecoute−nb_passe et on triera dans l’ordre décroissant. Dans l’exemple, on doit donc obtenir :

TrackId | #listener | #listening  | #skips
--|---|---|--
225  | 2 | 5 | 1
222  | 1 | 1 | 0
223  | 1 | 1 | 1
221  | 0 | 0 | 1

Nous considérons que les données sont stockées dans des fichiers textes sur le HDFS et que les champs de chaque ligne sont séparés par un espace.
**Hypothèse 1** : une ligne de données est identifiée par le couple (**UserId**, **TrackId**), autrement dit deux lignes quelconques ne peuvent pas avoir le même couple.
On propose le programme suivant :

````Java
object LastFM {
case class UserId ( val id : Int )
case class TrackId ( val id : Int )
def main ( args : Array [ String ]): Unit = {
val conf = new SparkConf (). setAppName ( " LastFM " )
val sc = new SparkContext ( conf )
val rdd0 = loadData ( sc , " hdfs ://........ " )
val rdd1 = nbListenerByTrack ( rdd0 )
val rdd2 = nbListeningAndNbSkipByTrack ( rdd0 )
val rdd3 = mergeAndSort ( rdd1 , rdd2 )
rdd3 . saveAsTextFile ( " hdfs :// dfs . lastfm . fr :9000/ hitparade " )
rdd3 . take (10). foreach ( println )
}
````

### Question 1
Écrire la fonction **loadData** qui permet à partir d’un fichier et d’un context Spark de produire un RDD de tuple de 5 éléments, où chaque tuple représente une ligne du
fichier. Vous ferez en sorte que le premier élément du tuple soit de type **UserId** et que le deuxième soit de type **TrackId**, et que les autres soient de type **Int**.
Rappel : la méthode d’instance toInt permet de convertir une String vers un **Int**.


````Java
def loadData(sp:SparkContext, f:String):RDD[(userId,TrackId,Int,Int,Int)]={
	 val textFile = spark.textFile(f,2)
 	 return textFile.map(line -> line.split(" "))
  .map(case array(a,b,c,d,e) => (new UserId(a.toInt), new TrackId(b.toInt), c.toInt, d.toInt, e.toInt))
}
````

### Question 2
Écrire la fonction **nbListenerByTrack** qui à partir du RDD produit par la fonction **loadData** produit un RDD de couple dont le premier élément est un TrackId et le
deuxième élément est le nombre de personnes ayant écouté au moins une fois ce titre (en ligne ou en local).

````Java
nbListenerByTrack(r: RDD[UserId,TrackId,Int,Int,Int]):RDD[(TrackId,Int)]={
  r.filter(t => if(t._3 >= 1 || t.4 >= 1) true else false) //on retire toutes les lignes qui n'ont pas eu au moins une écoute
  .map(e=>(e._2,1)) //on créé un nouveau tuple (TrackId,1)
  .reduceByKey(_+_) //on réduit en additionnant les résultats pour obtenir le trackId et son nombre de personne ayant écouté au moins une fois
}
````

### Question 3
Écrire la fonction **nbListeningAndNbSkipByTrack** qui à partir du RDD produit par la fonction loadData produit un RDD de couple dont le premier élément est un
**TrackId** et le deuxième élément est un couple composé du nombre total d’écoutes (locales et radio) et du nombre de skips.
````Java
nbListeningAndNbSkipByTrack(r: RDD[UserId,TrackId,Int,Int,Int]):RDD[(TrackId,(Int,Int))]={
  val RDD1 = r.map(e=>(e._2,(e._3+e._4))).reduceByKey(2,_+_)
  val RDD2 = r.map(e=>(e._2,(e._5))).reduceByKey(2,_+_)
  return RDD1.join(RDD2)
}
````

### Question 4
Écrire la fonction **mergeAndSort** qui permet de fusionner les résultats des fonctions **nbListenerByTrack** et **nbListeningAndNbSkipByTrack** pour produire le résultat final
trié selon la politique de tri définie ci-avant. Le RDD de sortie doit être un RDD de couple dont le premier élément est un **TrackId** et le deuxième élément un triplet
d’entiers correspondant respectivement à #listener, #listening et #skips.

````Java
mergeAndSort(r1:RDD[(TrackId,Int), r2:RDD[(TrackId,(Int,Int))]):RDD[trackId,(Int,Int,Int)]={
  return r1.join(r2).sortBy(e=>e._2._2-e._2._3,false) 
}
````

## Exercice 2 – Calcul matriciel
Dans cet exercice notre but final est d’écrire un programme spark permettant de faire des opérations sur des (grandes) matrices d’entiers. L’avantage de spark est que l’on peut
tirer parti de ses capacités de parallélisation afin de pouvoir passer à l’échelle lorsque la taille des matrices considérées augmente.
**Consigne générale** : Lors de la manipulation d’une collection quelconque vous privilégierez les méthodes de transformation (map, zip, filter, etc....) qui vous sont offertes
au lieu des boucles.
**Pré-requis** : vous devez avoir terminé la classe VectorInt du premier TP de scala.
**Objectif** : A partir de la classe VectorInt précédemment codée Scala, nous allons coder une classe qui représentera une matrice répartie sur un cluster à l’aide de Spark.
Les questions qui suivent vous aideront a enrichir progressivement les services qu’offre cette classe.

### Question 1
Déclarez une classe **MatrixIntAsRDD** qui aura un seul attribut immutable lines de type **RDD[VectorInt]** qui sera renseigné à l’instanciation de la classe. On représente
ainsi une matrice comme étant un ensemble de vecteurs, où chaque vecteur représente une ligne de la matrice. Vous y ajouterez la méthode suivante qui permet d’avoir 
une représentation String de la matrice :

````Java
override def toString ={
val sb = new StringBuilder ()
lines . collect (). foreach ( line = > sb . append ( line + " \ n " ))
sb . toString ()
}
````

Les matrices que nous allons manipuler sont donc des ensembles de vecteurs ordonnés par indice de ligne. Nous souhaitons construire une instance de **MatrixIntAsRDD** à partir
d’un fichier texte. Quelques exemples de fichier texte vous sont fournis dans les ressources de TP . Nous devons assurer que toutes matrices ayant le même nombre de lignes soient
partitionnées exactement de la même manière. En résumé deux matrices ayant le même nombre de lignes doivent :
- avoir le même nombre de partitions
- que chaque partition correspondante entre les deux matrices, doivent avoir le même nombre d’éléments.
- être triées par ordre de vecteur croissant, c’est à dire que le n-ième élément dans le RDD doit être la n-ième ligne de la matrice

### Question 2
Écrire une fonction (ou méthode de classe)
`makeMatriceIntRdd(file:String, nb_part:Int, sc:SparkContext):MatrixIntAsRDD` qui permet de créer une nouvelle instance de **MatrixIntAsRDD** à partir du fichier
texte file et du SparkContext **sc** et en partitionnant sur **nb_part partitions**. Vous pourrez utiliser la transformation **sortBy** qui répartit de manière déterministe sur un
nombre de partitions donnés les éléments d’un RDD en fonction d’un ordre sur une clé. Nous supposerons que l’utilisateur de cette fonction donnera le même nombre de
partitions pour chaque fichier de matrice ayant le même nombre de lignes. Pour vous aider, voici l’enchaînement des transformations attendues dans cette fonction :
- 1er rdd (**RDD[String]**) : création à partir du fichier (textfile)
- 2ème rdd (**RDD[Array[Int]]**) : on transforme chaque ligne du 1er rdd en array de **Int(map)**
- 3ème rdd (**RDD[VectorInt]**) : on transforme chaque élément du 2ème rdd en **VectorInt(map)**

A partir de maintenant nous souhaitons nous assurer que la répartition des éléments soit la même quelque soit le fichier d’entrée :
- 4ème rdd (**RDD[(VectorInt,Long)]**) : lier chaque élément du 3eme rdd avec son index(**zipWithIndex**)
- 5ème rdd (**RDD[(VectorInt,Long)]**) : trier le 4ème rdd en fonction de l’index croissant(**sortBy**)
- 6ème rdd (**RDD[VectorInt]**) : enlever la partie droite de chaque élément pour negarder que le vecteur (**map**)
- enfin construire et retourner une **MatrixIntAsRDD** à partir du 6ème rdd.

### Question 3
Placez les fichiers de matrice fournis à la racine de votre projet eclipse et testez votre fonction sur le programme de test suivant en vérifiant que les affichages correspondent
bien aux fichiers :

````Java
val conf = new SparkConf().setAppName("Matrice").setMaster("local[2]")
val sc = new SparkContext(conf)
val num_partition = 4
val mat = new Array[MatrixIntAsRDD](6)
mat(0) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat(1) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat(2) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat(3) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat(4) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat(5) = makeMatriceIntRdd("matrice1", num_partition, sc )
mat.foreach(m => assert(m.lines.getNumPartitions == num_partition))
assert(mat(1).lines.first() == new VectorInt(Array(1 ,1 ,-1)))
assert(mat(5).lines.first() == new VectorInt(Array(2 ,8 ,2 ,10)))
var i = 0
mat.foreach(m => {println("matrice␣ " + i + " ␣:\n" + m ) ; i +=1})
````

### Question 4
Écrire dans la classe **MatrixIntAsRDD** , deux méthodes **nb_lines** et **nb_columns** qui renvoient respectivement le nombre de lignes et le nombre de colonnes de la matrice.
Vous testerez ces fonctions en ajoutant à votre programme de test la ligne suivante :
`assert(mat(1).nb_lines == mat(0).nb_lines && mat(1).nb_columns == mat(0).nb_columns )`

### Question 5
Écrire dans la classe **MatrixIntAsRDD** une méthode `get(i:Int,j:Int):Int` qui renvoie l’élément à l’indice i, j où 0 ≤ i < nb_lines et 0 ≤ j < nb_columns. Vous
testerez cette fonction en ajoutant à votre programme de test les lignes suivantes :
````Java
assert(mat(1).get(3 , 1) == 7)
assert(mat(5).get(2 , 3) == -2)
````

### Question 6
Écrire dans la classe **MatrixIntAsRDD** la méthode `equals(a:Any):Boolean` qui teste si deux matrices sont égales. Vous testerez cette fonction en ajoutant à votre programme
de test les lignes suivantes :
````Java
assert(mat(1) == mat(0))
assert(mat(0) == mat(1))
assert(mat(1) != mat(3))
assert(mat(3) != mat(5))
assert(mat(5) != mat(2))
````

### Question 7
Écrire dans la classe **MatrixIntAsRDD** la méthode `+(other: MatrixIntAsRDD):MatrixIntAsRDD` qui additionne deux matrices. Vous testerez cette fonction en ajoutant à votre programme
de test la ligne suivante :
````Java
assert(mat(1) + mat(0) == mat(4))
````


### Question 8
Écrire dans la classe **MatrixIntAsRDD** la méthode `transpose():MatrixIntAsRDD` qui calcule la transposée d’une matrice, c’est à dire que la ligne i devient la colonne i
et la colonne j devient la ligne j. Vous testerez cette fonction en ajoutant à votre programme de test les lignes suivantes :
````Java
assert(mat(5) == mat(4).transpose ())
assert(mat(1) != mat(4).transpose ())
assert(mat(0).transpose() == mat(1).transpose ())
````

### Question 9
(question issue de l’examen janvier 2017)
La multiplication de deux matrices A par B nécessite que le nombre de colonnes de A soit égale au nombre de lignes de B. Ainsi si la matrice C est égale à la multiplication
de A par B, alors l’élément (i, j) de C correspond à la multiplication la ligne i de A avec la colonne j de B. Exemple :
