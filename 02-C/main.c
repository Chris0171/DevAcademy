#include <stdio.h>


int main(){
    int numero = 20;
    float decimal = 10.20;
    double decimalM = 20.30040;
    char letra = '%';

    printf("Numero entero: %d", numero);
    printf("\nNumero decimal: %.2f", decimal);
    printf("\nNumero decimal con mas precision: %.5lf", decimalM);
    printf("\nCaracter: %c", letra);

    // Entrada de datos
    int num; 
    printf("\nTeclea un numero entero: ");
    scanf("%d", &num);

    num = num * 20;
    printf("El numero tecleado se ha multiplicado por 20: %d",
    num);

    // Operadores aritmeticos
    int a = 10;
    int b = 8;
    int c = 4;

    printf("\nSuma: %d", a + b + c);
    printf("\nResta: %d", b - a - c);
    printf("\nMultiplicacion: %d", a * b * c);
    printf("\nDivision: %.2f", (float)a / b / c);
        
    // Condicionales
    int edad = 12;
    char genero = 'M';

    if(edad > 18){
        printf("\nEres mayor de edad");
    } else if (edad < 18){
        printf("\nEres menor de edad");
    }else{
        printf("\nTienes exactamente 18 años");
    }


    if(edad >= 18){
        printf("\nPuedes votar");
    }


    if(genero == 'M' && edad >= 18){
        printf("\nEres hombre y mayor de edad");
    }else{
        printf("\nEres mujer");
    }

    // Bucles (for)
    // contar de 1 a 10
    printf("\n");
    for(int i = 1; i <= 10; i++){
        if(i % 2 == 0){
            printf("%d ", i);
        }
    }


    return 0;
}

