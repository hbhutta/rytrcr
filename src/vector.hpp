#ifndef VECTOR_H
#define VECTOR_H

class Vector3 {
    public:
        Vector3() {}
        Vector3(double x_, double y_, double z_) : 
        x(x_), y(y_), z(z_) {}

    public: 
        double x, y, z;
};

using Point3 = Vector3;
using Color = Vector3;

#endif