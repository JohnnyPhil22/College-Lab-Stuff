// Write a program that decrypts the file produced by the program in previous question. The decryption program should read the contents of the coded file, restore the data to its original state, and write it to another file.
import java.io.*;
import java.util.*;

public class q9 {
	public static void main(String[] args) {
		File inp = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 9\\enc.rst");
		File out = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 9\\notEnc.rst");
		try {
			Scanner input = new Scanner(inp);
			FileWriter output = new FileWriter(out);

			String[] words = input.nextLine().split("\\s+");

			for (String word : words) {
				for (int i = 0; i < word.length(); i++) {
					char inpLet = word.charAt(i);
					if (Character.isLowerCase(inpLet)) {
						int ascii = (int) inpLet;
						ascii = ((ascii - 'a' - 10 + 26) % 26) + 'a';
						char outLet = (char) ascii;
						output.write(outLet);
					} else if (Character.isUpperCase(inpLet)) {
						int ascii = (int) inpLet;
						ascii = ((ascii - 'A' - 10 + 26) % 26) + 'A';
						char outLet = (char) ascii;
						output.write(outLet);
					} else {
						output.write(inpLet);
					}
				}
				output.write(' ');
			}

			output.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.toString());
		} catch (IOException e) {
			System.out.println(e.toString());
		}
		System.out.println("Decrypted the file");
	}
}