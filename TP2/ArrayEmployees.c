#include "ArrayEmployees.h"
int inicializarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            lista[i].estado = LIBRE;
            lista[i].id=0;

        }
        retorno=1;
    }

    return retorno;
}
int buscarLibre(eEmpleado lista[],int tam)
{
    int i;
    int indice=-1;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if( lista[i].estado==LIBRE)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

int guardarEmpleado(eEmpleado lista[], int tam, int id, char nombre[],char apellido[],float salario,int sector,int indice,int estado)
{
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        lista[indice].id=id;
        strcpy(lista[indice].nombre,nombre);
        strcpy(lista[indice].apellido,apellido);
        lista[indice].salario=salario;
        lista[indice].sector=sector;
        lista[indice].estado=estado;
        retorno=1;
    }

    return retorno;
}
int agregarEmpleados(eEmpleado lista[], int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;
    int indice;
    int retorno;
    indice=buscarLibre(lista,tam);
    if(indice!=LIBRE)
    {
        id=generadorDeId(lista,tam);
        id++;
        pedirCadena("ingrese un nombre: ","Error al ingresar un nombre. Ingrese un nombre: ",nombre);
        pedirCadena("ingrese un apellido: ","Error al ingresar un apellido. Ingrese un apellido: ",apellido);
        salario=pedirFlotante("ingrese el salario: ");
        sector=pedirEntero("ingrese el sector: ");
        estado=OCUPADO;
        retorno=guardarEmpleado(lista,tam,id,nombre,apellido,salario,sector,indice,estado);
    }
    return retorno;
}
int buscarEmpleado(eEmpleado lista[], int tam,int id)
{
    int retorno=-1;
    int i;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(id==lista[i].id && lista[i].estado==OCUPADO)
            {
                retorno=i;
            }
        }



    }
    return retorno;
}
int eliminarEmpleado(eEmpleado lista[], int tam)
{
    int retorno=-1;
    int idBaja;
    int indice;
    if(lista!=NULL && tam>0)
    {

        mostrarEmpleados(lista,tam);
        idBaja=pedirEntero("Ingrese el id, del empleado, que desea dar de baja: \n");
        indice=buscarEmpleado(lista,tam,idBaja);
        if(indice!=-1)
        {
            // printf("");
            //pedirCaracter("Estas seguro kpo?\n Ingrese s")
            lista[indice].estado=LIBRE;
            //printf("Se dio de baja correctament\n");
            retorno=1;
        }


    }
    return retorno;
}
int ordenarEmpleadosxNombreYSector(eEmpleado lista[], int tam, int orden)
{
    int retorno=-1;
    int i;
    int j;
    eEmpleado auxEmpleado;
    if(lista!=NULL && tam>0)
    {
        if(orden==1)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(stricmp(lista[i].apellido,lista[j].apellido )>0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        auxEmpleado=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmpleado;

                    }
                    else if(stricmp(lista[i].apellido,lista[j].apellido)==0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        if(lista[i].sector<lista[j].sector)
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
            }
        }
        else if(orden==0)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(stricmp(lista[i].apellido,lista[j].apellido )<0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        auxEmpleado=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmpleado;

                    }
                    else if(stricmp(lista[i].apellido,lista[j].apellido)==0&& lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        if(lista[i].sector>lista[j].sector)
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
            }
        }

        retorno=1;
    }

    return retorno;
}


void mostrarUnEmpleado(eEmpleado lista)
{
    printf("%10d %15s %15s \t%.2f %10d\n",lista.id,lista.nombre,lista.apellido,lista.salario,lista.sector);
}
int mostrarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        printf("        ID           NOMBRE         APELLIDO   SALARIO     SECTOR\n");
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                mostrarUnEmpleado(lista[i]);
            }
        }
        retorno=1;
    }#include "ArrayEmployees.h"
int inicializarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            lista[i].estado = LIBRE;
            lista[i].id=0;

        }
        retorno=1;
    }

    return retorno;
}
int buscarLibre(eEmpleado lista[],int tam)
{
    int i;
    int indice=-1;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if( lista[i].estado==LIBRE)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

int guardarEmpleado(eEmpleado lista[], int tam, int id, char nombre[],char apellido[],float salario,int sector,int indice,int estado)
{
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        lista[indice].id=id;
        strcpy(lista[indice].nombre,nombre);
        strcpy(lista[indice].apellido,apellido);
        lista[indice].salario=salario;
        lista[indice].sector=sector;
        lista[indice].estado=estado;
        retorno=1;
    }

    return retorno;
}
int agregarEmpleados(eEmpleado lista[], int tam)
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;
    int indice;
    int retorno;
    indice=buscarLibre(lista,tam);
    if(indice!=LIBRE)
    {
        id=generadorDeId(lista,tam);
        id++;
        pedirCadena("ingrese un nombre: ","Error al ingresar un nombre. Ingrese un nombre: ",nombre);
        pedirCadena("ingrese un apellido: ","Error al ingresar un apellido. Ingrese un apellido: ",apellido);
        salario=pedirFlotante("ingrese el salario: ");
        sector=pedirEntero("ingrese el sector: ");
        estado=OCUPADO;
        retorno=guardarEmpleado(lista,tam,id,nombre,apellido,salario,sector,indice,estado);
    }
    return retorno;
}
int buscarEmpleado(eEmpleado lista[], int tam,int id)
{
    int retorno=-1;
    int i;
    if(lista!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(id==lista[i].id && lista[i].estado==OCUPADO)
            {
                retorno=i;
            }
        }



    }
    return retorno;
}
int eliminarEmpleado(eEmpleado lista[], int tam)
{
    int retorno=-1;
    int idBaja;
    int indice;
    if(lista!=NULL && tam>0)
    {

        mostrarEmpleados(lista,tam);
        idBaja=pedirEntero("Ingrese el id, del empleado, que desea dar de baja: \n");
        indice=buscarEmpleado(lista,tam,idBaja);
        if(indice!=-1)
        {
            // printf("");
            //pedirCaracter("Estas seguro kpo?\n Ingrese s")
            lista[indice].estado=LIBRE;
            //printf("Se dio de baja correctament\n");
            retorno=1;
        }


    }
    return retorno;
}
int ordenarEmpleadosxNombreYSector(eEmpleado lista[], int tam, int orden)
{
    int retorno=-1;
    int i;
    int j;
    eEmpleado auxEmpleado;
    if(lista!=NULL && tam>0)
    {
        if(orden==1)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(stricmp(lista[i].apellido,lista[j].apellido )>0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        auxEmpleado=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmpleado;

                    }
                    else if(stricmp(lista[i].apellido,lista[j].apellido)==0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        if(lista[i].sector<lista[j].sector)
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
            }
        }
        else if(orden==0)
        {
            for(i=0; i<tam-1; i++)
            {
                for(j=i+1; j<tam; j++)
                {
                    if(stricmp(lista[i].apellido,lista[j].apellido )<0 && lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        auxEmpleado=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxEmpleado;

                    }
                    else if(stricmp(lista[i].apellido,lista[j].apellido)==0&& lista[i].estado==OCUPADO && lista[j].estado==OCUPADO)
                    {
                        if(lista[i].sector>lista[j].sector)
                        {
                            auxEmpleado=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxEmpleado;
                        }
                    }
                }
            }
        }

        retorno=1;
    }

    return retorno;
}


