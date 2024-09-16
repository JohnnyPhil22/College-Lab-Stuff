/* Q5: Develop a class hierarchy of shapes and write a program that computes the amount of paint needed to paint different objects. The hierarchy will consist of a parent class Shape with three derived classes - Sphere, Rectangle, and Cylinder. For the purposes of this exercise, the only attribute a shape will have is a name and the method of interest will be one that computes the area of the shape (surface area in the case of three-dimensional shapes). Write an abstract class Shape with the following properties:
- An instance variable shapeName of type String
- An abstract method area()
- A toString method that returns the name of the shape */
import java.util.List;
import java.util.ArrayList;

abstract class Shape {
    private String shapeName;

    public Shape(String shapeName) {
        this.shapeName = shapeName;
    }

    abstract public double area();

    public String toString() {
        return shapeName;
    }
}

class Sphere extends Shape {
    private double radius;

    public Sphere(double radius) {
        super("Sphere");
        this.radius = radius;
    }

    public double area() {
        return 4 * Math.PI * radius * radius;
    }

    public String toString() {
        return super.toString() + "\nRadius: " + radius;
    }
}

class Rectangle extends Shape {
    private double length, width;

    public Rectangle(double length, double width) {
        super("Rectangle");
        this.length = length;
        this.width = width;
    }

    public double area() {
        return length * width;
    }

    public String toString() {
        return (super.toString() + "\nLength: " + length + ", Width: " + width);
    }
}

class Cylinder extends Shape {
    private double radius, height;

    public Cylinder(double radius, double height) {
        super("Cylinder");
        this.radius = radius;
        this.height = height;
    }

    public double area() {
        return 2 * Math.PI * radius * (radius + height);
    }

    public String toString() {
        return (super.toString() + "\nRadius: " + radius + ", Height: " + height);
    }
}

public class q5 {
    public static void main(String[] args) {
        List<Shape> shapes = new ArrayList<>();
        shapes.add(new Sphere(5));
        shapes.add(new Rectangle(4, 5));
        shapes.add(new Cylinder(3, 7));

        for (Shape shape : shapes) {
            System.out.println("Shape: " + shape);
            System.out.println("Area: " + String.format("%.2f", shape.area()));
        }
    }
}
