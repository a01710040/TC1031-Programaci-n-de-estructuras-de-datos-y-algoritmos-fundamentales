# Proyecto: Sistema de Distribución Café Don Virginio
Este proyecto es un sistema de gestión y organización de pedidos para el emprendimiento de distribución de Café Don Virginio, producido en la sierra. Permite administrar los registros de ventas de manera estructurada y consultarlos ordenados según su valor financiero.

## Descripción del avance 1
En este avance 1, se modelaron los pedidos utilizando la clase `Pedido` y se implementó un programa interactivo en C++ que inicializa una lista de ventas en memoria dentro de un `std::vector<Pedido>`. El programa integra la plantilla de algoritmos de ordenamiento `Sorts<T>` vista en clase para organizar los pedidos por su monto total a cobrar mediante el algoritmo `mergeSort`.

## Descripción del avance 2
En este avance los pedidos ya no están escritos dentro del código: se **leen de un archivo `pedidos.csv`** y se **almacenan en una lista doblemente encadenada** (`DList<Pedido>`, en `dlist.h`). El programa conserva el ordenamiento con Merge Sort del avance 1, pero ahora lo aplica sobre los datos cargados desde el archivo, y agrega mecanismos para consultar la información: buscar un pedido por ID, ver los pedidos de un cliente y ver el primer y el último pedido registrados.

### Cambios sobre el primer avance
1. **Los datos se cargan desde `pedidos.csv`.** En el avance 1 los cinco pedidos estaban escritos en `main.cpp`, así que cualquier pedido nuevo obligaba a modificar y recompilar el programa. Con el archivo, los datos se cambian sin tocar el código.
2. **Los pedidos se guardan en una `DList<Pedido>` en lugar de un `std::vector<Pedido>`.** Los pedidos se registran con el paso del tiempo (se agregan al final) y se recorren de forma secuencial. La lista permite agregar al final en $O(1)$ sin reservar ni copiar memoria contigua, y conserva el orden de registro. El `std::vector` solo se usa como copia temporal para ordenar, porque `Sorts<T>` trabaja con vectores.
3. **Se agregaron consultas:** buscar por ID, pedidos de un cliente y primer/último pedido registrado. Sin ellas, la información almacenada solo podía verse completa o completa y ordenada.
4. **El menú lee la opción como una línea de texto.** En el avance 1, escribir una letra en el menú provocaba un ciclo infinito; ahora se muestra "Opcion invalida." y el programa sigue funcionando, incluso si la entrada termina de forma inesperada.
5. **Se usa el `dlist.h` visto en clase, con `getLast()` implementado.** En el archivo de clase `getLast()` estaba declarado pero no definido; se implementó igual que `getFirst()` pero regresando `tail->value`, porque se necesita para consultar el último pedido en $O(1)$. `dlist.h` incluye `exception.h`, por lo que también se agrega a la carpeta.

## Instrucciones para compilar el avance de proyecto
Los archivos `main.cpp`, `Pedido.h`, `Sorts.h`, `dlist.h`, `exception.h` y `pedidos.csv` deben estar en la misma carpeta. Ejecuta el siguiente comando en la terminal:
 
`g++ main.cpp -std=c++11 -o segundo_avance`

## Descripción de las entradas del avance de proyecto
### Archivo `pedidos.csv`
Archivo de texto con un pedido por línea y los campos separados por comas. **La primera línea es el encabezado y se ignora.** El formato es:
 
```text
id,cliente,fecha,tipoCafe,cantidadKg,total
101,Cafeteria El Centro,2026-08-10,Molido,15.5,3875.00
102,Abarrotes Don Pedro,2026-08-12,Grano,5.0,1150.00
103,Hotel Sierra Azul,2026-08-11,Grano,25.0,5750.00
```
 
