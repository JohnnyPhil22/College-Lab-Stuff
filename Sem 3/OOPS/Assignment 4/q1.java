// Q1: Temperatures of items
import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String[][] substances = {
            { "Water", "0", "100" },
            { "Ethanol", "-114", "78" },
            { "Mercury", "-39", "357" },
            { "Oxygen", "-218", "-183" }
        };

        System.out.print("Enter temperature: ");
        int temp = s.nextInt();
        boolean flag = false;

        for (int i = 0; i < substances.length; i++) {
            String substance = substances[i][0];
            int freezing = Integer.parseInt(substances[i][1]), boiling = Integer.parseInt(substances[i][2]);

            if (temp == freezing) {
                System.out.println(temp + " is the freezing point of " + substance);
                flag = true;
            } else if (temp == boiling) {
                System.out.println(temp + " is the boiling point of " + substance);
                flag = true;
            }
        }

        if (!flag) {
            System.out.println(temp + " is not found in the list");
        }
    }
}