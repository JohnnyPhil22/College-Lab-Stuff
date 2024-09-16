// Q1: You are required to write a base class Student having details (name, registration number, father's name, address (current address, permanent address), and contact details (phone number, email Id). UGStudent, PGStudent, and PhDStudent extend the Student class they have details about the past qualifying degree and marks. Make each attribute protected and provide suitable getter and setter to access attributes. Use the Java Abstract class concept.
import java.util.ArrayList;
import java.util.List;

abstract class Student {
    protected String name, fatherName, currAddress, permAddress, email;
    protected int regNo;
    protected long phone;

    Student(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
            String email) {
        this.name = name;
        this.regNo = regNo;
        this.fatherName = fatherName;
        this.currAddress = currAddress;
        this.permAddress = permAddress;
        this.phone = phone;
        this.email = email;
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

    public abstract String getStudentType();
}

class UGStudent extends Student {
    protected String qualifyDeg;
    protected double marks;

    UGStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
            String email, String qualifyDeg, double marks) {
        super(name, regNo, fatherName, currAddress, permAddress, phone, email);
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

    public String getStudentType() {
        return "Undergraduate Student";
    }
}

class PGStudent extends Student {
    protected String qualifyDeg;
    protected double marks;

    PGStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
            String email, String qualifyDeg, double marks) {
        super(name, regNo, fatherName, currAddress, permAddress, phone, email);
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

    public String getStudentType() {
        return "Postgraduate Student";
    }
}

class PHDStudent extends Student {
    protected String qualifyDeg;
    protected double marks;

    PHDStudent(String name, int regNo, String fatherName, String currAddress, String permAddress, long phone,
            String email, String qualifyDeg, double marks) {
        super(name, regNo, fatherName, currAddress, permAddress, phone, email);
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

    public String getStudentType() {
        return "Doctorate Student";
    }
}

public class q1 {
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();

        students.add(new UGStudent("John Doe", 1001, "Mark Doe", "123 Street A", "456 Street B", 1234567890L,
                "john@example.com", "B.Sc. Computer Science", 94.2));

        students.add(new PGStudent("Jane Smith", 2001, "Robert Smith", "789 Street C", "012 Street D", 2345678901L,
                "jane@example.com", "M.Sc. Computer Science", 88.8));

        students.add(new PHDStudent("Alice Brown", 3001, "Charlie Brown", "345 Street E", "678 Street F", 3456789012L,
                "alice@example.com", "Ph.D. Research Thesis", 97.3));

        for (Student student : students) {
            printStudentInfo(student);
            System.out.println();
        }
    }

    public static void printStudentInfo(Student student) {
        System.out.println("Student Type: " + student.getStudentType());
        System.out.println("Name: " + student.getName());
        System.out.println("Registration Number: " + student.getRegNo());
        System.out.println("Father's Name: " + student.getFatherName());
        System.out.println("Contact: " + student.getPhone());
        System.out.println("Email: " + student.getEmail());

        if (student instanceof UGStudent) {
            UGStudent ug = (UGStudent) student;
            System.out.println("Past Qualifying Degree: " + ug.getQualifyDeg());
            System.out.println("Past Qualifying Marks: " + ug.getMarks());
        } else if (student instanceof PGStudent) {
            PGStudent pg = (PGStudent) student;
            System.out.println("Past Qualifying Degree: " + pg.getQualifyDeg());
            System.out.println("Past Qualifying Marks: " + pg.getMarks());
        } else if (student instanceof PHDStudent) {
            PHDStudent phd = (PHDStudent) student;
            System.out.println("Past Qualifying Degree: " + phd.getQualifyDeg());
            System.out.println("Past Qualifying Marks: " + phd.getMarks());
        }
        System.out.println();
    }
}