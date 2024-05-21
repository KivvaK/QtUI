#include <cmath>

float mhat(float x, float y) {
    float r2 = x * x + y * y;
    return (1 - r2) * exp(-r2 / 2);
}

float sinc(float x, float y) {
    float r = sqrt(x * x + y * y), z;

    if (r == 0)
        z = 1;
    else
        z = sin(M_PI * r) / (M_PI * r);
    return z;
}

float peaks(float x, float y) {
    float _1x = 1 - x, _1y = y + 1, x2 = x * x, y2 = y * y, y5 = y2 * y2 * y, _2x = x + 1;
    return 3 * _1x * _1x * exp(-x2 - _1y * _1y) -
           10 * (x / 5 - x2 * x - y5) * exp(-x2 - y2) -
           1. / 3 * exp(-_2x * _2x - y2);
}
