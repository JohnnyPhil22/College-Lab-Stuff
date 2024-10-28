// Design a class that has a static method named writeArray. The method should take two arguments: the name of a file and a reference to an int array. The file should be opened as a binary file, the contents of the array should be written to the file, and then the file should be closed. Write a second method in the class named readArray. The method should take two arguments: the name of a file and a reference to an int array. The file should be opened, data should be read from the file and stored in the array, and then the file should be closed. Demonstrate both methods in a program.
import java.io.*;

class ArrFuncs {
    public static void writeArray(String filename, int[] arr) {
        try (DataOutputStream output = new DataOutputStream(new FileOutputStream(filename))) {
            for (int num : arr) {
                output.writeInt(num);
            }
            output.close();
            System.out.println("Array written to file");
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }

    public static void readArray(String filename, int[] arr) {
        try (DataInputStream input = new DataInputStream(new FileInputStream(filename))) {
            for (int i = 0; i < arr.length; i++) {
                arr[i] = input.readInt();
            }
            System.out.println("Array read from file:");
        } catch (FileNotFoundException e) {
            System.out.println(e.toString());
        } catch (IOException e) {
            System.out.println(e.toString());
        }
    }
}

public class q7 {
    public static void main(String[] args) {
        String file = "C:\\Users\\Jonathan Philips\\Coding\\College-Lab-Stuff\\Sem 3\\OOPS\\Assignment 8\\Question 7\\data.bin";

        int[] writeArray = { 10, 20, 30, 40, 50 };
        ArrFuncs.writeArray(file, writeArray);

        int[] readArray = new int[writeArray.length];
        ArrFuncs.readArray(file, readArray);
        for (int num : readArray) {
            System.out.print(num + " ");
        }
    }
}