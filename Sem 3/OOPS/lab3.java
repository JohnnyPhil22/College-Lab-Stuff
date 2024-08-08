import java.util.Scanner;

class Employee {
	String name;
	int id, age, salary;
	
	Employee(int id, String name, int age, int salary) {
		this.id=id;
		this.name=name;
		this.age=age;
		this.salary=salary;
	}
	
	void detail_print() {
		System.out.println("Employee ID: "+id+"\nEmployee Name: "+name+"\nEmployee Age: "+age+"\nEmployee Salary: "+salary);
	}
}

public class lab3 {
	public static void main (String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.print("Number of employees: ");
		int num=s.nextInt();
		
		String[][] emp_arr= new String[num][4];
		for (int i=0;i<num;i++) {
			System.out.print("Enter ID, name, age and salary of employee "+(i+1)+": ");
			emp_arr[i][0]=s.nextLine();
			emp_arr[i][1]=s.nextLine();
			emp_arr[i][2]=s.nextLine();
			emp_arr[i][3]=s.nextLine();
			System.out.print("ID, name, age and salary of employee "+(i+1)+": "+Employee.detail_print(emp_arr[i][0], emp_arr[i][1], emp_arr[i][2], emp_arr[i][3]));
		}
	}
}
