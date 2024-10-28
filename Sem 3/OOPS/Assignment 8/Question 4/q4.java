// Write a class named TestScores. The class constructor should accept an array of test scores as its argument. The class should have a method that returns the average of the test scores. If any test score in the array is negative or greater than 100, the class should throw an IllegalArgumentException. Demonstrate the class in a program.
import java.util.*;

class TestScores {
    int[] scores;

    TestScores(int[] scores) {
        this.scores = scores;
    }

    double returnAvg() {
        int sum = 0;
        double avg = 0.0;
        for (int score : scores) {
            if (score < 0) {
                throw new IllegalArgumentException("Score cannot be less than 0");
            } else if (score > 100) {
                throw new IllegalArgumentException("Score cannot be greater than 100");
            } else {
                sum += score;
            }
        }
        if (scores.length > 0) {
            avg = ((double) sum / scores.length);
        }
        return avg;
    }
}

public class q4 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter number of scores: ");
        int size = s.nextInt();
        s.nextLine();

        int[] scores = new int[size];
        for (int i = 0; i < size; i++) {
            System.out.print("Enter score " + (i + 1) + ": ");
            scores[i] = s.nextInt();
            s.nextLine();
        }

        TestScores avgScore = new TestScores(scores);
        System.out.println("Average of all test scores: " + avgScore.returnAvg());
    }
}