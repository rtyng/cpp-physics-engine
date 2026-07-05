#include <math.h>
#include "precision.hpp"


/*
Create the Vec3 class, ignore Millington's padding structure unless needed for future performance
*/
class Vec3{

    public:
    /*
    define x, y, and z coordinates for the Vec3 class
    */
    double x;
    double y;
    double z;

    // Use a default constructor to create a zero vector
    Vec3() = default;

    // Use a explicit constructor to create a vector with given components
    explicit Vec3(double xValue, double yValue, double zValue)
        : x{xValue}, y{yValue}, z{zValue} {}

    /*
    Keep Millington's inversion utility. 
    robably won't need it as much for a solar system sim
    */
    void invert() {
        x = -x;
        y = -y;
        z = -z;
    }


    /*
    using v = vbar*vmag aka a vector can be broken down into it's magnitude and direction
    in other words vbar (direction) = v / vmag (vector divided by magnitude of the vector)
    */

    // Get magnitude of a Vec3 object
    double magnitude() const{
        return double_sqrt(x*x+y*y+z*z);
    }

    // Get squared magnitude of a Vec3 object
    double squareMagnitude() const{
        return x*x+y*y+z*z;
    }
    
    // Normalize method: for now just copy from Millington
    void Normalize(){
        double l = magnitude();
        if (l > 0)
        {
            (*this)*=((double)1)/l;
        }
    }
};  