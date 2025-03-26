# push_swap  

Pequeño proyecto en C para ordenar números usando dos pilas y un conjunto limitado de operaciones. Este proyecto está diseñado para funcionar de manera eficiente con listas de distintos tamaños.  

## 🛠️ Instalación  
Clona este repositorio y compila el programa:  
```bash
git clone https://github.com/davx00/Push_Swap42.git push_swap
cd push_swap  
make
```

## 🚀 Uso

Ejecuta el programa pasando una lista de números como argumentos:
```bash
./push_swap 4 67 3 87 23  
```
El programa imprimirá en pantalla la secuencia de operaciones necesarias para ordenar los números.

## 🔧 Operaciones disponibles

El programa utiliza estas operaciones para manipular las pilas:

sa/sb/ss: Intercambia los dos primeros elementos de la pila a/b/ambas
pa/pb: Mueve el primer elemento de una pila a la otra
ra/rb/rr: Rota la pila hacia arriba (el primer elemento pasa al final)
rra/rrb/rrr: Rota la pila hacia abajo (el último elemento pasa al inicio)

##  🏎️ Estrategia de ordenación

El algoritmo varía según el tamaño de la lista:

≤ 5 elementos: Algoritmo optimizado con reglas específicas
> 5 elementos: Implementación tipo quicksort/buckets para minimizar movimientos

## 📜 Evaluación y pruebas

Verifica la corrección:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
Cuenta los movimientos:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```


## 📌 Notas importantes

Gestión de errores: Detecta números duplicados y caracteres inválidos
Prueba de memoria:
```bash
valgrind --leak-check=full ./push_swap 4 67 3 87 23
```
#  🏗️ Autor

Desarrollado por despanol
