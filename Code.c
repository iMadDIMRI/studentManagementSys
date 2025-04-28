#include "FonctionSource.c"

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
        printf("MAIN MENU:\n 1:Add a student \n 2:Search a student \n 3:Show All student \n 4:Change a student's info \n 5:Delete a student \n 6:Delete ALL students \n 7:Clear Window \n 0:Exit the programme.\n NB:When you enter a value and it reask you for the same information it means you didnt enter it in the correct format showen by the question\n");
        scanf("%d",&N);
        switch(N){
            case 1:
            addStudent(file);
            break;
            case 2:
            do {
            printf("Enter the first Name: [Format:Azer..y]\n");
            scanf("%19s",FName);
            printf("Enter the Last Name: [Format:AZER..Y]\n");
            scanf("%19s",LName);
        } while(!(FormVerif(FName,"FName") && FormVerif(LName,"LName")));
            searchS(file,FName,LName);
            break;                
            case 3:
            showAllS(file);
            break;
            case 4:
            do {
                printf("Enter the first Name: [Format:Azer..y]\n");
                scanf("%19s",FName);
                printf("Enter the Last Name: [Format:AZER..Y]\n");
                scanf("%19s",LName);
            } while(!(FormVerif(FName,"FName") && FormVerif(LName,"LName")));
            editS(file,FName,LName);
            break;
            case 5:
            do {
                printf("Enter the first Name: [Format:Azer..y]\n");
                scanf("%19s",FName);
                printf("Enter the Last Name: [Format:AZER..Y]\n");
                scanf("%19s",LName);
            } while(!(FormVerif(FName,"FName") && FormVerif(LName,"LName")));
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
            system("@cls||clear");
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