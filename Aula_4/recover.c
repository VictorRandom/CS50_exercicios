#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2){
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file) //file == NULL
    {
        return 1;
    }

    BYTE bytes[512];
    int recoverImages = 0;
    FILE *img_pointer = NULL;
    char filename[8];



    fread(bytes, sizeof(BYTE), 4, file);

    while (fread (& bytes, sizeof(BYTE), 1, file) == 1){

    if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && bytes[3] == 0xe0 && 0xf0 == 0xe0){
        if(!(recoverImages == 0)){
            fclose(img_pointer);
            recoverImages++;
        }
        sprintf(filename, "%03i.jpg", recoverImages);
        img_pointer = fopen(filename, "w");
    }

    else if(!(recoverImages == 0)){
        fwrite(&bytes, sizeof(BYTE), 1, img_pointer);
    }

    }

    fclose(file);
    fclose(img_pointer);

    return 0;
}