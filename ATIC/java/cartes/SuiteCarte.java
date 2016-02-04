import java.util.*;

public class SuiteCarte implements Iterable<Carte>{
    
    public Iterator<Carte> iterator(){
	return new CarteIter(this);
    }

    public ArrayList<Carte> makeList(){
	ArrayList<Carte> res = new ArrayList<Carte>();
	for(Carte c:this)
	    res.add(c);
	return res;
    }
    public Iterator<Carte> randomIterator(){
	return new RandomIter<Carte>(makeList());
    }

    public ArrayList<Carte> makeListRandom(){
	ArrayList<Carte> res = new ArrayList<Carte>();
	Iterator<Carte> it = randomIterator();
	while(it.hasNext()){
	    res.add(it.next());
	}
	return res;

    }
    
    public static void main(String[] args){
	SuiteCarte sc = new SuiteCarte();
	/*	for(Carte c:sc)
		System.out.println(c);*/
	ArrayList<Carte> Suite = sc.makeListRandom();
	System.out.println(Suite);
    }
    
}