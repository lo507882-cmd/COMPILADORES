#include <iostream>
#include <cstring>
using namespace std;


bool esNumero(char palabra[]) {
    for(int i = 0; i < strlen(palabra); i++) {
        if(palabra[i] < '0' || palabra[i] > '9') {
            return false;
        }
    }
    return true;
}

bool esMinuscula(char palabra[]) {
    for(int i = 0; i < strlen(palabra); i++) {
        if(palabra[i] < 'a' || palabra[i] > 'z') {
            return false;
        }
    }
    return true;
}

bool esMayuscula(char palabra[]) {
    for(int i = 0; i < strlen(palabra); i++) {
        if(palabra[i] < 'A' || palabra[i] > 'Z') {
            return false;
        }
    }
    return true;
}

bool esIdentificador(char palabra[]) {
    char primera = palabra[0];
    if(!(primera >= 'a' && primera <= 'z') && 
       !(primera >= 'A' && primera <= 'Z') && 
       primera != '_') {
        return false;
    }
    
    for(int i = 1; i < strlen(palabra); i++) {
        char c = palabra[i];
        if(!(c >= 'a' && c <= 'z') && 
           !(c >= 'A' && c <= 'Z') && 
           !(c >= '0' && c <= '9') && 
           c != '_') {
            return false;
        }
    }
    return true;
}

bool esSimbolo(char palabra[]) {
    char simbolos[] = "+-*/=<>!&|(){}[];:,. '\"";
    
    for(int i = 0; i < strlen(palabra); i++) {
        bool encontrado = false;
        for(int j = 0; j < strlen(simbolos); j++) {
            if(palabra[i] == simbolos[j]) {
                encontrado = true;
                break;
            }
        }
        if(!encontrado) {
            return false;
        }
    }
    return true;
}


void clasificar(char palabra[], char tipo[]) {
    if(esNumero(palabra)) {
        strcpy(tipo, "NUMERO");
    }
    else if(esMinuscula(palabra)) {
        strcpy(tipo, "MINUSCULA");
    }
    else if(esMayuscula(palabra)) {
        strcpy(tipo, "MAYUSCULA");
    }
    else if(esIdentificador(palabra)) {
        strcpy(tipo, "IDENTIFICADOR");
    }
    else if(esSimbolo(palabra)) {
        strcpy(tipo, "SIMBOLO");
    }
    else {
        strcpy(tipo, "DESCONOCIDO");
    }
}

int main() {
    
    cout << "=========================================" << endl;
    cout << "ALFABETO Y EXPRESIONES REGULARES" << endl;
    cout << "=========================================" << endl;
    
    cout << "\nALFABETO:" << endl;
    cout << "Letras: a-z, A-Z" << endl;
    cout << "Numeros: 0-9" << endl;
    cout << "Simbolos: + - * / = < > ! & | ( ) { } [ ] ; : , . ' \" _" << endl;
    
    cout << "\nEXPRESIONES REGULARES:" << endl;
    cout << "1. NUMERO: solo digitos (0-9)" << endl;
    cout << "2. MINUSCULA: solo letras a-z" << endl;
    cout << "3. MAYUSCULA: solo letras A-Z" << endl;
    cout << "4. IDENTIFICADOR: empieza con letra o _, luego letras, numeros o _" << endl;
    cout << "5. SIMBOLO: caracteres como + - * / = ( ) { } etc." << endl;
    
    
    cout << "\n=========================================" << endl;
    cout << "ANALISIS PERSONALIZADO" << endl;
    cout << "=========================================" << endl;
    
    char palabras[50][50];
    char tipos[50][30];
    char entrada[500];
    char palabra[50];
    int pos = 0;
    int contNum = 0, contMin = 0, contMay = 0, contId = 0, contSim = 0;
    int totalPalabras = 0;
    cout << "Escribe una frase para analizar: ";
    cin.getline(entrada, 500);
    
   
    for(int i = 0; i <= strlen(entrada); i++) {
        if(entrada[i] == ' ' || entrada[i] == '\0') {
            if(pos > 0) {
                palabra[pos] = '\0';
                
                clasificar(palabra, tipos[totalPalabras]);
                strcpy(palabras[totalPalabras], palabra);
                
                if(strcmp(tipos[totalPalabras], "NUMERO") == 0) contNum++;
                else if(strcmp(tipos[totalPalabras], "MINUSCULA") == 0) contMin++;
                else if(strcmp(tipos[totalPalabras], "MAYUSCULA") == 0) contMay++;
                else if(strcmp(tipos[totalPalabras], "IDENTIFICADOR") == 0) contId++;
                else if(strcmp(tipos[totalPalabras], "SIMBOLO") == 0) contSim++;
                
                totalPalabras++;
                pos = 0;
            }
        }
        else {
            palabra[pos] = entrada[i];
            pos++;
        }
    }
    
    cout << "\nResultados:" << endl;
    for(int i = 0; i < totalPalabras; i++) {
        cout << (i+1) << ". " << palabras[i] << " => " << tipos[i] << endl;
    }
    
    cout << "\nEstadisticas:" << endl;
    cout << "Numeros: " << contNum << endl;
    cout << "Minusculas: " << contMin << endl;
    cout << "Mayusculas: " << contMay << endl;
    cout << "Identificadores: " << contId << endl;
    cout << "Simbolos: " << contSim << endl;
    cout << "Total: " << totalPalabras << endl;
    
    cout << "\nFIN DEL PROGRAMA" << endl;
    return 0;
}
