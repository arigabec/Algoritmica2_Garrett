# Trie
Trie es una estructura de datos de tipo árbol que permite la recuperación de información. La información almacenada en un trie es un conjunto de claves, donde una clave es una secuencia de símbolos pertenecientes a un alfabeto.

Las claves son almacenadas en las hojas del árbol y los nodos internos son pasarelas para guiar la búsqueda. El árbol se estructura de forma que cada letra de la clave se sitúa en un nodo de forma que los hijos de un nodo representan las distintas posibilidades de símbolos diferentes que pueden continuar al símbolo representado por el nodo padre.

Podemos representar esta estructura utilizando un array o un map pero, para determinar cuál nos conviene usar debemos ver las ventajas y desventajas que tiene cada uno.

![image](https://user-images.githubusercontent.com/80705691/129494531-17f8b2bd-0a09-4bc0-b0c5-4a1634a89d57.png)

El árbol de Trie tiene algunas características:
1. El nodo raíz no contiene caracteres y cada nodo, excepto el nodo raíz, contiene solo un carácter.
2. Desde el nodo raíz hasta cierto nodo, los caracteres que pasan por la ruta se conectan para formar la cadena de caracteres correspondiente al nodo.
3. Todos los nodos secundarios de cada nodo contienen caracteres diferentes.
4. Si el número de caracteres es n, entonces el grado de salida de cada nodo es n, que también es una manifestación del espacio para el tiempo, que desperdicia mucho espacio.
5. La complejidad de la búsqueda por inserción es O (n) y n es la longitud de la cadena.

