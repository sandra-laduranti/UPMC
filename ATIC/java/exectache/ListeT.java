import java.util.*;

public class ListeT {

    private List<Task> listeTask;
    
    public ListeT(){
	listeTask = new ArrayList<Task>();
    }
    
    public int nbTask(){
	return listeTask.size();
    }
    
    public int indexOf(int num){
	int listeSize = nbTask();
	for (int i = 0; i < listeSize; i++){
	    if (listeTask[i].getID() == num)
		return i;
	}
	return -1;
    }

    public static void main(String[] args){
	ListeT lT = new ListeT();
    }
}