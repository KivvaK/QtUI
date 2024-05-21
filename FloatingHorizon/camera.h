#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
private:
    float dA, dG, aInitial, gInitial;
    float sx, sy;
    float xmin0, xmax0, zmin0, zmax0;
    float halfW, halfH;
    float R, planeY = 0.f;

    int aSteps = 0, gSteps = 0;
public:
    Camera(float screenW, float screenH,
           float xmin0, float xmax0, float zmin0, float zmax0,
           float R, float dAlpha, float dGamma,
           float aInitial = 0.f, float gInitial = 0.f) :
        xmin0(xmin0), xmax0(xmax0), zmin0(zmin0), zmax0(zmax0),
        halfW(0.5 * screenW), halfH(0.5 * screenH),
        R(R), dA(dAlpha), dG(dGamma),
        aInitial(aInitial), gInitial(gInitial)
    {
        sx = calcSx(xmin0, xmax0, screenW);
        sy = calcSy(zmin0, zmax0, screenH);
    }

    float xReal(float xScreen) const;
    float yScreen(float zReal) const;
    void rotateX(int steps = 1);
    void rotateZ(int steps = 1);
    bool inverseYPlaneOrder(float yMin, float yMax);

    float alpha() const { return aInitial + aSteps * dA; }
    float gamma() const { return gInitial + gSteps * dG; }

    void setScreenW(float screenW) {
        halfW = 0.5 * screenW;
        sx = calcSx(xmin0, xmax0, screenW);
    }

    void setScreenH(float screenH) {
        halfH = 0.5 * screenH;
        sy = calcSy(zmin0, zmax0, screenH);
    }

    void setXMin(float xmin) {
        xmin0 = xmin;
        sx = calcSx(xmin0, xmax0, 2 * halfW);
    }

    void setXMax(float xmax) {
        xmax0 = xmax;
        sx = calcSx(xmin0, xmax0, 2 * halfW);
    }

    void setZMin(float zmin) {
        zmin0 = zmin;
        sy = calcSy(zmin0, zmax0, 2 * halfH);
    }

    void setZMax(float zmax) {
        zmax0 = zmax;
        sy = calcSy(zmin0, zmax0, 2 * halfH);
    }

    void setPlaneY(float planeY) {
        this->planeY = planeY;
    }

private:
    static float calcSx(float xmin0, float xmax0, float screenW) {
        return (xmax0 - xmin0) / screenW;
    }

    static float calcSy(float zmin0, float zmax0, float screenH) {
        return (zmax0 - zmin0) / screenH;
    }
};

#endif // CAMERA_H
