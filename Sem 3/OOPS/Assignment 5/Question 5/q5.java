// Q5: Convert paragraph to tokens to store in array without duplicates then sort it
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class q5 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter paragraph: ");
        String paragraph = s.nextLine();
        String[] tokens = paragraph.split("\\s+");

        List<String> sortedUniqueTokens = new ArrayList<>();

        for (String token : tokens) {
            if (!sortedUniqueTokens.contains(token)) {
                sortedUniqueTokens.add(token);
            }
        }

        Collections.sort(sortedUniqueTokens);

        System.out.println("\nUnique tokens in paragraph after sorting:");
        for (String token : sortedUniqueTokens) {
            System.out.print(token + " ");
        }
    }
}