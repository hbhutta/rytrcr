#ifndef RAY_H
#define RAY_H

#include <vector.hpp>

class Ray {
    public:
        Ray() {}
        Ray(Vector3 direction_, Point3 origin_) : 
        direction(direction_), origin(origin_) {}

    public:
        Vector3 direction;
        Point3 origin;
};

#endif