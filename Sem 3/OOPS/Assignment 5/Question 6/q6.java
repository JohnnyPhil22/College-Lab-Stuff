// Q6: Convert paragraph containing continuous alphabets into fixed size tokens then remove duplicates and sort
import java.util.*;

public class q6 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter paragraph: ");
        String paragraph = s.nextLine();

        int tokenSize = 5;

        List<String> sortedUniqueTokens = new ArrayList<>();

        for (int i = 0; i <= paragraph.length() - tokenSize; i++) {
            String token = paragraph.substring(i, i + tokenSize);
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