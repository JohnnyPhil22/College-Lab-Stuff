import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

// Q2: Base class Course with child classes UGCourse & PGCourse
class Course {
	protected String courseCode, courseName;
	protected int credit;

	Course(String courseCode, String courseName, int credit) {
		this.courseCode = courseCode;
		this.courseName = courseName;
		this.credit = credit;
	}

	// Mutator methods
	public void setCourseCode(String courseCode) {
		this.courseCode = courseCode;
	}

	public void setCourseName(String courseName) {
		this.courseName = courseName;
	}

	public void setCredit(int credit) {
		this.credit = credit;
	}

	// Acceptor methods
	public String getCourseCode() {
		return courseCode;
	}

	public String getCourseName() {
		return courseName;
	}

	public int getCredit() {
		return credit;
	}

	// Print course details
	public void printCourseDetails() {
		System.out
				.println("Course Code: " + courseCode + "\n\t\tCourse Name: " + courseName + "\n\t\tCourse Credit: "
						+ credit);
	}
}

class UGCourse extends Course {
	UGCourse(String courseCode, String courseName, int credit) {
		super(courseCode, courseName, credit);
		if (!courseCode.matches("UG-\\d{4}")) {
			throw new IllegalArgumentException("Invalid course code. Expected format: UG-xxxx");
		}
	}
}

class PGCourse extends Course {
	PGCourse(String courseCode, String courseName, int credit) {
		super(courseCode, courseName, credit);
		if (!courseCode.matches("PG-\\d{4}")) {
			throw new IllegalArgumentException("Invalid course code. Expected format: PG-xxxx");
		}
	}
}

// Q3: Base class Payment with child classes PaymentDD, PaymentUPI & PaymentNB
class Payment {
	protected String paymentID;
	protected LocalDate date;
	protected double amount;

	Payment(String paymentID, LocalDate date, double amount) {
		this.paymentID = paymentID;
		this.amount = amount;
		this.date = date;
	}

	// Mutator method
	public void setPaymentID(String paymentID) {
		this.paymentID = paymentID;
	}

	public void setAmount(double amount) {
		this.amount = amount;
	}

	public void setDate(LocalDate date) {
		this.date = date;
	}

	// Acceptor method
	public String getPaymentID() {
		return paymentID;
	}

	public double getAmount() {
		return amount;
	}

	public LocalDate getDate() {
		return date;
	}

	// Print payment details
	public void printPaymentDetails() {
		System.out.println("Payment ID: " + paymentID + "\n\t\t Payment Date: " + date + "\n\t\t Amount: " + amount);
	}
}

class paymentDD extends Payment {
	protected String payeeDeets, bankBranch, DDNo;

	paymentDD(String paymentID, String payeeDeets, LocalDate date, String bankBranch, double amount, String DDNo) {
		super(paymentID, date, amount);
		this.payeeDeets = payeeDeets;
		this.bankBranch = bankBranch;
		this.DDNo = DDNo;
	}

	// Mutator methods
	public void setPayeeDeets(String payeeDeets) {
		this.payeeDeets = payeeDeets;
	}

	public void setBankBranch(String bankBranch) {
		this.bankBranch = bankBranch;
	}

	public void setDDNo(String DDNo) {
		this.DDNo = DDNo;
	}

	// Acceptor methods
	public String getPayeeDeets() {
		return payeeDeets;
	}

	public String getBankBranch() {
		return bankBranch;
	}

	public String getDDNo() {
		return DDNo;
	}
}

class paymentUPI extends Payment {
	protected String upiID;

	paymentUPI(String paymentID, String upiID, LocalDate date, double amount) {
		super(paymentID, date, amount);
		this.upiID = upiID;
	}

	// Mutator methods
	public void setUpiID(String upiID) {
		this.upiID = upiID;
	}

	// Acceptor methods
	public String getUpiID() {
		return upiID;
	}
}

class paymentNB extends Payment {
	protected String fundTransferType, payeeName, IFSC, payeeBank;
	protected long accNo;

	paymentNB(String paymentID, String fundTransferType, String payeeName, long accNo, String IFSC, String payeeBank,
			LocalDate date, double amount) {
		super(paymentID, date, amount);
		this.fundTransferType = fundTransferType;
		this.payeeName = payeeName;
		this.accNo = accNo;
		this.IFSC = IFSC;
		this.payeeBank = payeeBank;
	}

	// Mutator methods
	public void setFundTransferType(String fundTransferType) {
		this.fundTransferType = fundTransferType;
	}

	public void setPayeeName(String payeeName) {
		this.payeeName = payeeName;
	}

	public void setAccNo(long accNo) {
		this.accNo = accNo;
	}

	public void setIFSC(String IFSC) {
		this.IFSC = IFSC;
	}

	public void setPayeeBank(String payeeBank) {
		this.payeeBank = payeeBank;
	}

	// Acceptor methods
	public String getFundTransferType() {
		return fundTransferType;
	}

	public String getPayeeName() {
		return payeeName;
	}

	public long getAccNo() {
		return accNo;
	}

	public String getIFSC() {
		return IFSC;
	}

	public String getPayeeBank() {
		return payeeBank;
	}
}

// Q1: Base class student with child classes UGStudent, PGStudent & PHDStudent
class Student {
	protected String name, fatherName, currAddress, permAddress, email;
	protected int regNo;
	protected long phone;
	protected Course course;
	protected Payment payment;

