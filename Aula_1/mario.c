#include <cs50.h>
#include <stdio.h>

int main(void){
    int i;

    do{
        i = get_int ("Altura: \n");
    }
    while (i < 1 || i > 8);



    for (int x = 0; x < i; x++)
    {

        for (int y1 = 0; y1 <= i-x-2; y1++){
        printf(" ");
        }
        for (int y = 0; y <= x; y++){

        printf("#");
        }
    printf("\n");
    }

}