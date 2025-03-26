# Push_Swap42

Pequeño proyecto en C para ordenar números usando dos pilas y un conjunto limitado de operaciones. Este proyecto está diseñado para funcionar de manera eficiente con listas de distintos tamaños.

🛠️ Instalación

Clona este repositorio y compila el programa:

 git clone https://github.com/tu_usuario/push_swap.git
 cd push_swap
 make

Esto generará el ejecutable push_swap.

🚀 Uso

Ejecuta el programa pasando una lista de números como argumentos:

./push_swap 4 67 3 87 23

El programa imprimirá en pantalla la secuencia de operaciones necesarias para ordenar los números.

🔧 Operaciones disponibles

El programa utiliza un conjunto de operaciones específicas para manipular las pilas:

sa, sb, ss → Intercambiar los dos primeros elementos de una pila.

pa, pb → Mover el primer elemento de una pila a la otra.

ra, rb, rr → Rotar la pila hacia arriba.

rra, rrb, rrr → Rotar la pila hacia abajo.

🏎️ Estrategia de ordenación

El algoritmo implementado varía en función del número de elementos:

Para listas pequeñas (≤ 5 elementos), se usa un conjunto de reglas específicas.

Para listas más grandes, se implementa un algoritmo basado en quicksort/buckets para minimizar el número de movimientos.

📜 Evaluación y pruebas

Puedes probar el programa con diferentes valores y verificar su eficiencia con un checker:

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

También puedes contar el número de movimientos:

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

📌 Notas

El programa maneja errores de entrada (números duplicados, caracteres no válidos, etc.).

Se recomienda probar con valgrind para verificar posibles fugas de memoria:

valgrind --leak-check=full ./push_swap 4 67 3 87 23

🏗️ Autor

Desarrollado por Tu Nombre.

