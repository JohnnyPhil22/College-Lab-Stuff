import java.io.*;
import java.util.*;
// A software development firm is tasked with creating a robust and extensible solution for processing different types of textual data. The data consists of records related to various employees, including Managers, Engineers, and Interns. Each type of employee has different methods of salary calculation, job roles, and other properties. The data is stored in a text file, and the program should be capable of reading the file, processing the information, and displaying it in a structured manner.

class Employee {
    private String name;
    private int employeeID;
    protected double salary;

    public Employee(String name, int employeeID) {
        this.name = name;
        this.employeeID = employeeID;
    }

    public String getDetails() {
        return ("Name: " + name + "\nEmployee ID: " + employeeID + "\n");
    }
}

class Manager extends Employee {
    private int numOfProjects;
    private double baseSalary;

    public Manager(String name, int employeeID, int numOfProjects, double baseSalary) {
        super(name, employeeID);
        this.numOfProjects = numOfProjects;
        this.baseSalary = baseSalary;
    }

    public void calculateSalary() {
        this.salary = baseSalary + (numOfProjects * 1000);
    }

    public String getDetails() {
        return super.getDetails() + "Role: Manager\nTotal Salary: " + salary +
                " (Base: " + baseSalary + ", Bonus for " + numOfProjects + " projects)\n";
    }
}

class Engineer extends Employee {
    private double hourlyRate;
    private int hoursWorked;

    public Engineer(String name, int employeeID, double hourlyRate, int hoursWorked) {
        super(name, employeeID);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    public void calculateSalary() {
        this.salary = hourlyRate * hoursWorked;
    }

    public String getDetails() {
        return super.getDetails() + "Role: Engineer\nTotal Salary: " + salary +
                " (Hourly Rate: " + hourlyRate + ", Hours Worked: " + hoursWorked + ")\n";
    }
}

class Intern extends Employee {
    private double stipend;

    public Intern(String name, int employeeID, double stipend) {
        super(name, employeeID);
        this.stipend = stipend;
    }

    public void calculateSalary() {
        this.salary = stipend;
    }

    @Override
    public String getDetails() {
        return super.getDetails() + "Role: Intern\nTotal Salary: " + salary + "\n";
    }
}

public class caseStudy {
    public static Employee[] readEmployeesFromFile(String fileName) throws IOException {
        List<Employee> employeeList = new ArrayList<>();
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        String line;

        while ((line = br.readLine()) != null) {
            String[] parts = line.split(", ");
            String type = parts[0];
            String name = parts[1];
            int employeeID = Integer.parseInt(parts[2]);

            if (type.equalsIgnoreCase("Manager")) {
                int numOfProjects = Integer.parseInt(parts[3]);
                double baseSalary = Double.parseDouble(parts[4]);
                Manager manager = new Manager(name, employeeID, numOfProjects, baseSalary);
                manager.calculateSalary();
                employeeList.add(manager);
            } else if (type.equalsIgnoreCase("Engineer")) {
                double hourlyRate = Double.parseDouble(parts[3]);
                int hoursWorked = Integer.parseInt(parts[4]);
                Engineer engineer = new Engineer(name, employeeID, hourlyRate, hoursWorked);
                engineer.calculateSalary();
                employeeList.add(engineer);
            } else if (type.equalsIgnoreCase("Intern")) {
                double stipend = Double.parseDouble(parts[3]);
                Intern intern = new Intern(name, employeeID, stipend);
                intern.calculateSalary();
                employeeList.add(intern);
            }
        }
        br.close();
        return employeeList.toArray(new Employee[0]);
    }

    public static Employee[] filterByType(Employee[] employees, String type) {
        List<Employee> filteredList = new ArrayList<>();
        for (Employee employee : employees) {
            if (employee.getClass().getSimpleName().equalsIgnoreCase(type)) {
                filteredList.add(employee);
            }
        }
        return filteredList.toArray(new Employee[0]);
    }

    public static void main(String[] args) {
        try {
            Employee[] employees = readEmployeesFromFile(
                    "C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Polymorphism Case Study\\data.txt");

            System.out.print("Enter type of employee to filter (Manager/Engineer/Intern): ");
            Scanner sc = new Scanner(System.in);
            String filterType = sc.nextLine();
            Employee[] filteredEmployees = filterByType(employees, filterType);

            System.out.println("Details of filtered employees:");
            for (Employee emp : filteredEmployees) {
                System.out.println(emp.getDetails());
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}