- `id` (entero mayor a 0): identificador del pedido.
- `cliente` (texto): nombre del comprador. No puede contener comas.
- `fecha` (texto): fecha de registro, `AAAA-MM-DD`.
- `tipoCafe` (texto): `Molido` o `Grano`.
- `cantidadKg` (decimal mayor a 0): kilogramos pedidos.
- `total` (decimal mayor o igual a 0): monto a cobrar en pesos mexicanos.
Las líneas vacías se ignoran. Si una línea tiene campos faltantes o números inválidos, no se carga y se cuenta como omitida. Si el archivo no se puede abrir, el programa avisa y termina.
 
### Menú
El usuario escribe el número de la opción y, según la opción, un ID (número entero) o el nombre de un cliente (o parte del nombre, sin importar mayúsculas o minúsculas).
 
## Descripción de las salidas del avance de proyecto
Al iniciar, el programa informa cuántos pedidos cargó y muestra el menú:
 
```text
Se cargaron 12 pedidos de pedidos.csv
 
===== Cafe Don Virginio: pedidos =====
1. Mostrar pedidos (en orden de registro)
2. Mostrar pedidos ordenados por total (Merge Sort)
3. Buscar pedido por ID
4. Ver pedidos de un cliente
5. Ver primer y ultimo pedido registrados
6. Salir
Opcion:
```
 
- **Opción 1:** una línea por pedido, en el orden en que aparecen en el archivo.
- **Opción 2:** los pedidos de menor a mayor `total`:
```text
  [OK] Pedidos ordenados por monto total:
 
  ID: 104 | Cliente: Maria Elena Gomez | Fecha: 2026-08-15 | Tipo: Molido | Kg: 2 | Total: $500
  ID: 109 | Cliente: Maria Elena Gomez | Fecha: 2026-09-05 | Tipo: Grano | Kg: 3 | Total: $690
  ...
  ID: 107 | Cliente: Hotel Sierra Azul | Fecha: 2026-08-25 | Tipo: Grano | Kg: 30 | Total: $6900
```
- **Opción 3:** el pedido con el ID indicado, o `No existe un pedido con el ID 999.` Si lo escrito no es un número: `El ID debe ser un numero entero.`
- **Opción 4:** todos los pedidos cuyo cliente contiene el texto escrito, o `No se encontraron pedidos para ese cliente.`
- **Opción 5:** el primer y el último pedido registrados (en el orden del archivo, no por fecha):
```text
  Primero: ID: 101 | Cliente: Cafeteria El Centro | Fecha: 2026-08-10 | Tipo: Molido | Kg: 15.5 | Total: $3875
  Ultimo:  ID: 112 | Cliente: Tienda La Sierra | Fecha: 2026-09-18 | Tipo: Molido | Kg: 6 | Total: $1500
```
- **Opción 6:** termina el programa. Cualquier otro valor muestra `Opcion invalida.`


## Desarrollo de competencias

### SICT0301: Evalúa los componentes

Para demostrar esta competencia, se analiza formalmente la razón matemática y algorítmica por la cual el algoritmo **Merge Sort** implementado en `Sorts.h` responde a una complejidad de **$O(n \log n)$**.

#### 1. Origen del componente $\log n$: Cantidad de divisiones recursivas
La función `mergeSplit` parte el vector por la mitad en cada llamada.
* Cada paso reduce el tamaño de las sublistas.
* La cantidad de veces que un conjunto de tamaño $n$ se puede dividir a la mitad hasta llegar a elementos individuales de tamaño 1 está dada por la función logarítmica base 2: $\log_2(n)$.
* Esto significa que la secuencia de llamadas recursivas se ejecuta a lo largo de exactamente **$\log_2(n)$ etapas de división**.

#### 2. Origen del componente $n$:
En cada etapa de la recursión, la función `mergeArray` se encarga de combinar las sublistas de forma ordenada.
* Para realizar la mezcla, el ciclo `while` compara los valores y los coloca en el vector auxiliar `tmp`. Posteriormente, un ciclo `for` copia de vuelta estos elementos al arreglo principal.
* En cualquier etapa de la recursión, la suma total de los elementos distribuidos entre todas las sublistas que se están procesando **siempre es igual a $n$**.
* Por lo tanto, el trabajo de comparación y copia acumulado en cada etapa de mezcla es estrictamente lineal: **$O(n)$**.

