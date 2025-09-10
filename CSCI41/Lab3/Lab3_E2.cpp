#include <iostream>
#include <cmath> // For sqrt function

using namespace std;

// Define the Point3D struct
struct Point3D
{
    double x, y, z;

    // Function to calculate the distance between two points
    double Distance(const Point3D &other) const
    {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2) + pow(other.z - z, 2));
    }

    // Function to calculate the distance from the origin (0,0,0)
    double DistanceFromOrigin() const
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    // Function to add two points
    Point3D Add(const Point3D &other) const
    {
        return Point3D{x + other.x, y + other.y, z + other.z};
    }

    // Function to subtract two points
    Point3D Subtract(const Point3D &other) const
    {
        return Point3D{x - other.x, y - other.y, z - other.z};
    }
};

// Main function to test the struct
int main()
{
    // Define two points in 3D space
    Point3D p1 = {1, 2, 3};
    Point3D p2 = {4, 5, 6};

    // Compute and display distances
    cout << "Distance between p1 and p2: " << p1.Distance(p2) << endl;
    cout << "Distance of p1 from origin: " << p1.DistanceFromOrigin() << endl;

    // Add two points
    Point3D sum = p1.Add(p2);
    cout << "Sum of p1 and p2: (" << sum.x << ", " << sum.y << ", " << sum.z << ")" << endl;

    // Subtract two points
    Point3D diff = p1.Subtract(p2);
    cout << "Difference of p1 and p2: (" << diff.x << ", " << diff.y << ", " << diff.z << ")" << endl;

    return 0;
}
