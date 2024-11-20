// Q5: Create Pyramid and Pattern
import java.util.Scanner;

public class pyramids_and_patterns {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Half - pyramid using stars
        System.out.print("Half - pyramid using stars\nEnter number of rows: ");
        int rows = s.nextInt(), i;
        for (i = 1; i <= rows; i++) { // For inverted half-pyramid, (i = rows; i >= 1; i--)
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }

        // Half - pyramid using numbers
        System.out.print("\nHalf - pyramid using numbers\nEnter number of rows: ");
        rows = s.nextInt();
        for (i = 1; i <= rows; i++) { // For inverted half-pyramid, (i = rows; i >= 1; i--)
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }

        // Half - pyramid using alphabets
        System.out.print("\nHalf - pyramid using alphabets\nEnter number of rows: ");
        rows = s.nextInt();
        char start = 65, ending = (char) (65 + rows - 1);
        for (i = 1; i <= (ending - 'A' + 1); i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(start + " ");
            }
            start++;
            System.out.println();
        }

        // Inverted Half - Pyramid using Alphabets
        System.out.print("\nInverted Half - pyramid using alphabets\nEnter number of rows: ");
        rows = s.nextInt();
        start = 65;
        for (i = rows; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print(start + " ");
            }
            start++;
            System.out.println();
        }

        // Full pyramid using star
        System.out.print("\nFull pyramid using star\nEnter number of rows: ");
        rows = s.nextInt();
        int k = 0;
        for (i = 1; i <= rows; i++, k = 0) {
            for (int j = 1; j <= rows - i; j++) {
                System.out.print("  ");
            }
            while (k != 2 * i - 1) {
                System.out.print("* ");
                ++k;
            }
            System.out.println();
        }

        // Inverted full pyramid using star
        System.out.print("\nInverted Full pyramid using star\nEnter number of rows: ");
        rows = s.nextInt();
        for (i = rows; i >= 1; i--) {
            for (int j = 1; j <= rows - i; j++) {
                System.out.print("  ");
            }
            for (int j = i; j <= 2 * i - 1; ++j) {
                System.out.print("* ");
            }
            for (int j = 0; j < i - 1; ++j) {
                System.out.print("* ");
            }
            System.out.println();
        }

        // Full pyramid using numbers
        System.out.print("\nFull pyramid using numbers\nEnter number of rows: ");
        rows = s.nextInt();
        k = 0;
        int count = 0, count1 = 0;
        for (i = 1; i <= rows; i++) {
            for (int j = 1; j <= rows - i; j++) {
                System.out.print("  ");
                count++;
            }
            while (k != 2 * i - 1) {
                if (count <= rows - 1) {
                    System.out.print((i + k) + " ");
                    count++;
                } else {
                    count1++;
                    System.out.print((i + k - 2 * count1) + " ");
                }
                k++;
            }
            count1 = count = k = 0;
            System.out.println();
        }

        // Pascal's triangle
        System.out.print("\nPascal's Triangle\nEnter number of rows: ");
        rows = s.nextInt();
        int coef = 1;
        for (i = 0; i < rows; i++) {
            for (int j = 1; j < rows - i; j++) {
                System.out.print("  ");
            }
            for (int j = 0; j <= i; j++) {
                if (j == 0 || i == 0) {
                    coef = 1;
                } else {
                    coef = coef * (i - j + 1) / j;
                }
                System.out.printf("%4d", coef);
            }
            System.out.println();
        }

        // Floyd's Triangle
        System.out.print("\nFloyd's Triangle\nEnter number of rows: ");
        rows = s.nextInt();
        int number = 1;
        for (i = 1; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(number + " ");
                number++;
            }
            System.out.println();
        }
    }
}