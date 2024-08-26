// Q3: Correlation factor
public class q3 {
    public static void main(String[] args) {
        int[] arr1 = { 1, 2, 3, 4 };
        int[] arr2 = { 2, 4, 1, 5 };
        int match = 0, count = arr1.length - 1;

        if (arr1.length != arr2.length) {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }

        for (int i = 0; i < count; i++) {
            if ((Integer.compare(arr1[i + 1], arr1[i])) == (Integer.compare(arr2[i + 1], arr2[i]))) {
                match++;
            }
        }

        System.out.print("Array 1: ");
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr1[i] + " ");
        }

        System.out.print("\nArray 2: ");
        for (int i = 0; i < arr2.length; i++) {
            System.out.print(arr2[i] + " ");
        }

        double corr_fac = (double) match / count;
        System.out.printf("\nCorrelation factor of arrays 1 and 2: %.3f", corr_fac);
    }
}