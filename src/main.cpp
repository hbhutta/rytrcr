#include <iostream>
#include <vector.hpp>
#include <ray.hpp>

/**
 * Determine if the ray originating from the camera,
 * and going through this pixel, intersects some part of 
 * the object being viewed. 
 * If there is an intersection, color this pixel the color
 * of the object at the intersection.
 * Otherwise, do nothing.
*/
void raytrace(Ray& ray, Point3& pixel) {
    
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
            raytrace(ray, pixel);

            std::cout << "pixel_color" << std::flush;
        }
    }
}

/**
 * Creates a ray between the camera position, and a pixel.
 * 
*/
Ray createRay(Point3& cameraPosition, Point3& pixelPosition) {

}

int main() {
    int width = 400;
    int height = 400;
    double distanceFromCameraAlongZ = 100.0;
    Vector3 cameraPosition = Point3(50.0, 50.0, 0.0);
    createScene(width, height, distanceFromCameraAlongZ, cameraPosition);
    return 0;
}
