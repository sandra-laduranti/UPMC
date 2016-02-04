public class Maillon{
    private int num;
    private Maillon suivant;

    public Maillon(int n, Maillon s){
	num = n;
	suivant = s;
    }

    public String toString(){
	return String.valueOf(num);
    }

    public int getCont(){
	return num;
    }

    public Maillon getNext(){
	return suivant;
    }

    public void setNext(Maillon m){
	suivant=m;
    }

    public static void main(String[] arg){
	Maillon m1 = new Maillon(3,null);
	Maillon m2 = new Maillon(5,m1);
	System.out.println(m2);
	System.out.println(m2.suivant);
	m1.setNext(m2);
	System.out.println(m1.suivant);
    }
}