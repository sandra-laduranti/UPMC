import java.util.*;

public class Echantillon extends ArrayList<Test>{
    public Echantillon(){
	super();
    }

    public double getTaux(int i){
	if (i < 0 || i > size())
	    return -1;
	Test t = get(i);
	return t.getTaux();

    }

    private void triAux(int crit){
	OrdreTest c = new OrdreTest(crit);
	Collections.sort(this,c);
    }

    public void triTaux(){
	triAux(1);
    }

    public void triNoms(){
	triAux(0);
    }

    public static void main(String[] args){
	Echantillon e = new Echantillon();
	e.add(new Test());
	e.add(new Test("tata",20140120,10));
	e.add(new Test("touta",20140120,0.12));
	e.add(new Test("trululu",20140120,15));

	System.out.println(e);
	System.out.println(e.getTaux(2));
	e.triTaux();
	System.out.println(e);
	e.triNoms();
	System.out.println(e);
    }
}