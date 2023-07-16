#include <iostream>

using namespace std;

template <typename T>
class Complex {
    private:
    T real;
    T imaginary;

    public:
    Complex() {
        real = imaginary = 0;
    }

    Complex(T real, T imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    ~Complex() {

    }

    T getReal() {
        return real;
    }

    T getImaginary() {
        return imaginary;
    }

    T getMagnitude() {
        return sqrt(  real*real + imaginary*imaginary );
    }

    Complex operator+(T value) {

        Complex sum;
        sum.real = real + value;
        sum.imaginary = imaginary;
        return sum;

    }

    Complex operator+(Complex c) {

        Complex sum;
        sum.real = real + c.real;
        sum.imaginary = imaginary + c.imaginary;
        return sum;

    }

    Complex operator-(T value) {

        Complex difference;
        difference.real = real - value;
        difference.imaginary = imaginary;
        return difference;

    }

    Complex operator-(Complex c) {

        Complex difference;
        difference.real = real - c.real;
        difference.imaginary = imaginary - c.imaginary;
        return difference;

    }

    Complex operator*(T value) {

        Complex product;
        product.real = real * value;
        product.imaginary = imaginary * value;
        return product;

    }

    Complex operator*(Complex c) {

        Complex product;
        product.real = (real * c.real - imaginary * c.imaginary);
        product.imaginary = (imaginary * c.real + c.imaginary * real);
        return product;

    }

    Complex operator/(T value) {

        Complex quotient;
        quotient.real = real/value;
        quotient.imaginary = imaginary/value;
        return quotient;

    }

    Complex operator/(Complex c) {

        Complex quotient;
        T abs = c.getMagnitude() * c.getMagnitude();
        quotient.real = (real * c.real + imaginary * c.imaginary)/abs;
        quotient.imaginary = (imaginary * c.real - c.imaginary * real)/abs;
        return quotient;

    }

    Complex operator~() {
        Complex conjugate;
        conjugate.real = real;
        conjugate.imaginary = -imaginary;
        return conjugate;
    }

    double arg() {
        return atan2(imaginary, real);
    }

};

int main() {

    Complex c1(1.0, 2.0);
    Complex c2(4.0, 5.0);

    Complex c3 =  c1 + c2;
    Complex c4 =  c2 - c1;
    Complex c5 =  c1 * 2.0;
    Complex c6 =  c1 * c2;
    Complex c7 = c1 / c2;
    Complex c8 = ~c2;
    double arg = c2.arg();

    cout<<"c1: "<<c1.getReal()<<" "<<c1.getImaginary()<<"\n";
    cout<<"c2: "<<c2.getReal()<<" "<<c2.getImaginary()<<"\n";
    cout<<"c3: "<<c3.getReal()<<" "<<c3.getImaginary()<<"\n";
    cout<<"c4: "<<c4.getReal()<<" "<<c4.getImaginary()<<"\n";
    cout<<"c5: "<<c5.getReal()<<" "<<c5.getImaginary()<<"\n";
    cout<<"c6: "<<c6.getReal()<<" "<<c6.getImaginary()<<"\n";
    cout<<"c7: "<<c7.getReal()<<" "<<c7.getImaginary()<<"\n";
    cout<<"c8: "<<c8.getReal()<<" "<<c8.getImaginary()<<"\n";
    cout<<arg<<"\n";

    return 0;

}