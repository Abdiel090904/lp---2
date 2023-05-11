#include <iostream>
using namespace std;

class circulo{
    double radio, diametro;
    public:
    circulo(int d){
        radio = d/2;
        diametro = d;
    }
    void SetDiametro(double d){
        diametro = d;
    }
    void SetRadio(double r){
        radio = r;
    }

    double GetDiametro(){
        return diametro;
    }
    double GetRadio(){
        return radio;
    }
};
double Calculate(circulo & C){
    return (C.GetRadio() * C.GetRadio()) * 3.1416
}   