import java.util.*;

public class Cercle implements Figure{
    public PointR2 cent;
    public double  ray;

    public Cercle(){
	cent = new PointR2();
	ray = 1;
    }

    public Cercle(PointR2 c, double r){
	cent = c;
	ray = r;
    }

    public double perimetre(){
	return 2*ray*Math.PI;
    }

    public double aire(){
	return Math.PI*Math.pow(ray,2);
    }

    public int compareTo(Figure f){
	double res = perimetre() - f.perimetre();
	
	if (res == 0)
	    return 0;
	if (res < 0)
	    return -1;
	return 1;
    }

    public String toString(){
	return "(" + this.cent + "," + this.ray + ")";
    }

    public static void main(String[] args){
	Figure[] t= new Figure[4];
	PointR2 r1 = new PointR2(3,2);
	PointR2 r2 = new PointR2(4,3);
	double rayon = 5;
	Cercle c1 = new Cercle(r1,rayon);

	System.out.println(c1);
	System.out.println(c1.perimetre());
	System.out.println(c1.aire());
	t[0] = new Cercle(r1,rayon);
	t[1] = new Rectangle();
	t[2] = new Cercle();
	t[3] = new Rectangle(r1,r2);
	System.out.println(Arrays.toString(t));
	Arrays.sort(t);
	System.out.println(Arrays.toString(t));
    }
}