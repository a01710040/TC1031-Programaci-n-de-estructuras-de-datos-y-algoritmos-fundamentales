#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Pedido.h"
#include "Sorts.h"
#include "dlist.h"

bool aEntero(const std::string &texto, int &valor) {
    std::stringstream aux(texto);
    char resto;
    return ((aux >> valor) && !(aux >> resto));
}

bool aDecimal(const std::string &texto, double &valor) {
    std::stringstream aux(texto);
    char resto;
    return ((aux >> valor) && !(aux >> resto));
}

bool leerPedido(const std::string &linea, Pedido &pedido) {
    std::stringstream aux(linea);
    std::string campoId, cliente, fecha, tipoCafe, campoKg, campoTotal;
    int id;
    double kg, total;

    if (!std::getline(aux, campoId, ',')) return false;
    if (!std::getline(aux, cliente, ',')) return false;
    if (!std::getline(aux, fecha, ',')) return false;
    if (!std::getline(aux, tipoCafe, ',')) return false;
    if (!std::getline(aux, campoKg, ',')) return false;
    if (!std::getline(aux, campoTotal)) return false;

    if (!aEntero(campoId, id)) return false;
    if (!aDecimal(campoKg, kg)) return false;
    if (!aDecimal(campoTotal, total)) return false;
    if (id <= 0 || kg <= 0 || total < 0) return false;

    pedido = Pedido(id, cliente, fecha, tipoCafe, kg, total);
    return true;
}

int cargarPedidos(const std::string &archivo, DList<Pedido> &lista, int &omitidas) {
    std::ifstream entrada(archivo.c_str());
    std::string linea;
    int cargados = 0;

    omitidas = 0;
    if (!entrada.is_open()) {
        return -1;
    }

    std::getline(entrada, linea);
    while (std::getline(entrada, linea)) {
        if (!linea.empty() && linea[linea.size() - 1] == '\r') {
            linea.erase(linea.size() - 1);
        }
        if (linea.empty()) {
            continue;
        }

        Pedido pedido;
        if (leerPedido(linea, pedido)) {
            lista.add(pedido);
            cargados++;
        } else {
            omitidas++;
        }
    }
    return cargados;
}

void imprimirLista(DList<Pedido> &lista) {
    DListIterator<Pedido> it(&lista);

    it.begin();
    while (!it.end()) {
        std::cout << it().toString() << std::endl;
        ++it;
    }
}

std::vector<Pedido> aVector(DList<Pedido> &lista) {
    std::vector<Pedido> resultado;
    DListIterator<Pedido> it(&lista);

    it.begin();
    while (!it.end()) {
        resultado.push_back(it());
        ++it;
    }
    return resultado;
}

void imprimirOrdenados(DList<Pedido> &lista) {
    Sorts<Pedido> ordenador;
    std::vector<Pedido> pedidos = aVector(lista);
    std::vector<Pedido> ordenados = ordenador.mergeSort(pedidos);

    int n = ordenados.size();
    for (int i = 0; i < n; i++) {
        std::cout << ordenados[i].toString() << std::endl;
    }
}

bool buscarPorId(DList<Pedido> &lista, int id, Pedido &encontrado) {
    DListIterator<Pedido> it(&lista);

    it.begin();
    while (!it.end()) {
        if (it().getId() == id) {
            encontrado = it();
            return true;
        }
        ++it;
    }
    return false;
}

int pedidosDeCliente(DList<Pedido> &lista, const std::string &texto) {
    DListIterator<Pedido> it(&lista);
    int encontrados = 0;

    it.begin();
    while (!it.end()) {
        if (it().getCliente().find(texto) != std::string::npos) {
            std::cout << it().toString() << std::endl;
            encontrados++;
        }
        ++it;
    }
    return encontrados;
}

void mostrarMenu() {
    std::cout << "\n===== Cafe Don Virginio: pedidos =====" << std::endl;
    std::cout << "1. Mostrar pedidos (en orden de registro)" << std::endl;
    std::cout << "2. Mostrar pedidos ordenados por total (Merge Sort)" << std::endl;
    std::cout << "3. Buscar pedido por ID" << std::endl;
    std::cout << "4. Ver pedidos de un cliente" << std::endl;
    std::cout << "5. Ver primer y ultimo pedido registrados" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cout << "Opcion: ";
}

int leerOpcion() {
    std::string linea;
    int opcion;

    if (!std::getline(std::cin, linea)) {
        return 6;
    }
    if (!aEntero(linea, opcion)) {
        return -1;
    }
    return opcion;
}

int main() {
    std::string archivo = "pedidos.csv";
    DList<Pedido> pedidos;
    int omitidas;
    int cargados;
    int opcion;

    cargados = cargarPedidos(archivo, pedidos, omitidas);
    if (cargados < 0) {
        std::cout << "No se pudo abrir el archivo: " << archivo << std::endl;
        return 1;
    }
    std::cout << "Se cargaron " << cargados << " pedidos de " << archivo;
    if (omitidas > 0) {
        std::cout << " (" << omitidas << " lineas omitidas por formato invalido)";
    }
    std::cout << std::endl;

    do {
        mostrarMenu();
        opcion = leerOpcion();
        std::cout << std::endl;

        if (opcion == 1) {
            if (pedidos.empty()) {
                std::cout << "No hay pedidos registrados." << std::endl;
            } else {
                imprimirLista(pedidos);
            }
        } else if (opcion == 2) {
            if (pedidos.empty()) {
                std::cout << "No hay pedidos registrados." << std::endl;
            } else {
                std::cout << "[OK] Pedidos ordenados por monto total:\n" << std::endl;
                imprimirOrdenados(pedidos);
            }
        } else if (opcion == 3) {
            std::string linea;
            int id;
            Pedido encontrado;

            std::cout << "ID del pedido: ";
            if (!std::getline(std::cin, linea) || !aEntero(linea, id)) {
                std::cout << "\nEl ID debe ser un numero entero." << std::endl;
            } else if (buscarPorId(pedidos, id, encontrado)) {
                std::cout << "\n" << encontrado.toString() << std::endl;
            } else {
                std::cout << "\nNo existe un pedido con el ID " << id << "." << std::endl;
            }
        } else if (opcion == 4) {
            std::string texto;

            std::cout << "Nombre del cliente (o parte del nombre): ";
            if (!std::getline(std::cin, texto) || texto.empty()) {
                std::cout << "\nDebes escribir un nombre." << std::endl;
            } else {
                std::cout << std::endl;
                if (pedidosDeCliente(pedidos, texto) == 0) {
                    std::cout << "No se encontraron pedidos para ese cliente." << std::endl;
                }
            }
        } else if (opcion == 5) {
            if (pedidos.empty()) {
                std::cout << "No hay pedidos registrados." << std::endl;
            } else {
                std::cout << "Primero: " << pedidos.getFirst().toString() << std::endl;
                std::cout << "Ultimo:  " << pedidos.getLast().toString() << std::endl;
            }
        } else if (opcion != 6) {
            std::cout << "Opcion invalida." << std::endl;
        }
    } while (opcion != 6);

    return 0;
}
