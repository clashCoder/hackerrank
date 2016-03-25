import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {    

      public static void print(int A[],int i){
          try{
                System.out.println(A[i]);
            }
//------------------------code written was only betwen hyphens-----------------------------
	//Write your code here
         finally {
             Arrays.sort(A);
             int aLength = A.length;
             System.out.print(A[aLength - 1] + " " + A[0]);
             
             if ( (i >= aLength) || (i < 0) ) {
                 System.out.print("\n");
                 throw new ArrayIndexOutOfBoundsException("");
             }
          }
}
//------------------------------------------------------------------------------------------


public static void main(String[] args) {
        int N;
        Scanner st=new Scanner(System.in);
        N=st.nextInt();
        int A[]=new int[N];
        for(int i=0;i<N;i++)
        {
           A[i]=st.nextInt();
        }
        int i=st.nextInt();
        try
        {
            print(A,i);

        }
        catch(Exception e){
            System.out.println(e.getClass().getName());
        }
        
   }// end of main
}// end of Solution