/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
public class ArrayDisp
{
	public static void main(String[] args) {
	
		
		int[] array=new int[5];
		
		array[0]=10;
		array[1]=2;
		array[2]=19;
		array[3]=22;
		array[4]=80;
		for (int i=0;i<array.length;i++)
		{
		    System.out.println("element at index"+i+":"+array[i]);
		}
		
	}
}


