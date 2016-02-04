public class EchantillonT{
    private int nbElem;
    private static int nbTotal = 50;
    private Test[] contenu;

    public EchantillonT(){
	nbElem = 0;
	contenu = new Test[nbTotal];
    }

    public boolean isEmpty(){
	return nbElem == 0;
    }

    public void add(Test t){
	if (nbElem < nbTotal)
	    contenu[nbElem++] = t;
	else
	    System.out.println("vous devez creer un nouvel échantillon");
    }

    public String toString(){
	if (isEmpty())
	    return "{}";
	StringBuffer sb = new StringBuffer("{");
	for (int i = 0; i < nbElem - 1; i++)
	    sb.append(contenu[i]+", ");
	sb.append(contenu[nbElem-1]+"}");
	return sb.toString();
    }

    public int size(){
	return nbElem;
    }

    public Test getTest(int i){
	if (i < 0 || i > nbElem)
	    return null;
	return contenu[i];
    }

    public double getTaux(int i){
	Test t = this.getTest(i);
	if (t == null)
	    return -1;
	return t.getTaux();
    }

    public int indexOf(Test t){
	for (int i = 0; i < nbElem; i++){
	    if (t.equals(contenu[i]))
		return i;
	}
	return -1;
    }

    public void modifTaux(Test t, double ntaux){
	int index = this.indexOf(t);

	if (index != -1)
	    contenu[index] = new Test(t.getNom(),t.getDate(),ntaux);
	else
	    System.out.println("votre test ne fait pas parti de l'echantillon");
    }

    public void affAlerte(){
	for (int i = 0; i < nbElem; i++){
	    if (contenu[i].alerte() == true)
		System.out.println("Alerte: " + contenu[i]);
	}
    }

    public static void main(String[] args){
	Test t1 = new Test();
	Test t2 = new Test("titi",20140120,10);
	Test t3 = new Test("toto",20140120,0.12);
	Test t4 = new Test("trululu",20140120,15);
	EchantillonT e = new EchantillonT();

	e.add(t1);
	System.out.println(e);
	e.add(t2);
	System.out.println(e);
	e.add(t3);
	System.out.println(e);
	System.out.println(e.getTest(2));
	System.out.println(e.getTaux(2));
	System.out.println(e.indexOf(t4));
	e.modifTaux(t1,0.1);
	System.out.println(e);
	System.out.println("alertes =");
	e.affAlerte();
    }
}