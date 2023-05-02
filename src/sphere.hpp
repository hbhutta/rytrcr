#ifndef SPHERE_H
#define SPHERE_H

#include <vector.hpp>

class Sphere {
    public:
        Sphere() {}
        Sphere(double radius_, Point3 position_) :
        radius(radius_), position(position_) {}

    public:
        double radius;
        Point3 position;
};

#endif SPHERE_H