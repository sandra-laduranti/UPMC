package TP01Part1;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;

public class Monologue {
	
	void main(String args[]){
			InputStream is = System.in;
			Reader r = new InputStreamReader(is);
			
			try {
				int x;
				while((x = r.read()) != -1 ){
					System.out.write(x);
				}
				is.close();
				r.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

}
