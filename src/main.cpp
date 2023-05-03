#include <iostream>
#include <vector.hpp>
#include <ray.hpp>
#include <sphere.hpp>
#include <quadratic.hpp>

Sphere spheres[] = {
    Sphere(20.0, Point3(80, 50.4, 6)),
    Sphere(12.0, Point3(80, 60.4, 6)),
    Sphere(1.0, Point3(50, 50.4, 6)),
    Sphere(10.0, Point3(80, 80.4, 6))
};

/**
 * There are three possible cases:
 * 1. No intesection, 
 * 2. Single intersection (ray is tangent to sphere)
 * 3. Two intersections (ray forms a chord through sphere)
 * In case 3. pick the smaller of the two intersections
*/
double findIntersection(Ray& ray, Sphere& sphere) {
    // from https://gabrielgambetta.com/computer-graphics-from-scratch/02-basic-raytracing.html
    double a, b, c;
    double a = ray.direction.dot(ray.direction);
    double b = 1;
    double c = 1;
    Quadratic sphereIntersections = Quadratic(a,b,c);
}

/**
 * Determine if the ray originating from the camera,
 * and going through this pixel, intersects some part of 
 * the object being viewed. 
 * If there is an intersection, color this pixel the color
 * of the object at the intersection.
 * Otherwise, do nothing.
*/
Color raytrace(Ray& ray, Point3& pixel) {
    for (Sphere sphere : spheres) {
        findIntersection(ray, sphere);
    }
}

/**
 * Prints a scene (as a PPM image)
 * O(WIDTH*HEIGHT)
*/
void createScene(int width, int height, double distanceFromCameraAlongZ, Point3& cameraPosition) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Determine the color of this pixel, by ray tracing:

            Vector3 pixel = Point3(x, y, distanceFromCameraAlongZ);

            Ray ray = createRay(cameraPosition, pixel);
            Color pixelColor = raytrace(ray, pixel);
            double r = pixelColor.x;
            double g = pixelColor.y;
            double b = pixelColor.z;

            std::cout << r << std::endl;
            std::cout << g << std::endl;
            std::cout << b << std::endl;
        }
    }
}

/**
 * Creates a ray between the camera position, and a pixel.
 * 
*/
Ray createRay(Point3& cameraPosition, Point3& pixelPosition) {
    Vector3 direction = pixelPosition - cameraPosition;
    Point3 origin = cameraPosition;
    return Ray(direction, origin);
}

int main() {
    int width = 400;
    int height = 400;
    double distanceFromCameraAlongZ = 100.0;
    Vector3 cameraPosition = Point3(50.0, 50.0, 0.0);
    createScene(width, height, distanceFromCameraAlongZ, cameraPosition);
    return 0;
}
