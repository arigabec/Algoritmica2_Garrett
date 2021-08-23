# BIT
El BIT es una estructura de datos que proporciona métodos eficientes para el cálculo y la manipulación de las cantidades de prefijos de un array de valores.
Principalmente resuelve el problema de equilibrar la eficiencia de la suma del prefijo con la eficiencia de modificar un elemento. Es muy fácil para manejar un array de suma acumulativa y de este es posible calcular la suma de las frecuencias en un cierto rango en el orden de O (log (n)). Permite hacer este procedimiento además con cualquier operación asociativa.

![image](http://iq.opengenus.org/content/images/2019/07/i-1product.png)

El codigo de BIT es mas fácil que del Segment Tree, ya que tiene menos líneas de codigo.

Los métodos funcionan de la siguiente manera:
- update(): actualiza el valor contenido en la posicion que deseemos. De igual manera, inicializamos el árbol de BIT con un primer update() de cada posición con su valor.
- query(): realiza una operacion como ser el máximo, el mínimo o la suma de los nodos contenidos en un intérvalo específico.
