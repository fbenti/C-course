#ifndef __v2d__
#define __v2d__

template<class T>
class v2d {
    public:
        // Standard constructor: builds a vector (a,b)
        v2d(T a, T b);

        // Copy constructor: builds a vector that is exactly as v
        v2d(const v2d &v);

        // Destructor
        ~v2d(void);

        // Assignment operator: updates the vector to make it as v
        v2d & operator=(const v2d &v);

        // Vector addition: updates the vector by adding v
        v2d & operator+(const v2d &v);

        // Scalar multiplication: updates the vector by scaling by k
        v2d & operator*(double k);

        // Scalar product of the current vector by another vector v 
        T operator*(const v2d &v);

        // Returns the length of a vector
        double length(void);

    private: 
        // Internal representation of a vector with just two doubles x and y
        T x;
        T y;
};

#include "vector2d.hpp"


#endif

