/*
core.hpp

Basic math types for the physics engine

Vec3 represents a 3D vector using double precision. It is used for 
positions, velocities, accelerations, forces, and directions.

Design notes:
- No padding component currently
- Methods ending with "operator+=" or "normalize" modify the object.
- Methods like operator+ and unit() return a new Vec3
- Quaternions added for rendering, and eventually axial tilt and rigid body torque

Key Design Difference:
- Millington's integration implementation doesn't easily translate to Fourth-Order Runge-Kutta (RK4)
- I need an n-body force calculation, not Millington's per-body ForceGenerator
    - Gravity in an n-body simulation is coupled across all bodies
        - RK4 will need to evaluate that coupled system at intermediate points in time

*/
#pragma once 

#include <cmath>


/*
*Vec3 Represents a 3D vector

This class only stores x, y, and z components. Millington's padding value is currently not included.

Used for:
- position
- velocity
- acceleration
- force 
- vector normalization through v = |v|*vbar
*/
class Vec3{

    public:
    /*
    *Define x, y, and z as doubles and use {} to default to zero

    *Future uses/purpose:
        - Doubles will be necessary for consistent reduction of error during the simulations and rendering processes. 
        - It should also help with RK4. If need be they can be easily changed after testing
    */
    double x{};
    double y{};
    double z{};

    /*
    *Generate the default constructor 
    *Member function for the user to create their own custom Vec3

    *Future uses/purpose:
        - Necessary for future testing and simulation purposes, explicit keyword should keep compiler from trying to change Vec3 to another type
    */ 
    Vec3() = default;
    explicit Vec3(double xValue, double yValue, double zValue)
        : x{xValue}, y{yValue}, z{zValue} {}

    
    /*
    *Member functions for the class to add and subtract other vectors
    
    *Future uses/purpose:
        - operator overload, const, &, are for optimization purposes
        - other Vec3 won't be copied, both const are promises not to modify other Vec3 or original Vec3
    */
    Vec3 operator+(const Vec3& other) const {
        return Vec3{x + other.x, y + other.y, z + other.z};
    }
    Vec3 operator-(const Vec3& other) const {
        return Vec3{x - other.x, y - other.y, z - other.z};
    }


    /*
    *Member function for scalar multiplication

    *Future uses/purpose:
        - Allows Vec3 larger = velocity * 10.0; for example
        - Same idea as the vector addition and subtraction implementation
    */
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
    *magnitude() and squareMagnitude() modify vectors in place

    *Future uses/promise:
        - 
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

    Returns nothing; member function for manipulation of a vector in place 

    It allows position.addScaledVector(velocity, dt); -> position = position + velocity * dt;
    */
    void addScaledVector(const Vec3& vector, double scale) {
        x += vector.x * scale;
        y += vector.y * scale;
        z += vector.z * scale;
    }
};

/*
*class Quarternion represents Quarternion objects, which will be used in the simulation for planetary rotations, axial tilts, etc. 

A Quarternion is a four-part hyper-complex number used in 3d rotations and orientations. Represented in the form a + bi + cj + dk where 
a, b, c, d are real numbers. i, j, k are the basis elements which satisfy the equation: i^2 = j^2 = k^2 = -1

Quarternion math is not commutative:
    - ij = -ji = k
    - jk = -kl = i
    - ki = -ik = j

Similar to 3d vectors can be broken down into their magnitude and direction, Quarternions can also be broken down into their angle of rotation theta, and their axis of rotation

Example: A unit quarternion designed to rotate a point is typically written mathematically as:

q = cos(theta/2) + sin(theta/2)*(xi + yj + zk)

references:
https://www.mathworks.com/help/aerotbx/ug/quaternion.html
https://mathworld.wolfram.com/Quaternion.html
Chapter 9.2.4: Quarternions from Millington
*/


class Quarternion{
    public:
        // Same declarations as the Vec3 class above, just declaring r to 1 instead of 0
        double r{1}, i{}, j{}, k{};

        // default to zero, then allow user to explicitly declare a Quarternion object
        Quarternion() = default;
        explicit Quarternion(double r_, double i_, double j_, double k_)
            : r{r_}, i{i_}, j{j_}, k{k_} {}
        
        // quarternion normalization follows the same idea as vector normalization
        void normalize() {
            double d = r*r + i*i + j*j + k*k;
            if (d == 0) { r = 1.0; return; }
            double invMag = 1.0 / std::sqrt(d);
            r *= invMag; i *= invMag; j *= invMag; k *= invMag;
        }

        // Add in Hamilton Product to compose rotations 


        // Add in the quarternion version of addScaledVector






};
