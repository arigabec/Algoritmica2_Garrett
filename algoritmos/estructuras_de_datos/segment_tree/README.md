# Segment Tree
El Segment Tree es una estructura de datos que sirve para responder varias consultas de agregación tipo máximo, mínimo, sumas, promedio, multiplicaciones y otras, en tiempo log N para un universo de N elementos.
Típicamente, un Segment Tree se construye para responder consultas sobre un arreglo; también se pueden hacer actualizaciones de elementos de ese arreglo que tardan tiempo log N.

![image](https://programming.vip/images/doc/b15e4588c3635c11a0ecebb18cc806a7.jpg)

Para construir un Segment Tree debemos crear una estructura node que guardará los resultados de las operaciones necesarias, como ser el máximo, mínimo o la suma de sus nodos hijos. Ademas, crearemos una variable de tipo int[] para poder almacenar los datos, los cuales convertiremos en nodos en nuestra propia estructura segmentTree[].

Los métodos funcionan de la siguiente manera:
-  init(): inicia el segment tree.
- query(): responde a una consulta de un nodo especifico o de un conjunto de nodos en un determinado intérvalo.
- update(): permite realizar una actualización de la información contenida en una casilla del arreglo original.