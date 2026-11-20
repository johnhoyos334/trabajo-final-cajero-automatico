#include <iostream>
using namespace std;

void consultarSaldo(double saldo);
double retirarDinero(double saldo, double retiro);
double consignarDinero(double saldo, double consignacion);
void tipoCuenta();

int main() {

    int opcion;
    double saldo = 1000000;
    double dinero;

    do {

        cout << "\n===== CAJERO AUTOMATICO =====" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Consignar dinero" << endl;
        cout << "4. Tipo de cuenta" << endl;
        cout << "5. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                consultarSaldo(saldo);
                break;

            case 2:
                cout << "Ingrese el valor a retirar: ";
                cin >> dinero;

                saldo = retirarDinero(saldo, dinero);
                break;

            case 3:
                cout << "Ingrese el valor a consignar: ";
                cin >> dinero;

                saldo = consignarDinero(saldo, dinero);
                break;

            case 4:
                tipoCuenta();
                break;

            case 5:
                cout << "Gracias por utilizar el cajero.";
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}

void consultarSaldo(double saldo) {

    cout << "Su saldo actual es: $" << saldo << endl;
}

double retirarDinero(double saldo, double retiro) {

    if (retiro <= 0) {
        cout << "Valor invalido." << endl;
    }
    else if (retiro > saldo) {
        cout << "Saldo insuficiente." << endl;
    }
    else {
        saldo = saldo - retiro;
        cout << "Retiro exitoso." << endl;
        cout << "Saldo restante: $" << saldo << endl;
    }

    return saldo;
}

double consignarDinero(double saldo, double consignacion) {

    if (consignacion <= 0) {
        cout << "Valor invalido." << endl;
    }
    else {
        saldo = saldo + consignacion;
        cout << "Consignacion exitosa." << endl;
        cout << "Nuevo saldo: $" << saldo << endl;
    }

    return saldo;
}

void tipoCuenta() {

    cout << "Tipo de cuenta: Ahorros" << endl;
}
