#include <iostream>
#include <string>
using namespace std;

/* 
  Explicacion de los especificadores de acceso:
  - Los atributos de las clases se declaran como private para asegurar el encapsulamiento y proteger el estado interno.
  - Se tienen metodos publicos para que el usuario interactue con la cuenta (depositar, retirar, mostrarInfo).
  - Se utilizan metodos protegidos en la clase base para permitir a las clases derivadas acceder y modificar el estado sin exponerlo externamente.
  - En CajaDeAhorro se declara a CuentaCorriente como friend, permitiendo que esta pueda acceder a los miembros privados necesarios (por ejemplo, el balance) para realizar la operacion de retiro complementario.
*/
class CuentaBancaria {
private:
    double balance;
    string titularCuenta;

public:
    CuentaBancaria(double balance, const string& titular): balance(balance), titularCuenta(titular) {};

    virtual void depositar(double cantidad) {
        if (cantidad <= 0) {
            cout << "La cantidad a depositar debe ser mayor que cero." << endl;
            return;
        }
        cout << "Depositando " << cantidad << " a la cuenta de " << titularCuenta << endl;
        balance += cantidad;
        cout << "Nuevo balance: " << balance << endl;
    }

    virtual double retirar(double cantidad) {
        if (cantidad <= 0) {
            cout << "La cantidad a retirar debe ser mayor que cero." << endl;
            return 0;
        }
        if (cantidad > balance) {
            cout << "Fondos insuficientes. No se puede retirar " << cantidad << endl;
            return 0;
        }
        cout << "Retirando " << cantidad << " de la cuenta de " << titularCuenta << endl;
        balance -= cantidad;
        cout << "Nuevo balance: " << balance << endl;
        return cantidad;
    }

    virtual void mostrarInfo() {
        cout << "Titular de la cuenta: " << titularCuenta << endl;
        cout << "Balance actual: " << balance << endl;
    }

protected:
    double getBalance() const { return balance; }
    void setBalance(double nuevoBalance) { balance = nuevoBalance; }
    const string& getTitularCuenta() const { return titularCuenta; }
};

class CajaDeAhorro : public CuentaBancaria {
private:
    int contadorMostrar;

public:
    CajaDeAhorro(double balance, const string& titular) : CuentaBancaria(balance, titular), contadorMostrar(0) {}

    double retirar(double cantidad) override {
        if (cantidad > getBalance()) {
            cout << "Fondos insuficientes en CajaDeAhorro. No se puede retirar " << cantidad << endl;
            return 0;
        }
        return CuentaBancaria::retirar(cantidad);
    }

    void mostrarInfo() override {
        contadorMostrar++;
        CuentaBancaria::mostrarInfo();
        if (contadorMostrar > 2) {
            double nuevoBalance = getBalance() - 20;
            setBalance(nuevoBalance);
            cout << "Se ha aplicado un cargo de $20. Nuevo balance: " << nuevoBalance << endl;
        }
    }
    friend class CuentaCorriente;
};

class CuentaCorriente : public CuentaBancaria {
private:
    CajaDeAhorro* cajaAhorro;

public:
    CuentaCorriente(double balance, const string& titular, CajaDeAhorro* caja = nullptr) : CuentaBancaria(balance, titular), cajaAhorro(caja) {}

    double retirar(double cantidad) override {
        if (cantidad <= 0) {
            cout << "La cantidad a retirar debe ser mayor que cero." << endl;
            return 0;
        }
        double saldoActual = getBalance();
        if (cantidad <= saldoActual) {
            return CuentaBancaria::retirar(cantidad);
        } else {
            double diferencia = cantidad - saldoActual;
            if (cajaAhorro != nullptr) {
                if (diferencia <= cajaAhorro->getBalance()) {
                    if (saldoActual > 0)
                        CuentaBancaria::retirar(saldoActual);
                    cout << "Retirando " << diferencia << " de la Caja de Ahorro asociada." << endl;
                    cajaAhorro->retirar(diferencia);
                    cout << "Total retirado: " << cantidad << endl;
                    return cantidad;
                } else {
                    cout << "La cuenta no posee dinero." << endl;
                    return 0;
                }
            } else {
                cout << "Fondos insuficientes y no hay Caja de Ahorro asociada." << endl;
                return 0;
            }
        }
    }

    void mostrarInfo() override {
        cout << "Cuenta Corriente de " << getTitularCuenta() << endl;
        cout << "Balance actual: " << getBalance() << endl;
        if (cajaAhorro != nullptr) {
            cout << "Informacion de la Caja de Ahorro asociada:" << endl;
            cajaAhorro->mostrarInfo();
        }
    }
};

int main() {
    cout << "Prueba CajaDeAhorro" << endl;
    CajaDeAhorro caja(100, "Juan Perez");
    caja.depositar(50);
    cout << "\nLlamada 1 a mostrarInfo():" << endl;
    caja.mostrarInfo();
    cout << "\nLlamada 2 a mostrarInfo():" << endl;
    caja.mostrarInfo();
    cout << "\nLlamada 3 a mostrarInfo():" << endl;
    caja.mostrarInfo();
    cout << "\nIntento de retirar $30:" << endl;
    caja.retirar(30);
    cout << "\nIntento de retirar $200:" << endl;
    caja.retirar(200);

    cout << "\nPrueba CuentaCorriente" << endl;
    CajaDeAhorro caja2(80, "Maria Lopez");
    CuentaCorriente cuentaCorriente(50, "Maria Lopez", &caja2);
    cuentaCorriente.depositar(20);
    cout << "\nIntento de retirar $90 (se requiere complementar con la Caja de Ahorro):" << endl;
    cuentaCorriente.retirar(90);
    cout << "\nIntento de retirar $100 (fondos insuficientes en ambas cuentas):" << endl;
    cuentaCorriente.retirar(100);

    return 0;
}
