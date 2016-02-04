package filter;

import java.io.*;

public class CesarWriter extends FilterWriter{

	private int c;

	public CesarWriter(Writer w,int c){
		super(w);
		this.c = c;
	}


	@Override
	public void write(String s,int in1,int in2){
		try {
			StringBuffer sb = new StringBuffer();
			char[] y = s.toCharArray();
			for(int i=0 ; i<y.length ; i++){
				sb.append((char)encode(y[i]));
			}
			super.write(sb.toString(),in1,in2);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	public void write(String s){
		write(s, 0, s.length());
	}
	
	public int encode(int x){
		if(c>0){
			if(Character.isLetter(x)){		
				if(Character.isUpperCase(x)){
					return ('A' + ((x - 'A' + this.c) % 26) );
				}
				else {
					return ('a' + ((x - 'a' + this.c) % 26) );
				}
			}
			else{
				return x;
			}
			
		}else{
			if(Character.isLetter(x)){		
				if(Character.isUpperCase(x)){
					return ('A' + (((26+x) - 'A' + this.c) % 26) );
				}
				else {
					return ('a' + (((26+x) - 'a' + this.c) % 26) );
				}
			}
			else{
				return x;
			}
		}
	}
	
	/*public String decodeString(String x){
		
	}*/
	
	public static void main(String[] args) {
		String s = "aaaaa zzzz\nAAAA ZZZZ\n";
		char[] chars = s.toCharArray();
		System.out.println(chars);
		
		PrintWriter cswc = new PrintWriter(new CesarWriter(new OutputStreamWriter(System.out), 2),true);
		PrintWriter cswu = new PrintWriter(new CesarWriter(new OutputStreamWriter(System.out), -2),true);
		
		for(char x : chars){
			cswc.print(x);
			cswu.print(x);
		}
		
		cswc.flush();
		
		cswu.flush();
		
		System.out.println("\nwot");
		
		
	}
	
}
