// Q4: Create an interface Shape having two methods getArea and getPerimeter. Three classes Circle, Triangle, and Rectangle implement the Shape interface and override the two methods. Create a Test class to demonstrate each of these classes.
interface Shape {
    double getArea();

    double getPerimeter();
}

class Circle implements Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return (Math.PI * radius * radius);
    }

    public double getPerimeter() {
        return (2 * Math.PI * radius);
    }

    public String printDimens() {
        return ("Circle (Radius = " + radius + "):");
    }
}

class Triangle implements Shape {
    private double side1, side2, side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double getArea() {
        double s = (side1 + side2 + side3) / 2;
        return (Math.sqrt(s * (s - side1) * (s - side2) * (s - side3)));
    }

    public double getPerimeter() {
        return (side1 + side2 + side3);
    }

    public String printDimens() {
        return ("Triangle (Side 1 = " + side1 + ", Side 2 = " + side2 + ", Side 3 = " + side3 + "):");
    }
}

class Rectangle implements Shape {
    private double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getArea() {
        return (length * width);
    }

    public double getPerimeter() {
        return (2 * (length + width));
    }

    public String printDimens() {
        return ("Rectangle (Length = " + length + ", Width = " + width + "):");
    }
}

public class q4 {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        System.out.println(circle.printDimens());
        System.out.println("Area: " + circle.getArea());
        System.out.println("Perimeter: " + circle.getPerimeter());
        System.out.println();

        Triangle triangle = new Triangle(3, 4, 5);
        System.out.println(triangle.printDimens());
        System.out.println("Area: " + triangle.getArea());
        System.out.println("Perimeter: " + triangle.getPerimeter());
        System.out.println();

        Rectangle rectangle = new Rectangle(4, 6);
        System.out.println(rectangle.printDimens());
        System.out.println("Area: " + rectangle.getArea());
        System.out.println("Perimeter: " + rectangle.getPerimeter());
    }
}