// You are required to write classes for student details (name, registration number, fathers name), address (current address, permanent address, contact number, email Id) using inheritance concept where address is child class. Take the input data required for classes from keyboard and store it into the output file. Further, you are required to search the particular student’s ID and display its details with remark that whether required student details is available in the input file or not.
import java.io.*;
import java.util.*;

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

public class q3 {
	public static void main(String[] args) {
		File file = new File(
				"C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 3\\data.txt");
		try {
			Scanner input = new Scanner(System.in);
			FileWriter output = new FileWriter(file, true);

			System.out.print("Enter number of students: ");
			int num = input.nextInt();
			input.nextLine();

			String name, fatherName, currAddress, permAddress, email;
			int regNo;
			long contact;
			for (int i = 0; i < num; i++) {
				System.out.print("Enter name: ");
				name = input.nextLine();
				System.out.print("Enter reg. no.: ");
				regNo = input.nextInt();
				input.nextLine();
				System.out.print("Enter father's name: ");
				fatherName = input.nextLine();
				System.out.print("Enter current address: ");
				currAddress = input.nextLine();
				System.out.print("Enter permanent address: ");
				permAddress = input.nextLine();
				System.out.print("Enter contact no.: ");
				contact = input.nextLong();
				input.nextLine();
				System.out.print("Enter email: ");
				email = input.nextLine();
				System.out.println();
				output.write(name + "," + regNo + "," + fatherName + "," + currAddress + "," + permAddress + ","
						+ contact + "," + email + "\n");
			}
			output.close();

			System.out.print("Enter reg. no. for details: ");
			int findRegNo = input.nextInt();
			boolean flag = false;
			Scanner findDeets = new Scanner(file);
			while (findDeets.hasNextLine()) {
				String line = findDeets.nextLine();
				String[] data = line.split(",");

				int fileRegNo = Integer.parseInt(data[1]);
				if (fileRegNo == findRegNo) {
					System.out.println("Student details found:");
					System.out.println("Name: " + data[0]);
					System.out.println("Registration Number: " + data[1]);
					System.out.println("Father's name: " + data[2]);
					System.out.println("Current Address: " + data[3]);
					System.out.println("Permanent Address: " + data[4]);
					System.out.println("Contact Number: " + data[5]);
					System.out.println("Email Address: " + data[6]);
					flag = true;
					break;
				}
			}
			if (!flag) {
				System.out.println("Student details with reg. no. " + findRegNo + " not found.");
			}
		} catch (FileNotFoundException e) {
			System.out.println(e.toString());
		} catch (IOException e) {
			System.out.println(e.toString());
		}
	}
}