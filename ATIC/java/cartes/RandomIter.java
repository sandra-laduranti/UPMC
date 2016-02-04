import java.util.*;


public class RandomIter<Carte> implements Iterator<Carte>{
    private Iterator<Carte> iterator;

    public RandomIter(Collection<Carte> cartes){
	List<Carte> shuffled = new ArrayList<Carte>(cartes);
	Collections.shuffle(shuffled);
	iterator = shuffled.iterator();
    }

    public boolean hasNext(){
	return iterator.hasNext();
    }

    public Carte next(){
	return iterator.next();
    }

    public void remove(){
	throw new UnsupportedOperationException("Pas implemente");
    }
}