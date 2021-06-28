#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int arc, string argv[]){

    if (arc != 2){
        printf("Something went wrong \n");
        return 1;
    } else {

    string s = get_string("Plaintex: ");
    printf("ciphertext: ");

    for (int i = 0, n = strlen(s); i < n; i++){

        if( isupper (s[i]) ){

            if (atoi (argv[1]) + s[i] - 65 > 25){
                int ASC11 = atoi (argv[1]) + s[i] - 65;
                int alpha = ASC11 % 26;
                int back = alpha + 65;

            printf("%c", back);
            } else {
            printf("%c", atoi (argv[1]) + s[i]);
            }
            }

        else if ( islower (s[i]) ){
            if (atoi (argv[1]) + s[i] - 97 > 25){
                int ASC12 = atoi (argv[1]) + s[i] - 97;
                int alpha2 = ASC12 % 26;
                int back2 = alpha2 + 97;

                printf("%c", back2);
            } else {
                printf("%c", atoi (argv[1]) + s[i]);
            }
        } else {
            printf("%c", s[i]);
        }
    }
     printf("\n");
    }
}