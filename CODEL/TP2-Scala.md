# TP2 Scala
Par Jonathan Lejeune

### Objectifs
Ce sujet de travaux pratiques vous permettra de vous exercer sur la syntaxe scala et à la programmation fonctionnelle. Vous pourrez au choix utiliser l'interpréteur scala ou
bien utiliser le compilateur scala.

## Exercice 1 - C'est les soldes ! !
### Question 1
  Dans la classe Catalogue du TP1 sur sala, écrire une méthode qui réduit de x % tous les prix du catalogue. Vous ferez une version :
    - avec une boucle for (appelée soldefor(percent:Int))
    - avec l'appel à la méthode mapValues de la classe map avec un paramétrage d'une fonction nommée (appelée soldeFNomme(percent:Int)). La fonction nommée à
passer en paramètre sera la suivante :
`def diminution( a:Double ,percent:Int) : Double = a ∗ ((100.0 − percent)/100.0`
    - avec l'appel à la méthode mapValues de la classe map avec un paramétrage d'une fonction anonyme (appelée soldeFAno(percent:Int)) 
    Le prototype de la méthode mapValues est le suivant :
`def mapValues[C](f:(B)=>C):Map[A,C]`

Elle produit une nouvelle map à partir de la map appelante en appliquant sur chaque valeur la fonction f.

## Exercice 2 - Nombres premiers
Le crible d'Ératosthène est une méthode qui permet de trouver tous les nombres premiers inférieurs à un certain entier naturel N donné. Pour rappel un nombre premier est un
nombre entier qui n'est divisible que par 1 ou par lui-même. Exemples : 2 3 5 7 11 ....
Le principe de l'algorithme est de procéder par élimination. Il s'agit de supprimer d'une liste triée des entiers de 2 à N tous les éléments qui sont multiples d'un entier inférieur.
Ainsi il ne restera que les entiers qui ne sont multiples d'aucun entier, et qui sont donc les nombres premiers.

### Question 1
Écrire la fonction premiers qui pour un entier n donné renvoie la liste des nombres premiers inférieurs ou égaux à n. L'idée de cette fonction est d'appliquer le crible
d'Eratosthène en initialisant une liste d'entiers de 2 à n (utilisation de range) et d'appliquer successivement des ltres (méthode filter). Au ltre i il faudra enlever
de la liste les nombres qui sont divisible par i.

### Question 2
Écrire une autre version de la fonction premiers en utilisant une fonction imbriquée récursive dont l'algorithme est le suivant :
````
FONCTION f (liste entiers 1)
  SI  1 e r element au carré > dernier element
  ALORS resultat 1
  SINON
    resultat = concetenation du 1er element avec f 
    //( l sans le 1er element et tous les elements non multiples du 1er element )
  FIN SI
FIN FONCTION
````

## Exercice 3 - Letter Count
### Question 1
Écrire une fonction nbLetters qui pour une liste de chaîne de caractères donnée calcule le nombre de lettres différentes d'un espace qu'elle contient. Exemple : Pour
la liste
`( "Hadoop est une plateforme distribuee" , "Spark en est une autre" ,"scala est un langage" , "Java aussi" )`

Le résultat doit être 76.
Il vous est interdit d'utiliser une boucle. Pour ceci il faut :
  1. transformer la liste en liste de mots grâce à la méthode flatMap
  2. transformer la liste de mots en remplaçant chaque mot par son nombre de lettres grâce à la méthode map
  3. faire la somme de chaque élément grâce à la méthode reduce
  
## Exercice 4 - Moyenne
### Question 1
Nous souhaitons écrire une fonction moyenne qui pour une liste de notes pondérées donnée calcule la moyenne de cette liste. Un élément d'une telle liste est un tuple de
deux valeurs où le premier élément représente la note et le deuxième son coefficient respectif. Nous souhaitons utiliser les fonctions map et reduce qui calculeront un tuple
de deux valeurs :
  - la première valeur sera égale à la somme pondérée des notes
  - la deuxième valeur sera égale à la somme des coecients.
Le résultat de la fonction sera la division entre ces deux valeurs. Il vous est interdit d'utiliser une boucle.

## Exercice 5 - Fonction d'ordre supérieure
### Question 1
Écrire la fonction suivante : `def isSorted[A](as: Array[A], ordered: (A,A) =>Boolean): Boolean` qui teste si un tableau est trié selon l'ordre passé en paramètre.

### Question 2
Complétez le code suivant et faite en sorte qu'il fonctionne

````Scala
val ascending = //a compléter
val descending = //a compléter
val ar1 = Array(3,4,5,6,10)
val ar2 = Array(13,4,6,7,49)
assert(isSorted(ar1,ascending))
assert(!isSorted(ar1,descending))
assert(!isSorted(ar1.reverse,ascending))
assert(isSorted(ar1.reverse,descending))
assert(!isSorted(ar2,ascending))
assert(!isSorted(ar2,descending))
assert(!isSorted(ar2.reverse,ascending))
assert(!isSorted(ar2.reverse,descending))
````

## Exercice 6 - Des fonctions en folies !
### Question 1
Donnez le code des fonction suivantes :
`curryfie[A,B,C](f: (A, B) =>C): A =>B =>C = .....` qui renvoie une fonction quiest la version curryfiée de la fonction passée en paramètre
`decurryfie[A,B,C](f: A =>B =>C):(A, B) =>C = .....` qui renvoie une fonction qui est la version non curryée de la fonction passée en paramètre
et testez le code suivant :

````Scala
def plus(x:In t, y:Int ) = x+y
def fois(x:Int, y:Int) = x∗y
val p_curr = curryfie(plus)
val p_decurr = decurryfie(p_curr)
val f_curr = curryfie(fois)
val f_decurr = decurryfie(f_curr)
assert(p_curr(3)(4)==p_decurr(3,4))
assert(f_curr(6)(7)==f_decurr(6,7))
````

### Question 2
Donnez le code de la fonction suivante :
`compose[A, B, C](f: B =>C, g: A =>B): A =>C = .....` qui renvoie une fonction qui fait la composition des deux fonctions passées en paramètre

### Question 3
En utilisant exclusivement les fonctions dénies précédemment, donnez le code de la fonction suivante :
`axplusb(a:Int,b:Int):Int=>Int = .....` qui renvoie une fonction `f` tel que `f(x) = ax + b`
et testez le code suivant :

````Scala
valf1 = axplusb(3,4)
valf2 = axplusb(2,1)
assert(f1(3) == 13)
assert(f2(3 == 7)
````
