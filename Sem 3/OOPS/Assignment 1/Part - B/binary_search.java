import java.util.Scanner;

// Q7: Binary Search

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

        System.out.print("Enter element to search: ");
        int elem = s.nextInt(), l = 0, r = size - 1;
        boolean flag = false;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (elem == arr[mid]) {
                System.out.println(elem + " is present in array at position " + (mid + 1));
                flag = true;
                break;
            } else if (arr[mid] > elem) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (!flag) {
            System.out.println(elem + " is not present in array");
        }
    }
}
