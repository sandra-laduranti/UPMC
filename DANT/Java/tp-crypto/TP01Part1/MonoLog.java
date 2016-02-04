package TP01Part1;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.Reader;
import java.io.Writer;

public class MonoLog {

	public static void main(String[] args) {
		InputStream is = System.in;
		Reader r = new InputStreamReader(is);
		Writer w;

		int x;
				
		try {
			
			w = new FileWriter("Monolog.log");
			
			while ((x=r.read())!=-1) {
					System.out.write(x);
					if (x == 'z')
						break;
					w.write(x);
			}
			is.close();
			w.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}