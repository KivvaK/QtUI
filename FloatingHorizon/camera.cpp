#include "camera.h"

#include <cmath>

float Camera::xReal(float xScreen) const {
    return (xScreen - halfW) * sx / cos(gamma()) - planeY * tan(gamma());
}

float Camera::yScreen(float zReal) const {
    return halfH + (planeY * sin(alpha()) - zReal * cos(alpha())) / sy;
}

void Camera::rotateX(int steps) {
    aSteps += steps;
}

void Camera::rotateZ(int steps) {
    gSteps += steps;
}

bool Camera::inverseYPlaneOrder(float yMin, float yMax) {
    float y = R * cos(alpha()) * cos(gamma());
    return fabs(y - yMin) < fabs(y - yMax);
}
