// You are required to read a given paragraph consisting of words from input file and convert this paragraph to tokens to be stored in array of string in sorted order where sorted array does not have duplicate words. Finally array of string to be stored in output file.
import java.io.*;
import java.util.*;

public class q2 {
	public static void main(String[] args) {
		File inp = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 2\\input.txt");
		File out = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 2\\output.txt");
		try {
			Scanner input = new Scanner(inp);
			FileWriter output = new FileWriter(out);

			String[] words = input.nextLine().toLowerCase().split("\\s+");
			Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));
			List<String> sorted = new ArrayList<>(uniqueWords);
			Collections.sort(sorted);

			for (String word : sorted) {
				output.write(word + " ");
			}

			output.close();
		} catch (FileNotFoundException e) {
			System.out.println(e.toString());
		} catch (IOException e) {
			System.out.println(e.toString());
		}
		System.out.println("Appended all unique words to output file");
	}
}