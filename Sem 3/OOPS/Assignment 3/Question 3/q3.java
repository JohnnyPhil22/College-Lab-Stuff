// Q3: Personal records
class Personal_Info {
	private String name, address;
	private int age;
	private long phone;

	Personal_Info(String name, String address, int age, long phone) {
		this.name = name;
		this.address = address;
		this.age = age;
		this.phone = phone;
	}

	// Mutator methods
	public void setName(String name) {
		this.name = name;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setPhone(long phone) {
		this.phone = phone;
	}

	// Acceptor methods
	public String getName() {
		return name;
	}

	public String getAddress() {
		return address;
	}

	public int getAge() {
		return age;
	}

	public long getPhone() {
		return phone;
	}

	// Print method
	public String print_deets() {
		return ("Name: " + name + "\nAddress: " + address + "\nAge: " + age + "\nPhone Number: " + phone);
	}
}

public class q3 {
	public static void main(String[] args) {
		Personal_Info person1 = new Personal_Info("Jonathan", "Tamil Nadu", 19, 9129590905L);
		Personal_Info person2 = new Personal_Info("Vijay", "Tamil Nadu", 50, 7200017193L);
		Personal_Info person3 = new Personal_Info("Jatin", "Haryana", 18, 8878568848L);

		System.out.println("Person 1:\n" + person1.print_deets());
		System.out.println("\nPerson 2:\n" + person2.print_deets());
		System.out.println("\nPerson 3:\n" + person3.print_deets());
	}
}