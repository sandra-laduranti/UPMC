public class Multiple{
    public static String transf(int n){
	if ((n % 5 == 0) && (n % 7 == 0))
	    return "fizzbuzz";
	if (n % 5 == 0)
	    return "fizz";
	if (n % 7 == 0)
	    return "buzz";
	return " "+n;
    }

    public static void main(String[] args){
	for (int i = 1; i <= 100; i++)
	    System.out.println(transf(i));
    }
}