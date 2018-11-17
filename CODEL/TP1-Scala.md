#Scala

Tp par Jonathan Lejeune

*note: possible de tester scala en ligne via [Scatie](https://scastie.scala-lang.org)*

### Objectifs
Ce sujet de travaux pratiques vous permettra de vous exercer sur la syntaxe scala et à la programmation objet.
Vous pourrez au choix utiliser l'interpréteur scala ou bien utiliser le compilateur scala.
Dans un premier temps créez un projet scala nommé "TPs_scala" dans Eclipse et créez y un package appelé "TP1".

## Excercice 1 - Coder une classe simple
### Question 1
Dans le package du TP créez un application scala appelée "exo1".
###Question 2
Dans le même fichier créez une classe Catalogue. Cette classe permet d'associer un nom de produit à un prix unitaire. Ainsi ses champs seront :
  - un attribut de type Map qui associera un nom de produit à un prix
  - une méthode addProduit qui ajoute un produit dans le catalogue avec son prix unitaire
  - une méthode removeProduit qui supprimera un produit donné du catalogue
  - une redéfinition de la méthode toString qui produira grâce à un StringBuffer de Java une chaine de caractère affichant pour chaque produit de catalogue son prix unitaire en euros sur une ligne. Exemple

_produit1 : 10 euros
produit2 : 1.99 euros_

````Scala
class Catalogue(){
  var catal:Map[String, Int] = Map()
  
  def addProduit(p:String, e:Int) = {
    catal += (p -> e)
  }
  
  def removeProduit(p:String) = {
    catal -= (p)
  }
  
  override def toString()={
    var bl = new StringBuilder()
    for ((k,v) <- catal){
      bl.append(k+":"+v+"e\n")
    }
    bl.toString()
  }
}

val catalogue = new Catalogue
catalogue.addProduit("peluche",10)
catalogue.addProduit("tondeuse",250)
println(catalogue)
catalogue.removeProduit("peluche")
println(catalogue)
````

## Exercice 2 - Structure de données en arbre binaire

### Question 1
Dans le package du TP créez un application scala appelée "exo2".

### Question 2
Soient les définitions suivantes :

````Scala
abstract class IntTree ;
case object EmptyIntTree extends IntTree ;
case class NodeInt ( elem : Int , left : IntTree , right : IntTree ) extends IntTree ;
````

Complétez les fonctions suivantes :
````Scala
def contains( t : IntTree , v : Int ) : Boolean = t match 
def size ( t : IntTree ) : I n t = t match
def insert ( t : IntTree , v : Int ) : IntTree = t match 
````

### Question 3
Testez vos fonctions avec le code suivant :
var tree : IntTree = EmptyIntTree
for( v <- 1 t o 1 0 ) {
tree=insert(tree , v )
}
assert(size(tree) == 1 0 )
for( v <- 1 t o 1 0 ) {
  assert(contains (tree , v ) )
}
for( v <- 11 t o 2 0 ) {
  assert ( !contains (tree , v ) )
}
println("Ok")

### Question 4
Généralisez les types IntTree, EmptyIntTree et NodeInt respectivement en Tree, EmptyTree
et Node afin de traiter des arbres de n'importe quel type A.
### Question 5
Recodez une version des fonctions contains, size et insert pour les Tree.
### Question 6
Testez votre généralisation avec le programme de la question 3 en remplaçant la
première ligne par var tree:Tree[Int] = EmptyTree
