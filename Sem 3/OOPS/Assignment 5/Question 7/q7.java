// Q7: Convert paragraph containing continuous alphabets into tokens based on char occurrence then remove duplicates and sort
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class q7 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter paragraph: ");
        String paragraph = s.nextLine();

        List<String> sortedUniqueTokens = new ArrayList<>();

        StringBuilder currentToken = new StringBuilder();

        for (int i = 0; i < paragraph.length(); i++) {
            char currentChar = paragraph.charAt(i);
            if (i == 0 || paragraph.charAt(i) == paragraph.charAt(i - 1)) {
                currentToken.append(currentChar);
            } else {
                if (currentToken.length() > 0) {
                    String token = currentToken.toString();
                    if (!sortedUniqueTokens.contains(token)) {
                        sortedUniqueTokens.add(token);
                    }
                    currentToken = new StringBuilder();
                }
                currentToken.append(currentChar);
            }
        }

        if (currentToken.length() > 0) {
            String token = currentToken.toString();
            if (!sortedUniqueTokens.contains(token)) {
                sortedUniqueTokens.add(token);
            }
        }

        Collections.sort(sortedUniqueTokens);

        System.out.println("Unique tokens in paragraph after sorting:");
        for (String token : sortedUniqueTokens) {
            System.out.print(token + " ");
        }
    }
}