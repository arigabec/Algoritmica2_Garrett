# Digit DP
Es una técnica de programación dinámica que sirve para resolver problemas sobre conteo o suma de los dígitos de un número, dado un rango desde a hasta b.

Dados 2 números a y b, podríamos hallar los números dentro del rango que cumplan una propiedad particular. Por ejemplo, dados 2 números podemos hallar todos los números dentro del rango [a,b] tales que estén compuestos por 2 números pares. Además, la solución puede dividirse en :

- f(a,b) = f(b) - f(a - 1)

![image](https://i.ytimg.com/vi/Pa4YwO8B8-w/maxresdefault.jpg)

Para resolver un problema usando Digit debemos seguir los siguientes pasos:
- Primeramente, debemos fabricar todos los números sin que excedan a x (x es el número máximo del rango dado).
- A partir de esto podemos calcular los números que cumplan la condición dada, fijándonos en la posicion de cada dígito y si el número en esa posicion es mayor o menor a x.