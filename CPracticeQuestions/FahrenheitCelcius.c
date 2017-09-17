#include<stdio.h>
void main(){
    float fahrenheit, celsius;
    printf("Fahrenheit\tCelsius\n");
    for(fahrenheit = 0; fahrenheit<=300; fahrenheit+=1){
        printf("%0.1f",fahrenheit);    //0.1f means 1 characters after decimal
        celsius = (5*fahrenheit - 160)/9;
        printf("\t\t%0.1f\n", celsius);
    }
}