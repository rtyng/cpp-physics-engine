/*
core.hpp

Basic math types for the physics engine

Vec3 represents a 3D vector using double precision. It is used for 
positions, velocities, accelerations, forces, and directions.

Design notes:
- No padding component
- Currently no quarternion integration
- Methods ending with "operator+=" or "normalize" modify the object.
- Methods like operator+ and unit() return a new Vec3
*/
#pragma once 

#include <cmath>


/*
Vec3 Represents a 3D vector

This class only stores x, y, and z components. Millington's padding value is not included to favor clarity over performance. 
After future testing, the padding value could be implemented for memory-alignment optimization.

Used for:
- position
- velocity
- acceleration
- force 
- vector normalization through v = |v|*vbar
*/
class Vec3{

    public:
    // Define x, y, and z as doubles and uses {} to default to zero
    double x{};
    double y{};
    double z{};

    // Generate the default constructor
    Vec3() = default;

    // Use a explicit constructor to create a custom vector with given components
    // : -> member initializer list initializes x, y, and z before the constructor body runs
    explicit Vec3(double xValue, double yValue, double zValue)
        : x{xValue}, y{yValue}, z{zValue} {}

    
    /*
    Create the ability for the class to add, subtract, and multiply other vectors

    Allows user to write Vec3 c = a + b or Vec3 c = a - b
    (const Vec3& other) -> recieve another vector by reference, and don't modify it
    final const -> this function promises not to modify the current object
    */
    Vec3 operator+(const Vec3& other) const {
        return Vec3{x + other.x, y + other.y, z + other.z};
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3{x - other.x, y - other.y, z - other.z};
    }

    // Allows Vec3 larger = velocity * 10.0; for example
    Vec3 operator*(double scalar) const {
        return Vec3{x * scalar, y * scalar, z * scalar};
    }

    // Modifications of current vector instead of returning a new one
    void operator+=(const Vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    void operator-=(const Vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    void operator*=(double scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }


    /*
    using v = vbar*vmag aka a vector can be broken down into it's magnitude and direction
    in other words vbar (direction) = v / vmag (vector divided by magnitude of the vector)
    */

    /*
    magnitude() and squareMagnitude() modify vectors in place
    */
    double magnitude() const{
        return std::sqrt(x * x + y * y + z * z);
    }

    double squareMagnitude() const{
        return x*x+y*y+z*z;
    }
    
    // Change current vector into a unit vector with the same direction and length of 1
    void normalize() {
        double length = magnitude();

        // Avoids division by zero and uses a pointer to the current vector to turn it into a unit vector
        if (length > 0.0) {
            (*this) *= 1.0 / length;
        }
    }

    /*
    Return a normalized copy without changing the original vector
    */
    Vec3 unit() const {
        Vec3 result = *this;
        result.normalize();
        return result;
    }

    // Reset the vector
    void clear() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

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
    This method is for numerical integrations
    It allows 
    position.addScaledVector(velocity, dt); -> position = position + velocity * dt;
    */
    void addScaledVector(const Vec3& vector, double scale) {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
    }
};
