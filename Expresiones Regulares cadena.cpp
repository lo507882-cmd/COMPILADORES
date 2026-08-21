#include <iostream>
#include <regex>
#include <string>
using namespace std;

string clasificar(string palabra) {
    regex numero("^[0-9]+$");
    regex minuscula("^[a-z]+$");
    regex mayuscula("^[A-Z]+$");
    regex identificador("^[a-zA-Z_][a-zA-Z0-9_]*$");
    regex simbolo("^[+\\-*/=<>!&|(){}\\[\\] ;:,.']+$");
    
    if(regex_match(palabra, numero)) return "NUMERO";
    if(regex_match(palabra, minuscula)) return "MINUSCULA";
    if(regex_match(palabra, mayuscula)) return "MAYUSCULA";
    if(regex_match(palabra, identificador)) return "IDENTIFICADOR";
    if(regex_match(palabra, simbolo)) return "SIMBOLO";
    
    return "DESCONOCIDO";
}

int main() {
    cout << "ANALIZADOR DE PALABRAS" << endl;
    
    cout << "\nEXPRESIONES REGULARES:" << endl;
    cout << "1. NUMERO: ^[0-9]+$ (ej: 123, 45)" << endl;
    cout << "2. MINUSCULA: ^[a-z]+$ (ej: hola, mundo)" << endl;
    cout << "3. MAYUSCULA: ^[A-Z]+$ (ej: HOLA, MUNDO)" << endl;
    cout << "4. IDENTIFICADOR: ^[a-zA-Z_][a-zA-Z0-9_]*$ (ej: var1, _temp)" << endl;
    cout << "5. SIMBOLO: ^[+\\-*/=<>!&|(){}\\[\\] ;:,.']+$ (ej: +, -, =)" << endl;
    
    cout << "Ingresa una frase para analizar: ";
    string entrada;
    getline(cin, entrada);
    
    string palabras[100];
    string tipos[100];
    int total = 0;
    
    int cNum = 0, cMin = 0, cMay = 0, cId = 0, cSim = 0;
    
    string palabra = "";
    for(int i = 0; i <= entrada.length(); i++) {
        if(i == entrada.length() || entrada[i] == ' ') {
            if(palabra != "") {
                string tipo = clasificar(palabra);
                palabras[total] = palabra;
                tipos[total] = tipo;
                total++;
             
                if(tipo == "NUMERO") cNum++;
                else if(tipo == "MINUSCULA") cMin++;
                else if(tipo == "MAYUSCULA") cMay++;
                else if(tipo == "IDENTIFICADOR") cId++;
                else if(tipo == "SIMBOLO") cSim++;
                
                palabra = "";
            }
        } else {
            palabra += entrada[i];
        }
    }
    
    cout << "RESULTADOS" << endl;
    
    cout << "\nPalabras encontradas:" << endl;
    for(int i = 0; i < total; i++) {
        cout << (i+1) << ". '" << palabras[i] << "' = " << tipos[i] << endl;
    }
    
    cout << "\nEstadisticas:" << endl;
    cout << "Numeros: " << cNum << endl;
    cout << "Minusculas: " << cMin << endl;
    cout << "Mayusculas: " << cMay << endl;
    cout << "Identificadores: " << cId << endl;
    cout << "Simbolos: " << cSim << endl;
    cout << "Total palabras: " << total << endl;
    
    return 0;
}
