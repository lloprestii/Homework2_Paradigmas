#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    double balance;
    string titularCuenta;

protected:
    double getBalance() const;
    void setBalance(double nuevoBalance);
    const string& getTitularCuenta() const;

public:
    CuentaBancaria(double balance, const string& titular);
    virtual ~CuentaBancaria() = default;

    virtual void depositar(double cantidad);
    virtual double retirar(double cantidad);
    virtual void mostrarInfo();
};

class CuentaCorriente;

class CajaDeAhorro : public CuentaBancaria {
private:
    int contadorMostrar;

public:
    CajaDeAhorro(double balance, const string& titular);

    double retirar(double cantidad) override;

    void mostrarInfo() override;

    friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBancaria {
private:
    CajaDeAhorro* cajaAhorro;

public:
    CuentaCorriente(double balance, const string& titular, CajaDeAhorro* caja = nullptr);

    double retirar(double cantidad) override;

    void mostrarInfo() override;
};

