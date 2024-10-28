// File encryption is the science of writing the contents of a file in a secret code. Your encryption program should work like alter, reading the contents of one file, modifying the data into a code, and then writing the coded contents out to a second file. The second file will be a version of the rst file, but written in a secret code. Although there are complex encryption techniques, you should come up with a simple one of your own. For example, you could read the rst file one character at a time, and add 10 to the character code of each character before it is written to the second file.
import java.io.*;
import java.util.*;

public class q8 {
	public static void main(String[] args) {
		File inp = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 8\\notEnc.rst");
		File out = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 8\\enc.rst");
		try {
			Scanner input = new Scanner(inp);
			FileWriter output = new FileWriter(out);

			String[] words = input.nextLine().split("\\s+");

			for (String word : words) {
				for (int i = 0; i < word.length(); i++) {
					char inpLet = word.charAt(i);
					if (Character.isLowerCase(inpLet)) {
						int ascii = (int) inpLet;
						ascii = ((ascii - 'a' + 10) % 26) + 'a';
						char outLet = (char) ascii;
						output.write(outLet);
					} else if (Character.isUpperCase(inpLet)) {
						int ascii = (int) inpLet;
						ascii = ((ascii - 'A' + 10) % 26) + 'A';
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
		System.out.println("Encrypted the file");
	}
}