#include <string>
#include <stdexcept>
#include <sstream>
#include <cmath>

using namespace std;

class Numero {
public:
    virtual Numero* suma(const Numero* otro) const = 0;

    virtual Numero* resta(const Numero* otro) const = 0;

    virtual Numero* multiplicacion(const Numero* otro) const = 0;

    virtual Numero* division(const Numero* otro) const = 0;

    virtual string toString() const = 0;
};

class Entero : public Numero {
private:
    int valor;
public:
    Entero(int v);

    int getValor() const;

    Numero* suma(const Numero* otro) const override;

    Numero* resta(const Numero* otro) const override;

    Numero* multiplicacion(const Numero* otro) const override;

    Numero* division(const Numero* otro) const override;

    string toString() const override;
};

class Real : public Numero {
private:
    double valor;
public:
    Real(double v);

    double getValor() const;

    Numero* suma(const Numero* otro) const override;

    Numero* resta(const Numero* otro) const override;

    Numero* multiplicacion(const Numero* otro) const override;

    Numero* division(const Numero* otro) const override;

    string toString() const override;
};

class Complejo : public Numero {
private:
    double real;
    double imaginario;
public:
    Complejo(double r, double i);

    double getReal() const;

    double getImaginario() const;

    Numero* suma(const Numero* otro) const override;

    Numero* resta(const Numero* otro) const override;

    Numero* multiplicacion(const Numero* otro) const override;

    Numero* division(const Numero* otro) const override;

    string toString() const override;
};