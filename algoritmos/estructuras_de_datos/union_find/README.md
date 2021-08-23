# Union Find
Union Find nos sirve para unificar grupos de nodos y encontrar a sus padres. La idea consiste en recibir un arreglo donde inicialmente todos los nodos son padres de si mismos y luego pueden ser unidos con otros. De esta forma se facilita la busqueda ya que sino se tendrian que recorrer muchos nodos, y al unificarlos inicialmente, hacemos que unicamente se recorran unos cuantos nodos a partir del nodo padre.

![image](https://media.geeksforgeeks.org/wp-content/uploads/union3.png)

Este algoritmo cuenta con 3 métodos principalmente, y funcionan de la siguiente manera:
- makeSet(): junta todos los valores en un arreglo comun para asignarles un padre especifico (ellos mismos, inicialmente).
- find(): sirve para buscar recursivamente al nodo padre de un nodo.
- union(): convierte al padre de de un nodo b en el nuevo padre del padre de un nodo a.