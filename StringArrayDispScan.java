/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Scanner; 
public class StringArrayDispScan
{
	public static void main(String[] args) {
	
		
		String[] array = new String[5];
		Scanner sc = new Scanner(System.in);
	
		for (int i=0;i<array.length;i++)
		{
		    System.out.println("enter String");
		    array[i] = sc.nextLine();
		    
		}
		for (int i=0;i<array.length;i++)
		{
		   
		    System.out.println("element at index"+i+":"+array[i]);
		}
	}
}


