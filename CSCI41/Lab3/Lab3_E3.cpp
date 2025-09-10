#include <iostream>
#include <cmath> // For sqrt function

using namespace std;

class Point3D
{
private:
    double x, y, z; // Coordinates

public:
    // Default Constructor
    Point3D()
    {
        x = 0.0, y = 0.0, z = 0.0;
    }

    // Constructor with 3 values
    Point3D(double xVal, double yVal, double zVal)
    {
        x = xVal, y = yVal, z = zVal;
    }

    // Copy Constructor
    Point3D(const Point3D &other)
    {
        x = other.x, y = other.y, z = other.z;
    }

    // Accessor functions
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    double getZ() const
    {
        return z;
    }

    // Modifier functions
    void setX(double newX)
    {
        x = newX;
    }
    void setY(double newY)
    {
        y = newY;
    }
    void setZ(double newZ)
    {
        z = newZ;
    }

    // Distance between two points
    double Distance(const Point3D &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
    }

    // Distance from the origin (0, 0, 0)
    double DistanceFromOrigin() const
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    // Overload + operator to add two points
    Point3D operator+(const Point3D &other) const
    {
        return Point3D{x + other.x, y + other.y, z + other.z};
    }

    // Overload - operator to subtract two points
    Point3D operator-(const Point3D &other) const
    {
        return Point3D{x - other.x, y - other.y, z - other.z};
    }

    // Display function for convenience
    void Display() const
    {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

int main()
{
    // Testing the Point3D class

    // Using the default constructor
    Point3D pointA;
    cout << "Default point: ";
    pointA.Display();
    cout << endl;

    // Using the constructor with 3 values
    Point3D pointB(3.0, 4.0, 5.0);
    cout << "Point B: ";
    pointB.Display();
    cout << endl;

    // Using the copy constructor
    Point3D pointC(pointB);
    cout << "Copied point (Point C): ";
    pointC.Display();
    cout << endl;

    // Testing accessor and modifier functions
    pointA.setX(1.0);
    pointA.setY(2.0);
    pointA.setZ(3.0);
    cout << "Modified Point A: ";
    pointA.Display();
    cout << endl;

    // Distance calculations
    cout << "Distance between A and B: " << pointA.Distance(pointB) << endl;
    cout << "Distance from origin to B: " << pointB.DistanceFromOrigin() << endl;

    // Testing operator overloading
    Point3D sum = pointA + pointB;
    cout << "Sum of A and B: ";
    sum.Display();
    cout << endl;

    Point3D diff = pointA - pointB;
    cout << "Difference between A and B: ";
    diff.Display();
    cout << endl;

    return 0;
}
