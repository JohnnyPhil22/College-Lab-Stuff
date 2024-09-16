// Q3: Write a class Employee having attributes: employeeID, name, department, DOB, designation, yearOfJoining, and phoneNumber. Add a function to print details of employee using employeeID. Two classes, i.e., Faculty and OfficeStaff, extends the Employee class. The faculty has a list of subjects and labs taught by them. OfficeStaff has a list of skills which stores skill such as Typing, Technician, etc. Each of the above classes has appropriate getter setter for inserting skill in the list and printing the list of skill. Demonstrate above class using a Test class which creates 5 employees of deferent types and print their details. Use Java Abstract class concept.
import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;

abstract class Employee {
    private int ID, joinYear;
    private String name, dept, desgn;
    private LocalDate DOB;
    private long phone;

    Employee(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone) {
        this.ID = ID;
        this.name = name;
        this.dept = dept;
        this.DOB = DOB;
        this.desgn = desgn;
        this.joinYear = joinYear;
        this.phone = phone;
    }

    // Mutator methods
    public void setID(int ID) {
        this.ID = ID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }

    public void setDOB(LocalDate DOB) {
        this.DOB = DOB;
    }

    public void setDesgn(String desgn) {
        this.desgn = desgn;
    }

    public void setJoinYear(int joinYear) {
        this.joinYear = joinYear;
    }

    public void setPhone(long phone) {
        this.phone = phone;
    }

    // Acceptor methods
    public int getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public String getDept() {
        return dept;
    }

    public LocalDate getDOB() {
        return DOB;
    }

    public String getDesgn() {
        return desgn;
    }

    public int getJoinYear() {
        return joinYear;
    }

    public long getPhone() {
        return phone;
    }

    // Print details
    public abstract void printDeets();

    public String toString() {
        return ("Employee ID: " + ID + "\nName: " + name + "\nDepartment: " + dept + "\nDate of Birth: " + DOB
                + "\nDesignation: " + desgn + "\nYear of Joining: " + joinYear + "\nPhone Number: " + phone);
    }
}

class Faculty extends Employee {
    private List<String> subjects, labs;

    Faculty(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.subjects = new ArrayList<>();
        this.labs = new ArrayList<>();
    }

    public void addSubject(String subject) {
        subjects.add(subject);
    }

    public void addLab(String lab) {
        labs.add(lab);
    }

    public List<String> getSubjects() {
        return new ArrayList<>(subjects);
    }

    public List<String> getLabs() {
        return new ArrayList<>(labs);
    }

    public void printDeets() {
        System.out.println(this);
        System.out.println("Subjects taught: " + subjects);
        System.out.println("Labs conducted: " + labs);
    }

    public String toString() {
        return super.toString() + "\nFaculty";
    }
}

class OfficeStaff extends Employee {
    private List<String> skills;

    OfficeStaff(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.skills = new ArrayList<>();
    }

    public void addSkill(String skill) {
        skills.add(skill);
    }

    public List<String> getSkills() {
        return new ArrayList<>(skills);
    }

    public void printDeets() {
        System.out.println(this);
        System.out.println("Skills: " + skills);
    }

    public String toString() {
        return (super.toString() + "\nOffice Staff");
    }
}

public class q3 {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<>();

        Faculty f1 = new Faculty(101, "Alice Smith", "Computer Science", LocalDate.of(1980, 5, 12), "Professor", 2010,
                1234567890L);
        f1.addSubject("Java Programming");
        f1.addLab("Data Structures Lab");
        employees.add(f1);

        Faculty f2 = new Faculty(102, "David Lee", "Mathematics", LocalDate.of(1985, 7, 24), "Associate Professor",
                2012, 1235557890L);
        f2.addSubject("Quantum Mechanics");
        f2.addLab("Physics Lab");
        employees.add(f2);

        Faculty f3 = new Faculty(103, "Eva Brown", "Physics", LocalDate.of(1979, 11, 15), "Senior Lecturer", 2008,
                1238887890L);
        f3.addSubject("Calculus");
        f3.addSubject("Linear Algebra");
        employees.add(f3);

        OfficeStaff s1 = new OfficeStaff(201, "Bob Johnson", "Administration", LocalDate.of(1975, 03, 22),
                "Office Manager", 2005, 9087654321L);
        s1.addSkill("Typing");
        s1.addSkill("Filing");
        employees.add(s1);

        OfficeStaff s2 = new OfficeStaff(202, "Mary Brown", "Maintenance", LocalDate.of(1982, 11, 13), "IT Support",
                2008, 5559876543L);
        s2.addSkill("Network Troubleshooting");
        s2.addSkill("Hardware Repair");
        employees.add(s2);

        for (Employee emp : employees) {
            emp.toString();
            emp.printDeets();
            System.out.println();
        }
    }
}