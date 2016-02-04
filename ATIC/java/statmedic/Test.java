public class Test{
    private static double tauxAlerte = 0.22;
    private String nom;
    private int date;
    private double taux;

    public Test(String n, int d, double t){
	this.nom = n;
	this.date = d;
	this.taux = t;
    }

    public Test(){
	this("",0,-1);
    }

    public String toString(){
	return "["+nom+", "+date+" : "+taux+"]";
    }    

    public String getNom(){
	return nom;
    }

    public int getDate(){
	return date;
    }

    public double getTaux(){
	return taux;
    }

    public boolean isTest(){
	return (taux >= 0 && taux <= 1);
    }

    public boolean alerte(){
	return (taux <= tauxAlerte);
    }

    public double compareTaux(Test t){
	return (taux - t.taux);
    }

    public boolean equals(Object o){
	if (o instanceof Test){
	    Test p = (Test)o;
	    return (nom.compareTo(p.nom) == 0 && date == p.date);
	}
	return false;
    }

    public static void main(String[] args){
	Test m1 = new Test();
	Test m2 = new Test("titi",20130114,10);
	Test m3 = new Test("titi",20130114,10);
	System.out.println(m1);
	System.out.println(m2);
	System.out.println(m1.isTest());
	System.out.println(m2.alerte());
	System.out.println(m2.compareTaux(m1));
	System.out.println(m2.equals(m3));
    }
}