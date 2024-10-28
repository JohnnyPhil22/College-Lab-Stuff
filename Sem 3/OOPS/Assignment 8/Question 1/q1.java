// Convert integer decimal number to binary number. You are required to take input from a given input file and store results in output file.
import java.io.*;
import java.util.Scanner;

public class q1 {
	public static void main(String[] args) {
		File inp = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 1\\input.txt");
		File out = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 1\\output.txt");
		try {
			Scanner input = new Scanner(inp);
			FileWriter output = new FileWriter(out);
			for (int i = 0; i < 5; i++) {
				int num = input.nextInt();
				String bin = Integer.toBinaryString(num);
				output.write(bin + "\n");
				System.out.println(num + " in binary: " + bin);
			}
			output.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.toString());
		} catch (IOException e) {
			System.out.println(e.toString());
		}
		System.out.println("Appended all binary numbers to output file");
	}
}