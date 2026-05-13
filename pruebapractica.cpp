#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    double notas[5];
    double promedio;
    double mayor;
    double menor;
    int aprobados;
    int reprobados;
};

string obtenerFechaActual() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string fecha(dt);
    fecha.pop_back();
    return fecha;
}

void mostrarMenu() {
    cout << "\n=== MENU INTERACTIVO ===" << endl;
    cout << "1. Operaciones basicas" << endl;
    cout << "2. Registrar notas de estudiantes" << endl;
    cout << "3. Guardar resultados" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void operacionesBasicas() {
    double a, b;
    int opcion;

    cout << "\n--- OPERACIONES BASICAS ---" << endl;
    cout << "Ingrese primer numero: ";
    cin >> a;
    cout << "Ingrese segundo numero: ";
    cin >> b;

    cout << "\nSeleccione operacion:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Division" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            cout << "Resultado: " << a << " + " << b << " = " << (a + b) << endl;
            break;
        case 2:
            cout << "Resultado: " << a << " - " << b << " = " << (a - b) << endl;
            break;
        case 3:
            cout << "Resultado: " << a << " * " << b << " = " << (a * b) << endl;
            break;
        case 4:
            if(b != 0) {
                cout << "Resultado: " << a << " / " << b << " = " << (a / b) << endl;
            } else {
                cout << "ERROR: No se puede dividir entre cero!" << endl;
            }
            break;
        default:
            cout << "Opcion invalida!" << endl;
    }
}

void registrarNotasEstudiante(Estudiante &e) {
    cout << "\n--- REGISTRO DE NOTAS PARA: " << e.nombre << " ---" << endl;
    double suma = 0;
    e.mayor = 0;
    e.menor = 10;
    e.aprobados = 0;
    e.reprobados = 0;

    for(int i = 0; i < 5; i++) {
        do {
            cout << "Ingrese nota " << (i + 1) << " (0-10): ";
            cin >> e.notas[i];
            if(e.notas[i] < 0 || e.notas[i] > 10) {
                cout << "Nota invalida. Ingrese un valor entre 0 y 10." << endl;
            }
        } while(e.notas[i] < 0 || e.notas[i] > 10);

        suma += e.notas[i];

        if(e.notas[i] > e.mayor) {
            e.mayor = e.notas[i];
        }

        if(e.notas[i] < e.menor) {
            e.menor = e.notas[i];
        }

        if(e.notas[i] >= 7) {
            e.aprobados++;
        } else {
            e.reprobados++;
        }
    }

    e.promedio = suma / 5;
}

void mostrarResultadosEstudiante(Estudiante e) {
    cout << "\n--- RESULTADOS DE " << e.nombre << " ---" << endl;
    cout << "Promedio: " << fixed << setprecision(2) << e.promedio << endl;
    cout << "Nota mayor: " << e.mayor << endl;
    cout << "Nota menor: " << e.menor << endl;
    cout << "Aprobados: " << e.aprobados << endl;
    cout << "Reprobados: " << e.reprobados << endl;
}

