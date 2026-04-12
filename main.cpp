#include <iostream>
#include <fstream>
using namespace std;

const int PIN_CORRECTO = 1234;
const string ARCHIVO = "saldo.txt";

void guardarSaldo(double saldo) {
    ofstream archivo(ARCHIVO);
    archivo << saldo;
}

double cargarSaldo() {
    ifstream archivo(ARCHIVO);
    double saldo;

    if (archivo >> saldo) {
        return saldo;
    } else {
        return 1000; // Saldo Inicial (con el que iniciamos, puede ser cambiado a cualquier saldo que se desee).
    }
}

bool login() {
    int pin, intentos = 3;

    while (intentos > 0) {
        cout << "Ingrese su PIN: ";
        cin >> pin;

        if (pin == PIN_CORRECTO) {
            cout << "Acceso concedido.\n";
            return true;
        } else {
            intentos--;
            cout << "PIN incorrecto. Intentos restantes: " << intentos << endl;
        }
    }

    cout << "Cuenta bloqueada.\n";
    return false;
}

void menu() {
    cout << "\n--- CAJERO AUTOMATICO ---\n";
    cout << "1. Consultar saldo\n";
    cout << "2. Depositar dinero\n";
    cout << "3. Retirar dinero\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

void consultar(double saldo) {
    cout << "Saldo actual: $" << saldo << endl;
}

double depositar(double saldo) {
    double cantidad;
    cout << "Cantidad a depositar: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad invalida.\n";
    } else {
        saldo += cantidad;
        cout << "Deposito exitoso.\n";
    }

    return saldo;
}

double retirar(double saldo) {
    double cantidad;
    cout << "Cantidad a retirar: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad invalida.\n";
    } else if (cantidad > saldo) {
        cout << "Fondos insuficientes.\n";
    } else {
        saldo -= cantidad;
        cout << "Retiro exitoso.\n";
    }

    return saldo;
}

int main() {
    if (!login()) return 0;

    double saldo = cargarSaldo();
    int opcion;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                consultar(saldo);
                break;
            case 2:
                saldo = depositar(saldo);
                guardarSaldo(saldo);
                break;
            case 3:
                saldo = retirar(saldo);
                guardarSaldo(saldo);
                break;
            case 4:
                cout << "Gracias por usar el cajero.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}
