public class TriString{
    public static int posMin(String[] t, int d, int f){
	int imin = d;

	for (int i = d; i <= f; i++)
	    if (t[i].compareTo(t[imin]) < 0)
		imin = i;
	return imin;
    }


    public static void tri(String[] t){
	int p = t.length - 1;
	String tmp;
	int imin;

	for (int i = 0; i <= p; i++){
	    tmp = t[i];
	    imin = posMin(t,i,p);
	    t[i] = t[imin];
	    t[imin] = tmp;
	}
    }

    public static void aff(String[] t){
	int p = t.length - 1;

	for (int i = 0; i <= p; i++)
	    System.out.print(t[i]+" ");
	System.out.println();
    }

    public static void main(String[] args){
	String[] t= {"titi","zeze","abs"};

	aff(t);
	tri(t);
	aff(t);
    }
}