# TD CODEL 20172018
Exercices de Map-Reduce
(par Jonathan Lejeune)

la fonction map
````Java
Map(<TypeCléMap> key, <TypeValeurMap> value){
//ici votre pseudo code map
}
````
  - la fonction reduce
Reduce(<TypeCléReduce> key, liste de <TypeValeurReduce> values){
//ici votre pseudo code reduce
}
````
  - la fonction de partitionnement
````Java
IdReduce getPartition(<TypeCléReduce> key, <TypeValeurReduce> value,
entier nbReduce){
//retourne l'identifiant reduce de 0 à nbReduce-1 pour <key,value>
}
````
  - la fonction de tri
````Java
entier compare(<TypeCléReduce> key1, <TypeCléReduce> key2){
//retourne négatif si key1 < key2
//retourne nul si key1 = key2
//retourne positif si key1 > key2
}
````



## StereoPrix est une entreprise de grande distribution et souhaite faire des statistiques sur
les ventes. Elle possède une base de données stockée sur un système HDFS. Ces données
sont stockées dans des fichiers textes. Chaque ligne d'un fichier correspond à la vente
d'un produit et on peut y trouver des informations comme :
  - la date et l'heure de vente
  - le nom du magasin où le produit a été vendu
  - le prix de vente
  - la dénomination du produit
  - la catégorie du produit (ex : fruits et légumes, électroménager, jouet, ....)
  - 12:15:00-15/12/18 totomagasin 5€ pile electromenager

### Question 1
Écrivez un programme map-reduce permettant de calculer Le chiffre d'affaire de
l'entreprise c'est à dire la somme total des ventes des 5 dernières années (année en
cours non comprise)

````Java

Map(Integer key, string value){
  //key => id of the line
  //value =>content of the line
  (split dans tab)
  if (value.date.year >= yearnow-5 && value.date.year != yearnow){
    Emit ("price", value.price);
  }
}

Reduce(String key, liste de integer values){
  //key: price
  //values: list of prices
  integer total = 0
  for each(v in values){
    total += v
  }
  Emit (key, total)
}
````

### Question 2
Écrivez le programme map-reduce permettant de calculer le chiffre d'affaire généré
pour chaque catégorie.

````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  Emit(value.categorie, value.price)
}

Reduce(String key, liste de integer values){
  //key => categorie
  //values => list of prices
  integer total = 0
  for each (v in values){
    total += v
  }
  Emit(key,total)
}
````

### Question 3
Écrivez le programme map-reduce permettant de calculer le produit le plus vendu par
catégorie.

````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  Emit(value.categorie, value.product)

}

Reduce(String key, liste de string values){
  //key => categorie
  //values => list de produits
  Hashmap products = {product,occur}
  Int max = 0
  String maxprod;
  for each v in value{
    products[v].occur++ // on augmente la valeur du nb de fois
    if (products[v].occur > max){
      max = products[v].occur
      maxprod = v
    }
  }
  Emmit(key,maxprod);
}
````


## Exercice 2 - Booble
L'entreprise "Booble" , gestionnaire d'un moteur de recherche de pages web, souhaite
effectuer des statistiques sur l'ensemble des requêtes des usagers. L'entreprise possède
plusieurs serveurs dans le monde. À chaque nouvelle requête reçue, une ligne de log est
sauvegardée dans un fichier du serveur sur lequel la connexion s'est faite. Cette ligne de
log est formatée de la manière suivante :
- le premier mot indique la date de la connexion au format JJ_MM_AAAA
- le deuxième mot indique l'heure de la connexion au format HH_MM_SS
- le troisième mot indique l'adresse IP du client ayant fait la requête
- le reste de la ligne contient les mots-clés de la requête. Chaque mot-clé est séparé
par le caractère +.
Nous donnons comme exemple la ligne ci-dessous où des espaces ont été ajoutés pour une
meilleure lisibilité.
02_11_2012 12_32_10 132.227.045.028 musique+orientale
Ceci indique que le client 132.227.45.28 a fait une requête comportant les mots clés "musique" et
"orientale" le 02/11/2012 à 12h 32min 10sec

### Question 1
Écrivez le programme map-reduce permettant de calculer par tranche horaire d'une
demi-heure d'une journée type le mot clé le plus recherché dans la tranche ainsi que
le nombre total de requêtes reçues dans la tranche.
Par exemple, voici le format d'un fichier de sortie
_entre 00h00 et 00h29 <Le mot le plus recherché dans cette tranche horaire> <le nombre total de requêtes reçues dans cette tranche horaire>
entre 00h30 et 00h59 <Le mot le plus recherché dans cette tranche horaire> <le nombre total de requêtes reçues dans cette tranche horaire>
entre 01h00 et 01h29 <Le mot le plus recherché dans cette tranche horaire> <le nombre total de requêtes reçues dans cette tranche horaire>
...
entre 23h00 et 23h29 <Le mot le plus recherché dans cette tranche horaire> <le nombre total de requêtes reçues dans cette tranche horaire>
entre 23h30 et 23h59 <Le mot le plus recherché dans cette tranche horaire> <le nombre total de requêtes reçues dans cette tranche horaire>_


````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  Tab req = value.split(" ")
  String tranche <- calcul tranche horaire
  String mois <- getMois
  String motsclés = req[3]
  Emit(tranche, motsclés)
}

