import java.time.LocalDate;
import java.util.*;

// Q5: Employee class with child classes Faculty and Office Staff
class Employee {
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

    @Override
    public String toString() {
        return ("Employee ID: " + ID + "\nName: " + name + "\nDepartment: " + dept + "\nDate of Birth: "
                + DOB + "\nDesignation: " + desgn + "\nYear of Joining: " + joinYear + "\nPhone Number: " + phone);
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

    @Override
    public String toString() {
        return super.toString() + "\nSubjects taught by " + getID() + ": " + subjects + "\n" + "Labs taught by "
                + getID() + ": " + labs + "\n";
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

    @Override
    public String toString() {
        return super.toString() + "\nSkills: " + skills + "\n";
    }
}

// Q6: Children classes HOD, DUGC, DMPC, DDPC from Faculty and SkilledStaff and
// UnskilledStaff from OfficeStaff
class HOD extends Faculty {
    private String deptHeaded;

    HOD(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone, String deptHeaded) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.deptHeaded = deptHeaded;
    }

    @Override
    public String toString() {
        return "HOD Details:\n" + super.toString() + "Department Headed: " + deptHeaded + "\n";
    }
}

class DUGC extends Faculty {
    private String committeeRole;

    DUGC(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone,
            String committeeRole) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.committeeRole = committeeRole;
    }

    @Override
    public String toString() {
        return "DUGC Convenor Details:\n" + super.toString() + "Committee Role: " + committeeRole + "\n";
    }
}

class DMPC extends Faculty {
    private String committeeRole;

    DMPC(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone,
            String committeeRole) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.committeeRole = committeeRole;
    }

    @Override
    public String toString() {
        return "DMPC Convenor Details:\n" + super.toString() + "Committee Role: " + committeeRole + "\n";
    }
}

class DDPC extends Faculty {
    private String committeeRole;

    DDPC(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone,
            String committeeRole) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.committeeRole = committeeRole;
    }

    @Override
    public String toString() {
        return "DDPC Convenor Details:\n" + super.toString() + "Committee Role: " + committeeRole + "\n";
    }
}

class SkilledStaff extends OfficeStaff {
    private String skillLevel;

    SkilledStaff(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone,
            String skillLevel) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.skillLevel = skillLevel;
    }

    @Override
    public String toString() {
        return "Skilled Staff Details:\n" + super.toString() + "Skill Level: " + skillLevel + "\n";
    }
}

class UnskilledStaff extends OfficeStaff {
    private String workDescription;

    UnskilledStaff(int ID, String name, String dept, LocalDate DOB, String desgn, int joinYear, long phone,
            String workDescription) {
        super(ID, name, dept, DOB, desgn, joinYear, phone);
        this.workDescription = workDescription;
    }

    @Override
    public String toString() {
        return "Unskilled Staff Details:\n" + super.toString() + "Work Description: " + workDescription + "\n";
    }
}

public class q5to6 {
    public static void main(String[] args) {
        Employee[] employees = new Employee[6];

        employees[0] = new HOD(101, "Alice Smith", "Computer Science", LocalDate.of(1980, 5, 12), "Professor", 2010,
                1234567890L, "Computer Science");
        employees[1] = new DUGC(102, "David Lee", "Mathematics", LocalDate.of(1985, 7, 24), "Associate Professor",
                2012, 1235557890L, "Undergraduate Courses");
        employees[2] = new DMPC(103, "Eva Brown", "Physics", LocalDate.of(1979, 11, 15), "Senior Lecturer", 2008,
                1238887890L, "Master Programs");
        employees[3] = new DDPC(104, "Chris Green", "Biology", LocalDate.of(1978, 9, 10), "Lecturer", 2015, 3216540987L,
                "Doctoral Programs");
        employees[4] = new SkilledStaff(201, "Bob Johnson", "Administration", LocalDate.of(1975, 03, 22),
                "Office Manager", 2005, 9087654321L, "Expert");
        employees[5] = new UnskilledStaff(202, "Mary Brown", "Maintenance", LocalDate.of(1982, 11, 13), "Janitor", 2008,
                5559876543L, "Cleaning");

        for (Employee emp : employees) {
            System.out.println(emp.toString());
        }
    }
}