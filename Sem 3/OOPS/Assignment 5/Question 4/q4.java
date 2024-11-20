// Q4: Sort string array of length 10 in ascending order
import java.util.*;

public class q4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String[] arr = new String[10];

        for (int i = 0; i < 10; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            arr[i] = s.nextLine();
        }

        System.out.println("\nOriginal array: ");
        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }

        Arrays.sort(arr, String.CASE_INSENSITIVE_ORDER);

        System.out.println("\n\nArray after sorting in ascending order: ");
        for (int i = 0; i < 10; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}