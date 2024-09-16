// Q2: Create an interface Vehicle having three methods changeGear, speedUp, and applyBrakes. Two other classes, Bike and Bicycle, implement the Vehicle interface. These classes have two fields, i.e., gear and speed. The change Gear method accepts the value of gear and assigns it to the gear field. The speedup method accepts the value by which the speed field should be increased. The apply Brakes method accepts the value by which the speed field should be decreased. Create a Test class to demonstrate each of these classes.
interface Vehicle {
    void changeGear(int gear);

    void speedUp(int inc);

    void applyBrakes(int dec);
}

class Bike implements Vehicle {
    private int gear, speed;

    public Bike() {
        this.gear = 1;
        this.speed = 0;
    }

    public void changeGear(int gear) {
        this.gear = gear;
    }

    public void speedUp(int inc) {
        this.speed += inc;
    }

    public void applyBrakes(int dec) {
        this.speed = Math.max(0, this.speed - dec);
    }

    public String toString() {
        return "Bike - Gear: " + gear + ", Speed: " + speed;
    }
}

class Bicycle implements Vehicle {
    private int gear, speed;

    public Bicycle() {
        this.gear = 1;
        this.speed = 0;
    }

    public void changeGear(int gear) {
        this.gear = gear;
    }

    public void speedUp(int inc) {
        this.speed += inc;
    }

    public void applyBrakes(int dec) {
        this.speed = Math.max(0, this.speed - dec);
    }

    public String toString() {
        return "Bicycle - Gear: " + gear + ", Speed: " + speed;
    }
}

public class q2 {
    public static void main(String[] args) {
        Bike bike = new Bike();
        System.out.println("Bike initial state: " + bike);
        bike.changeGear(3);
        bike.speedUp(20);
        System.out.println("Bike after changing gear and speeding up: " + bike);
        bike.applyBrakes(5);
        System.out.println("Bike after applying brakes: " + bike);

        Bicycle bicycle = new Bicycle();
        System.out.println("\nBicycle initial state: " + bicycle);
        bicycle.changeGear(2);
        bicycle.speedUp(15);
        System.out.println("Bicycle after changing gear and speeding up: " + bicycle);
        bicycle.applyBrakes(5);
        System.out.println("Bicycle after applying brakes: " + bicycle);
    }
}
