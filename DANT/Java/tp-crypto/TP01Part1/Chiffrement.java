package TP01Part1;
import java.io.*;


public class Chiffrement {
		
	public static void main(String[] args) throws FileNotFoundException{
				System.setIn(new FileInputStream(args[0]));
				CryptoLog.main(args);
	}
}
