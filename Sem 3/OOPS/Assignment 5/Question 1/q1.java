// Employee details database
import java.time.LocalDate;

class emp_db {
    private int empID;
    private String empName;
    private String fatherName;
    private String address;
    private LocalDate DOB;
    private String designation;
    private double payRate;
    private double maxPay;

    public emp_db(int empID, String empName, String fatherName, String address, LocalDate DOB, String designation,
            double payRate) {
        this.empID = empID;
        this.empName = empName;
        this.fatherName = fatherName;
        this.address = address;
        this.DOB = DOB;
        this.designation = designation;
        this.payRate = payRate;
        this.maxPay = (payRate * 100);
    }

    // Mutator Methods
    public void setEmpId(int empID) {
        this.empID = empID;
    }

    public void setEmpName(String empName) {
        this.empName = empName;
    }

    public void setFatherName(String fatherName) {
        this.fatherName = fatherName;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setDOB(LocalDate DOB) {
        this.DOB = DOB;
    }

    public void setDesignation(String designation) {
        this.designation = designation;
    }

    public void setPayRate(double PayRate) {
        this.payRate = PayRate;
        this.maxPay = (PayRate * 100);
    }

    // Acceptor Methods
    public int getEmpID() {
        return empID;
    }

    public String getEmpName() {
        return empName;
    }

    public String getFatherName() {
        return fatherName;
    }

    public String getAddress() {
        return address;
    }

    public LocalDate getDOB() {
        return DOB;
    }

    public String getDesignation() {
        return designation;
    }

    public String getPayRate() {
        return String.format("%.2f", payRate);
    }

    public String getMaxPay() {
        return String.format("%.2f", maxPay);
    }
}

public class q1 {
    public static void main(String[] args) {
        emp_db[] Employees = new emp_db[100];

        Employees[0] = new emp_db(1, "John Doe", "Richard Doe", "San Francisco", LocalDate.of(1985, 5, 20),
                "Software Engineer", 25.0);
        Employees[1] = new emp_db(2, "Jane Smith", "Michael Smith", "London", LocalDate.of(1990, 8, 15),
                "Data Analyst", 30.0);

        for (int i = 0; i < Employees.length; i++) {
            if (Employees[i] != null) {
                System.out.println("Employee " + (i + 1) + " Details:");
                System.out.println("Employee ID: " + Employees[i].getEmpID() + "\nEmployee Name: "
                        + Employees[i].getEmpName() + "\nFather's Name: " + Employees[i].getFatherName() + "\nAddress: "
                        + Employees[i].getAddress() + "\nDate of Birth: " + Employees[i].getDOB() + "\nDesignation: "
                        + Employees[i].getDesignation() + "\nHourly Payment Rate: " + Employees[i].getPayRate()
                        + "\nMaximum Pay: " + Employees[i].getMaxPay() + "\n");
            }
        }
    }
}