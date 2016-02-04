public class Rectangle implements Figure{
    public PointR2 ext1;
    public PointR2 ext2;

    public Rectangle(){
	this.ext1 = new PointR2();
	this.ext2 = new PointR2();
    }

    public Rectangle(PointR2 p, PointR2 q){
	this.ext1 = p;
	this.ext2 = q;
    }
    
    public Rectangle(PointR2 cig, double lo, double h){
	this.ext1 = cig;
	this.ext2 = new PointR2(cig.x+lo, cig.y+h);
    }
    
    public double longueur(){
	return (Math.abs(this.ext1.x - this.ext2.x));
    }

    public double hauteur(){
	return (Math.abs(this.ext1.y - this.ext2.y));
    }    

     public double perimetre(){
	 double total = this.longueur() + this.hauteur();
	 return (2*total);
    }

    public double aire(){
	double total = this.longueur() * this.hauteur();
	return (total);
    }

    public String toString(){
	return "(" + this.ext1 + "," + this.ext2 + ")";
    }

    public Rectangle symetrique(){
	return (new Rectangle(new PointR2(this.ext1.y,this.ext1.x),new PointR2(this.ext2.y,this.ext2.x)));
    }    

    public int compareTo(Figure f){
	double res = perimetre() - f.perimetre();
	
	if (res == 0)
	    return 0;
	if (res < 0)
	    return -1;
	return 1;
    }

    public static void main(String[] args){
	PointR2 p1 = new PointR2();
	PointR2 p2 = new PointR2(2,1);
	PointR2 p3 = new PointR2(3,4);
	Rectangle R1 = new Rectangle(p1, p2);
	Rectangle R2 = new Rectangle(p1, p3);
	System.out.println(R1);
	System.out.println(R1.longueur());
	System.out.println(R1.hauteur());
	System.out.println(R1.perimetre());
	System.out.println(R1.symetrique());
	System.out.println("R1 ="+R1.perimetre()+" R2= "+R2.perimetre());
	System.out.println(R2.compareTo(R1));
    }
}