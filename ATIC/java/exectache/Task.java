public class Task{
    private int id;
    private int duree;
    private int reste;

    public Task(int n,int d){
	id = n;
	duree = d;
	reste = d;
    }

    public int getID(){
	return id;
    }

    public boolean fini(){
	return ((duree - reste) <= 0);
    }

    public void exec(int t){
	if ((duree - t) <= 0)
	    duree = 0;
	else
	    duree = (duree - t);
    }

    public String toString(){
	return "["+id+";"+duree+";"+reste+"]";
    }

    public boolean equals(Object o){
	if (o instanceof Task){
	    Task p = (Task)o;
	    return (p.id == id);
	}
	return false;
    }

    public static void main(String[] args){
	Task tache1 = new Task(1,10);
	Task tache2 = new Task(2,5);
	System.out.println(tache1);
	System.out.println(tache1.equals(tache2));
	tache1.exec(3);
	System.out.println(tache1);
    }
}