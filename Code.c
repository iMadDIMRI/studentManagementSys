#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FonctionSource.c"

int main(){
    char studentN[100];
    FILE *fileR = fopen("Database.txt", "r");
    if (fileR == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    FILE *fileW = fopen("Database.txt", "a");
    if (fileW == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    //Close files
    fclose(fileW);
    fclose(fileR);
    return 1;
}