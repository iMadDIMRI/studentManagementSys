#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FonctionSource.c"
#include <unistd.h>
#include <errno.h>
#include <conio.h>

void clrscr()
{
    system("@cls||clear");
}

int main(){
    char FName[20],LName[20];
    int N;
    char studentN[100];
    FILE *file = fopen("Database.txt", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }
    while(N){
        printf("MAIN MENU:\n 1:Add a student \n 2:Search a student \n 3:Show All student \n 4:Change a student's info \n 5:Delete a student \n 6:Delete ALL students \n 7:Clear Window \n 0:Exit the programme.\n ");
        scanf("%d",&N);
        switch(N){
            case 1:
            addStudent(file);
            break;
            case 2:
            printf("Enter the first Name:\n");
            scanf("%19s",FName);
            printf("Enter the Last Name:\n");
            scanf("%19s",LName);
            searchS(file,FName,LName);
            break;                
            case 3:
            showAllS(file);
            break;
            case 4:
            printf("Enter the first Name:\n");
            scanf("%19s",FName);
            printf("Enter the Last Name:\n");
            scanf("%19s",LName);
            editS(file,FName,LName);
            break;
            case 5:
            printf("Enter the first Name:\n");
            scanf("%19s",FName);
            printf("Enter the Last Name:\n");
            scanf("%19s",LName);
            deleteS(file,FName,LName);
            break;
            case 6:
            fclose(file);
            FILE *file = fopen("Database.txt", "wb+");
            if (file == NULL) {
                printf("Error reseting file!\n");
                return 0;
            }
            break;
            case 7:
            clrscr(); // Clear the screen
            printf("Screen cleared!\n");
            break;
            case 0:
            break;
        }
    }
    //Close file
    fclose(file);
    return 0;
}