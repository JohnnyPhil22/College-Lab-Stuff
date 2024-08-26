// Q2: Merge jagged array and its transpose
import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of rows in the jagged array: ");
        int rows = s.nextInt();
        int[][] jaggedArray = new int[rows][];
        for (int i = 0; i < rows; i++) {
            System.out.print("Enter the number of columns in row " + (i + 1) + ": ");
            int cols = s.nextInt();
            jaggedArray[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                System.out.print("Enter element for row " + (i + 1) + " column " + (j + 1) + ": ");
                jaggedArray[i][j] = s.nextInt();
            }
        }

        int maxCols = 0;
        for (int i = 0; i < jaggedArray.length; i++) {
            maxCols = Math.max(maxCols, jaggedArray[i].length);
        }

        int[][] transposedArray = new int[maxCols][];
        for (int i = 0; i < maxCols; i++) {
            int count = 0;
            for (int j = 0; j < jaggedArray.length; j++) {
                if (i < jaggedArray[j].length) {
                    count++;
                }
            }

            transposedArray[i] = new int[count];

            int index = 0;
            for (int j = 0; j < jaggedArray.length; j++) {
                if (i < jaggedArray[j].length) {
                    transposedArray[i][index++] = jaggedArray[j][i];
                }
            }
        }

        int rows_new = Math.max(jaggedArray.length, transposedArray.length);
        int[][] mergedArray = new int[rows_new][];

        for (int i = 0; i < rows; i++) {
            int[] row1 = i < jaggedArray.length ? jaggedArray[i] : new int[0];
            int[] row2 = i < transposedArray.length ? transposedArray[i] : new int[0];
            mergedArray[i] = new int[row1.length + row2.length];

            System.arraycopy(row1, 0, mergedArray[i], 0, row1.length);

            System.arraycopy(row2, 0, mergedArray[i], row1.length, row2.length);
        }

        System.out.println("\nOriginal Jagged Array:");
        for (int[] row : jaggedArray) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }

        System.out.println("\nTransposed Jagged Array:");
        for (int[] row : transposedArray) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }

        System.out.println("\nMerged Jagged Array:");
        for (int[] row : mergedArray) {
            for (int element : row) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }
}