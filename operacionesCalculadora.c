
int sumar (int num1 , int num2)
{
    int resultado = num1 + num2;
    return resultado;
}


int restar (int num1 , int num2)
{
    int resultado = num1 - num2;
    return resultado;
}


int multip (int num1 , int num2)
{
    int resultado = num1 * num2;
    return resultado;
}


int divid (int num1 , int num2)
{
    int resultado = num1 / num2;
    return resultado;
}


int factorial(int num1)
{
    int factorial1;
    factorial1=num1;

    for (int i = factorial1 - 1; i >= 1; i--)
    {
        factorial1 = factorial1 * i;
    }
    return factorial1;
}
