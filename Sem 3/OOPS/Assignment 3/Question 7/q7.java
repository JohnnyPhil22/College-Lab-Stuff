// Q7: Number of days in month
import java.util.Scanner;

class month_days {
	private int month, year, days;
	private boolean flag = false;

	month_days(int month, int year) {
		this.month = month;
		this.year = year;
	}

	// Check if year is leap year or not
	boolean is_leap_year() {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				flag = true;
			}
		} else if (year % 4 == 0) {
			flag = true;
		}
		return flag;
	}

	// Return number of days in a month
	public int getNumberOfDays() {
		if (month == 2) {
			if (is_leap_year()) {
				days = 29;
			} else {
				days = 28;
			}
		} else {
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				days = 30;
			} else {
				days = 31;
			}
		}
		return days;
	}
}

public class q7 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.print("Enter month and year: ");
		int month = s.nextInt(), year = s.nextInt();

		month_days month_days = new month_days(month, year);

		String month_name;
		switch (month) {
			case 1:
				month_name = "January";
				break;
			case 2:
				month_name = "February";
				break;
			case 3:
				month_name = "March";
				break;
			case 4:
				month_name = "April";
				break;
			case 5:
				month_name = "May";
				break;
			case 6:
				month_name = "June";
				break;
			case 7:
				month_name = "July";
				break;
			case 8:
				month_name = "August";
				break;
			case 9:
				month_name = "September";
				break;
			case 10:
				month_name = "October";
				break;
			case 11:
				month_name = "November";
				break;
			case 12:
				month_name = "December";
				break;
			default:
				month_name = "Invalid month";
		}

		System.out.println(month_name + " " + year + " has " + month_days.getNumberOfDays() + " days");
	}
}