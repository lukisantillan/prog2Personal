/*
Un arbol se define como un nodo raiz, el cual puede tener una serie de descendientes, cada descendiente puede ser raiz de un subarbol, por lo tanto cada subarbol, 
puede tener descendiente, y asi hasta llegar a lo que llamamos "hojas", es una estructura recursiva, un arbol nulo es cuando la raiz no exista. Cuando creemos el arbol
nulo la raiz no va a apuntar a ningun lado. El nodo mas importante es la raiz, si perdemos la raiz, perdemos el arbol, el acceso a todo el arbol es a traves del nodo raiz. 

Hay dos tipos de arboles
    -Binarios
    -N-arios = no sabemos la cantidad maxima de hijos que pueda llegar a tener el arbol, depende de la ejecucion. N > 2.


El grado del arbol se define en funcion de saber cual es la mayor cantidad de hijos de un determinado nodo, un arbol binario es de grado 2, en el grado n-ario el
grado es n. 

Hermanos : Son los nodos que dependen del mismo padre.
Padre: Todos los nodos tienen un padre a excepcion de la raiz.
Camino : Enlace entre dos nodos consecutivos.
Rama: Es un camino que termina en una hoja.
Nivel: Cantidad de pasos que tengo que dar para alcanzar un nodo desde la raiz.  POR LO GENERAL EL NIVEL ES 0 EN LA RAIZ. 
Altura: Determina el numero maximo de nodos desde la raiz, hasta el nodo mas profundo del arbol.
Peso: Se determina por la cantidad de nodos terminales u hojas. 

Arbol binario: Los dos hijos se consideran hijo izquierdo e hijo derecho. Cada nodo puede tener 0 hijos, 1 hijo o dos hijos. Cada hijo sera un subarbol  y puede cumplir
con las caracteristicas anteriores, el nodo que no tenga hijos es la hoja. 

Arbol similar: Lo tengo cuando la estructura es igual, sin importar los datos que contengan. 

Arbol Equivalente: Lo tengo cuando tienen la misma estructura y el mismo contenido. 

Arbol Equilibrado: Es aquel donde cada nodo entre los hijos izquierdo y derechos, tienen una relacion de altura que en absoluto es <= 1.

Arbol binario completo: 

Arbol binario Lleno: Es aquel que todos sus niveles estan llenos.

Arbol Binario degenerado: todos los nodos salvo las hojas tienen un solo hijo.

Como determinar cuantos son los nodos del arbol si esta lleno: 
Cantidad maxima de nodos: 2^H-1 (H = ALTURA);
Altura del arbol lleno: log2(n+1).

Los arboles n-arios se transforman en binarios, Al hijo descendiente de mas a la izquierda se lo llama HIJO EXTREMO IZQUIERDO. Los hijos derechos del arbol
Se llaman hermanos derechos.  

Se puede implementar con punteros y cursores. Se define el nodo <NodoArbol> que debe contener como mínimo: 
                                                                            - Dato a guardar
                                                                            - Puntero al hijo izquierdo
                                                                            - Puntero al hijo derecho
                                                                            - (Factor de equlibrio) nos ayuda a mantener un arbol equilibrado. 
El arbol tiene un puntero al nodo raiz. 

Se pueden recorrer de dos maneras:
    - Por profundidad: Se divide en 3 formas, tiene que ver con el momento en el cual voy a procesar el nodo. 
        - Pre-orden, procesa la raiz, agarra por la izquierda y despues por la derecha. La repite en cada nodo. PRIMERA VEZ QUE LO TOCO
        - In-orden, Deja la raiz en el medio de los dos subarboles, primero hace el arbol izquierdo, despues la raiz, y despues el derecho SEGUNDA VEZ
        -Post-orden, primero recorre los subarboles y por ultimo la raiz. ULTIMA VEZ QUE LO TOCO 
    - Por anchura: Se divide en 2. Recorren el arbol nivel por nivel, hasta que sea acaben
        - Toma los nodos de izquierda a derecha.
        - Toma los nodos de derecha a izquierda.

*/