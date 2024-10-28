// Write an exception class named InvalidTestScore. Modify the TestScores class so that it throws an InvalidTestScore exception if any of the test scores in the array are invalid.
import java.util.*;

class InvalidTestScore extends Exception {
    public InvalidTestScore(String message) {
        super(message);
    }
}

class TestScores {
    int[] scores;

    TestScores(int[] scores) {
        this.scores = scores;
    }

    double returnAvg() throws InvalidTestScore {
        int sum = 0;
        double avg = 0.0;
        for (int score : scores) {
            if (score < 0) {
                throw new InvalidTestScore("Score cannot be less than 0");
            } else if (score > 100) {
                throw new InvalidTestScore("Score cannot be greater than 100");
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

public class q5 {
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
        try {
            System.out.println("Average of all test scores: " + avgScore.returnAvg());
        } catch (InvalidTestScore e) {
            System.out.println(e.toString());
        }
    }
}