import java.util.*;

public class CarteIter implements Iterator<Carte>{
    // private SuiteCarte suiteC;
    private int positionBois = -1;
    private int positionCarte = 1;

    public CarteIter(SuiteCarte sc){
	//suiteC = sc;
    }

    public boolean hasNext(){
	if (positionCarte == 1){
	    positionBois ++;
	    positionCarte ++;
	}
	else if (positionCarte == 13) positionCarte=1;
	else positionCarte++;
	return (positionBois < 4);   /* ou return (positionBois < 3 || positionCarte > 1) */
    }

    public Carte next(){
	return new Carte(positionBois, positionCarte);
    }

    public void remove(){
	throw new UnsupportedOperationException("Pas implemente");
    }
}