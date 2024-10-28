/*
 * Write a class named RetailItem that holds data about an item in a retail store. The class should have the following fields:
 * 	description. The description field references a String object that holds a brief description of the item.
 * 	unitsOnHand. The unitsOnHand field is an int variable that holds the number of units currently in inventory.
 * 	price. The price field is a double that holds the item’s retail price.
 * Write a constructor that accepts arguments for each field, appropriate mutator methods that store values in these fields, and accessor methods that return the values in these fields. Once you have written the class, write a separate program that creates three RetailItem objects and stores the following data in them:
 *           description    unitsOnHand   price
 * Item #1 Jacket                12       59.95
 * Item #2 Designer Jeans	     40       34.95
 * Item #3 Shirt                 20       24.95
 * Write an exception class that can be instantiated and thrown when a negative number is given for the price. Write another exception class that can be instantiated and thrown when a negative number is given for the units on hand. Demonstrate the exception classes in a program.
 */
class NegativePriceError extends Exception {
    public NegativePriceError(String message) {
        super(message);
    }
}

class NegativeCountError extends Exception {
    public NegativeCountError(String message) {
        super(message);
    }
}

class RetailItem {
    String description;
    int unitsOnHand;
    double price;

    RetailItem(String description, int unitsOnHand, double price) throws NegativeCountError, NegativePriceError {
        this.description = description;
        if (unitsOnHand < 0) {
            throw new NegativeCountError("Count cannot be negative");
        }
        this.unitsOnHand = unitsOnHand;
        if (price < 0) {
            throw new NegativePriceError("Price cannot be negative");
        }
        this.price = price;
    }

    // Mutator methods
    public void setDescription(String description) {
        this.description = description;
    }

    public void setUnitsOnHand(int unitsOnHand) throws NegativeCountError {
        if (unitsOnHand < 0) {
            throw new NegativeCountError("Count cannot be negative");
        }
        this.unitsOnHand = unitsOnHand;
    }

    public void setPrice(double price) throws NegativePriceError {
        if (price < 0) {
            throw new NegativePriceError("Count cannot be negative");
        }
        this.price = price;
    }

    // Accessor methods
    public String getDescription() {
        return description;
    }

    public int getUnitsOnHand() {
        return unitsOnHand;
    }

    public double getPrice() {
        return price;
    }
}

public class q6 {
    public static void main(String[] args) throws NegativeCountError, NegativePriceError {
        RetailItem item1 = new RetailItem("Item #1 Jacket", 12, 59.95);
        RetailItem item2 = new RetailItem("Item #2 Designer Jeans", -40, 34.95);
        RetailItem item3 = new RetailItem("Item #3 Shirt", 20, 24.95);

        System.out.println("Description\t\t\tUnits On Hand\t\t\tPrice");
        System.out.println(item1.getDescription() + "\t\t\t" + item1.getUnitsOnHand() + "\t\t\t\t" + item1.getPrice());
        System.out.println(item2.getDescription() + "\t\t" + item2.getUnitsOnHand() + "\t\t\t\t" + item2.getPrice());
        System.out.println(item3.getDescription() + "\t\t\t" + item3.getUnitsOnHand() + "\t\t\t\t" + item3.getPrice());
    }
}