import java.io.*;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.util.*;

public class assignment_2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        // Q1: Average, sum, min, max of n numbers
        System.out.print("Q1: How many numbers?: ");
        int n = s.nextInt(), sum_numb = 0;
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("    Enter number " + (i + 1) + ": ");
            numbers[i] = s.nextInt();
            sum_numb += numbers[i];
        }
        float avg_num = (sum_numb / n);
        Arrays.sort(numbers);
        int min_num = numbers[0], max_num = numbers[n - 1];
        System.out.println(
                "\n    Sum of numbers: " + sum_numb + "\n    Average of numbers: " + String.format("%.2f", avg_num)
                        + "\n    Minimum of numbers: " + min_num + "\n    Maximum of numbers: " + max_num);

        // Q2: Calculate Simple Interest
        System.out.print("Q2: Enter principal, rate and time: ");
        int principal = s.nextInt(), rate = s.nextInt(), time = s.nextInt();
        s.nextLine();
        float si = (principal * rate * time) / 100;
        System.out.println("    Simple interest: " + String.format("%.2f", si));

        // Q5: Display details after input
        System.out.print("Q5: Enter your name: ");
        String name = s.nextLine();
        System.out.print("    Enter your father's name: ");
        String father_name = s.nextLine();
        System.out.print("    Enter your date of birth: ");
        String dobInput = s.nextLine();
        DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        LocalDate dob = LocalDate.parse(dobInput, dateFormatter), today = LocalDate.now();
        Period age = Period.between(dob, today);
        System.out.println("\n    Details\n    Name: " + name + "\n    Father's Name: " + father_name
                + "\n    Date of Birth: " + dob + "\n    Age: " + age.getYears() + " years, " + age.getMonths()
                + " months, " + age.getDays() + " days");

        // Q6: Q5 but using buffer class (buffered Reader)
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Q6: Enter your name: ");
            name = reader.readLine();
            System.out.print("    Enter your father's name: ");
            father_name = reader.readLine();
            System.out.print("    Enter your date of birth: ");
            dobInput = reader.readLine();
            dob = LocalDate.parse(dobInput, dateFormatter);
            age = Period.between(dob, today);
            System.out.println("\n    Details\n    Name: " + name + "\n    Father's Name: " + father_name
                    + "\n    Date of Birth: " + dob + "\n    Age: " + age.getYears() + " years, " + age.getMonths()
                    + " months, " + age.getDays() + " days");
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        }

        // Q7: Perimeter of rectangle
        System.out.print("Q7: Enter length and breadth of rectangle: ");
        float length = s.nextFloat();
        double breadth = s.nextDouble();
        s.nextLine();
        double perimeter = 2 * (((int) length) + ((int) breadth));
        System.out.println(
                "    Perimeter of rectangle of length " + length + " and breadth " + breadth + ": " + perimeter);

        // Q8: Check if five integers are prime numbers
        System.out.print("Q8: Enter five integers: ");
        int[] nums = new int[5];
        for (int i = 0; i < 5; i++) {
            nums[i] = s.nextInt();
        }
        s.nextLine();
        ArrayList<Integer> primes = new ArrayList<>(), notprimes = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            boolean isPrime = true;
            for (int j = 2; j <= nums[i] / 2; ++j) {
                if (nums[i] % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.add(nums[i]);
            } else {
                notprimes.add(nums[i]);
            }
        }
        System.out.print("    Prime numbers: ");
        for (int i = 0; i < primes.size(); i++) {
            System.out.print(primes.get(i) + " ");
        }
        System.out.print("\n    Not prime numbers: ");
        for (int i = 0; i < notprimes.size(); i++) {
            System.out.print(notprimes.get(i) + " ");
        }

        // Q9: Q8 but compute GCD and LCM without using Arrays
        System.out.print("\nQ9: Enter five integers: ");
        int num1 = s.nextInt(), num2 = s.nextInt(), num3 = s.nextInt(), num4 = s.nextInt(), num5 = s.nextInt();
        System.out.println("    GCD of " + num1 + ", " + num2 + ", " + num3 + ", " + num4 + ", " + num5 + ": "
                + gcd(num1, num2, num3, num4, num5));
        System.out.println("    LCM of " + num1 + ", " + num2 + ", " + num3 + ", " + num4 + ", " + num5 + ": "
                + lcm(num1, num2, num3, num4, num5));
    }

    // Functions used in Q9
    public static int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static int gcd(int a, int b, int c, int d, int e) {
        return computeGCD(computeGCD(computeGCD(computeGCD(a, b), c), d), e);
    }

    public static int computeLCM(int a, int b) {
        return a * (b / computeGCD(a, b));
    }

    public static int lcm(int a, int b, int c, int d, int e) {
        return computeLCM(computeLCM(computeLCM(computeLCM(a, b), c), d), e);
    }
}
