// Q4: Employee records
import java.util.Scanner;

class Payroll {
	private String name;
	private int id, hours_worked;
	private float rate_hour;

	// Return all fields
	Payroll(String name, int id, float rate_hour, int hours_worked) {
		this.name = name;
		this.id = id;
		this.rate_hour = rate_hour;
		this.hours_worked = hours_worked;
	}

	// Return only name and ID
	Payroll(String name, int id) {
		this(name, id, 0, 0);
	}

	// Mutator methods
	public void setName(String name) {
		this.name = name;
	}

	public void setID(int id) {
		this.id = id;
	}

	public void setRate(float rate_hour) {
		this.rate_hour = rate_hour;
	}

	public void setHours(int hours_worked) {
		this.hours_worked = hours_worked;
	}

	// Acceptor methods
	public String getName() {
		return name;
	}

	public int getID() {
		return id;
	}

	public float getRate() {
		return rate_hour;
	}

	public int getHours() {
		return hours_worked;
	}

	// Print method
	public String print_deets() {
		return ("Name: " + name + "\nID: " + id + "\nHourly Pay Rate: " + rate_hour + "\nNumber of Hours Worked: "
				+ hours_worked);
	}

	// Returns Gross Pay
	public float gross_pay() {
		return (rate_hour * hours_worked);
	}
}

public class q4 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		String name;
		int id, hours_worked;
		float rate_hour;

		System.out.print("Enter Employee Name: ");
		name = s.nextLine();
		System.out.print("Enter Employee ID: ");
		id = s.nextInt();
		System.out.print("Enter Hourly Pay Rate: ");
		rate_hour = s.nextFloat();
		System.out.print("Enter Number of Hours Worked: ");
		hours_worked = s.nextInt();
		s.nextLine();

		Payroll emp1 = new Payroll(name, id, rate_hour, hours_worked);

		System.out.println("\nEmployee Details:\n" + emp1.print_deets());
		System.out.println("Gross Pay: " + emp1.gross_pay());
	}
}