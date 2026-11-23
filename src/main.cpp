

#include <iostream>
#include <limits>
#include <string>

#ifdef _WIN32
#include <windows.h>   // Para mostrar correctamente tildes y eñes en la consola
#endif

using namespace std;

// -----------------------------------------------------------------------------
// EJERCICIO 1: El Sensor de Aprobación
// -----------------------------------------------------------------------------
void ejercicio1() {
    const float NOTA_MINIMA = 6.0f;
    float nota1, nota2, promedio;

    cout << "\n--- EJERCICIO 1: El Sensor de Aprobación ---\n";

    cout << "Ingrese nota1 (Primer Cuatrimestre): ";
    cin >> nota1;
    cout << "Ingrese nota2 (Segundo Cuatrimestre): ";
    cin >> nota2;

    promedio = (nota1 + nota2) / 2.0f;

    cout << "Promedio: " << promedio << "\n";
    if (promedio >= NOTA_MINIMA) {
        cout << "APROBADO\n";
    } else {
        cout << "A INTENSIFICACIÓN\n";
    }
}

// -----------------------------------------------------------------------------
// EJERCICIO 2: El Bucle del Contador de Vidas
// -----------------------------------------------------------------------------
void ejercicio2() {
    int vidas = 3;

    cout << "\n--- EJERCICIO 2: El Bucle del Contador de Vidas ---\n";

    while (vidas > 0) {
        cout << "Jugador activo. Vidas restantes: " << vidas << "\n";
        vidas = vidas - 1;   // impacto del obstáculo
    }

    cout << "GAME OVER\n";
}

// -----------------------------------------------------------------------------
// EJERCICIO 3: Registro de Jugador en Memoria (estructura)
// -----------------------------------------------------------------------------
struct Jugador {
    string nickname;
    int nivel;
    bool esVIP;
};

void ejercicio3() {
    Jugador jugador;
    int vip;

    cout << "\n--- EJERCICIO 3: Registro de Jugador en Memoria ---\n";

    cout << "Ingrese nickname: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, jugador.nickname);

    cout << "Ingrese nivel: ";
    cin >> jugador.nivel;

    cout << "Ingrese esVIP (1 = Verdadero, 0 = Falso): ";
    cin >> vip;
    jugador.esVIP = (vip == 1);

    if (jugador.esVIP) {
        cout << "Bienvenido al Servidor VIP, " << jugador.nickname << "\n";
    } else {
        cout << "Bienvenido al Servidor Estándar, " << jugador.nickname << "\n";
    }
}

// -----------------------------------------------------------------------------
// EJERCICIO 4: Control de Inventario con Arreglos
// -----------------------------------------------------------------------------
void ejercicio4() {
    int stock[5] = {12, 0, 5, 30, 0};
    int i = 0;

    cout << "\n--- EJERCICIO 4: Control de Inventario con Arreglos ---\n";
    cout << "Vector stock = [";
    for (int k = 0; k < 5; k++) {
        cout << stock[k] << (k < 4 ? ", " : "");
    }
    cout << "]\n";

    while (i < 5) {
        if (stock[i] == 0) {
            cout << "ALERTA: Sin stock en la posición " << i << "\n";
        }
        i = i + 1;
    }
}

// -----------------------------------------------------------------------------
// PROGRAMA PRINCIPAL: menú para ejecutar cada algoritmo por separado
// -----------------------------------------------------------------------------
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int opcion;

    do {
        cout << "\n==================================================\n";
        cout << " ACTIVIDAD 9 - PENSAR ANTES DE PROGRAMAR\n";
        cout << "==================================================\n";
        cout << "  1) Ejercicio 1 - Sensor de Aprobación\n";
        cout << "  2) Ejercicio 2 - Contador de Vidas\n";
        cout << "  3) Ejercicio 3 - Registro de Jugador (struct)\n";
        cout << "  4) Ejercicio 4 - Control de Inventario (vector)\n";
        cout << "  5) Salir\n";
        cout << "--------------------------------------------------\n";
        cout << "Seleccione una opción: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1;
            continue;
        }

        switch (opcion) {
            case 1: ejercicio1(); break;
            case 2: ejercicio2(); break;
            case 3: ejercicio3(); break;
            case 4: ejercicio4(); break;
            case 5: cout << "Fin del programa.\n"; break;
            default: cout << "Opción inválida. Intente nuevamente.\n"; break;
        }

    } while (opcion != 5);

    return 0;
}
