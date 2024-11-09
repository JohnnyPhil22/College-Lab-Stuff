// Write a simple form which takes input from the user and display the student details.
import java.util.*;
import java.sql.*;

public class q1 {
    private static final String URL = "jdbc:mysql://localhost:3306/student_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "JohnnyPhil22";

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            Scanner s = new Scanner(System.in);
            System.out.print("Enter your name: ");
            String name = s.nextLine();
            System.out.print("Enter your age: ");
            int age = s.nextInt();
            System.out.print("Enter your grade: ");
            double grade = s.nextDouble();

            PreparedStatement pstmt = conn.prepareStatement("INSERT INTO students (name, age, grade) VALUES (?, ?, ?)");
            pstmt.setString(1, name);
            pstmt.setInt(2, age);
            pstmt.setDouble(3, grade);
            pstmt.executeUpdate();
            System.out.println("Data stored successfully!");

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM students");
            System.out.println("\nAll Student Details:");
            while (rs.next()) {
                System.out.println("Name: " + rs.getString("name"));
                System.out.println("Age: " + rs.getInt("age"));
                System.out.println("Grade: " + rs.getDouble("grade"));
                System.out.println();
            }

            rs.close();
            stmt.close();
            pstmt.close();
            conn.close();
            s.close();
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Database connection error!");
            e.printStackTrace();
        }
    }
}