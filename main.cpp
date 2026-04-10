#include <iostream>
#include <cstdlib>
using namespace std;

/*
    Cajero automatico.
*/

int main() {
    system("cls");
    
    int opcion;
    double saldo = 1000, cantidad;

    do {
        cout << "====== CAJERO AUTOMATICO ======" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Depositar dinero" << endl;
        cout << "3. Retirar dinero" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Tu saldo es: $" << saldo << endl;
                break;
            case 2:
                cout << "Cantidad a depositar: ";
                cin >> cantidad;
                saldo += cantidad;
                cout << "Deposito exitoso." << endl;
                break;
            case 3:
                cout << "Cantidad a retirar: ";
                cin >> cantidad;
                if (cantidad > saldo) {
                    cout << "Fondos insuficientes." << endl;
                }
                else {
                    saldo -= cantidad;
                    cout << "Retiro exitoso." << endl;
                }
                break;
            case 4:
                cout << "Has salido con exito de tu banco." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    }while (opcion != 4); 

    return 0;
}