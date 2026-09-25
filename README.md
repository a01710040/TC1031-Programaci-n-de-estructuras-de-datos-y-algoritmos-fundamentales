# Proyecto: Sistema de Distribución Café Don Virginio
Este proyecto es un sistema de gestión y organización de pedidos para el emprendimiento de distribución de Café Don Virginio, producido en la sierra. Permite administrar los registros de ventas de manera estructurada y consultarlos ordenados según su valor financiero.

## Descripción del avance 1
En este avance 1, se modelaron los pedidos utilizando la clase `Pedido` y se implementó un programa interactivo en C++ que inicializa una lista de ventas en memoria dentro de un `std::vector<Pedido>`. El programa integra la plantilla de algoritmos de ordenamiento `Sorts<T>` vista en clase para organizar los pedidos por su monto total a cobrar mediante el algoritmo `mergeSort`.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance` 

## ¿Cómo usar el programa?

Al ejecutar el programa se muestra el menú principal interactivo:

```text
=== SISTEMA DE DISTRIBUCION CAFE DON VIRGINIO ===
1. Mostrar pedidos originales (sin ordenar)
2. Ordenar pedidos por Total (Merge Sort)
3. Salir
Selecciona una opcion:
```

### 1. Mostrar pedidos originales (sin ordenar)

Al seleccionar la opción `1`, el programa despliega la lista completa de ventas registradas en el orden inicial en el que están almacenadas en memoria. Para cada pedido se muestra su ID, cliente, fecha de registro, tipo de café (molido o grano), kilogramos y el monto total a cobrar.

### 2. Ordenar pedidos por Total (Merge Sort)

Al seleccionar la opción `2`, el programa ejecuta el algoritmo **Merge Sort** para clasificar todos los pedidos de manera ascendente tomando como criterio el monto total (`total`). Inmediatamente después, despliega la lista resultante ordenada de menor a mayor precio.

### 3. Salir

Al seleccionar la opción `3`, el programa imprime el mensaje `Saliendo del programa...` y finaliza la ejecución de forma limpia.

Si se ingresa un valor que no corresponda a las opciones del menú (por ejemplo, `4` o un número negativo), el programa despliega el mensaje de advertencia:

```text
Opcion invalida.
```

## Descripción de las entradas del avance de proyecto
Las entradas son generadas dinámicamente en memoria dentro del archivo `main.cpp` mediante la inicialización directa de la estructura `std::vector<Pedido>`. Cada objeto de la clase `Pedido` contiene los siguientes atributos:
- `id` (`int`): Identificador único del pedido.
- `cliente` (`std::string`): Nombre o razón social del comprador.
- `fecha` (`std::string`): Fecha de registro ("YYYY-MM-DD").
- `tipoCafe` (`std::string`): Presentación del producto ("Molido" o "Grano").
- `cantidadKg` (`double`): Volumen de café solicitado en kilogramos.
- `total` (`double`): Monto acumulado a cobrar en pesos mexicanos.

Ejemplo de inicialización de datos en C++:
```cpp
std::vector<Pedido> pedidos = {
    Pedido(101, "Cafeteria El Centro", "2026-08-10", "Molido", 15.5, 3875.00),
    Pedido(102, "Abarrotes Don Pedro", "2026-08-12", "Grano", 5.0, 1150.00)
};
```

## Descripción de las salidas del avance de proyecto
Las salidas se despliegan en la consola mediante la función `imprimirLista()`, la cual invoca el método `toString()` de cada objeto `Pedido`. Al seleccionar la opción de ordenamiento dentro del menú interactivo, el programa muestra la lista formateada de los pedidos ordenados de forma ascendente por el monto total a cobrar.

Ejemplo de salida en consola:
```text
[OK] Pedidos ordenados por monto total:

ID: 104 | Cliente: Maria Elena Gomez | Fecha: 2026-08-15 | Tipo: Molido | Kg: 2 | Total: $500
ID: 102 | Cliente: Abarrotes Don Pedro | Fecha: 2026-08-12 | Tipo: Grano | Kg: 5 | Total: $1150
ID: 105 | Cliente: Restaurante El Mirador | Fecha: 2026-08-14 | Tipo: Grano | Kg: 10 | Total: $2300
ID: 101 | Cliente: Cafeteria El Centro | Fecha: 2026-08-10 | Tipo: Molido | Kg: 15.5 | Total: $3875
ID: 103 | Cliente: Hotel Sierra Azul | Fecha: 2026-08-11 | Tipo: Grano | Kg: 25 | Total: $5750
```

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El desarrollo de esta competencia se demuestra en el análisis del algoritmo `mergeSort` de la clase `Sorts<T>` utilizado en `main.cpp`:

- **Mejor Caso - $O(n \log n)$:** Ocurre de forma constante independientemente del estado inicial de los datos. La función `mergeSplit` divide recursivamente el vector a la mitad ($\log n$ niveles de división) y `mergeArray` realiza la mezcla de los elementos en $O(n)$ por cada nivel.
- **Caso Promedio - $O(n \log n)$:** Se mantiene por la consistencia de la estrategia Divide y Vencerás.
- **Peor Caso - $O(n \log n)$:** No presenta degradación de rendimiento sin importar el grado de desorden de los elementos.


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El desarrollo de esta competencia se demuestra en la elección e integración de **Merge Sort** para el sistema de Café Don Virginio:
- **Justificación del algoritmo:** En mi sistema del café los datos representan transacciones comerciales que se busca y se esperan que escalen de una manera rápida conforme el negocio progresa.A difrencia de Insertion Sort que se vuele ineficiente con conjuntos de datosde tamaño mediano a grande, Merge sort tiende a mantener el mismo rendimiento y complejidad sin importar el volumen de los pedidos, por lo que puede garantizar tiempos de respuestas prácticamente instantaneos. Y aunque quick sort suele ser más rápido en promedio su peor caso se degrada si la lista ya está casi ordenada o si no se elige un buen pivote, además no es un algoritmo estable por defecto, y en cuanto a Merge Sort, su tiempo de ejecución es totalmente determínistico por lo que nunca habrá un escenario en el que el sistema se retrase por datos en un orden desfavorable.
