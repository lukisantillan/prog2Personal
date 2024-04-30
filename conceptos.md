# REPASO DE PROG 1.

El lenguaje de prog esta realcionado a un paradigma y ademas a definir si un lenguaje es compilado o interpretado.

Un lenguaje que compila es un lenguaje que chequea la sintaxis antes de ejecutar un programa. Esto no asegura que el 
programa funciona correctamente, solo chequea que no haya errores de sintaxis. 

Un lenguaje interpretado ejecuta y si hay algun error de sintaxis se aborta la ejecucion, tiene la ventaja de poder probar algo hasta cierto lugar, cosa que el compilador no me deja si en alguna parte del codigo hay un error. 

Despues existen plataformas virtuales que nos permite estar en un entorno de desarrollo con un proyecto ya asignado.

Existen tipos de datos primitivos.
    - Tienen tipos de datos numericos
        -Enteros y enteros largos (short, long)
        -float
        -precision de los tipos primitivos.
    - Tipos de datos de texto
        - Tipo char
        - tipo string variable y fijo.
        -Tipos de datos long string
    - Otros tipos primitivos.
        -Boolean.
        -Apuntadores.
Tipos definidos por el usuario
    -Vector o Array
        -Vector de dimnesion fija
        -Vector variables o dinamicas
    -Vectores de mas de una dimension.
        -vectores con dos dimensiones(matrices)
        -vectores de n dimensiones.
    -Tipos de datos refgistros
        -Concepto de registro
        -definicion de registros fijos y variables.
        -vector de registros.
Archivo
    -Archivo de texto
        - Sin encriptar
        - Se pueden leer con cualquier programa
        - Escritos solo en codigos ASCII
        - Se accede a los mimso solo en forma secuencial.
    -Archivos Binarios
        -Archivos encriptados.
        -Son generados y leidos por una aplicacion en particular
        -Almacenan dentro una estructura de datos de bloque fijo.
        -Se puede acceder a una determinada posicion en forma directa.
        -Se pueden leer y escribir al mismo tiempo.

-Recomendaciones para desarrollar un programa
    -Interpretar el problema que debemos resolver.
    -Desarrollar un algoritmo que pueda dar solucion al problema.
    -Probar el algoritmo con las situaciones NO normales del problema. Casos de excepcion.
    -Pasar el algoritmo al lenguaje seleccionado.
    -Definir las variables con nombres claros y con el tipo de datos necesarios para resolver el problema.
    -Documentar el programa para poder interpretarlo mejor en caso de tener que modificarlo en el futuro.
    -Probar el programa en casos normales y NO normales. 
    -Verificar que los resultaso tanto de casos normales como NO normales sean correctos.
    -Programa listo para poner en produccion.

# Clase 3 Archivos
-Archivos Binarios
    -Se debe definir un registro para almacenar dentro del archivo.
    -Se pueden manejar en forma:
        -   SECUENCIAL
        -   ALEATORIA
    -Definir el lugar del disco donde residirá el archivo.
    -Crear el archivo vació cuando no existe.
    -Si se manjea en fomra directa(aleatoria o random) se deben generar los registros vacios del dominio del problema.
    -Cada vez que se escribe en el archivo para asegurarse de que los datos estan guardados dentro del archivo se lo debe cerrar.
    -Se debe usar la libreria stdio.h
    -La mayoria de las funciones comienzan con la letra "f"
    - "fopen" abre el archivo. Posee para indicar el tipo de archivo y la forma de abrirlo.
        - FILE *fopen(nonmbre, caracter modo).
        -r abre un archivo de texto para lectura
        -w abre un archivo de texto para escritura desde el comienzo
        -a abre un archivo de texto para escritura al final del archivo 
        -rb abre un archivo binario para lecutra
        -wb abre un archivo binario para escritura desde el comienzo
        -ab abre un archivo binario para escritura al final del archivo.
        -r+ abre o crea un archivo de texto para lectura / escritura.
        -w+ crea un archivo de texto para lecutra / escritura.
        -a+ añade o crea un archivo de texto para lectura / escritura
        -rb+ abre o crea un archivo binario para lectura / escritura.
        -wb+ crea un archivo binario para lecutra / escritura.
        -ab+ añade o crea un archivo binario para lectura / escritura
    - "fclose" cierra el archivo 

    -fprintf() escribe en el archivo en vez de en la pantalla
    -fscanf() trae lo del archivo a las variables
    -fgetc

    -ARCHIVO BINARIO
        -   fread() para leer
        -   fwrite() para escribir 