#### 3. Demostración de la Complejidad Global $O(n \log n)$
La complejidad total se obtiene multiplicando la cantidad de etapas de división por el trabajo de mezcla requerido en cada una de ellas:

$$\text{Complejidad Total} = \log_2(n) \times O(n) = O(n \log n)$$

#### Justificación del comportamiento en cada escenario:

| Escenario | Complejidad | Razón Algorítmica |
| :--- | :---: | :--- |
| **Mejor caso** | $O(n \log n)$ | La división recursiva se realiza siempre hasta el final. No existe una condición de parada temprana aunque el vector inicial ya se encuentre ordenado. |
| **Caso promedio** | $O(n \log n)$ | Las particiones dividen el arreglo simétricamente a la mitad en cada paso, manteniendo constante la cantidad de etapas en $\log_2(n)$ y la complejidad en $O(n)$. |
| **Peor caso** | $O(n \log n)$ | Incluso en el caso con mayor cantidad de intercalaciones, la cantidad de etapas no cambia y la complejidad sigue en $O(n)$ en cada paso. |

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El desarrollo de esta competencia se demuestra en la elección e integración de **Merge Sort** para el sistema de Café Don Virginio:
##### Justificación del algoritmo:
- En mi sistema del café los datos representan transacciones comerciales que se busca y se esperan que escalen de una manera rápida conforme el negocio progresa.A diferencia de Insertion Sort que se vuelve ineficiente con conjuntos de datos de tamaño mediano a grande, Merge sort tiende a mantener el mismo rendimiento y complejidad sin importar el volumen de los pedidos, por lo que puede garantizar tiempos de respuestas prácticamente instantaneos.
- Aunque Quick Sort suele ser más rápido en promedio su peor caso se degrada si la lista ya está casi ordenada o si no se elige un buen pivote, además no es un algoritmo estable por defecto, y en cuanto a Merge Sort, su tiempo de ejecución es totalmente determínistico por lo que nunca habrá un escenario en el que el sistema se retrase por datos en un orden desfavorable.

### SICT0303: Implementa acciones científicas
 
#### Implementa mecanismos para consultar información de las estructuras correctos.
Todas las consultas están en el menú y recorren la lista con el iterador de `DList`:
- **Buscar por ID** (`buscarPorId`, `main.cpp`, línea 147): regresa el pedido, o indica que no existe. Valida que lo escrito sea un entero.
- **Pedidos de un cliente** (`pedidosDeCliente`, línea 164): imprime los pedidos cuyo cliente contiene el texto, sin importar mayúsculas, y regresa cuántos encontró. Esto permite buscar con el nombre completo o con una parte.
- **Primer y último pedido registrados** (líneas 279 y 280): usa `getFirst()` y `getLast()` de la lista en $O(1)$.
- **Pedidos ordenados por total** (`imprimirOrdenados`, línea 135): usa Merge Sort sobre una copia, sin alterar la lista.
En todos los casos se manejan los resultados vacíos (no existe el ID, no hay pedidos de ese cliente, la lista está vacía) con un mensaje claro.
 
#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- `cargarPedidos` (`main.cpp`, línea 73) abre `pedidos.csv` con `std::ifstream`, ignora la línea de encabezado y, por cada línea, llama a `leerPedido` (línea 47). Cada pedido válido se agrega a la `DList` con `add`.
- `leerPedido` separa los seis campos por comas con `std::getline` y convierte los números con `aEntero` y `aDecimal`, que rechazan texto como `x` o `12abc`. También valida que el `id` y los kilogramos sean mayores a 0 y que el total no sea negativo.
- Las líneas inválidas no detienen la carga: se omiten y al inicio el programa informa cuántas fueron omitidas.
- Se manejan las líneas vacías, los saltos de línea de Windows (`\r\n`) y el caso de que el archivo no exista (el programa avisa y termina con código 1).
