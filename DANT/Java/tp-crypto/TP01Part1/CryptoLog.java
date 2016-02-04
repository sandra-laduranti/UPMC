package TP01Part1;
import java.io.*;

import filter.CesarWriter;

public class CryptoLog {
		
	public static void main(String[] args){
		InputStream is = System.in;
		Reader r = new InputStreamReader(is);
		Writer w;
		filter.CesarWriter ws;
		String x;
		BufferedReader bfr = new BufferedReader(r);
				
		try {
			
			w = new FileWriter("Crypto.Cesar");
			ws= new filter.CesarWriter(w, 2);
			
			System.out.println("Enter the text to crypt (Ctrl+D to stop) :\n");
			
			x = bfr.readLine();
			ws.write(x);
			ws.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
