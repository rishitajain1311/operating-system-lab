/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Arrays;
import java.util.Scanner; 
public class SortArrayDispScan
{
	public static void main(String[] args) {
	
		
		int[] a = new int[5];
		Scanner sc = new Scanner(System.in);
	
		for (int i=0;i<a.length;i++)
		{
		    System.out.println("enter integer");
		    a[i] = sc.nextInt();
		    
		}
		System.out.println("original array is:");
		for (int i=0;i<a.length;i++)
		{
		   
		    System.out.println("element at index"+i+":"+a[i]);
		}
		Arrays.sort(a);
			System.out.println("Sorted array is:");
			for (int i=0;i<a.length;i++)
		{
		   
		    System.out.println("element at index"+i+":"+a[i]);
		}
	}
}


