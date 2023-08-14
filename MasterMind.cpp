#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Generar clave aleatoriamente
void generarClave(int clave[4]) {
    for (int i = 0; i < 4; ++i) {
        int num;
        bool repetido;
        do {
            repetido = false;
            num = rand() % 6 + 1;
            for (int j = 0; j < i; ++j) {
                if (clave[j] == num) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido);
        clave[i] = num;
    }
}

// Mostrar las pistas
void mostrarPistas(const int clave[4], const int intento[4]) {
    for (int i = 0; i < 4; ++i) {
        if (intento[i] == clave[i]) {
            cout << "C ";
        } else if (find(clave, clave + 4, intento[i]) != clave + 4) {
            cout << "F ";
        } else {
            cout << "X ";
        }
    }
    cout << endl;
}

int main(){
    int clave[4];
    generarClave(clave);
    int intentos = 10;

    cout << "Bienvenido a Master Mind!" << endl;
    cout << "Adivina la clave de 4 números entre 1 y 6." << endl;

    while (intentos > 0) {
        cout << "Intentos restantes: " << intentos << endl;
        int intento[4];

        cout << "Ingresa tu intento separado por espacios: ";
        for (int i = 0; i < 4; ++i) {
            cin >> intento[i];
            if (intento[i] < 1 || intento[i] > 6) {
                cout << "Número fuera de rango. Debe estar entre 1 y 6." << endl;
                return 1;
            }
        }

        mostrarPistas(clave, intento);

        bool ganado = true;
        for (int i = 0; i < 4; ++i) {
            if (intento[i] != clave[i]) {
                ganado = false;
                break;
            }
        }

        if (ganado) {
            int puntuacion = (10 - (10 - intentos)) * 10;
            cout << "¡Ganaste! Tu puntuación es: " << puntuacion << endl;
            break;
        }
        --intentos;
    }

    if (intentos == 0) {
        cout << "¡Perdiste! La clave era: ";
        for (int i = 0; i < 4; ++i) {
            cout << clave[i] << " ";
        }
        cout << endl;
    }

    return 0;
}