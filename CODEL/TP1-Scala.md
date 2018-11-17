# Scala

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
def size ( t : IntTree ) : Int = t match
def insert ( t : IntTree , v : Int ) : IntTree = t match 
````

````Scala
def size(t:IntTree):Int=t match{
  case EmptyIntTree=>0
  case NodeInt(e,l,r)=>1+size(l)+size(r)
}

def contains(t:IntTree, v:Int):Boolean= t match{
	case EmptyIntTree => false
  case NodeInt(e,l,r) if e==v =>true
  case NodeInt(e,l,r) if e<v=>contains(r,v)
   case NodeInt(e,l,r) if e>v=>contains(l,v)
}

def insert(t:IntTree, v:Int):IntTree = t match{
  case EmptyIntTree => new NodeInt(v, EmptyIntTree, EmptyIntTree)
  case NodeInt(e,l,t) if v<e => NodeInt(e, insert(t,v), t)
  case NodeInt(e,l,r) => NodeInt(e, l, insert(r,v))
}

````

### Question 3
Testez vos fonctions avec le code suivant :
````Scala
var tree : IntTree = EmptyIntTree
for(v <- 1 to 10 ) {
tree=insert(tree,v)
}
assert(size(tree) == 10 )
for(v <- 1 to 10 ) {
  assert(contains (tree,v))
}
for(v <- 11 to 20) {
  assert (!contains (tree,v))
}
println("Ok")
````

### Question 4
Généralisez les types IntTree, EmptyIntTree et NodeInt respectivement en Tree, EmptyTree
et Node afin de traiter des arbres de n'importe quel type A.

````Scala
abstract class Tree[+T];
case object EmptyTree extends Tree;
case class Node[T] ( elem : Int , left : Tree[T] , right : Tree[T] ) extends Tree ;
````

### Question 5
Recodez une version des fonctions contains, size et insert pour les Tree.
````Scala
def size[T](t:T):Int=t match{
  case EmptyTree=>0
  case Node(e,l,r)=>1+size(l)+size(r)
}

def contains[T](t:T, v:Int):Boolean= t match{
	case EmptyTree => false
  case Node(e,l,r) if e==v =>true
  case Node(e,l,r) if e<v=>contains(r,v)
   case Node(e,l,r) if e>v=>contains(l,v)
}

def insert[T](t:Tree[T], v:Int):Tree[T] = t match{
  case EmptyTree => new Node(v, EmptyTree, EmptyTree)
  case Node(e,l,t) if v<e => Node(e, insert(t,v), t)
  case Node(e,l,r) => Node(e, l, insert(r,v))
}
````
### Question 6
Testez votre généralisation avec le programme de la question 3 en remplaçant la
première ligne par var tree:Tree[Int] = EmptyTree

````Scala
var tree : Tree[Int] = EmptyTree
for(v <- 1 to 10 ) {
tree=insert(tree,v)
}
assert(size(tree) == 10 )
for(v <- 1 to 10 ) {
  assert(contains (tree,v))
}
for(v <- 11 to 20) {
  assert (!contains (tree,v))
}
println("Ok")
````

## Exercice 3 - Vecteur d'entier
### Question 1
Écrire une classe scala VectorInt
- qui étend le trait Serializable
- qui possède un attribut immutable elements qui est un tableau de Int, que l'on
spécifiera à l'instanciation de l'objet
- qui possède une méthode implicit permettant de convertir implicitement et automatiquement
un tableau de Int en VectorInt
- et qui offre comme méthodes :
	- length:Int qui renvoie la taille du vecteur
	- get(i:Int):Int qui renvoie la valeur présente à l'indice i compris entre 0 et length -1
	- tostring qui renvoie une représentation String du vecteur au format (v0 v1 v2 ..)
	- equals(a:Any):Boolean qui teste l'égalité avec un objet a. Vous utiliserez un pattern matching : si a est de type Vector et que toutes les valeurs sont égales alors retourne vrai, faux sinon.
	- +(other:VectorInt):VectorInt qui fait la somme de deux vecteurs
	- *(v:Int):VectorInt qui multiplie toutes les valeurs du vecteur par le scalaire v
	- prodDyadique(other:VectorInt):Array[VectorInt] : (noté ⊗ en mathématiques) et qui calcul le produit dyadique entre deux vecteurs, où le résultat est une matrice que nous représentons ici par un tableau de vecteur (un vecteur est une ligne de la matrice). Un produit dyadique u⊗v de deux vecteurs de même taille revient à multiplier u en tant que vecteur colonne par v en tant que vecteur ligne. Par exemple :
	
