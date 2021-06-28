#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void){
    float money;
    float coins = 0;

    do{
        money = get_float("Change owned: \n");
    }
    while(money < 0);

    float cents = round(money * 100);

    while (cents >= 25){
        cents = cents - 25;
        coins++;
    }

    while (cents >= 10){
            cents = cents - 10;
            coins++;
    }

    while (cents >= 5){
                cents = cents - 5;
                coins++;
    }

    while (cents > 0){
                    cents = cents - 1;
                    coins++;
    }


    printf("%.0f\n", coins);


}