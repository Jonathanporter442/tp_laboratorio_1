#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define EMPLEADOS 1000
int main()
{
    int flagAlta=0;
    int opcion;
    int respuesta;
    eEmpleado listaEmpleados[EMPLEADOS];
    inicializarEmpleado(listaEmpleados,EMPLEADOS);
    do
    {


       opcion= pedirEntero("1) Ingresar Empleado\n2) Modificar Empleado\n3) Dar de baja un Empleado\n4) Informar\n5) Salir\n");
        fflush(stdin);


        system("cls");
        switch(opcion)
        {
        case 1:
        {
            respuesta=agregarEmpleados(listaEmpleados,EMPLEADOS);
            if(respuesta!=-1)
            {
                printf("Se a cargado con exito el empleado\n");
            }
            else
            {
                printf("No se a cargado con exito el empleado\n");
            }
            flagAlta++;
            break;
        }
        case 2:
        {
            if(flagAlta>0)
            {
                modificarEmpleado(listaEmpleados,EMPLEADOS);
                break;
            }
            else
            {
                printf("No puede ingresar a esta opcion hasta que cargue, al menos, un empleado primero\n ");
            }

        }
        case 3:
        {
            if(flagAlta>0)
            {
                respuesta=eliminarEmpleado(listaEmpleados,EMPLEADOS);

                if(respuesta==-1)
                {
                    printf("No se encontro el id del empleado\n");
                }
                else if(respuesta==1)
                {
                    printf("Se dio de baja correctamente \n");
                                        flagAlta--;

                }
            }
            else
            {
                printf("No puede ingresar a esta opcion hasta que cargue, al menos, un empleado primero\n ");

            }

            break;
        }
        case 4:
        {
            if(flagAlta>0)
            {
                informarEmpleados(listaEmpleados,EMPLEADOS);
            }
            else
            {
                printf("No puede ingresar a esta opcion hasta que cargue, al menos, un empleado primero\n ");

            }
            break;
        }

        case 5:
        {
            printf("Usted esta saliendo\n");
        }
        default:
        {
            printf("No ingreso una opcion valida. Intento de nuevo\n");
            break;
        }

        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);  //hardcodearOrquestas(listaOrquesta);
    // en el case 3
}
