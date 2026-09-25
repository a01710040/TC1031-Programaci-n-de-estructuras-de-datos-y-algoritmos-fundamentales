#include <iostream>
#include <vector>
#include "Pedido.h"
#include "Sorts.h"

void imprimirLista(const std::vector<Pedido> &lista) {
    std::cout << std::endl;
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << lista[i].toString() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Pedido> pedidos = {
        Pedido(101, "Cafeteria El Centro", "2026-08-10", "Molido", 15.5, 3875.00),
        Pedido(102, "Abarrotes Don Pedro", "2026-08-12", "Grano", 5.0, 1150.00),
        Pedido(103, "Hotel Sierra Azul", "2026-08-11", "Grano", 25.0, 5750.00),
        Pedido(104, "Maria Elena Gomez", "2026-08-15", "Molido", 2.0, 500.00),
        Pedido(105, "Restaurante El Mirador", "2026-08-14", "Grano", 10.0, 2300.00)
    };

    Sorts<Pedido> ordenador;
    int opcion = 0;

    while (opcion != 3) {
        std::cout << "\n=== SISTEMA DE DISTRIBUCION CAFE DON VIRGINIO ===\n";
        std::cout << "1. Mostrar pedidos originales (sin ordenar)\n";
        std::cout << "2. Ordenar pedidos por Total (Merge Sort)\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            imprimirLista(pedidos);
        } 
        else if (opcion == 2) {
            std::vector<Pedido> resultado = ordenador.mergeSort(pedidos);
            std::cout << "\n[OK] Pedidos ordenados por monto total:";
            imprimirLista(resultado);
        } 
        else if (opcion == 3) {
            std::cout << "Saliendo del programa..." << std::endl;
        } 
        else {
            std::cout << "Opcion invalida." << std::endl;
        }
    }

    return 0;
}
