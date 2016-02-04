public class Carte implements Comparable<Carte>{
    private int valBois;
    private int valCarte;
    public final static String[] figure={"as","valet","dame","roi"};
    public final static String[] bois ={"trefle","carreau","coeur","pique"};

    public Carte(){
	valBois = 1;
	valCarte = 1;
    }

    public Carte(int b, int h){
	valBois = b;
	valCarte = h;
    }

    public int getValBois(){
	return valBois;
    }

    public int getValCarte(){
	return valCarte;
    }

    public String toString(){
	if (valCarte > 1 && valCarte < 11)
	    return "{"+valCarte+" de "+bois[valBois]+"}";
	if (valCarte == 1)
	    return "{"+figure[0]+" de "+bois[valBois]+"}";
	return "{"+figure[valCarte-10]+" de "+bois[valBois]+"}";
    }

    public boolean equals(Object ob){
	if (ob instanceof Carte){
	    Carte c = (Carte)ob;
	    return valCarte == c.getValCarte();
	} 
	return false;
    }

    public int compareTo(Carte c){
	int c2val = c.getValCarte();
	if (valCarte == c2val)
	    return 0;
	if (valCarte == 1)
	    return 1;
	if (c2val == 1)
	    return -1;
	if (valCarte > c2val)
	    return 1;
	return -1;
    }

    public static void main(String[] args){
	Carte c = new Carte();
	System.out.println(c);
	Carte c1 = new Carte(2,1);
	Carte c2 = new Carte(3,12);
	Carte c3 = new Carte(1,1);
	System.out.println("c1="+c1);
	System.out.println("c2="+ c2);
	System.out.println("c3="+c3);
	System.out.println(c1.equals(c3));
	System.out.println(c2.equals(c3));
	System.out.println(c2.compareTo(c3));
	System.out.println(c3.compareTo(c2));
	System.out.println(c3.compareTo(c));
    }
}