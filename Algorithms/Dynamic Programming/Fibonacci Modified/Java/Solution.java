import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*  Input:
 *      A -> integer representing first term of series
 *      B -> integer representing second term of series
 *      N -> nth term of series
 *  Constraints:
 *      0 <= A , B <= 2, 3 <= N <= 20
 *  Output:
 *      Compute the nth term of the series : Tn+2 = (Tn+1)^2 + Tn , given the first two terms of the series.
 */

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        
        BigInteger a = sc.nextBigInteger();
        BigInteger b = sc.nextBigInteger();
        int n = sc.nextInt();
        
        ArrayList<BigInteger> fib = new ArrayList<BigInteger>(n);
        
        fib.add(0,a);
        fib.add(1,b);
        
        for (int i = 2; i < n; i++) {
            BigInteger prev_prev_val = fib.get(i-2);
            BigInteger prev = fib.get(i-1);
            BigInteger prev_val = prev.multiply(prev);
            BigInteger next = prev_val.add(prev_prev_val);
            
            
            //System.out.println(next);
            fib.add(i,next);
        }
        
        System.out.println(fib.get(n-1));
    }
}