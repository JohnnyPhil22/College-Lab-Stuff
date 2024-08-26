// Q6: Circle's area, diameter and circumference
import java.util.Scanner;

class Circle {
	private double radius, pi = 3.14159;

	// Accepts radius
	Circle(double radius) {
		this.radius = radius;
	}

	// No arguments accepted
	Circle() {
		this(0);
	}

	// Mutator methods
	public void setRadius(double radius) {
		this.radius = radius;
	}

	// Acceptor methods
	public double getRadius() {
		return radius;
	}

	// Area of circle
	public double getArea() {
		return (pi * radius * radius);
	}

	// Diameter of circle
	public double getDiameter() {
		return (radius * 2);
	}

	// Circumference of circle
	public double getCircumference() {
		return (2 * pi * radius);
	}
}

public class q6 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.err.print("Enter radius of circle: ");
		int rad = s.nextInt();

		Circle circle = new Circle(rad);

		System.out.println("Area of circle: "+circle.getArea());
		System.out.println("Diameter of circle: "+circle.getDiameter());
		System.out.println("Circumference of circle: "+circle.getCircumference());
	}
}