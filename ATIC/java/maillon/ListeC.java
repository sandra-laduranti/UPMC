public class ListeC{
    private Maillon dernier;

    public ListeC(){
	dernier = null;
    }

    public boolean isEmpty(){
	return dernier == null;
    }

    public Maillon premier(){
	if (isEmpty())
	    return null;
	return (dernier.getNext());
    }

    public int numPremier(){
	return premier().getCont();
    }

    public void add(int n){
	Maillon m;

	if (isEmpty()){
	    m = new Maillon(n,null);
	    m.setNext(m);
	    dernier = m;
	}
	else{
	    m = new Maillon(n,premier());
	    dernier.setNext(m);
	    dernier = m;
	}
    }

    public void remove(){
	if (!isEmpty()){
	    if (premier() == dernier)
		dernier = null;
	    else
		dernier.setNext(premier().getNext());
	    }
    }

    public void lNext(){
	dernier = premier();
    }

    public String toString(){
	if (isEmpty())
	    return "{}";
	StringBuffer sb = new StringBuffer("{");
	for (Maillon m = premier(); m != dernier; m = m.getNext())
	    sb.append(m.getCont()+", ");
	sb.append(dernier.getCont()+"}");
	return sb.toString();
    }
 
   public static void main(String[] arg){
	ListeC lc = new ListeC();
	System.out.println(lc);
	System.out.println(lc.isEmpty());
	lc.add(3);
	lc.add(5);
	System.out.println(lc.numPremier());
	lc.add(8);
	System.out.println(lc);
	lc.lNext();
	System.out.println(lc);
	lc.remove();
	System.out.println(lc);
    }
}