#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FonctionSource.c"

int main(){
    char studentN[100];
    FILE *file = fopen("Database.txt", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    showAllS(file);
    //Close file
    fclose(file);
    return 1;
}