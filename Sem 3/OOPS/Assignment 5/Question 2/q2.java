// Q2: Student details class with address class as child class
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

public class q2 {
    public static void main(String[] args) {
        address address1 = new address("Jonathan", 20233525, "Vijay", "Prayagraj", "Chennai", 9129590905L,
                "jonathan.20233525@mnnit.ac.in");
        System.out.println(address1.print_deets());
    }
}
