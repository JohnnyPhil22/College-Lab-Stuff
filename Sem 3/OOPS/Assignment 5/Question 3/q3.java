// Q3: Student details class with address, course, academic records, and payment details classes as child classes
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

class studDeets {
    String name, fatherName;
    int regNo;

    public studDeets(String name, int regNo, String fatherName) {
        this.name = name;
        this.regNo = regNo;
        this.fatherName = fatherName;
    }
}

class address extends studDeets {
    String currAddress, permAddress, email;
    long contact;

    public address(String name, int regNo, String fatherName, String currAddress, String permAddress, long contact,
            String email) {
        super(name, regNo, fatherName);
        this.currAddress = currAddress;
        this.permAddress = permAddress;
        this.contact = contact;
        this.email = email;
    }

    public String print_deets() {
        return ("Name: " + name + "\nRegistration Number: " + regNo + "\nFather's name: " + fatherName
                + "\nCurrent Address: " + currAddress + "\nPermanent Address: " + permAddress + "\nContact Number: "
                + contact + "\nEmail Address: " + email);
    }
}

class courses extends studDeets {
    String courseName, courseNumber, teachers;
    int credit;

    public courses(String name, int regNo, String fatherName, String courseName, int credit, String courseNumber,
            String teachers) {
        super(name, regNo, fatherName);
        this.courseName = courseName;
        this.credit = credit;
        this.courseNumber = courseNumber;
        this.teachers = teachers;
    }

    public String print_deets() {
        return ("Name: " + name + "\nRegistration Number: " + regNo + "\nFather's name: " + fatherName
                + "\nCourse Name: " + courseName + "\nNumber of Credits: " + credit + "\nCourse Number: "
                + courseNumber + "\nAssociated Teachers: " + teachers);
    }
}

class academicRecords extends studDeets {
    String degreeName, university;
    int passingYear;
    double percentageMarks;

    public academicRecords(String name, int regNo, String fatherName, String degreeName, int passingYear,
            String university, double percentageMarks) {
        super(name, regNo, fatherName);
        this.degreeName = degreeName;
        this.passingYear = passingYear;
        this.university = university;
        this.percentageMarks = percentageMarks;
    }

    public String print_deets() {
        return ("Name: " + name + "\nRegistration Number: " + regNo + "\nFather's name: " + fatherName
                + "\nDegree Name: " + degreeName + "\nPassing Year: " + passingYear + "\nUniversity: "
                + university + "\nPercentage Marks: " + percentageMarks);
    }
}

class payment extends studDeets {
    String bankName, transactionID;
    double amount;
    LocalDate date;

    public payment(String name, int regNo, String fatherName, String bankName, String transactionID, double amount,
            LocalDate date) {
        super(name, regNo, fatherName);
        this.bankName = bankName;
        this.transactionID = transactionID;
        this.amount = amount;
        this.date = date;
    }

    public String print_deets() {
        return ("Name: " + name + "\nRegistration Number: " + regNo + "\nFather's name: " + fatherName
                + "\nBank Name: " + bankName + "\nTransaction ID: " + transactionID + "\nAmount: "
                + amount + "\nDate: " + date);
    }
}

public class q3 {
    public static void main(String[] args) {
        courses course1 = new courses("Jonathan", 20233525, "Vijay", "OOPS", 3, "CSN13101", "Prof. R. S. Yadav");
        System.out.println(course1.print_deets() + "\n");

        academicRecords record1 = new academicRecords("Jonathan", 20233525, "Vijay", "B. Tech CSE", 2027,
                "MNNIT Allahabad", 85.2);
        System.out.println(record1.print_deets() + "\n");

        LocalDate paymentDate = LocalDate.parse("2024-07-16", DateTimeFormatter.ISO_DATE);
        payment payment1 = new payment("Jonathan", 20233525, "Vijay", "Bank of Baroda", "OYOICEWYORB9PQYC", 25000.00,
                paymentDate);
        System.out.println(payment1.print_deets() + "\n");
    }
}