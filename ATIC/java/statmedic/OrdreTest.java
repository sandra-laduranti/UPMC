import java.util.*;

public class OrdreTest implements Comparator<Test>{
    private int critere;
    //1 => taux 0 => nom

    public OrdreTest(int c){
	critere = c;
    }

    public int compare(Test o1, Test o2){
	if (critere == 0){
	    return o1.getNom().compareTo(o2.getNom());
	}
	else{
	    double res = o1.compareTaux(o2);
	    if (res == 0)
		return 0;
	    if (res > 0)
		return 1;
	    return -1;
	}
    }

    public static void main(String[] args){
    }
}