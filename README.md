# Taller de Programacion - TP Threads

El presente trabajo práctico aborda la comunicación entre múltiples clientes y un servidor respecto de las acciones del juego Jazz Jackrabbit. Se comunican a través de sockets, cuya implementación es la dada por la cátedra:

[Repositorio de Sockets de la cátedra](https://github.com/eldipa/sockets-en-cpp)

A su vez, se trata de un proyecto multi-threading donde la implementación de la clase thread es la dada por la cátedra:

[Repositorio de Threads de la cátedra](https://github.com/eldipa/hands-on-threads)

## Compilación

Desde el root del proyecto

`make`

Esto generara los ejecutables.
## Uso

* Para ejecutar el servidor

`./server <puerto>`
* Para ejecutar un cliente (se permiten múltiples clientes)

`./client <hostname> <servicio>`

## Modelo

El trabajo consta de 3 partes principales: client, common, y server. 

### Client

El cliente es quien se encarga de leer las acciones ingresadas por el usuario. Las mismas son enviadas al servidor mediante ClientProtocol (quien se comunica con el socket) con el protocolo establecido por el juego. Las acciones posibles son Atacar, Leer <n> , y Salir. La última cierra el socket del cliente.

Por cada comando de leer se imprimen por pantalla la cantidad de eventos (n). Se trata de una acción bloqueante, ya que si el cliente pide leer más eventos de los sucedidos, se quedará esperando a que sucedan la cantidad de eventos necesarios para poder imprimirlos. 


### Common

Simplemente son clases que utilizan tanto el server como el cliente. Se encuentra la clase Socket con sus dependencias, y StatusPrinter ya que tanto el servidor como el cliente deben imprimir por pantalla con el mismo formato.

### Server


![img](/docs/server_uml.png?raw=true "img")

Aquí se implementa la lógica multi-threading. Todas las clases terminadas con Thread son hilos independientes que heredan de la clase Thread de la cátedra. Se posee un hilo para el gameloop, el cual contiene a Game con los 5 enemigos (se inicializan vivos). Dicho gameloop simula 5 iteraciones por segundo, y todos los enemigos reviven a los 3 segundos de haber muerto. Los enemigos mueren cuando un cliente ingresa Atacar.

Luego está el hilo aceptador, el cual se encarga de aceptar a los nuevos clientes que se quieran conectar. Dicho hilo lanza por cada cliente 2 hilos más: el receiver y el sender. El receiver se encarga de recibir los mensajes del cliente mediante su socket (solo pueden ser attacks), y aplica la lógica necesaria para que los ataques se vean efectuados. Luego, el sender se fija los eventos sucedidos y los envía al cliente. Ambos hacen lo mencionado anteriormente reiteradamente hasta que sus hilos se vean cerrados porque el cliente ingresó Salir y se cierra su socket.

### Queues

Es importante destacar que se utilizan colas thread-safe (la clase del Dipa) para poder hacer funcionar todo. 
Cada receiver posee una referencia de una única queue llamada Clients Commands que le pertenece al Game. Cada receiver encola el comando attack cada vez que lo recibe del cliente.
Luego, cada Sender posee una propia cola llamadas Server Messages de donde popea los mensajes del servidor. El Game posee un monitor de una clase llamada MapQueues la cual tiene un mapa con referencias a las queues mencionadas de cada sender. Cada una de estas queues posee una id única.

Finalmente, cabe mencionar que el gameloop nunca puede trabarse, por lo que utiliza try_push y try_pop que son acciones no bloqueantes. Es decir, si la cola está vacía try_pop devuelve false en lugar de quedarse esperando que tenga un elemento, y si la cola está llena try_push devuelve false en lugar de esperar que se libere un espacio. 
En cambio, pop es bloqueante y se queda esperando a que haya un elemento en la cola (si estaba vacía), y push es bloqueante y se queda esperando que se libere un espacio en la cola (si estaba llena).

Para mayor legibilidad, separé el diagrama de las queues en dos partes. 

![img](/docs/clients_commands_queue.png?raw=true "img")

![img](/docs/server_messages_queue.png?raw=true "img")
