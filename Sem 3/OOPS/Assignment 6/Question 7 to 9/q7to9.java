import java.time.LocalDate;
// Q7: Class Employee with child class ProductionWorker

class Employee {
    private String name, empNo;
    private LocalDate date;

    Employee(String name, String empNo, LocalDate date) {
        this.name = name;
        this.empNo = empNo;
        this.date = date;
    }

    // Mutator methods
    public void setName(String name) {
        this.name = name;
    }

    public void setEmpNo(String empNo) {
        this.empNo = empNo;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    // Accessor methods
    public String getName() {
        return name;
    }

    public String getEmpNo() {
        return empNo;
    }

    public LocalDate getDate() {
        return date;
    }

    @Override
    public String toString() {
        return ("Employee Name: " + name + "\nEmployee Number: " + empNo + "\nHiring Date: " + date);
    }
}

class ProductionWorker extends Employee {
    private int shift;
    private double hourlyRate;

    ProductionWorker(String name, String empNo, LocalDate date, int shift, double hourlyRate) {
        super(name, empNo, date);
        this.shift = shift;
        this.hourlyRate = hourlyRate;
    }

    @Override
    public String toString() {
        return (super.toString() + "\nShift: " + shift + "\nHourly Rate: " + hourlyRate);
    }
}

// Q8: Child class ShiftSupervisor extended from parent class Employee
class ShiftSupervisor extends Employee {
    private double annualSal, prodBonus;

    ShiftSupervisor(String name, String empNo, LocalDate date, double annualSal, double prodBonus) {
        super(name, empNo, date);
        this.annualSal = annualSal;
        this.prodBonus = prodBonus;
    }

    // Mutator methods
    public void setAnnualSal(double annualSal) {
        this.annualSal = annualSal;
    }

    public void setProdBonus(double prodBonus) {
        this.prodBonus = prodBonus;
    }

    // Accessor methods
    public double getAnnualSal() {
        return annualSal;
    }

    public double getProdBonus() {
        return prodBonus;
    }

    @Override
    public String toString() {
        return (super.toString() + "\nAnnual Salary: " + annualSal + "\nProduction Bonus: " + prodBonus);
    }
}

// Q9: Child class TeamLeader extended from parent class ProductionWorker
class TeamLeader extends ProductionWorker {
    private double monthBonus;
    private int reqTrainHrs, attendTrainHrs;

    TeamLeader(String name, String empNo, LocalDate date, int shift, double hourlyRate, double monthBonus,
            int reqTrainHrs, int attendTrainHrs) {
        super(name, empNo, date, shift, hourlyRate);
        this.monthBonus = monthBonus;
        this.reqTrainHrs = reqTrainHrs;
        this.attendTrainHrs = attendTrainHrs;
    }

    // Mutator methods
    public void setMonthBonus(double monthBonus) {
        this.monthBonus = monthBonus;
    }

    public void setReqTrainHrs(int reqTrainHrs) {
        this.reqTrainHrs = reqTrainHrs;
    }

    public void setAttendTrainHrs(int attendTrainHrs) {
        this.attendTrainHrs = attendTrainHrs;
    }

    // Accessor methods
    public double getMonthBonus() {
        return monthBonus;
    }

    public int getReqTrainHrs() {
        return reqTrainHrs;
    }

    public int getAttendTrainHrs() {
        return attendTrainHrs;
    }

    @Override
    public String toString() {
        return (super.toString() + "\nMonth Bonus: " + monthBonus + "\nRequired Training Hours: " + reqTrainHrs
                + "\nAttended Training Hours: " + attendTrainHrs);
    }
}

public class q7to9 {
    public static void main(String[] args) {
        TeamLeader tl1 = new TeamLeader("Jonathan", "100J", LocalDate.of(2019, 9, 9), 1, 30, 20000, 50, 40);
        System.out.println("Team Leader:\n" + tl1.toString());
    }
}