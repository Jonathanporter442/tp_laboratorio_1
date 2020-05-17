#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define LIBRE -1
#define OCUPADO 1


typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;
}eEmpleado;
/** \brief se encarga de inicializar los estados y el id
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int inicializarEmpleado(eEmpleado lista[], int tam);
/** \brief se encarga de buscar el primer indice que este libre
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int buscarLibre(eEmpleado lista[],int tam);
/** \brief guarda los datos de un empleado
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \param id int recibe el un id de un empleado
 * \param nombre[] char recibe el nombre de un empleado
 * \param apellido[] char recibe el apellido de un empleado
 * \param salario float recibe el salario de un empleado
 * \param sector int recibe el sector de un empleado
 * \param indice int recibe el indice de un empleado
 * \param estado int recibe el una posicion de la lista de empleados, que esta libre
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int guardarEmpleado(eEmpleado lista[], int tam, int id, char nombre[],char apellido[],float salario,int sector,int indice,int estado);
/** \brief agrega un empleado
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int agregarEmpleados(eEmpleado lista[], int tam);
/** \brief busca un empleado por su id
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \param id int recibe el id por el cual se quiere buscar
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int buscarEmpleado(eEmpleado lista[], int tam,int id);
/** \brief se encarga de dar de baja a un empleado
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int eliminarEmpleado(eEmpleado lista[], int tam);
/** \brief ordena a los empleados primero por apellido, y en el caso de que sean iguales, lo ordena por sector
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \param orden int recibe el orden por el cual se quiere realizar, ascendente o descendente
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int ordenarEmpleadosxNombreYSector(eEmpleado lista[], int tam, int orden);
/** \brief muestra por pantalla a un empleado
 *
 * \param lista eEmpleado recibe un solo empleado
 * \return void
 *
 */
void mostrarUnEmpleado(eEmpleado lista);
/** \brief muestra a todos los empleados si tienen de estado ocupado
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int mostrarEmpleados(eEmpleado lista[], int tam);
/** \brief pide un entero
 *
 * \param mensaje[] char es el mensaje que queremos que aparesca para pedir el entero
 * \return int  devuelve el numero ingresado
 *
 */
int pedirEntero(char mensaje[]);
/** \brief pide una cadena
 *
 * \param mensaje[] char es el mensaje que queremos que aparesca para pedir la cadena
 * \param mensajeError[] char es el mensaje que queremos que aparesca para indicar un error
 * \param laCadena[] char es donde se a va guardar la cadena
 * \return void
 *
 */
void pedirCadena(char mensaje[], char mensajeError[], char laCadena[]);
/** \brief realiza un id de forma automatica, siempre aumenta el valor
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int devuelve el id mayor
 *
 */
int generadorDeId(eEmpleado lista[],int tam);
/** \brief pide un fltante
 *
 * \param mensaje[] char es el mensaje que queremos que aparesca para pedir el flotante
 * \return int devuelve el numero ingresado
 *
 */
int pedirFlotante(char mensaje[]);
/** \brief pide un caracter
 *
 * \param mensaje[] char es el mensaje que queremos que aparesca para pedir un caracter
 * \return char devuelve el caracter ingresado
 *
 */
char pedirCaracter(char mensaje[]);
/** \brief modifica los datos de un empleado
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int returno devuelve 1 o -1 para indicar que cumplio o no la funcion(respectivamente)
 *
 */
int modificarEmpleado(eEmpleado lista[],int tam);
/** \brief lista a los empleados de forma alfabeticamente o el total,promedio y cantidad de empleados cuyo salario es superior al promedio
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return void
 *
 */
void informarEmpleados(eEmpleado lista[],int tam);
/** \brief calcula suma de los salarios de todos los empleados cargados
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return float devuelve la el total de los salarios
 *
 */
float calcularTotal(eEmpleado lista[],int tam);
/** \brief calcula el promedio de los salarios de los empleados cargados
 *
 * \param lista eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return float devuelve el promedio de los salarios
 *
 */
float calcularPromedio(eEmpleado lista[],int tam);
/** \brief informa el total, promedio y la cantidad de los empleados cuyo salario supera el promedio
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return void
 *
 */
void informarSalario(eEmpleado lista[],int tam);
/** \brief informa la cantidad de los empleados cuyo salario supera el promedio
 *
 * \param lista[] eEmpleado recibe la lista de empleados
 * \param tam int recibe la largo de la lista
 * \return int devuele esa misma cantidad
 *
 */
int cantidadESuperanPromedio(eEmpleado lista[], int tam);