# Clase 5 RECURSIVIDAD
    Se permite porque hay problemas que son recursivos, hay problemas que su solucion es una invocacion del mismo problema en un tamaño menor
    el caso tipico y ejemplo de recursion es el caso del calculo del factorial, porque el factorial es un problema donde su resolucion es parte
    de invocar el mismo problema. El factorial se soluciona multiplicando el numero por el factorial del anterior. Esto significa que la resolucion
    del problema es la invocacion del mismo en un tamaño menor. 
    - Hay algoritmos recursivos
    - Funciones recursivas
    - Problemas recursivos
    El problema recutsivo necesita resolverse con un ciclo a si mismo. 
    Lo iterativo es lo contrario a lo recursivo. 
    Es un algoritmo que soluciona el problema invocandose a si mismo y terminara en una funcion que se llamara asi misma y entregara un resultado cuando eso termine.
    Hay que tener en cuenta ademas de no entrar en un ciclo infinito, el no quedarnos sin espacio en memoria

    Hay dos tipos de recursion 
    La directa se da cuando yo dentro del mismo algoritmo me invoco a mi mismo:
    Directa Simple: incluye una unica llamada recursiva. Cuando se aplica se realiza una sola llamada en cada uno de los niveles que constituyen la aplicacion
    En la aplicacion existen dos fases:
        1- Niveles de anidamiento de llamdas recursivas hasta que se producen las condiciones de tope o condicion de salida.
        2- Vuelta atras de la recursion con resultados parciales en la expresion y tope en el valor que cumple con la condicion de inico. En el stack queda suspendido
        lo que no se puede resolver.

    Directa Multiple: En cada aplicacion se pueden producir varias aplicaciones de la misma funcion y dependen una de la otra para poder entregar un resultado. Esto
    quiere decir que hay llamadas recursivas en varios puntos de la funcion, el seguimiento de una funcion recursiva multiple describe un "arbol" de niveles de anidamiento
    de las llamadas recursivas efectuadas.

    Recursion final o de cola: No utiliza la pila, se hace antes de cada llamada, puede considerarse una recursividad complementaria a otro tipos de recutsividad, Al no
    existir calculos intermedios con los valores devueltos por cada aplicacion no se necesita el procedimiento de vuelta atras visto en otros tipos de recursividad. La ultima
    aplicacion devuelve el valor final resultatante.

    Recursion con parametros acumuladores se usa cuando necesito sumar o sacar un valor y no lo puedo entregar como parte de la funcion, entonces declaro una variable pasada
    por referencia que me permita acumular lo que necesito y cuando salgo de la funcion esa variable se traiga el valor acumulado, enrealidada a veces llamo a una rutina que uso de mascara que esa llama al proceso recursivo, pasandole parametros acumuladores. Por ejemplo si quiero sacar el promedio de un vector, que cuando llame a la funcion promedio le pase el vector y esta llame a otra funcion que se encargue de hacer la suma y contar la cantidad de elementos, pasandole estos dos parametro acumuladores, cuanddo finalice esta deberia solo hacer el calculo del promedio y no del calculo de acumular. 

    Backtracking: La usamos cuando recorremos arboles, es cuando yo inspecciono un determinado camino, no encuentro la salida y vuelvo hacia atras por donde fui. 

        Cuando la pila se llena nos puede saltar el error de "stack overflow".

    La indirecta es cuando tengo una serie de procesos donde hay alguno que llama al primero:
    Proceso A llama a proceso B, Proceso B a proceso C y C llame al Proceso A. No nos tenemos que olvidar que las llamadas tienen que finalizar.

    Cosas a tener en cuenta : 
     - Mi recursion es un loop, en algun momento se tiene que terminar, tengo que encontrar una condicion que consiga dejar de llamar recursivamente, este seria el caso
     base/caso embrionario. 
     - El caso recursivo es el caso que va a invocar al problema nuevamente tratando de que el problema se vaya reduciendo. 

     Si tengo que decidir entre algo que use o no recursividad, Lo que tengo que conocer es bien el problema, si yo tengo un problema que es netamente recursivo, lo resolvemos de esa manera, ya que el algoritmo puede ser mas sencillo, ya que es un problema recursivo y asi se soluciona. Despues analizo el tamaño del problema, es decir que tan critico puede ser si ese problema crece mucho, es decir ver si va a agotar la memoira, etc. 

     Hay que tener en cuenta como se comportan las variables, es decir si va por valor o referencia. NO ES LO MISMO DE LA MANERA EN QUE SE MANDE YA QUE PUEDEN AFECTAR AL RESULTADO. El pasaje de parametros es crucial tanto como las variables locales que se definen adentro de la misma funcion. Cuando yo dejo cosas suspendidas por procesar,el lenguaje ademas de guardar las variables con sus valores, tiene que saber en que lugar quedo suspendida, ese lugar tambien tiene que guardarlo, el lugar donde se guarda es un registro de activacion y se guarda en la pila.

     Toda solucion recursiva a un problema tiene un equivalente iterativo y su viceversa. Podemos simular en nuestro programa lo que haria la pila del sistema. 

     Para emular una recursion tengo que emular las pilas o arboles, tengo que tener en cuenta el registro de activacion, es decir en donde va a quedar el algoritmo parado, para seguir hacindo lo que tiene que hacer donde esta el llamado recursivo. 

     Para los algoritmos recursivos, no olvidar el divide y venceras, si se puede hacer con recursividad indirecta mejor, no olvidar el tamaño del problema, para ver si realmetne se puede resolver recursivamente, tampoco el caso base y caso de llamada recursiva. 

