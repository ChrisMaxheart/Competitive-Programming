import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.math.BigInteger;

class BigInteger2 {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    while(true) {
      String N = br.readLine();
      if(N == null) break;
      BigInteger BN = new BigInteger(N);
      BigInteger BRN = new BigInteger(
        new StringBuffer(BN.toString()).reverse().toString());
      pw.printf("%s is ", N);
      if(!BN.isProbablePrime(10)) // 10 is enough
        pw.printf("not prime.\n";
      else if (!BN.equals(BRN) && BRN.isProbablePrime(10))
        pw.printf("emirp.\n")
      else
        pw.printf("prime.\n")
    }
    pw.close();
  }
}

import java.util.Scanner; // Scanner class is inside package java.util
import java.math.BigInteger; // BigInteger class is inside package java.math

class Main { /* UVa 10925 - Krakovia, 0.732s in Java */
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int caseNo = 1;
    while (true) {
      int N = sc.nextInt(), F = sc.nextInt(); // N bills, F friends
      if (N == 0 && F == 0) break;
      BigInteger sum = BigInteger.ZERO; // BigInteger has this constant ZERO
      for (int i = 0; i < N; i++) { // sum the N large bills
        BigInteger V = sc.nextBigInteger(); // for reading next BigInteger!
        sum = sum.add(V); // this is BigInteger addition
      }
      System.out.println("Bill #" + (caseNo++) + " costs " +
        sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(F)));
      System.out.println(); // the line above is BigInteger division
} } }                       // divide the large sum to F friends