Reduce(String key, liste de string values){
  //key =>tranche horaire
  //value => motsclés
  Int totalReq = values.size()
  Tab motsclés = value.split("+")
  Hashmap mot<mot, occur)
  String maxMot;
  Int max = 0;

  for each m in motsclés{
    mot[m].occur++
    if (mot[m].occur > max){
      max = mot[m].occur
      maxMot = m
    }
  }
  String rep = "key" + maxMot + " " + totalReq
  Emit(rep, "")
}
````

### Question 2
Modifiez le programme précédent pour avoir ces mêmes informations mais classifiées
par mois de l'année. Nous souhaitons un fichier de sortie par mois. Par exemple un
fichier représentant le mois de février ne dois contenir que des informations sur les
jours du mois de février

````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  Tab req = value.split(" ")
  String trancheHoraire <- calcul tranche horaire
  String mois <- getMois
  String motsclés = req[3]
  Emit(<mois,trancheHoraire>, motsclés)
}

Reduce(String key, liste de string values){
  //key =>tranche horaire
  //value => motsclés
  Int totalReq = values.size()
  Tab motsclés = value.split("+")
  Hashmap mot<mot, occur)
  String maxMot;
  Int max = 0;

  for each m in motsclés{
    mot[m].occur++
    if (mot[m].occur > max){
      max = mot[m].occur
      maxMot = m
    }
  }
  String rep = "key" + maxMot + " " + totalReq
  Emit(rep, "")
}

IdReduce getPartition(<mois,tancheHoraire> key, list of string, entier nbReduce){
  //retourne l'identifiant reduce de 0 à nbReduce-1 pour <key,value>
  return (key.getmois-1)%nbReduce
}
````

## Exercice 3 - Un cas réel d'utilisation : Last.fm
Last.fm est un site web de radio en ligne et de musique communautaire orant diérents
services à ses utilisateurs comme par exemple l'écoute ou le téléchargement gratuit
de musiques. Il existe plus de 25 millions d'utilisateurs qui utilisent Last.fm tous les mois
générant ainsi beaucoup de données à traiter. L'analyse de données la plus courante se
fait sur les informations que les utilisateurs transmettent au site lorsqu'ils écoutent une
musique. Grâce à ces informations, il possible de produire entre autres des hit-parades.
Un titre peut être écouté de deux manières diérentes par un utilisateur :
- soit en local sur son propre ordinateur et les informations d'écoute sont envoyées
directement au serveur de Last.fm
- soit via une web radio sur le site même. Dans ce cas, l'utilisateur a la possibilité
de passer le titre sans l'écouter.
Le système logue pour chaque utilisateur et pour chaque titre le nombre de fois où
l'utilisateur a écouté le titre en local, le nombre de fois où l'utilisateur a écouté le titre
en ligne et le nombre de fois où l'utilisateur l'a passé sans l'écouter. Le tableau ci-dessous
en donne un exemple.
UserId  | TrackId  | LocalListening  | RadioListening | Skip
--|---|---|---|--
111115  | 222 | 0  | 1  | 0
111113  | 225 | 3  | 0  | 0
111117  | 223 | 0  | 1  | 1
111115  | 225 | 2  | 0  | 0
111120  | 221 | 0  | 0  | 1
L'objectif de cet exercice est de calculer pour chaque titre :
  1. le nombre de personnes qui l'ont écouté au moins une fois (en local ou en radio)
  2. le nombre de fois où il a été écouté et passé sans écoute.
Pour ceci nous allons procéder en trois jobs MapReduce :
  - le job 1 et 2 qui calculeront respectivement 1) et 2) et qui pourront s'exécuter en
parrallèle
  - le job 3 qui fusionnera les résultats des deux jobs précédents

### Question 1
Écrivez le programme map-reduce du job 1. Dans le cas de l'exemple donné sa sortie
devra être

TackId  | #listener
--|--
222  | 1
223  | 1
225  | 2

````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  //on calcul d'abord s'il y a eu au moins une écoute
  Int listening = (LocalListening >= 1 || RadioListening >=1) ? 1 : 0
  Emmit(TrackId, listening)
}

Reduce(String key, liste de int values){
  //key =>tranche horaire
  //values => si une personne a écouté ou non
  Int total = 0
  for each v in values{
    total += v
  }
  Emmit(key,total)
}
````
### Question 2
Écrivez le programme map-reduce du job 2. Dans le cas de l'exemple donné sa sortie
devra être :

TrackId | #listening  | #skips
--|---|--
221  | 0 | 1
222  | 1 | 0
223  | 1 | 1
225  | 5 | 0

````Java
Map (Integer key, string value){
  //key => id of the line
  //value => content of the line
  //on calcul d'abord s'il y a eu au moins une écoute
  Int listening = LocalListening + RadioListening
  Emmit(TrackId, <listening,skip>)
}

Reduce(String key, liste de <int,int> values){
  //key =>tranche horaire
  //values => nombre d'écoutes
  Int totalListen = 0
  Int totalSkip = 0
  for each v in values{
    totalListen += v.listening
    totalSkip += v.skip

  }
  Emmit(key,<totalListen,totalSkip>)
}
````

### Question 3
Écrivez le programme map-reduce du job 3. Dans le cas de l'exemple donné sa sortie
devra être :

TrackId | #listener | #listening  | #skips
--|---|---|--
221  | 0 | 0 | 1
222  | 1 | 1 | 0
223  | 1 | 1 | 1
225  | 2 | 5 | 0

````