![u \otimes v \rightarrow \begin{bmatrix} u_{1} \\u_{2} \\u_{3} \end{bmatrix} \otimes [v_{1}\ v_{2}\ v_{3}] = \begin{bmatrix} u_{1}v_{1} & u_{1}v_{2} & u_{1}v_{3} \\u_{2}v_{1} & u_{2}v_{2} & u_{2}v_{3} \\u_{3}v_{1} & u_{3}v_{2} & u_{3}v_{3} \end{bmatrix}]("https://www.codecogs.com/eqnedit.php?latex=u&space;\otimes&space;v&space;\rightarrow&space;\begin{bmatrix}&space;u_{1}&space;\\u_{2}&space;\\u_{3}&space;\end{bmatrix}&space;\otimes&space;[v_{1}\&space;v_{2}\&space;v_{3}]&space;=&space;\begin{bmatrix}&space;u_{1}v_{1}&space;&&space;u_{1}v_{2}&space;&&space;u_{1}v_{3}&space;\\u_{2}v_{1}&space;&&space;u_{2}v_{2}&space;&&space;u_{2}v_{3}&space;\\u_{3}v_{1}&space;&&space;u_{3}v_{2}&space;&&space;u_{3}v_{3}&space;\end{bmatrix}")

````Scala
class VectorInt(val t: Array[Int]) extends Serializable{
    class IntVector(val origin : Array[Int]) { 
      def vector = origin.toVector
    }
  
    implicit def tabIntToVector(value : Array[Int]) = new IntVector(value)
  
  	def length: Int = t.vector.size
  
  	def get(i:Int): Int = t(i)
  
  	override def toString(): String ={
      var str = new StringBuffer();
      str.append("( ")
      for ( i <- 0 to (t.length - 1)){
        str.append(t(i)+" ")
      }
      str.append(")")
      str.toString()
    }
  
    override def equals( a: Any ): Boolean = a match {
      case that : VectorInt if(that.t.vector.equals(this.t.vector) ) => true
      case that : VectorInt  => false
    }
  
  	def +(other: VectorInt): VectorInt = {
      if (other.length != t.length) throw new Exception("+ size error")
      var resVector : Array[Int] = Array.ofDim(t.length)
      for (i <- 0 to (t.length - 1)){
        resVector(i) = this.t(i) + other.t(i)
      }
      new VectorInt(resVector)
    }
  
    def *(v:Int): VectorInt = {
      var resVector : Array[Int] = Array.ofDim(t.length)
        for (i <- 0 to (t.length - 1)){
          resVector(i) = this.t(i) * v
        }
        new VectorInt(resVector)
    }
  
    def prodDyadique(other: VectorInt): Array[VectorInt] = {
        var resVector : Array[VectorInt] = Array.ofDim(t.length)
        for( i <- 0 to (other.t.length -1)){
          var tmp : Array[Int] = Array.ofDim(other.t.length)
          for(j <- 0 to (t.length - 1)){
            tmp(j) = (t(i)*other.t(j))
          }
          resVector(i) = new VectorInt(tmp);
        }
        return resVector
    }
}
````

### Question 2

Testez votre classe Vector avec le programme suivant :

````Scala
object Main extends App{
	def testVectorInt = {
	   	val v1 = new VectorInt(Array(1,4,1))
	    	val v2 = new VectorInt(Array(2,-1,4))
	    	val v3 = new VectorInt(Array(2,-1,4,6,10,-3))
	    	val v4 = new VectorInt(Array(1,4,1))
		assert( v1.length == 3 )
		assert( v2.length == 3 )
		assert( v3.length == 6 )
		assert( v4.length == 3 )
		assert( v4==v1 )
		assert( v1==v1 )
		assert( v4==v4 )
		assert( v3 != v2 )
		assert( v2 != v3 )
		assert( v1 != v3 )
		assert( v1 != v2 )
		assert( v1 + v2 == new VectorInt(Array(3,3,5)))
		assert( v2 + v1 == new VectorInt(Array(3,3,5)))
		assert( v1 + v1 == v4 + v1 )
		assert( v1 + v1 == v4 + v1 )
		assert( v3 ∗ 10 == v3 + ( v3 ∗9 ) )
		assert( v2 ∗ 2 == v2 + v2 )
		v2.prodD(v1).foreach(println(_))
	}
	t e s t V e c t o r I n t
}
````

L'affichage attendu pour le produit dyadique est :
````
( 2  8  2 )
( -1  -4  -1 )
( 4  16  4 )
````
