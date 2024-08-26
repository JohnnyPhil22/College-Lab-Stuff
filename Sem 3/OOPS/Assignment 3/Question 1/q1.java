// Q1: Employee records
class Employee {
	private String name, department, position;
	private int id_Number;

	// Return all fields
	Employee(String name, int id, String dept, String pos) {
		this.name = name;
		this.id_Number = id;
		this.department = dept;
		this.position = pos;
	}

	// Return only name and ID
	Employee(String name, int id) {
		this(name, id, "", "");
	}

	// Accepts nothing
	Employee() {
		this("", 0, "", "");
	}

	// Mutator methods
	public void setName(String name) {
		this.name = name;
	}

	public void setID(int id) {
		this.id_Number = id;
	}

	public void setDept(String dept) {
		this.department = dept;
	}

	public void setPos(String pos) {
		this.position = pos;
	}

	// Acceptor methods
	public String getName() {
		return name;
	}

	public int getID() {
		return id_Number;
	}

	public String getDept() {
		return department;
	}

	public String getPos() {
		return position;
	}

	// Print method
	public String print_deets() {
		return (name + "\t\t\t" + id_Number + "\t\t\t" + department + "\t\t\t" + position);
	}
}

public class q1 {
	public static void main(String[] args) {
		Employee emp1 = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
		Employee emp2 = new Employee("Mark Jones", 39119, "IT", "\tProgrammer");
		Employee emp3 = new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");

		System.out.println("Name\t\t\t\tID Number\t\tDepartment\t\t\tPosition");
		System.out.println(emp1.print_deets());
		System.out.println(emp2.print_deets());
		System.out.println(emp3.print_deets());
	}
}