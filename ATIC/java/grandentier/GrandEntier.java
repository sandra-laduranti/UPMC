import java.util.*;

public class GrandEntier {
    private  List<Integer> liste;
    
    public GrandEntier(int n){
	liste = new ArrayList<Integer>();
	if (n != 0){
	    for(int i = n; i > 0; i = i/10){
		liste.add(new Integer(i%10));
	    }
	}
    }
    
    public GrandEntier(){
	liste = new ArrayList<Integer>();
    }
    
    public GrandEntier(String s){
	this(Integer.parseInt(s));
    }
    
    public GrandEntier(GrandEntier g){
	liste = new ArrayList<Integer>();
	liste.addAll(g.liste);
    }
    
    public int nbChiffres(){
	return liste.size();
    }
    
    public int chiffre(int i){
	int nb = nbChiffres();
	if (i > nb)
	    return -1;
	return liste.get(i);
    }
    
    public String toString(){
	if (liste.isEmpty())
	    return "0";
	StringBuffer sb = new StringBuffer("");
	for (int i = liste.size()-1; i >= 0; i--)
	    sb.append(liste.get(i));
	return sb.toString();
    }

    public boolean equals(Object ob){
	if (ob instanceof GrandEntier){
	    GrandEntier p = (GrandEntier)ob;
	    return (liste.equals(p.liste));
	}
	return false;
    }
    
    public GrandEntier somme(GrandEntier g){
	boolean maxg;
	int ret = 0;
	int tmp = 0; 
	int nbmin = g.nbChiffres();
	int nbmax;
	GrandEntier res = new GrandEntier();
	
	if (g.nbChiffres() > nbChiffres())
	    return g.somme(this);
	
	for (int i = 0; i < nbChiffres(); i++){
	    if (i < nbmin)
		tmp = g.chiffre(i) + chiffre(i) + ret;
	    else{
		tmp = chiffre(i);
		if (ret > 0)
		    tmp += ret;
	    }
	    ret = tmp / 10;
	    res.liste.add(new Integer(tmp % 10));
	}
	if (ret > 0)
	    res.liste.add(new Integer(ret));
	return res;	
    }
    
    public GrandEntier mult(int k){
	GrandEntier res = new GrandEntier();
	int ret = 0;
	int tmp = 0;

	for (int i = 0; i < nbChiffres(); i++){
	    tmp = (chiffre(i) * k) + ret ;
	    ret = tmp / 10;
	    res.liste.add(new Integer(tmp % 10));
	}
	if (ret > 0)
	    res.liste.add(new Integer(ret));
	return res;
    }


    public GrandEntier mult10(int p){
	GrandEntier res = new GrandEntier();

	for (int i = 0; i < p; i++){
	    res.liste.add(new Integer(0));
	}
	res.liste.addAll(liste);
	return res;
    }

    public GrandEntier mult(GrandEntier g){
	GrandEntier res = new GrandEntier();
	GrandEntier tmp;

	for (int i = 0; i < g.nbChiffres(); i++){
	    tmp = this.mult(g.chiffre(i));
	    res = res.somme(tmp.mult10(i));
	}
	return res;
    }

    public GrandEntier puis(int k){
	GrandEntier res = new GrandEntier(this);

	for (int i = 0; i < k-1; i++){
	    res = mult(res);
	    }
	return res;
    }

    public static GrandEntier fact(int k){
	GrandEntier res = new GrandEntier(1);

	for (int i = 2; i <= k; i++){
	    res = res.mult(new GrandEntier(i));
	}
	return res;
    }

    public static void main(String[] args){
	GrandEntier g = new GrandEntier();
	System.out.println(g);
	System.out.println(g.nbChiffres());
	GrandEntier h = new GrandEntier(0);
	System.out.println(h);
	System.out.println(h.nbChiffres());
	System.out.println(h.equals(g));
	String s = "3452";
	GrandEntier m = new GrandEntier(s);
	GrandEntier mcopie = new GrandEntier(m);
	System.out.println(m);
	System.out.println(mcopie);
	h = m.somme(g);
	System.out.println(g);
	System.out.println(m);
	g = m.mult(4);
	System.out.println(g);
	System.out.println(m.mult10(1));
	g = new GrandEntier(23);
	System.out.println(m.mult(g));
	h = g.puis(2);
	System.out.println(g);
	System.out.println(h);
	System.out.println(Math.pow(23,2));
	//	for(int i=0; i<15; i++)
	    System.out.println(fact(25));
    }
}
