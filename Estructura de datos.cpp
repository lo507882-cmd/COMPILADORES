#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct Resultados {
    int numerosEnteros;
    int palabrasMinusculas;
    int palabrasMayusculas;
    int identificadores;
    int simbolos;
    char palabras[100][50]; 
    char tipos[100][20];     
    int contadorPalabras;
};

bool esNumeroEntero(char palabra[]) {
    int len = strlen(palabra);
    if (len == 0) {
	return false;
}
    
    for (int i = 0; i < len; i++) {
        if (!isdigit(palabra[i])) {
            return false;
        }
    }
    return true;
}

bool esPalabraMinuscula(char palabra[]) {
    int len = strlen(palabra);
    if (len == 0){
	return false;
}
    
    for (int i = 0; i < len; i++) {
        if (!islower(palabra[i])) {
            return false;
        }
    }
    return true;
}

bool esPalabraMayuscula(char palabra[]) {
    int len = strlen(palabra);
    if (len == 0){
	return false;
}
    
    for (int i = 0; i < len; i++) {
        if (!isupper(palabra[i])) {
            return false;
        }
    }
    return true;
}

bool esIdentificador(char palabra[]) {
    int len = strlen(palabra);
    if (len == 0){
	 return false;
}
    
    if (!isalpha(palabra[0]) && palabra[0] != '_') {
        return false;
    }
    
    for (int i = 1; i < len; i++) {
        if (!isalnum(palabra[i]) && palabra[i] != '_') {
            return false;
        }
    }
    return true;
}


void clasificarPalabra(char palabra[], Resultados &resultados) {

    if (esNumeroEntero(palabra)) {
        resultados.numerosEnteros++;
        strcpy(resultados.palabras[resultados.contadorPalabras], palabra);
        strcpy(resultados.tipos[resultados.contadorPalabras], "NUMERO_ENTERO");
        resultados.contadorPalabras++;
    }
    else if (esPalabraMinuscula(palabra)) {
        resultados.palabrasMinusculas++;
        strcpy(resultados.palabras[resultados.contadorPalabras], palabra);
        strcpy(resultados.tipos[resultados.contadorPalabras], "PALABRA_MINUSCULA");
        resultados.contadorPalabras++;
    }
    else if (esPalabraMayuscula(palabra)) {
        resultados.palabrasMayusculas++;
        strcpy(resultados.palabras[resultados.contadorPalabras], palabra);
        strcpy(resultados.tipos[resultados.contadorPalabras], "PALABRA_MAYUSCULA");
        resultados.contadorPalabras++;
    }
    else if (esIdentificador(palabra)) {
        resultados.identificadores++;
        strcpy(resultados.palabras[resultados.contadorPalabras], palabra);
        strcpy(resultados.tipos[resultados.contadorPalabras], "IDENTIFICADOR");
        resultados.contadorPalabras++;
    }
}

void analizarCadena(char cadena[], Resultados &resultados) {
    int len = strlen(cadena);
    char palabra[50];
    int pos = 0;
    
    for (int i = 0; i <= len; i++) {
        if (cadena[i] == ' ' || cadena[i] == '\t' || cadena[i] == '\n' || cadena[i] == '\0') {
            if (pos > 0) {
                palabra[pos] = '\0';
                clasificarPalabra(palabra, resultados);
                pos = 0;
            }
        } else {
            palabra[pos++] = cadena[i];
        }
    }
}


void mostrarResultados(Resultados &resultados) {
    cout << "\n=== Analisis ===" << endl;
    cout << "Numeros enteros: " << resultados.numerosEnteros << endl;
    cout << "Palabras en minusculas: " << resultados.palabrasMinusculas << endl;
    cout << "Palabras en mayusculas: " << resultados.palabrasMayusculas << endl;
    cout << "Identificadores: " << resultados.identificadores << endl;
    
    
    cout << "\n=== DETALLE DE PALABRAS ENCONTRADAS ===" << endl;
    for (int i = 0; i < resultados.contadorPalabras; i++) {
        cout << "Palabra: " << resultados.palabras[i] 
             << " -> Tipo: " << resultados.tipos[i] << endl;
    }
}

int main() {

    Resultados resultados;
    resultados.numerosEnteros = 0;
    resultados.palabrasMinusculas = 0;
    resultados.palabrasMayusculas = 0;
    resultados.identificadores = 0;
    resultados.simbolos = 0;
    resultados.contadorPalabras = 0;
    
    
    cout << "\n=== ANALISIS DE CADENA PERSONALIZADA ===" << endl;
    char entrada[500];
    cout << "Ingrese una cadena para analizar: ";
    cin.getline(entrada, 500);
    
    
    analizarCadena(entrada, resultados);
    mostrarResultados(resultados);
    
    return 0;
}