void mostrarUnEmpleado(eEmpleado lista)
{
    printf("%10d %15s %15s \t%.2f %10d\n",lista.id,lista.nombre,lista.apellido,lista.salario,lista.sector);
}
int mostrarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int retorno=-1;
    if(lista!=NULL && tam>0)
    {
        printf("        ID           NOMBRE         APELLIDO   SALARIO     SECTOR\n");
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                mostrarUnEmpleado(lista[i]);
            }
        }
        retorno=1;
    }
    return retorno;
}
int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;

}
void pedirCadena(char mensaje[], char mensajeError[], char laCadena[])
{
    char auxCadena[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxCadena);
    while(strlen(auxCadena)>51)
    {
        char auxCadena[100];
        printf(mensajeError);
        fflush(stdin);
        gets(auxCadena);
    }
    strcpy(laCadena,auxCadena);
}
int pedirFlotante(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}
int generadorDeId(eEmpleado lista[],int tam)
{
    int i;
    int idMayor;
    //int id;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(flag==0 || lista[i].id>idMayor)
        {
            idMayor=lista[i].id;


            flag=1;

        }
    }
    return idMayor;
}
char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}
int modificarEmpleado(eEmpleado lista[],int tam)
{
    int retorno=-1;
    int idModificar;
    int indice;
    int opcion;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    char confirmar;
    eEmpleado auxEmpleado;
    if(lista!=NULL && tam>0)
    {

        mostrarEmpleados(lista,tam);
        idModificar=pedirEntero("ingrese el id, del empleado, que desea modificar: \n");
        indice=buscarEmpleado(lista,tam,idModificar);
        auxEmpleado=lista[indice];
        if(indice!=-1)
        {
            retorno=1;

            opcion= pedirEntero("¡Que desea modificar!\n1) Nombre:\n2) Apellido\n3) Salario\n4) Sector\n5)Salir\n");
            switch(opcion)
            {
            case 1:
            {
                pedirCadena("Ingrese el nuevo nombre\n","Error. Ingrese un nuevo nombre",nombre);
                strcpy(auxEmpleado.nombre,nombre);

                break;
            }
            case 2:
            {
                pedirCadena("Ingrese el nuevo apellido\n","Error. Ingrese un nuevo apellido",apellido);
                strcpy(auxEmpleado.apellido,apellido);
                break;
            }
            case 3:

            {
                salario=pedirFlotante("ingrese un nuevo salario: ");
                auxEmpleado.salario=salario;
                break;

            }
            case 4:
            {
                sector=pedirEntero("ingrese el sector: ");
                auxEmpleado.sector=sector;
                break;

            }
            case 5:
                {
                    printf("Usted esta saliendo");
                }
            default:
            {
                printf("Opcion invalida");
            }
            }
            if(retorno==1)
            {
               confirmar =pedirCaracter("Esta seguro que desea guardar los  cambios? Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               while(!(confirmar=='s'||confirmar=='n'||confirmar=='N'||confirmar=='S'))
               {
                   confirmar =pedirCaracter("Error.Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               }
                if(confirmar=='s'||confirmar=='S')
                {
                    lista[indice]=auxEmpleado;
                    printf("Se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("No se han realizado las modificaciones\n");

                }
            }
        }
        system("pause");
        system("cls");
    }
    return retorno;
}
void informarEmpleados(eEmpleado lista[],int tam)
{
    int opcion;
    int ordenar;
    int retorno;
    if(lista!=NULL && tam>0)
    {
        do
        {
            opcion=pedirEntero("1)  Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n3) Salir\n ");
            system("cls");
            switch(opcion)
            {
            case 1:
            {
                ordenar=pedirEntero("1) Ordenar de forma ascendente\n0) Ordenar de forma descendente\n");
                retorno=ordenarEmpleadosxNombreYSector(lista,tam,ordenar);
                if(retorno!=-1)
                {
                    mostrarEmpleados(lista,tam);
                }
                else
                {
                    printf("No se a podido realizar el ordenamiento");

                }

                break;
            }
            case 2:
            {
                informarSalario(lista,tam);
                break;
            }
            case 3 :
            {
                printf("Usted esta saliendo\n");
                break;
            }
            default:
            {
                printf("Opcion incorrecta\n");
            }
            }
            system("pause");
            system("cls");
        }
        while(opcion!=3);
    }
}
float calcularTotal(eEmpleado lista[],int tam)
{
    float suma=0;
    float retorno=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            suma=suma+lista[i].salario;
            retorno=suma;
        }
    }
    return retorno;
}
float calcularPromedio(eEmpleado lista[],int tam)
{
    float promedio;
    float retorno;
    int contador=0;
    int i;
    retorno=calcularTotal(lista,tam);
    if(retorno!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                contador++;
            }
        }
        promedio=retorno/contador;
        retorno=promedio;
    }
    return retorno;
}
void informarSalario(eEmpleado lista[],int tam)
{
    int opcion;
    float total;
    float promedio;
    int cantidad;
    do
    {
        opcion=pedirEntero("Ingrese la opcion que desea ver\n1) Total de los salarios\n2) Promedio de los salarios\n3) Empleados que superan el promedio\n4) Salir\n");
        switch(opcion)
        {
        case 1:

        {
            total=calcularTotal(lista,tam);
            if(total!=-1)
            {
                printf("El total de los salaraios es: %f\n",total);
            }
            else
            {
                printf("No se pudo calcular el total");
            }
            break;
        }
        case 2:
        {
            promedio=calcularPromedio(lista,tam);
            if(promedio!=-1)
            {
                printf("El promedio de los salarios es: %f\n",promedio);

            }
            else
            {
                printf("No se pudo calcular el promedio");
            }
            break ;
        }
        case 3:
        {
            cantidad=cantidadESuperanPromedio(lista,tam);
            printf("La cantidad que empleados que superan el salario promedio son: %d\n",cantidad);
            break;
        }
        case 4:
        {
            printf("Usted esta saliendo\n");
            break;
        }
        default:
        {
            printf("Error. Ingrese una opcion valida\n");
        }
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);





}
int cantidadESuperanPromedio(eEmpleado lista[], int tam)
{

    int promedio;
    int cantidad=0;
    int i;
    promedio=calcularPromedio(lista,tam);
    printf("        ID           NOMBRE         APELLIDO   SALARIO     SECTOR\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO && lista[i].salario>promedio)
        {
            cantidad++;
            mostrarUnEmpleado(lista[i]);
        }
    }
    return cantidad;
}
    return retorno;
}
int pedirEntero(char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;

}
void pedirCadena(char mensaje[], char mensajeError[], char laCadena[])
{
    char auxCadena[100];
    printf("%s",mensaje);
    fflush(stdin);
    gets(auxCadena);
    while(strlen(auxCadena)>51)
    {
        char auxCadena[100];
        printf(mensajeError);
        fflush(stdin);
        gets(auxCadena);
    }
    strcpy(laCadena,auxCadena);
}
int pedirFlotante(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);

    return numero;
}
int generadorDeId(eEmpleado lista[],int tam)
{
    int i;
    int idMayor;
    //int id;
    int flag=0;
    for(i=0; i<tam; i++)
    {
        if(flag==0 || lista[i].id>idMayor)
        {
            idMayor=lista[i].id;


            flag=1;

        }
    }
    return idMayor;
}
char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&caracter);

    return caracter;
}
int modificarEmpleado(eEmpleado lista[],int tam)
{
    int retorno=-1;
    int idModificar;
    int indice;
    int opcion;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    char confirmar;
    eEmpleado auxEmpleado;
    if(lista!=NULL && tam>0)
    {

        mostrarEmpleados(lista,tam);
        idModificar=pedirEntero("ingrese el id, del empleado, que desea modificar: \n");
        indice=buscarEmpleado(lista,tam,idModificar);
        auxEmpleado=lista[indice];
        if(indice!=-1)
        {
            retorno=1;

            opcion= pedirEntero("¡Que desea modificar!\n1) Nombre:\n2) Apellido\n3) Salario\n4) Sector\n5)Salir\n");
            switch(opcion)
            {
            case 1:
            {
                pedirCadena("Ingrese el nuevo nombre\n","Error. Ingrese un nuevo nombre",nombre);
                strcpy(auxEmpleado.nombre,nombre);

                break;
            }
            case 2:
            {
                pedirCadena("Ingrese el nuevo apellido\n","Error. Ingrese un nuevo apellido",apellido);
                strcpy(auxEmpleado.apellido,apellido);
                break;
            }
            case 3:

            {
                salario=pedirFlotante("ingrese un nuevo salario: ");
                auxEmpleado.salario=salario;
                break;

            }
            case 4:
            {
                sector=pedirEntero("ingrese el sector: ");
                auxEmpleado.sector=sector;
                break;

            }
            case 5:
                {
                    printf("Usted esta saliendo");
                }
            default:
            {
                printf("Opcion invalida");
            }
            }
            if(retorno==1)
            {
               confirmar =pedirCaracter("Esta seguro que desea guardar los  cambios? Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               while(!(confirmar=='s'||confirmar=='n'||confirmar=='N'||confirmar=='S'))
               {
                   confirmar =pedirCaracter("Error.Ingrese 's' para guardar los cambios o 'n' para no guardar los cambio \n");
               }
                if(confirmar=='s'||confirmar=='S')
                {
                    lista[indice]=auxEmpleado;
                    printf("Se guardaron los datos correctamente\n");
                }
                else
                {
                    printf("No se han realizado las modificaciones\n");

                }
            }
        }
        system("pause");
        system("cls");
    }
    return retorno;
}
void informarEmpleados(eEmpleado lista[],int tam)
{
    int opcion;
    int ordenar;
    int retorno;
    if(lista!=NULL && tam>0)
    {
        do
        {
            opcion=pedirEntero("1)  Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n3) Salir\n ");
            system("cls");
            switch(opcion)
            {
            case 1:
            {
                ordenar=pedirEntero("1) Ordenar de forma ascendente\n0) Ordenar de forma descendente\n");
                retorno=ordenarEmpleadosxNombreYSector(lista,tam,ordenar);
                if(retorno!=-1)
                {
                    mostrarEmpleados(lista,tam);
                }
                else
                {
                    printf("No se a podido realizar el ordenamiento");

                }

                break;
            }
            case 2:
            {
                informarSalario(lista,tam);
                break;
            }
            case 3 :
            {
                printf("Usted esta saliendo\n");
                break;
            }
            default:
            {
                printf("Opcion incorrecta\n");
            }
            }
            system("pause");
            system("cls");
        }
        while(opcion!=3);
    }
}
float calcularTotal(eEmpleado lista[],int tam)
{
    float suma=0;
    float retorno=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            suma=suma+lista[i].salario;
            retorno=suma;
        }
    }
    return retorno;
}
float calcularPromedio(eEmpleado lista[],int tam)
{
    float promedio;
    float retorno;
    int contador=0;
    int i;
    retorno=calcularTotal(lista,tam);
    if(retorno!=-1)
    {
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==OCUPADO)
            {
                contador++;
            }
        }
        promedio=retorno/contador;
        retorno=promedio;
    }
    return retorno;
}
void informarSalario(eEmpleado lista[],int tam)
{
    int opcion;
    float total;
    float promedio;
    int cantidad;
    do
    {
        opcion=pedirEntero("Ingrese la opcion que desea ver\n1) Total de los salarios\n2) Promedio de los salarios\n3) Empleados que superan el promedio\n4) Salir\n");
        switch(opcion)
        {
        case 1:

        {
            total=calcularTotal(lista,tam);
            if(total!=-1)
            {
                printf("El total de los salaraios es: %f\n",total);
            }
            else
            {
                printf("No se pudo calcular el total");
            }
            break;
        }
        case 2:
        {
            promedio=calcularPromedio(lista,tam);
            if(promedio!=-1)
            {
                printf("El promedio de los salarios es: %f\n",promedio);

            }
            else
            {
                printf("No se pudo calcular el promedio");
            }
            break ;
        }
        case 3:
        {
            cantidad=cantidadESuperanPromedio(lista,tam);
            printf("La cantidad que empleados que superan el salario promedio son: %d\n",cantidad);
            break;
        }
        case 4:
        {
            printf("Usted esta saliendo\n");
            break;
        }
        default:
        {
            printf("Error. Ingrese una opcion valida\n");
        }
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);





}
int cantidadESuperanPromedio(eEmpleado lista[], int tam)
{

    int promedio;
    int cantidad=0;
    int i;
    promedio=calcularPromedio(lista,tam);
    printf("        ID           NOMBRE         APELLIDO   SALARIO     SECTOR\n");
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO && lista[i].salario>promedio)
        {
            cantidad++;
            mostrarUnEmpleado(lista[i]);
        }
    }
    return cantidad;
}
