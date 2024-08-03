import java.util.Scanner;

public class part_b {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Q1: Check if palindrome
        int num1, rev = 0;
        System.out.print("Q1: Enter a number: ");
        num1 = s.nextInt();
        int temp = num1;
        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp = Math.floorDiv(temp, 10);
        }
        if (num1 == rev) {
            System.out.println("    " + num1 + " is a palindrome");
        } else {
            System.out.println("    " + num1 + " is not a palindrome");
        }

        // Q2: Display factors of number
        System.out.print("Q2: Enter a number: ");
        int num2 = s.nextInt();
        System.out.print("    Factors of " + num2 + ": ");
        for (int i = 1; i <= num2; i++) {
            if (num2 % i == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();

        // Q3: Count number of digits
        System.out.print("Q3: Enter a number: ");
        int num3 = s.nextInt(), count = 0;
        temp = num3;
        while (temp > 0) {
            temp = Math.floorDiv(temp, 10);
            count++;
        }
        System.out.println("    " + num3 + " has " + count + " digits");

        // Q4: Find GCD of Two Numbers
        System.out.print("Q4: Enter two numbers: ");
        int num4 = s.nextInt(), num5 = s.nextInt(), gcd = 1, smaller;
        if (num4 < num5) {
            smaller = num4;
        } else {
            smaller = num5;
        }
        for (int i = smaller; i > 1; i--) {
            if (num4 % i == 0 && num5 % i == 0) {
                gcd = i;
                break;
            }
        }
        System.out.println("    GCD of " + num4 + " and " + num5 + " is " + gcd);

        // Q9: Prime numbers between two intervals
        System.out.print("Q9: Enter two numbers: ");
        int ll = s.nextInt(), ul = s.nextInt();
        System.out.print("    Prime numbers between " + ll + " and " + ul + " are: ");
        for (int i = (ll + 1); i <= ul; i++) {
            boolean isPrime = true;
            if (i <= 1) {
                isPrime = false;
            } else {
                for (int j = 2; j < i; j++) {
                    if (i % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
            }
            if (isPrime) {
                System.out.print(i + " ");
            }
        }
        System.out.println();

        // Q10: Check if number can be expressed as sum of two prime numbers
        System.out.print("Q10: Enter a number: ");
        int num6 = s.nextInt();
        boolean flag = false;
        for (int i = 2; i <= num6 / 2; ++i) {
            if (checkPrime(i) & checkPrime(num6 - i)) {
                System.out.printf("     %d = %d + %d\n", num6, i, num6 - i);
                flag = true;
            }
        }
        if (!flag) {
            System.out.println("     " + num6 + " cannot be expressed as the sum of two prime numbers");
        } else {
            System.out.println("     Hence, " + num6 + " can be expressed as the sum of two prime numbers");
        }

        // Q11: Q9 but using function
        System.out.print("Q11: Enter two numbers: ");
        int lowlim = s.nextInt(), uplim = s.nextInt();
        System.out.print("     Prime numbers between " + lowlim + " and " + uplim + " are: ");
        primeNumsBetween(lowlim, uplim);
    }

    // Function used in Q10
    static boolean checkPrime(int num) {
        boolean isPrime = true;
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }

    // Function used in Q11
    static void primeNumsBetween(int lowlim, int uplim) {
        for (int i = (lowlim + 1); i <= uplim; i++) {
            boolean isPrime = true;
            if (i <= 1) {
                isPrime = false;
            } else {
                for (int j = 2; j < i; j++) {
                    if (i % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
            }
            if (isPrime) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}