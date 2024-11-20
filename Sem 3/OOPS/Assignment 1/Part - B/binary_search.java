// Q7: Binary Search
import java.util.*;

public class binary_search {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int size = s.nextInt();
        int[] arr = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            arr[i] = s.nextInt();
        }

        Arrays.sort(arr);

        System.out.print("Enter element to search: ");
        int elem = s.nextInt(), result = binarySearch(arr, elem);
        if (result == -1) {
            System.out.println(elem + " is not present in array");
        } else {
            System.out.println(elem + " is present in array at position " + (result + 1));
        }

        System.out.print("Array: ");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static int binarySearch(int[] arr, int elem) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == elem) {
                return mid;
            } else if (arr[mid] > elem) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1; // Element not found
    }
}
