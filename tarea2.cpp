#include <iostream>
#include <string>
using namespace std;

// Declaración de funciones
string obtenerUnidad(int numero, bool esParteMiles = false);
string obtenerDecena(int numero, bool esParteMiles = false);
string obtenerCentena(int numero, bool esParteMiles = false);
string convertirMiles(int numero);
string convertirMillones(int numero);
string convertirRestante(int numero, bool esParteMiles = false);
string convertirNumero(int numero);

int main() {
    int numeroEntrada;
    cout << "Ingresa un numero entre 1 y 999999: ";
    cin >> numeroEntrada;

    if (numeroEntrada < 1 || numeroEntrada > 999999) {
        cout << "Fuera de rango. Inténtalo de nuevo." << endl;
        return 1;
    }

    string resultadoTexto = convertirNumero(numeroEntrada);
    cout << numeroEntrada << " = " << resultadoTexto << endl;

    return 0;
}

// Funciones específicas
string obtenerUnidad(int numero, bool esParteMiles) {
    if (numero >= 1 && numero <= 9) {
        switch (numero) {
            case 1: return esParteMiles ? "un" : "uno";
            case 2: return "dos";
            case 3: return "tres";
            case 4: return "cuatro";
            case 5: return "cinco";
            case 6: return "seis";
            case 7: return "siete";
            case 8: return "ocho";
            case 9: return "nueve";
        }
    }
    return "";
}

string obtenerDecena(int numero, bool esParteMiles) {
    if (numero >= 10 && numero <= 19) {
        switch (numero) {
            case 10: return "diez";
            case 11: return "once";
            case 12: return "doce";
            case 13: return "trece";
            case 14: return "catorce";
            case 15: return "quince";
            case 16: return "dieciséis";
            case 17: return "diecisiete";
            case 18: return "dieciocho";
            case 19: return "diecinueve";
        }
    } else if (numero >= 20) {
        switch (numero / 10) {
            case 2: return (numero % 10 == 0) ? "veinte" : "veinti" + obtenerUnidad(numero % 10, esParteMiles);
            case 3: return (numero % 10 == 0) ? "treinta" : "treinta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 4: return (numero % 10 == 0) ? "cuarenta" : "cuarenta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 5: return (numero % 10 == 0) ? "cincuenta" : "cincuenta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 6: return (numero % 10 == 0) ? "sesenta" : "sesenta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 7: return (numero % 10 == 0) ? "setenta" : "setenta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 8: return (numero % 10 == 0) ? "ochenta" : "ochenta y " + obtenerUnidad(numero % 10, esParteMiles);
            case 9: return (numero % 10 == 0) ? "noventa" : "noventa y " + obtenerUnidad(numero % 10, esParteMiles);
        }
    } else {
        return obtenerUnidad(numero, esParteMiles);
    }
    return "";
}

string obtenerCentena(int numero, bool esParteMiles) {
    if (numero >= 100) {
        switch (numero / 100) {
            case 1: return (numero % 100 == 0) ? "cien" : "ciento " + obtenerDecena(numero % 100, esParteMiles);
            case 2: return "doscientos " + obtenerDecena(numero % 100, esParteMiles);
            case 3: return "trescientos " + obtenerDecena(numero % 100, esParteMiles);
            case 4: return "cuatrocientos " + obtenerDecena(numero % 100, esParteMiles);
            case 5: return "quinientos " + obtenerDecena(numero % 100, esParteMiles);
            case 6: return "seiscientos " + obtenerDecena(numero % 100, esParteMiles);
            case 7: return "setecientos " + obtenerDecena(numero % 100, esParteMiles);
            case 8: return "ochocientos " + obtenerDecena(numero % 100, esParteMiles);
            case 9: return "novecientos " + obtenerDecena(numero % 100, esParteMiles);
        }
    } else {
        return obtenerDecena(numero, esParteMiles);
    }
    return "";
}

string convertirMiles(int numero) {
    if (numero >= 1000) {
        int valorMiles = numero / 1000;
        int restante = numero % 1000;

        string textoMiles;
        if (valorMiles == 1) {
            textoMiles = "mil";  
        } else {
            textoMiles = obtenerCentena(valorMiles, true) + " mil";  
        }

        if (restante > 0) {
            textoMiles += " " + obtenerCentena(restante);
        }

        return textoMiles;
    } else {
        return obtenerCentena(numero);
    }
}

string convertirRestante(int numero, bool esParteMiles) {
    if (numero == 0) {
        return "";
    } else if (numero < 100) {
        return obtenerDecena(numero, esParteMiles);
    } else {
        return obtenerCentena(numero, esParteMiles);
    }
}

string convertirNumero(int numero) {
    if (numero == 0) {
        return "cero";
    }

    if (numero >= 1000000) {
        return "FUERA DE RANGO";
    } else if (numero >= 1000) {
        return convertirMiles(numero);
    } else {
        return convertirRestante(numero);
    }
}
