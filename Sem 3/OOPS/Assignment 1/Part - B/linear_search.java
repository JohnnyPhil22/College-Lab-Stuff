import java.util.Scanner;

// Q6: Linear Search

public class linear_search {
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
        int elem = s.nextInt();
        boolean flag = false;
        for (int i = 0; i < size; i++) {
            if (elem == arr[i]) {
                System.out.println(elem + " is present in array at position " + (i + 1));
                flag = true;
            }
        }
        if (!flag) {
            System.out.println(elem + " is not present in array");
        }
    }
}
