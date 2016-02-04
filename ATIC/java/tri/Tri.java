public class Tri{
    public static int posMin(int[] t, int d, int f){
	int imin = d;
	
	for (int i = d; i <= f; i++)
	    if (t[i] < t[imin])
		imin = i;
	return imin;
    }

    public static void tri(int[] t, int d, int f){
	int tmp;
	int imin;
    
	if (d < f){
	    tmp = t[d];
	    imin = posMin(t,d,f);
	    t[d] = t[imin];
	    t[imin] = tmp;
	    tri(t,d+1,f);
	}
    }

    public static void aff(int[] t){
	int p = t.length - 1;

	for (int i = 0; i <= p; i++)
	    System.out.print(t[i]+" ");
	System.out.println();
    }

    public static void main(String[] args){
	int[] t;

	t = new int[10];
	for (int i = 0; i < 10; i++)
	    t[i] = (int)(Math.random() * 10);
	aff(t);
	tri(t,0,9);
	aff(t);
    }
}