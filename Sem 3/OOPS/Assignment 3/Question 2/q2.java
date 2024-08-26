// Q2: Car records
class Car {
	private int year, speed = 0;
	private String make;

	// Return only year and make
	Car(int year, String make) {
		this.year = year;
		this.make = make;
	}

	// Mutator methods
	public void setYear(int year) {
		this.year = year;
	}

	public void setMake(String make) {
		this.make = make;
	}

	public void setSpeed(int speed) {
		this.speed = speed;
	}

	// Acceptor methods
	public int getYear() {
		return year;
	}

	public String getMake() {
		return make;
	}

	public int getSpeed() {
		return speed;
	}

	// Accelerate method
	public void accelerate() {
		speed += 1;
	}

	// Brake method
	public void brake() {
		speed -= 1;
	}
}

public class q2 {
	public static void main(String[] args) {
		Car car = new Car(2018, "McLaren Senna GTR");
		System.out.println("Speed: " + car.getSpeed());

		System.out.println();
		for (int i = 0; i < 5; i++) {
			car.accelerate();
			System.out.println("Speed increased by 1\nNew speed: " + car.getSpeed());
		}

		System.out.println();
		for (int i = 0; i < 5; i++) {
			car.brake();
			System.out.println("Speed decreased by 1\nNew speed: " + car.getSpeed());
		}
	}
}