// Q5: Test scores
import java.util.Scanner;

class test_scores {
	private int score1, score2, score3;

	test_scores(int score1, int score2, int score3) {
		this.score1 = score1;
		this.score2 = score2;
		this.score3 = score3;
	}

	// Mutator methods
	public void setScore1(int score1) {
		this.score1 = score1;
	}

	public void setScore2(int score2) {
		this.score2 = score2;
	}

	public void setScore3(int score3) {
		this.score3 = score3;
	}

	// Acceptor methods
	public int getScore1() {
		return score1;
	}

	public int getScore2() {
		return score2;
	}

	public int getScore3() {
		return score3;
	}

	// Print method
	public String print_deets() {
		return ("Score 1: " + score1 + " | Score 2: " + score2 + " | Score 3: " + score3);
	}

	// Average method
	public double average() {
		return ((score1 + score2 + score3) / 3);
	}
}

public class q5 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.print("Enter three scores: ");
		int s1 = s.nextInt(), s2 = s.nextInt(), s3 = s.nextInt();

		test_scores test_scores = new test_scores(s1, s2, s3);

		System.out.println(test_scores.print_deets());
		System.out.println("Average of test scores: " + test_scores.average());
	}
}