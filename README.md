# Proyecto: Sistema de Distribución Café Don Virginio
Este proyecto es un sistema de gestión y organización de pedidos para el emprendimiento de distribución de Café Don Virginio, producido en la sierra. Permite administrar los registros de ventas de manera estructurada y consultarlos ordenados según su valor financiero.

## Descripción del avance 1
En este avance 1, se modelaron los pedidos utilizando la clase `Pedido` y se implementó un programa interactivo en C++ que inicializa una lista de ventas en memoria dentro de un `std::vector<Pedido>`. El programa integra la plantilla de algoritmos de ordenamiento `Sorts<T>` vista en clase para organizar los pedidos por su monto total a cobrar utilizando los métodos `mergeSort`, `insertionSort` y `selectionSort`.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -std=c++11 -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Las entradas son generadas dinámicamente en memoria dentro del archivo `main.cpp` mediante la función `cargarDatosIniciales()`. La función construye objetos de la clase `Pedido` con los siguientes atributos:
- `id` (`int`): Identificador único del pedido.
- `cliente` (`std::string`): Nombre o razón social del comprador.
- `fecha` (`std::string`): Fecha de registro ("YYYY-MM-DD").
- `tipoCafe` (`std::string`): Presentación del producto ("Molido" o "Grano").
- `cantidadKg` (`double`): Volumen de café solicitado en kilogramos.
- `total` (`double`): Monto acumulado a cobrar en pesos mexicanos.

## Descripción de las salidas del avance de proyecto
Escribe aquí la descripción de los resultados de la ejecución de tu programa.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Escribe aquí tus argumentos sobre por qué consideras que has desarrrollado esta competencia y dónde se puede observar el desarrollo que mencionas.
