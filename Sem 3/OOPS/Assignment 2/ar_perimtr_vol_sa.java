import java.util.Scanner;

class Rectangle {
    int length, width;

    Rectangle(int length, int width) {
        this.length = length;
        this.width = width;
    }

    int area() {
        return length * width;
    }

    int perimeter() {
        return 2 * (length + width);
    }
}

class Box extends Rectangle {
    int height;

    Box(int length, int width, int height) {
        super(length, width);
        this.height = height;
    }

    int volume() {
        return (super.area() * height);
    }

    int surface_area() {
        return (2 * ((length * width) + (width * height) + (height * length)));
    }
}

public class ar_perimtr_vol_sa {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Q3: Enter length and width of rectangle: ");
        int length = s.nextInt(), width = s.nextInt();
        Rectangle rect = new Rectangle(length, width);
        System.out.println("    Area of Rectangle: " + rect.area());
        System.out.println("    Perimeter of Rectangle: " + rect.perimeter());

        System.out.print("\n    Enter length, width and height of box: ");
        int height = s.nextInt();
        length = s.nextInt();
        width = s.nextInt();
        Box box = new Box(length, width, height);
        System.out.println("    Volume of Box: " + box.volume());
        System.out.println("    Surface Area of Box: " + box.surface_area());
    }
}
