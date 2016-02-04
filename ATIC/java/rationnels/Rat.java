import java.util.*;

public class Rat implements Comparable<Rat>{
    int num;
    int den;

    public static int pgcd(int p, int q){
	if (q == 0)
	    return (p);
	else
	    return (pgcd(q,p%q));	
    }

    public Rat(){
	num = 0;
	den = 1;
    }

    public Rat(int n){
	num = n;
	den = 1;
    }

    public Rat(int p, int q){
	num=p/pgcd(p,q);
	den=q/pgcd(p,q);

	if(den < 0){
	    num = -num;
	    den = -den;
	}
    }

    public String toString(){
	if (den == 1 || num == 0)
	    return num+"";
	return num+"/"+den;
    }

    public Rat plus(Rat r){
	int p;
	int q;

	p = (num*r.den)+(den*r.num);
	q = den*r.den;
	return (new Rat(p,q));
    }

    public Rat fois(Rat r){
	int p;
	int q;

	p = num*r.num;
	q = den*r.den;
	return (new Rat(p,q));
    }

    public double doubleVal(){
	double res = ((double)num/den);
	return (res);
    }

    public int compareTo(Rat r){
	return num*r.den - den*r.num;
    }

    public static void main(String[] args){
	Rat[] t = new Rat[4];
	Rat res = new Rat(1);

	for(int i = 1; i < 10; i++)
	   res = res.plus(new Rat(1,(int)Math.pow(2,i)));
	System.out.println(res);
	System.out.println(res.doubleVal());

	t[0] = new Rat(5);
	t[1] = new Rat(-6,5);
	t[2] = new Rat();
	t[3] = new Rat(-2,-9);
	System.out.println(Arrays.toString(t));
	Arrays.sort(t);
	System.out.println(Arrays.toString(t));
    }
}
