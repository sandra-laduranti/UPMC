public class PointR2{
    public double x;
    public double y;

    public PointR2(){
	this.x = 0;
	this.y = 0;
    }

    public PointR2(double a, double b){
	this.x = a;
	this.y = b;
    }
    
    public double distance(PointR2 p){
	return Math.sqrt(((p.x - this.x)*(p.x - this.x))+((p.y - this.y)*(p.y - this.y)));
    }
    
    public boolean equals(Object o){
	if (o instanceof PointR2){
	    PointR2 p = (PointR2)o;
	    return (this.x == p.x && this.y == p.y);
	}
	return false;
    }
    
    public String toString(){
	return "(" + this.x + "," + this.y + ")";
    }
    
    public static void main(String[] args){
	PointR2 p1 = new PointR2();
	PointR2 p2 = new PointR2(2,3);
	System.out.println(p1);
	System.out.println(p2);
	System.out.println(p1.distance(p2));
    }
}