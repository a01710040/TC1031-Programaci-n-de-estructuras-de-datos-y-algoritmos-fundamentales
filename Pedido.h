#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <string>
#include <iostream>
#include <sstream>

class Pedido {
private:
    int id;
    std::string cliente;
    std::string fecha;
    std::string tipoCafe;
    double cantidadKg;
    double total;

public:
    Pedido();
    Pedido(int _id, std::string _cliente, std::string _fecha, std::string _tipoCafe, double _cantidadKg, double _total);

    int getId() const;
    std::string getCliente() const;
    std::string getFecha() const;
    std::string getTipoCafe() const;
    double getCantidadKg() const;
    double getTotal() const;

    std::string toString() const;

    bool operator<(const Pedido&) const;
    bool operator>(const Pedido&) const;
    bool operator<=(const Pedido&) const;
    bool operator>=(const Pedido&) const;
};

Pedido::Pedido() {
    id = 0;
    cliente = "";
    fecha = "";
    tipoCafe = "";
    cantidadKg = 0.0;
    total = 0.0;
}

Pedido::Pedido(int _id, std::string _cliente, std::string _fecha, std::string _tipoCafe, double _cantidadKg, double _total) {
    id = _id;
    cliente = _cliente;
    fecha = _fecha;
    tipoCafe = _tipoCafe;
    cantidadKg = _cantidadKg;
    total = _total;
}

int Pedido::getId() const { return id; }
std::string Pedido::getCliente() const { return cliente; }
std::string Pedido::getFecha() const { return fecha; }
std::string Pedido::getTipoCafe() const { return tipoCafe; }
double Pedido::getCantidadKg() const { return cantidadKg; }
double Pedido::getTotal() const { return total; }

std::string Pedido::toString() const {
    std::stringstream aux;
    aux << "ID: " << id 
        << " | Cliente: " << cliente 
        << " | Fecha: " << fecha 
        << " | Tipo: " << tipoCafe 
        << " | Kg: " << cantidadKg 
        << " | Total: $" << total;
    return aux.str();
}

bool Pedido::operator<(const Pedido &right) const {
    return total < right.total;
}

bool Pedido::operator>(const Pedido &right) const {
    return total > right.total;
}

bool Pedido::operator<=(const Pedido &right) const {
    return total <= right.total;
}

bool Pedido::operator>=(const Pedido &right) const {
    return total >= right.total;
}

#endif 
