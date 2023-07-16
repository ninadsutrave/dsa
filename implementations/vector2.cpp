// implement dot product and cross product
#include <iostream>

using namespace std;

template <typename T>
class Vector {
    private:
    T xComponent;
    T yComponent;
    T zComponent;

    public:
    Vector() {
        xComponent = yComponent = zComponent = 0;
    }

    Vector(T xComponent, T yComponent, T zComponent) {
        this->xComponent = xComponent;
        this->yComponent = yComponent;
        this->zComponent = zComponent;
    }

    ~Vector() {

    }

    T getX() {
        return xComponent;
    }

    T getY() {
        return yComponent;
    }

    T getZ() {
        return zComponent;
    }

    T getMagnitude() {
        return sqrt(  xComponent * xComponent  
                    + yComponent * yComponent  
                    + zComponent * zComponent );
    }

    Vector getUnitVector() {

        Vector unitVector;
        T magnitude = getMagnitude();

        unitVector.xComponent = xComponent/magnitude;
        unitVector.yComponent = yComponent/magnitude;
        unitVector.zComponent = zComponent/magnitude; 

        return unitVector;       

    }

    Vector operator+(Vector v) {

        Vector resultant;
        resultant.xComponent = xComponent + v.xComponent;
        resultant.yComponent = yComponent + v.yComponent;
        resultant.zComponent = zComponent + v.zComponent;
        return resultant;

    }

    Vector operator-(Vector v) {

        Vector resultant;
        resultant.xComponent = xComponent - v.xComponent;
        resultant.yComponent = yComponent - v.yComponent;
        resultant.zComponent = zComponent - v.zComponent;
        return resultant;

    }

    Vector operator*(T value) {

        Vector resultant;
        resultant.xComponent = xComponent * value;
        resultant.yComponent = yComponent * value;
        resultant.zComponent = zComponent * value;
        return resultant;

    }

    Vector operator*(Vector v) {

        Vector vectorProduct;
        vectorProduct.xComponent = (yComponent * v.zComponent - zComponent * v.yComponent);
        vectorProduct.yComponent = (zComponent * v.xComponent - xComponent * v.zComponent);
        vectorProduct.zComponent = (xComponent * v.yComponent - yComponent * v.xComponent);
        return vectorProduct;

    }

    T operator,(Vector v) {

        T scalarProduct;
        scalarProduct =  xComponent * v.xComponent +  yComponent * v.yComponent + zComponent * v.zComponent;
        return scalarProduct;

    }

};

int main() {

    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    Vector v3 =  v1 + v2;
    Vector v4 =  v2 - v1;
    Vector v5 =  v1 * 2.0;
    Vector v6 =  v1 * v2;
    double v7 = (v1 , v2);

    cout<<"v1: "<<v1.getX()<<" "<<v1.getY()<<" "<<v1.getZ()<<"\n";
    cout<<"v2: "<<v2.getX()<<" "<<v2.getY()<<" "<<v2.getZ()<<"\n";
    cout<<"v3: "<<v3.getX()<<" "<<v3.getY()<<" "<<v3.getZ()<<"\n";
    cout<<"v4: "<<v4.getX()<<" "<<v4.getY()<<" "<<v4.getZ()<<"\n";
    cout<<"v5: "<<v5.getX()<<" "<<v5.getY()<<" "<<v5.getZ()<<"\n";
    cout<<"v6: "<<v6.getX()<<" "<<v6.getY()<<" "<<v6.getZ()<<"\n";
    cout<<"v7: "<<v7;

    return 0;

}