	Student(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
			String email, Course course, Payment payment) {
		this.name = name;
		this.regNo = regNo;
		this.fatherName = fatherName;
		this.currAddress = currAddress;
		this.permAddress = permAddress;
		this.phone = phone;
		this.email = email;
		this.course = course;
		this.payment = payment;
	}

	// Mutator methods
	public void setName(String name) {
		this.name = name;
	}

	public void setRegNo(int regNo) {
		this.regNo = regNo;
	}

	public void setFatherName(String fatherName) {
		this.fatherName = fatherName;
	}

	public void setCurrAddress(String currAddress) {
		this.currAddress = currAddress;
	}

	public void setPermAddress(String permAddress) {
		this.permAddress = permAddress;
	}

	public void setPhone(long phone) {
		this.phone = phone;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	// Acceptor methods
	public String getName() {
		return name;
	}

	public int getRegNo() {
		return regNo;
	}

	public String getFatherName() {
		return fatherName;
	}

	public String getCurrAddress() {
		return currAddress;
	}

	public String getPermAddress() {
		return permAddress;
	}

	public long getPhone() {
		return phone;
	}

	public String getEmail() {
		return email;
	}

	// Print student details
	public void printDeets() {
		System.out.println("Student Registration Number: " + regNo + "\nStudent Name: " + name + "\nCurrent Address: "
				+ currAddress + "\nPermanent Address: " + permAddress + "\nPhone number: " + phone + "\nE-Mail: "
				+ email);
		System.out.print("Course Details: ");
		course.printCourseDetails();
		System.out.print("Payment Details: ");
		payment.printPaymentDetails();
	}
}

class UGStudent extends Student {
	protected String qualifyDeg;
	protected double marks;

	UGStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
			String email, String qualifyDeg, double marks, Course course, Payment payment) {
		super(name, regNo, fatherName, currAddress, permAddress, phone, email, course, payment);
		this.qualifyDeg = qualifyDeg;
		this.marks = marks;
	}

	// Mutator methods
	public void setQualifyDeg(String qualifyDeg) {
		this.qualifyDeg = qualifyDeg;
	}

	public void setRegNo(double marks) {
		this.marks = marks;
	}

	// Acceptor methods
	public String getQualifyDeg() {
		return qualifyDeg;
	}

	public double getMarks() {
		return marks;
	}
}

class PGStudent extends Student {
	protected String qualifyDeg;
	protected double marks;

	PGStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
			String email, String qualifyDeg, double marks, Course course, Payment payment) {
		super(name, regNo, fatherName, currAddress, permAddress, phone, email, course, payment);
		this.qualifyDeg = qualifyDeg;
		this.marks = marks;
	}

	// Mutator methods
	public void setQualifyDeg(String qualifyDeg) {
		this.qualifyDeg = qualifyDeg;
	}

	public void setRegNo(double marks) {
		this.marks = marks;
	}

	// Acceptor methods
	public String getQualifyDeg() {
		return qualifyDeg;
	}

	public double getMarks() {
		return marks;
	}
}

class PHDStudent extends Student {
	protected String qualifyDeg;
	protected double marks;

	PHDStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
			String email, String qualifyDeg, double marks, Course course, Payment payment) {
		super(name, regNo, fatherName, currAddress, permAddress, phone, email, course, payment);
		this.qualifyDeg = qualifyDeg;
		this.marks = marks;
	}

	// Mutator methods
	public void setQualifyDeg(String qualifyDeg) {
		this.qualifyDeg = qualifyDeg;
	}

	public void setRegNo(double marks) {
		this.marks = marks;
	}

	// Acceptor methods
	public String getQualifyDeg() {
		return qualifyDeg;
	}

	public double getMarks() {
		return marks;
	}
}

public class q1to4 {
	public static void main(String[] args) {
		List<Student> students = new ArrayList<>();

		UGCourse ugCourse = new UGCourse("UG-1010", "B.Sc. Computer Science", 3);
		PGCourse pgCourse = new PGCourse("PG-2020", "M.Sc. Computer Science", 4);

		paymentDD paymentDD = new paymentDD("DD101", "Student", LocalDate.now(), "SBI", 5000.0, "DD1234");
		paymentUPI paymentUPI = new paymentUPI("UPI101", "upi@bank", LocalDate.now(), 3000.0);
		paymentNB paymentNB = new paymentNB("NB101", "IMPS", "Student", 1234567890L, "IFSC001", "ICICI Bank",
				LocalDate.now(), 10000.0);

		students.add(new UGStudent("John Doe", 1001, "Mark Doe", "123 Street A", "456 Street B", 1234567890L,
				"john@example.com", ugCourse.getCourseName(), 94.2, ugCourse, paymentDD));

		students.add(new PGStudent("Jane Smith", 2001, "Robert Smith", "789 Street C", "012 Street D", 2345678901L,
				"jane@example.com", pgCourse.getCourseName(), 88.8, pgCourse, paymentUPI));

		students.add(new PHDStudent("Alice Brown", 3001, "Charlie Brown", "345 Street E", "678 Street F", 3456789012L,
				"alice@example.com", pgCourse.getCourseName(), 97.3, pgCourse, paymentNB));

		for (Student student : students) {
			student.printDeets();
			System.out.println();
		}
	}
}