void guardarResultados(Estudiante estudiantes[], int cantidad) {
    ofstream archivo("resultados/resultados.txt");

    if(!archivo.is_open()) {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    archivo << "=== REPORTE DE NOTAS Y PROMEDIOS ===" << endl;
    archivo << "Fecha: " << obtenerFechaActual() << endl;
    archivo << "Lenguaje utilizado: C++" << endl;
    archivo << "\n--- LISTA DE ESTUDIANTES Y SUS PROMEDIOS ---" << endl;
    archivo << left << setw(25) << "NOMBRE" << setw(10) << "PROMEDIO" << setw(10) << "MAYOR" << setw(10) << "MENOR" << setw(12) << "APROBADOS" << "REPROBADOS" << endl;
    archivo << "----------------------------------------------------------------" << endl;

    for(int i = 0; i < cantidad; i++) {
        archivo << left << setw(25) << estudiantes[i].nombre;
        archivo << setw(10) << fixed << setprecision(2) << estudiantes[i].promedio;
        archivo << setw(10) << estudiantes[i].mayor;
        archivo << setw(10) << estudiantes[i].menor;
        archivo << setw(12) << estudiantes[i].aprobados;
        archivo << estudiantes[i].reprobados << endl;
    }

    archivo << "\n--- RESUMEN GENERAL ---" << endl;
    double sumaPromedios = 0;
    for(int i = 0; i < cantidad; i++) {
        sumaPromedios += estudiantes[i].promedio;
    }
    double promedioGeneral = sumaPromedios / cantidad;
    archivo << "Promedio general del curso: " << fixed << setprecision(2) << promedioGeneral << endl;

    archivo << "\n--- FIN DEL REPORTE ---" << endl;

    archivo.close();
    cout << "\nResultados guardados exitosamente en resultados/resultados.txt" << endl;
    cout << "Se guardaron las notas de " << cantidad << " estudiantes." << endl;
}

int main() {
    int opcion;
    Estudiante estudiantes[] = {
        {"Acosta Hanna", {0}, 0, 0, 0, 0, 0},
        {"Andrade Hugo", {0}, 0, 0, 0, 0, 0},
        {"Altercia Sofia", {0}, 0, 0, 0, 0, 0},
        {"Balarezo Diego", {0}, 0, 0, 0, 0, 0},
        {"Bautista Sol", {0}, 0, 0, 0, 0, 0},
        {"Bedoya Sivan", {0}, 0, 0, 0, 0, 0},
        {"Bravo Samuel", {0}, 0, 0, 0, 0, 0},
        {"Cajao Paulo", {0}, 0, 0, 0, 0, 0},
        {"Calopina Brandon", {0}, 0, 0, 0, 0, 0},
        {"Castelo Katherine", {0}, 0, 0, 0, 0, 0},
        {"Chacha Victor", {0}, 0, 0, 0, 0, 0},
        {"Chiluzia Steed", {0}, 0, 0, 0, 0, 0},
        {"Dominguez Daniel", {0}, 0, 0, 0, 0, 0},
        {"Freire Alan", {0}, 0, 0, 0, 0, 0},
        {"Guillen Abisag", {0}, 0, 0, 0, 0, 0},
        {"Guaman Alexander", {0}, 0, 0, 0, 0, 0},
        {"Guança Sebastian", {0}, 0, 0, 0, 0, 0},
        {"Guanoto Karla", {0}, 0, 0, 0, 0, 0},
        {"Landeta Edison", {0}, 0, 0, 0, 0, 0},
        {"Loor Jhon", {0}, 0, 0, 0, 0, 0},
        {"Lopez Washington", {0}, 0, 0, 0, 0, 0},
        {"Miranda Imanol", {0}, 0, 0, 0, 0, 0},
        {"Monar Jhaiti", {0}, 0, 0, 0, 0, 0},
        {"Muyulema Mateo", {0}, 0, 0, 0, 0, 0},
        {"Navonez Antonella", {0}, 0, 0, 0, 0, 0},
        {"Nunez Bryan", {0}, 0, 0, 0, 0, 0},
        {"Pilco Mario", {0}, 0, 0, 0, 0, 0},
        {"Pomagueño Katherine", {0}, 0, 0, 0, 0, 0},
        {"Quevedo Gina", {0}, 0, 0, 0, 0, 0},
        {"Ruizdeneira Matias", {0}, 0, 0, 0, 0, 0},
        {"Rocha Carolina", {0}, 0, 0, 0, 0, 0},
        {"Sanchez Isaac", {0}, 0, 0, 0, 0, 0},
        {"Segovia Joseph", {0}, 0, 0, 0, 0, 0},
        {"Supe Joan", {0}, 0, 0, 0, 0, 0},
        {"Toapanta Matias", {0}, 0, 0, 0, 0, 0},
        {"Viedesoto Kevin", {0}, 0, 0, 0, 0, 0},
        {"Villaces Alejandro", {0}, 0, 0, 0, 0, 0},
        {"Vitri Shantal", {0}, 0, 0, 0, 0, 0}
    };

    int cantidadEstudiantes = 38;
    bool notasRegistradas = false;

    cout << "Ingrese su nombre: ";
    string nombreProfesor;
    getline(cin, nombreProfesor);

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                operacionesBasicas();
                break;

            case 2:
                for(int i = 0; i < cantidadEstudiantes; i++) {
                    registrarNotasEstudiante(estudiantes[i]);
                    mostrarResultadosEstudiante(estudiantes[i]);
                }
                notasRegistradas = true;
                break;

            case 3:
                if(notasRegistradas) {
                    guardarResultados(estudiantes, cantidadEstudiantes);
                } else {
                    cout << "\nPrimero debe registrar las notas (opcion 2)." << endl;
                }
                break;

            case 4:
                cout << "\nSaliendo del programa. Hasta luego!" << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }
    } while(opcion != 4);

    return 0;
}
