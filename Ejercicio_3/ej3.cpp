#include "ej3.hpp"
#include <iostream>

using namespace std;

Entero::Entero(int v) : valor(v) {}

int Entero::getValor() const {
    return valor;
}

Numero* Entero::suma(const Numero* otro) const {
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (!e)
        throw invalid_argument("Tipo incompatible en suma (Entero).");
    return new Entero(valor + e->valor);
}

Numero* Entero::resta(const Numero* otro) const {
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (!e)
        throw invalid_argument("Tipo incompatible en resta (Entero).");
    return new Entero(valor - e->valor);
}

Numero* Entero::multiplicacion(const Numero* otro) const {
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (!e)
        throw invalid_argument("Tipo incompatible en multiplicacion (Entero).");
    return new Entero(valor * e->valor);
}

Numero* Entero::division(const Numero* otro) const {
    const Entero* e = dynamic_cast<const Entero*>(otro);
    if (!e)
        throw invalid_argument("Tipo incompatible en division (Entero).");
    if (e->valor == 0)
        throw runtime_error("Division por cero en Entero.");
    return new Entero(valor / e->valor);
}

string Entero::toString() const {
    return to_string(valor);
}

Real::Real(double v) : valor(v) {}

double Real::getValor() const {
    return valor;
}

Numero* Real::suma(const Numero* otro) const {
    const Real* r = dynamic_cast<const Real*>(otro);
    if (!r)
        throw invalid_argument("Tipo incompatible en suma (Real).");
    return new Real(valor + r->valor);
}

Numero* Real::resta(const Numero* otro) const {
    const Real* r = dynamic_cast<const Real*>(otro);
    if (!r)
        throw invalid_argument("Tipo incompatible en resta (Real).");
    return new Real(valor - r->valor);
}

Numero* Real::multiplicacion(const Numero* otro) const {
    const Real* r = dynamic_cast<const Real*>(otro);
    if (!r)
        throw invalid_argument("Tipo incompatible en multiplicacion (Real).");
    return new Real(valor * r->valor);
}

Numero* Real::division(const Numero* otro) const {
    const Real* r = dynamic_cast<const Real*>(otro);
    if (!r)
        throw invalid_argument("Tipo incompatible en division (Real).");
    if (r->valor == 0.0)
        throw runtime_error("Division por cero en Real.");
    return new Real(valor / r->valor);
}

string Real::toString() const {
    ostringstream oss;
    oss << valor;
    return oss.str();
}

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

double Complejo::getReal() const {
    return real;
}

double Complejo::getImaginario() const {
    return imaginario;
}

Numero* Complejo::suma(const Numero* otro) const {
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (!c)
        throw invalid_argument("Tipo incompatible en suma (Complejo).");
    return new Complejo(real + c->real, imaginario + c->imaginario);
}

Numero* Complejo::resta(const Numero* otro) const {
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (!c)
        throw invalid_argument("Tipo incompatible en resta (Complejo).");
    return new Complejo(real - c->real, imaginario - c->imaginario);
}

Numero* Complejo::multiplicacion(const Numero* otro) const {
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (!c)
        throw invalid_argument("Tipo incompatible en multiplicacion (Complejo).");

    double r = real * c->real - imaginario * c->imaginario;
    double i = real * c->imaginario + imaginario * c->real;
    return new Complejo(r, i);
}

Numero* Complejo::division(const Numero* otro) const {
    const Complejo* c = dynamic_cast<const Complejo*>(otro);
    if (!c)
        throw invalid_argument("Tipo incompatible en division (Complejo).");
    double denom = c->real * c->real + c->imaginario * c->imaginario;
    if (denom == 0)
        throw runtime_error("Division por cero en Complejo.");

    double r = (real * c->real + imaginario * c->imaginario) / denom;
    double i = (imaginario * c->real - real * c->imaginario) / denom;
    return new Complejo(r, i);
}

string Complejo::toString() const {
    ostringstream oss;
    oss << real;
    if (imaginario >= 0)
        oss << " + " << imaginario << "i";
    else
        oss << " - " << abs(imaginario) << "i";
    return oss.str();
}

int main() {
    try {
        Entero e1(10), e2(3);
        Numero* sumaE = e1.suma(&e2);
        Numero* restaE = e1.resta(&e2);
        Numero* multE = e1.multiplicacion(&e2);
        Numero* divE = e1.division(&e2);
        cout << "Enteros:" << endl;
        cout << e1.toString() << " + " << e2.toString() << " = " << sumaE->toString() << endl;
        cout << e1.toString() << " - " << e2.toString() << " = " << restaE->toString() << endl;
        cout << e1.toString() << " * " << e2.toString() << " = " << multE->toString() << endl;
        cout << e1.toString() << " / " << e2.toString() << " = " << divE->toString() << endl;
        delete sumaE; delete restaE; delete multE; delete divE;

        Real r1(10.5), r2(3.2);
        Numero* sumaR = r1.suma(&r2);
        Numero* restaR = r1.resta(&r2);
        Numero* multR = r1.multiplicacion(&r2);
        Numero* divR = r1.division(&r2);
        cout << "\nReales:" << endl;
        cout << r1.toString() << " + " << r2.toString() << " = " << sumaR->toString() << endl;
        cout << r1.toString() << " - " << r2.toString() << " = " << restaR->toString() << endl;
        cout << r1.toString() << " * " << r2.toString() << " = " << multR->toString() << endl;
        cout << r1.toString() << " / " << r2.toString() << " = " << divR->toString() << endl;
        delete sumaR; delete restaR; delete multR; delete divR;

        Complejo c1(2.0, 3.0), c2(1.0, -4.0);
        Numero* sumaC = c1.suma(&c2);
        Numero* restaC = c1.resta(&c2);
        Numero* multC = c1.multiplicacion(&c2);
        Numero* divC = c1.division(&c2);
        cout << "\nComplejos:" << endl;
        cout << c1.toString() << " + " << c2.toString() << " = " << sumaC->toString() << endl;
        cout << c1.toString() << " - " << c2.toString() << " = " << restaC->toString() << endl;
        cout << c1.toString() << " * " << c2.toString() << " = " << multC->toString() << endl;
        cout << c1.toString() << " / " << c2.toString() << " = " << divC->toString() << endl;
        delete sumaC; delete restaC; delete multC; delete divC;

    } catch (exception &ex) {
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
