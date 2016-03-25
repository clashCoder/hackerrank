import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*  Input:
 *      L -> list of integers
 *      N -> number of integers in L
 *      N integers that are in L
 *      Q -> number of queries
 *          for each query:
 *          Insert x y          OR      Delete x    , for insert value y inserted into position x and
 *                                                    for delete, value at position x must be deleted
 *  Constraint:
 *      1 <= N <= 4000
 *      1 <= Q <= 4000
 *      Each integer is a 32-bit integer
 *  Output:
 *      print the updated list after all queries have been done.
 */

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        
        ArrayList<Integer> L = new ArrayList<Integer>();
        
        for (int i = 0; i < N; i++) { 
            int Li = sc.nextInt();
            L.add(Li);
        }
        
       /* for(int value: L) {
            System.out.print(value);
            System.out.print(" ");
        }*/
        //System.out.println(L);
        
        int Q = sc.nextInt();
        sc.nextLine();
        
        for (int i = 0; i < Q; i++) {
            String query = sc.nextLine();
            query = query.replaceAll("[^a-zA-Z]","").toLowerCase();
            //System.out.println(query);
            
            int index = sc.nextInt();
            
            if (query.equals("insert")) {
                int val = sc.nextInt();
                //TODO: insert operation
                
                if (index >= 0 && index < L.size()) {
                    L.add(index, val);
                }
                
                if (index == L.size()) {
                    L.add(val);
                }
                /*if (index < 0) {
                    L.add(0, val);
                }
                else if (index >= N) {
                    L.add(val);
                }
                else {
                    L.add(index, val);
                }*/
                
                if(sc.hasNext()) {
                    sc.nextLine();
                }
            }
            if (query.equals("delete")) {
                //TODO: delete operation
                /*if (index >= 0 && index < N) {
                   L.remove(index);
                }*/
                
                if (index >= 0 && index < L.size()) {
                    L.remove(index);
                }
                
                if(sc.hasNext()) {
                    sc.nextLine();
                }
            }            
        }
        //System.out.println("");
        if (L.isEmpty()) {
            System.out.print("");
        }
        else {
            for (int val: L) {
                System.out.print(val);
                System.out.print(" ");
            }            
        }
    }
}
