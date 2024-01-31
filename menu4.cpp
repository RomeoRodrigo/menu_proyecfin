#include <iostream>
#include <string>
#include <random>

using namespace std;

// Prototipos de las funciones
int generarNumeroAleatorio(int minimo, int maximo);
void llenarDatosUsuario(string nombres[], string apellidos[], int notas[]);
void ofuscarNombresYApellidos(string nombres[], string apellidos[], string contrasenas[]);
void imprimirDatos(const string nombres[], const string apellidos[], const int notas[], const string contrasenas[]);
void mostrarMayorYMenor(const string nombres[], const string apellidos[], const int notas[]);
void mostrarMenu();
void ejecutarMenu();

// Declaracio de las variables
string nombres[10] = {"Nicol", "Rodrigo", "Jessenia", "Priscila", "Adriana", "Jennyfer", "Aneth", "Alejandro", "Diego", "Luis"};
string apellidos[10] = {"Espada", "Loayza", "Justiniano", "Bellido", "Bayo", "Martinez", "Moreno", "Delius", "Duran", "Cerrudo"};
string contrasenas[10];
int notas[10];
char opcion;

// Aqui se implementaran todas las funciones
void mostrarMenu() {
	// Imprime el menu en pantalla del usuario
	cout << "\nMENU #4\n"
		<< "(1) Llenar nombres, apellidos y notas de forma aleatoria.\n"
		<< "(2) Ofuscar nombres y apellidos para llenar las contraseñas.\n"
		<< "(3) Mostrar la nota mayor y menor de todas las notas.\n"
		<< "(4) Imprimir datos.\n"
		<< "(s/S) Salir\n";
}

void ejecutarMenu() {
	// Ciclo para ejecutar el menu y el usuario elija una opcion o salir
	do {
		// Llama a la funcion que muestra el menu
		mostrarMenu();
		
		// Solicita al usuario que ingrese una opcion
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		// Evalua la opcion ingresada por el usuario y realizar la accion seleccionada
		switch (opcion) {
		case '1':
			// Llama a la funcion para llenar datos de manera aleatoria
			llenarDatosUsuario(nombres, apellidos, notas);
			break;
		case '2':
			// Llama a la funcion para ofuscar nombres y apellidos y llenar contraseñas
			ofuscarNombresYApellidos(nombres, apellidos, contrasenas);
			break;
		case '3':
			// Llama a la funcion para mostrar la nota mayor y menor
			mostrarMayorYMenor(nombres, apellidos, notas);
			break;
		case '4':
			// Llama a la funcion para imprimir datos
			imprimirDatos(nombres, apellidos, notas, contrasenas);
			break;
		case 's':
		case 'S':
			// Informa al usuario que  saldra del programa
			cout << "Saliendo del programa.\n";
			break;
		default:
			// Informa al usuario que la opcion ingresada no es valida
			cout << "Opcion no valida. Intente de nuevo.\n";
			break;
		}
		
		// Continua ejecutando el menu mientras el usuario no elija salir
	} while (opcion != 's' && opcion != 'S');
}

// Implementa la funcion para generar numeros aleatorios
int generarNumeroAleatorio(int minimo, int maximo) {
	// Crear un generador de numeros aleatorios y obtener un numero en el rango especificado
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribucion(minimo, maximo);
	return distribucion(gen);
}

// funciones sin cambios
void llenarDatosUsuario(string nombres[], string apellidos[], int notas[]) {
	// Logica para llenar 10 notas aleatorias entre 20 y 100 y mostrar en pantalla
	cout << "Nombres y apellidos generados con notas aleatorias:\n";
	for (int i = 0; i < 10; ++i) {
		// Genera una nota aleatoria y muestra los datos en pantalla
		notas[i] = generarNumeroAleatorio(20, 100);
		cout << nombres[i] << " " << apellidos[i] << " - Nota: " << notas[i] << endl;
	}
}

void ofuscarNombresYApellidos(string nombres[], string apellidos[], string contrasenas[]) {
	// Para ofuscar nombres y apellidos y llenar las contraseñas
	for (int i = 0; i < 10; ++i) {
		contrasenas[i] = "";
		for (char c : nombres[i] + apellidos[i]) {
			// Cambiar ciertos caracteres segun las reglas definidas
			switch (c) {
			case 'A':
			case 'a':
				contrasenas[i] += '4';
				break;
			case 'E':
			case 'e':
				contrasenas[i] += '3';
				break;
			case 'I':
			case 'i':
				contrasenas[i] += '1';
				break;
			case 'O':
			case 'o':
				contrasenas[i] += '0';
				break;
			case 'S':
			case 's':
				contrasenas[i] += '5';
				break;
			case 'T':
			case 't':
				contrasenas[i] += '7';
				break;
			default:
				// Conservar otros caracteres sin cambios
				contrasenas[i] += c;
			}
		}
	}
	
	// Mostrar contraseñas ofuscadas en pantalla
	cout << "Nombres y apellidos ofuscados:\n";
	for (int i = 0; i < 10; ++i) {
		cout << contrasenas[i] << endl;
	}
}

void imprimirDatos(const string nombres[], const string apellidos[], const int notas[], const string contrasenas[]) {
	// Logica para imprimir los datos en formato tabular
	cout << "Nombre    Apellido   Nota   Contraseña" << endl;
	for (int i = 0; i < 10; ++i) {
		// Mostrar datos en cada fila de la tabla
		cout << nombres[i] << "   " << apellidos[i] << "   " << notas[i] << "   " << contrasenas[i] << endl;
	}
}

void mostrarMayorYMenor(const string nombres[], const string apellidos[], const int notas[]) {
	// Encontrar la nota mayor y menor
	int mayor = 0;
	int menor = 0;
	
	for (int i = 1; i < 10; ++i) {
		if (notas[i] > notas[mayor]) {
			mayor = i;
		}
		
		if (notas[i] < notas[menor]) {
			menor = i;
		}
	}
	
	// Mostrar la nota mayor y menor en pantalla
	cout << "La nota mayor es: " << nombres[mayor] << " " << apellidos[mayor] << " - " << notas[mayor] << endl;
	cout << "La nota menor es: " << nombres[menor] << " " << apellidos[menor] << " - " << notas[menor] << endl;
}

int main() {
	// Llama a la funcion que ejecuta el menu
	ejecutarMenu();
	
	// retorna 0 para indicar que el programa se ejecuto exitosamente
	return 0;
}
