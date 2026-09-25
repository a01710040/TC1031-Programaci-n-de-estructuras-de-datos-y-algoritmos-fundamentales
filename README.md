# Proyecto Avance 1: Sistema de Distribución de Café Don Virginio

**Materia:** TC1031 Programación de estructuras de datos y algoritmos fundamentales  
**Profesor:** Eduardo Juárez Pérez  
**Autor:** Raúl Enrique Torres Ledesma  
**Matrícula:** A01710040 

---

## Descripción del Proyecto
Este proyecto consiste en un sistema de gestión de pedidos para un emprendimiento de distribución de café producido en la sierra. El programa inicializa un conjunto de registros de ventas directamente en memoria mediante un `std::vector<Pedido>`, y permite al usuario consultar los datos ordenados por el monto total a cobrar utilizando las implementaciones de la plantilla `Sorts<T>` vistas en clase.

---

## Estructura de Archivos
* `Pedido.h`: Clase entidad que modela un pedido de café y sobrecarga los operadores de comparación (`<`, `>`, `<=`, `>=`).
* `sorts.h`: Plantilla con las implementaciones de los algoritmos de ordenamiento vistas en clase (`mergeSort`, `insertionSort`, `selectionSort`).
* `main.cpp`: Menú interactivo en consola y función de carga de datos en memoria.

---

## Instrucciones para Compilar y Ejecutar

### Compilación (Terminal)
```bash
g++ -std=c++11 main.cpp -o sistema_cafe
