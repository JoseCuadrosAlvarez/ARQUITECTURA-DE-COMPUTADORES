#include <iostream>
#include <bitset>

std::string SumaBinaria(int a, int b) {
    int sum = a + b;
    return std::bitset<32>(sum).to_string(); // suma los bits y los transforma en string para poder imprimirse
}

int Multiplicacion(int multiplicando, int multiplicador) {
    int resultado = 0;
    int multiplicando_v = abs(multiplicando); //sacamos el valor absoluto del multiplicando y multiplicador
    int multiplicador_v = abs(multiplicador);
    int producto = 0;

    for (int i = 0; i < 32; i++) { // Suponiendo números de 32 bits, se puede cambiar por la cantidad de bits que se desee
        int lsbMultiplicador = multiplicador_v & 1; // Se extrae el bit menos significativo del multiplicador
        if (lsbMultiplicador == 1) { // SSe suma el valor abosulto al producto parcial
            producto += multiplicando_v;
        }
        multiplicando_v <<= 1; //Se realiza un corrimiento a la izquierda del valor absoluto del multiplicando y un corrimiento a la derecha del valor absoluto del multiplicador para preparar los siguientes bits de multiplicación.
        multiplicador_v >>= 1;
    }
    if ((multiplicando < 0) ^ (multiplicador < 0)) { // Se determina el signo del resultado final.
        resultado = -producto;
    }
    else {
        resultado = producto;
    }
    return resultado;
}

std::string Binario(int n) {
    return std::bitset<32>(n).to_string(); // Transforma el número binario en string para que pueda imprimirse en pantalla
}

int main() {
    while (true) {
        int multiplicando, multiplicador, producto;
        multiplicando = 0;
        multiplicador = 0;
        producto = Multiplicacion(multiplicando, multiplicador);
        std::cout << "Ingrese el multiplicando: ";
        std::cin >> multiplicando;
        std::cout << "Ingrese el multiplicador: ";
        std::cin >> multiplicador;
        std::cout << "Resultado: " << producto << " // En binario: " << Binario(producto) << std::endl;
        std::cout << "Suma binaria de los multiplicandos: " << SumaBinaria(multiplicando, multiplicador) << std::endl;
    }
    return 0;
}
