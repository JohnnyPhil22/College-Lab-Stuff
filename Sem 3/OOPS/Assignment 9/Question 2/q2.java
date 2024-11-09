// Create a desktop application which behaves in a similar manner as the previous application.
import java.util.*;
import java.sql.*;

public class q2 {
    private static final String URL = "jdbc:mysql://localhost:3306/student_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "JohnnyPhil22";

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            Scanner s = new Scanner(System.in);
            while (true) {
                System.out.print("1. Enter details\n2. View details\n3. Exit\nEnter choice: ");
                int ch = s.nextInt();
                s.nextLine();

                switch (ch) {
                    case 1:
                        addStudent(conn, s);
                        break;
                    case 2:
                        viewStudentDeets(conn, s);
                        break;
                    case 3:
                        System.out.println("Exiting the application...");
                        conn.close();
                        return;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            }
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Database connection error!");
            e.printStackTrace();
        }
    }

    static void addStudent(Connection conn, Scanner sc) throws SQLException {
        System.out.print("Enter your name: ");
        String name = sc.nextLine();
        System.out.print("Enter your age: ");
        int age = sc.nextInt();
        System.out.print("Enter your grade: ");
        double grade = sc.nextDouble();
        sc.nextLine();

        PreparedStatement pstmt = conn.prepareStatement("INSERT INTO students (name, age, grade) VALUES (?, ?, ?)");
        pstmt.setString(1, name);
        pstmt.setInt(2, age);
        pstmt.setDouble(3, grade);
        pstmt.executeUpdate();

        System.out.println("Student data stored successfully!");
    }

    static void viewStudentDeets(Connection conn, Scanner sc) throws SQLException {
        System.out.print("Enter the student's name to search for: ");
        String searchName = sc.nextLine();

        PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM students WHERE name LIKE ?");
        pstmt.setString(1, "%" + searchName + "%");
        ResultSet rs = pstmt.executeQuery();

        boolean foundStudent = false;
        System.out.println("\nStudent Details:");
        while (rs.next()) {
            System.out.println("Name: " + rs.getString("name"));
            System.out.println("Age: " + rs.getInt("age"));
            System.out.println("Grade: " + rs.getDouble("grade"));
            System.out.println();
            foundStudent = true;
        }

        if (!foundStudent) {
            System.out.println("No student found with the name: " + searchName);
        }

        rs.close();
        pstmt.close();
    }
}