import java.util.Scanner;

class string_functions {
    boolean is_equal(String s1, String s2) {
        if (s1 == null && s2 == null) {
            return true;
        }

        if (s1 == null || s2 == null) {
            return false;
        }

        if (s1.length() != s2.length()) {
            return false;
        }

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    String reverse_string(String s1) {
        String s2 = "";
        for (int i = (s1.length() - 1); i >= 0; i--) {
            s2 += s1.charAt(i);
        }
        return s2;
    }

    String change_string_case(String s1, int ch) {
        String s2 = "";
        if (ch == 1) {
            for (int i = 0; i <= (s1.length() - 1); i++) {
                if (Character.isUpperCase(s1.charAt(i))) {
                    s2 += Character.toLowerCase(s1.charAt(i));
                } else {
                    s2 += s1.charAt(i);
                }
            }
        } else if (ch == 2) {
            for (int i = 0; i <= (s1.length() - 1); i++) {
                if (Character.isLowerCase(s1.charAt(i))) {
                    s2 += Character.toUpperCase(s1.charAt(i));
                } else {
                    s2 += s1.charAt(i);
                }
            }
        } else if (ch == 3) {
            for (int i = 0; i <= (s1.length() - 1); i++) {
                if (Character.isUpperCase(s1.charAt(i))) {
                    s2 += Character.toLowerCase(s1.charAt(i));
                } else if (Character.isLowerCase(s1.charAt(i))) {
                    s2 += Character.toUpperCase(s1.charAt(i));
                } else {
                    s2 += s1.charAt(i);
                }
            }
        }
        return s2;
    }

    String trim(String s1) {
        int start = 0, end = s1.length() - 1;
        while (start <= end && Character.isWhitespace(s1.charAt(start))) {
            start++;
        }
        while (end >= start && Character.isWhitespace(s1.charAt(end))) {
            end--;
        }
        return s1.substring(start, end + 1);
    }
}

public class string {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        string_functions string = new string_functions();

        System.out.print("Q4: Comparison\n    Enter first string to compare: ");
        String s1 = s.nextLine();
        System.out.print("    Enter second string to compare: ");
        String s2 = s.nextLine();
        if (string.is_equal(s1, s2)) {
            System.out.println("    '" + s1 + "' is equal to '" + s2 + "'");
        } else {
            System.out.println("    '" + s1 + "' is not equal to '" + s2 + "'");
        }

        System.out.print("\n    Reverse String\n    Enter string to reverse: ");
        String s3 = s.nextLine();
        System.out.println("    Reversed string: " + string.reverse_string(s3));

        System.out.print(
                "\n    Convert Case\n    Which case would you like to convert the string (1-Lowercase, 2-Uppercase, 3-Toggle): ");
        int ch = s.nextInt();
        s.nextLine();
        System.out.print("    Enter string: ");
        String s4 = s.nextLine();
        System.out.println("    Converted string: " + string.change_string_case(s4, ch));

        System.out.print("\n    Trimming\n    Enter string to trim: ");
        String s5 = s.nextLine();
        System.out.println("    Converted string: " + string.trim(s5));
    }
}
