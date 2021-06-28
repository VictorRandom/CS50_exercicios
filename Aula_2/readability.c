#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main (void){
    string s = get_string("Text: \n");

    float letter = 0;
    float words = 1;
    float senteses = 0;

    for (int i = 0, n = strlen(s); i < n; i++){

        if(isalpha(s[i])){
            letter++;
        } else if (isspace(s[i])){
            words++;
        } else if (s[i] == '.' || s[i] == '?' || s[i] == '!'){
            senteses++;
        }
    }

    float L = letter / words * 100;
    float S = senteses / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int indexi = round(index);

    if(indexi >= 1 && indexi <= 16){
        printf("Grade %i\n", indexi);
    } else if (indexi < 1){
        printf("Before Grade 1\n");
    } else{
        printf("Grade 16+\n");
    }
}
