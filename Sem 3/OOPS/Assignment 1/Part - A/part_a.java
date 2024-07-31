import java.util.Scanner;

public class part_a {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Q1: Write hello world
        System.out.println("Q1: Hello world");

        // Q2: Print integers
        System.out.print("Q2: Enter the integer: ");
        int num1 = s.nextInt();
        System.out.println("    Entered number: " + num1);

        // Q3: Compute area of circle
        System.out.print("Q3: Enter radius of circle: ");
        float rad = s.nextFloat();
        System.out.printf("    Area of circle: %.2f\n", (3.14 * (Math.pow(rad, 2))));

        // Q4: Odd or Even
        System.out.print("Q4: Enter number: ");
        int num2 = s.nextInt();
        if (num2 % 2 == 0) {
            System.out.println("    " + num2 + " is even");
        } else {
            System.out.println("    " + num2 + " is odd");
        }

        // Q5: Prime number or not
        System.out.print("Q5: Enter number: ");
        int num3 = s.nextInt();
        boolean isPrime = true;
        for (int i = 2; i < num3; i++) {
            if (num3 % i == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            System.out.println("    " + num3 + " is prime");
        } else {
            System.out.println("    " + num3 + " is not prime");
        }

        // Q6: Fibonacci Series
        System.out.print("Q6: Enter number of terms in series: ");
        int terms = s.nextInt(), term1 = 0, term2 = 1;
        if (terms == 1) {
            System.out.println("    Fibonacci Series: " + term1);
        } else if (terms == 2) {
            System.out.println("    Fibonacci Series: " + term1 + " " + term2 + " ");
        } else {
            System.out.print("    Fibonacci Series: " + term1 + " " + term2 + " ");
            for (int i = 2; i < terms; i++) {
                int term3 = term1 + term2;
                System.out.print(term3 + " ");
                term1 = term2;
                term2 = term3;
            }
            System.out.println();
        }

        // Q7: Check if Armstrong Number
        System.out.print("Q7: Enter number: ");
        int num4 = s.nextInt(), sum = 0, temp = num4;
        while (temp > 0) {
            int digit = temp % 10;
            sum += Math.pow(digit, 3);
            temp /= 10;
        }
        if (sum == num4) {
            System.out.println("    " + num4 + " is an Armstrong Number");
        } else {
            System.out.println("    " + num4 + " is not an Armstrong Number");
        }
    }
}