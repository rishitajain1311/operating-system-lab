/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.Arrays;
import java.util.Scanner; 
public class SortStringArrayDispScan
{
	public static void main(String[] args) {
	
		
		String[] a = new String[5];
		Scanner sc = new Scanner(System.in);
	
		for (int i=0;i<a.length;i++)
		{
		    System.out.println("enter string");
		    a[i] = sc.nextLine();
		    
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


