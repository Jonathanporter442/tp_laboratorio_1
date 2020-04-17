
#include <stdio.h>
#include <stdlib.h>
#include "operacionesCalculadora.h"

int main()
{
    int opcion;
    float num1;
    float num2;
    float resultado1;
    float resultado2;
    float resultado3;
    float resultado4;
    int factorial1;
    int factorial2;

    do
    {
        printf("\n\n1- Ingresar numero A \n");
        printf("2- Ingresar numero B \n");
        printf("3- Realizar las operaciones \n");
        printf("4- Mostrar resultado \n");
        printf("5- salir \n");

        scanf("\n%d", &opcion);


        switch(opcion)
        {

        case 1:

            printf("\nIngrese el numero ");
            scanf("%f", &num1);

            break;


        case 2:

            printf("\nIngrese el numero ");
            scanf("%f", &num2);
            break;


        case 3:

            resultado1 = sumar(num1,num2);

            resultado2 = restar(num1,num2);

            resultado3 = multip(num1,num2);

            if(num2 !=0)
            {
                resultado4  = divid(num1,num2);
            }
            else
            {
                printf("\n\nNo es posible dividir por cero.\n\n");
            }

            factorial1 = factorial(num1);
            factorial2 = factorial(num2);

            break;


        case 4:

            printf("El resultado de la suma es: %.f\n\n",resultado1);
            printf("El resultado de la resta es: %.f\n\n",resultado2);
            printf("El resultado de la multiplicacion es: %.f\n\n",resultado3);
            printf("El resultado de la division es: %.2f\n\n",resultado4);
            printf("La factorial del primer numero ingresado es: %d\n",factorial1);
            printf("La factorial del segundo numero ingresado es: %d\n\n",factorial2);

            break;


        case 5:

            printf("\n\nEligio salir del programa.\n\n");
            break;

        default:
            printf("\n\nEsa no es una opcion valida.\n\n");



        }
    }
    while(opcion!=5);

    return 0;
}