# Apuntadores
    Los apuntadores o punteros, lo usamos porque muchas veces no sabemos de antemano cuanta memoria vamos a necesitar para la ejecucion de un determinado progama, el problema que tienen las variables estaticas, el espacio de memoria se reserva con anticipacion y no cambia durante la ejecucion del programa. Tiene ciertos inconvenientes en la configuracion estatica: 
        -Problemas de rigides, ya que estas estructuras no pueden cambiar su tamaño
    Nos da la posibilidad de utilizar la flexibilidad de poder utilizar el espacio de memoria, es delicado trabajar con punterso porque cuando los utilizo, lo primero que tengo que hacer es crear el puntero, que es decirle al sistema operativo cuantos bytes necesitamos para guardar lo siguietne, la flexibilidad se basa en que durante el tiempo de ejecucion, pido los bytes, hay que tener en cuenta que despues de terminar hay que devolver los bytes utilizados, para que estos queden disponibles. 
    Aliasing es que cuando yo direcciono sobre una misma variable, es decir tengo dos punteros que apuntan a la misma direccion de memoria. 
    Cuando yo defino una varibale del tipo puntero, lo que yo defino es una variable que contiene una direccion de memoria, que en esa direccion de memoria almaceno. Por lo tanto la varibale siempre ocupa una cantidad de bytes fijos, porque siempre almacena una direcciom de memoria, lo que haya en esa direccion depende del tipo de dato que apuntamos, La variable netamente de tipo puntero siempre almacena una direccion de memoria. 

    Tengo dos tipos de variables puntero, las que estan definidas por el usuario(int, char, etc) y las que son de proposito general (void).
    CASO 1: Mi puntero puede apuntar a int, char, o struct. El struct puede tener un campo que sea un puntero a otro dato.
    CASO 2: Son los que declaro con void y no se de antemano que le voy a poner ahi, pero cuando le quiero asignar algo al void, le hago un casting.
    Con malloc solicito el espacio de memoria del puntero. //STRCPY es para pegar algo en una variable(variable, "cosa a pegar").
    Las variables puntero ocupan una cantidad de memoria fija, que es la cantiadad que necesita para almacenar una direccion de memoria, independeintemente de lo que pueda ocupar el tipo de puntero. 
    La variable de tipo puntero no ocupa memoria hasta no crear el puntero. Crear y destruir en ejecucuion el puntero. El tipo de dato puntero es un tipo dato simple.
    malloc = para crear puntero
    free(variable_de_tipo_puntero) para eliminarlo. Libera el espacio de memoria, la variable de tipo puntero queda apuntando a la nada.
    Es recomendable anular el puntero despues de la instruccion Free.
    Cuando trabajamos con punteros, podemos asignar, leer, escribir, y luego lo que nos permita hacer el tipo de dato al que apuntamos, si por ejemplo apuntamos a enteros, podremos sumarlos. 
    Se pueden comparar dos punteros, es decir si dos punteros apuntan a la misma direccion de memoira, lo que comparamos son las direcciones y no el contenido. 
    Cuando no usamos * hacemos referencia a la direccion de memoria almacenada en el puntero, usando el * hacemos referencia al contenido.

# Estructuras de datos 

Tipos abstracto de datos, podemos construir diferentes tipos abstractos de datos, se componen de una estructura que nos permite almacenar los datos que necesito y una serie de operaciones que van a trabajar y administrar esos dato. 
Mecanismos de Abstracción:
- Procedimientos y funciones
    - Ocultar información
    - Reutilización de códigos
- Módulos
- Tipos Abstractos de Datos.
    - Definicion de estructuras de datos
    - Operaciones de mantenimiento
    - Proteccion de la información
    - Permitir instancias múltiples del tipo.
- Objetos
Las ventajas de la especificacion: son que evita ambiguedades en el uso de lenguaje de una especificacion informal, la definicion es independientemente de la representacion de datos.
- Metodo algebraico: sintactica: nombres(de los tipos) y dominios, semantica: comportamiento de las operaciones. Desventaja: no cualquiera maneja este tipo de especificaciones. Ventajas: Es declarativa, es decir describe cual es el comportamiento de las operaciones que mantienen las estructuras.


# Lista 
Es una coleccion de elementos homogenea ( todos los elementos tienen el mismo tipo de datos ). Estan ordenados segun su posicion, en forma lineal, uno detras del otro, tienen un orden posicional, cada elemento tiene un predecesor y sucesor, excepto el primero y el ultimo.
Hay 3 formas de implementar las listas usando dsitnitos recursos del lenguaje de programacion
- Usar array
- Usar apuntadores a memoria (Listas enlazadas)
- Usar array de registros ( Cursor simulando listas enlazadas ).
Objetivo
Se define el TipoElemento que es la estructura abstracta a lamcenar dentro de las TAD y como es una estructura (registro) se forma de campos, uno de laos cuales es especial y se lo donima clave y esta almacena un valor generico.

# IMPLEMENTACION DE LISTAS.
