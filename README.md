# Proyecto: Sistema de Distribución Café Don Virginio
Este proyecto es un sistema de gestión y organización de pedidos para el emprendimiento de distribución de Café Don Virginio, producido en la sierra. Permite administrar los registros de ventas de manera estructurada y consultarlos ordenados según su valor financiero.

## Descripción del avance 1
En este avance 1, se modelaron los pedidos utilizando la clase `Pedido` y se implementó un programa interactivo en C++ que inicializa una lista de ventas en memoria dentro de un `std::vector<Pedido>`. El programa integra la plantilla de algoritmos de ordenamiento `Sorts<T>` vista en clase para organizar los pedidos por su monto total a cobrar mediante el algoritmo `mergeSort`.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

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
- **Complejidad Espacial - $O(n)$:** Requiere un vector auxiliar `tmp` de tamaño $n$ para almacenar temporalmente los subarreglos combinados antes de copiarlos de regreso a la estructura principal.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El desarrollo de esta competencia se demuestra en la elección e integración de **Merge Sort** para el sistema de Café Don Virginio:
- **Justificación del algoritmo:** En la operación comercial del negocio, el volumen de pedidos puede escalar a miles de registros. Se seleccionó Merge Sort sobre alternativas como Insertion Sort o Selection Sort porque garantiza un tiempo de ejecución acotado de $O(n \log n)$ en el peor caso, previniendo congelamientos del programa durante la consulta de ventas.
- **Uso correcto en C++:** El algoritmo opera sobre una estructura `std::vector<Pedido>` utilizando la sobrecarga explícita de operadores de comparación (`<`, `>`, `<=`, `>=`) definida en la clase `Pedido`, la cual evalúa directamente la propiedad `total`.
