// Q4: Correlation matrix for 5x5 matrix
public class q4 {
    public static void main(String[] args) {
        double[][] arr1 = {
                { 3, 7, 2, 8, 5 },
                { 14, 6, 9, 12, 4 },
                { 1, 19, 7, 13, 11 },
                { 8, 22, 5, 14, 6 },
                { 10, 3, 17, 8, 20 }
        };

        int n = arr1.length;
        double[][] corr_mat = new double[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                double correlation = computeCorrelation(arr1[i], arr1[j]);
                corr_mat[i][j] = correlation;
                corr_mat[j][i] = correlation;
            }
        }

        System.out.print("Matrix:\n");
        for (double[] row : arr1) {
            for (double value : row) {
                System.out.printf("%.0f ", value);
            }
            System.out.println();
        }

        System.out.print("\nCorrelation Matrix:\n");
        for (double[] row : corr_mat) {
            for (double value : row) {
                System.out.printf("%.2f ", value);
            }
            System.out.println();
        }
    }

    public static double computeCorrelation(double[] row1, double[] row2) {
        int n = row1.length;
        double mean1 = mean(row1);
        double mean2 = mean(row2);

        double numerator = 0.0;
        double denominator1 = 0.0;
        double denominator2 = 0.0;

        for (int i = 0; i < n; i++) {
            double diff1 = row1[i] - mean1;
            double diff2 = row2[i] - mean2;
            numerator += diff1 * diff2;
            denominator1 += diff1 * diff1;
            denominator2 += diff2 * diff2;
        }

        return numerator / Math.sqrt(denominator1 * denominator2);
    }

    public static double mean(double[] row) {
        double sum = 0.0;
        for (double value : row) {
            sum += value;
        }
        return sum / row.length;
    }
}
