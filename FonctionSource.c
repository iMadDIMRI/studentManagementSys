#include <ctype.h>
#include <errno.h>
#include <conio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char FName[20];
    char LName[20];
    char Sector[7];
    char Year[5];
    char ARating[6];
} Student;

int isInDB(FILE *file, Student *target) {
    rewind(file);
    Student temp;

    while (fread(&temp, sizeof(Student), 1, file)) {
        if (strcmp(temp.FName, target->FName) == 0 &&
            strcmp(temp.LName, target->LName) == 0 &&
            strcmp(temp.Sector, target->Sector) == 0 &&
            strcmp(temp.Year, target->Year) == 0 &&
            strcmp(temp.ARating, target->ARating) == 0) {
            return 1; //Found
        }
    }
    return 0; //Not found
}


int FormVerif(char* Word,char* Type){
    int Valide=1,n;
    if (strcmp(Type,"FName")==0){
        if ((isupper(Word[0])==0)) Valide=0;
        for (int i=1;i<strlen(Word);i++){
            if (!(islower(Word[i]) || Word[i]==' ')) Valide=0;
        }
    }
    if (strcmp(Type,"LName")==0){
        for (int i=0;i<strlen(Word);i++){
            if (!(isupper(Word[i]) || Word[i]==' ')) Valide=0;
            }
        }
    if (strcmp(Type,"Year")==0){
        for (int i=0;i<strlen(Word);i++){
            if (!(isdigit(Word[i]))) Valide=0;
            }
    }
    if (strcmp(Type,"Sector")==0){
        for (int i=0;i<strlen(Word);i++){
            if (!(isupper(Word[i]))) Valide=0;
            }
        }
    if (strcmp(Type,"ARating")==0){
        n=0;
        for (int i=0;i<strlen(Word);i++){
            if (!(isdigit(Word[i]))){
            if ((Word[i]=='.'|| Word[i]==',')&& n==0) {
                n++;
                continue;
            }
            Valide=0;
        }
    }
}
        return Valide;
    }

void addStudent(FILE *file){
    Student *temp = (Student *)malloc(sizeof(Student));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    //taking All informations about the student to add in DB
    do {
        printf("Enter the first Name: [Format:Azer..y]\n");
        scanf("%19s",temp->FName);
    }while(!FormVerif(temp->FName,"FName"));
    
    do {
        printf("Enter the Last Name: [Format:AZER..Y]\n");
        scanf("%19s",temp->LName);
    } while (!FormVerif(temp->LName,"LName"));
    do {
        printf("Enter the Sector: [Format:AZER..Y]\n");
        scanf("%19s",temp->Sector);
    } while (!FormVerif(temp->Sector,"Sector"));
    do {
        printf("Enter the Year: [Format: XXXX]\n");
        scanf("%19s",temp->Year);
    } while (!FormVerif(temp->Year,"Year"));
    do {
        printf("Enter the Average Rating: [Format:XX.XX or XX,XX]\n");
        scanf("%19s",temp->ARating);
    } while (!FormVerif(temp->ARating,"ARating"));

   if (isInDB(file,temp)){
    printf("This Student is already in th DataBase");
   }
   else{
    // Display the result and add it to the DataBase
    printf("\n The following Student has been added : \nStudent Info: %s %s %s %s %s\n",temp->FName,temp->LName,temp->Sector,temp->Year,temp->ARating);
    fwrite(temp, sizeof(Student),1,file);
   }
   free(temp);
}

void showAllS(FILE*file){
    int size;
    fseek (file, 0, SEEK_END);
    size = ftell(file);

    if (0 == size) {
        printf("DataBase is empty\n");
    }
    else
    {
    rewind(file);
    int n=1;
    Student temp;
    printf("\n List of Students:\n");

    while(fread(&temp,sizeof(Student),1,file)){
    printf("Student %d: %s %s | Sector: %s | Year: %s | ARating: %s\n",n, temp.FName, temp.LName, temp.Sector, temp.Year, temp.ARating);   
    n++;
    }}
    printf("\n");
}

void searchS(FILE *file,char *FName, char *LName){
    rewind(file);
    Student temp;
    while(fread(&temp, sizeof(Student),1, file)){
        if (strcmp(temp.FName, FName) == 0 &&
        strcmp(temp.LName,LName) == 0 ){
            printf("Student: %s %s | Sector: %s | Year: %s | ARating: %s\n", temp.FName, temp.LName, temp.Sector, temp.Year, temp.ARating);   
            return;
        }
    }
    printf("the Student you entered is not in the DataBase");
}

void editS(FILE* file,char *FName, char *LName){
    rewind(file);
    int choice=-1;
    Student temp;
    char NLName[20],NFName[20];
    while(fread(&temp, sizeof(Student),1,file)){
        if (strcmp(temp.FName, FName) == 0 &&
        strcmp(temp.LName,LName) == 0 ){
            while(choice){
                printf("Which information are you changing?\n 1:First Name \n 2:Last Name \n 3:Sector \n 4:Year \n 5:Average Rating\n 0:Done.\n ");
                scanf("%d",&choice);
                switch(choice){
                    case 1:
                    do {
                        printf("Enter the first Name: [Format:Azer..y]\n");
                        scanf("%19s",temp.FName);
                    }while(!FormVerif(temp.FName,"FName"));
                    break;
                    case 2:
                    do {
                        printf("Enter the Last Name: [Format:AZER..Y]\n");
                        scanf("%19s",temp.LName);
                    } while (!FormVerif(temp.LName,"LName"));
                    break;                
                    case 3:
                    do {
                        printf("Enter the Sector: [Format:AZER..Y]\n");
                        scanf("%19s",temp.Sector);
                    } while (!FormVerif(temp.Sector,"Sector"));
                    break;
                    case 4:
                    do {
                        printf("Enter the Year: [Format: XXXX]\n");
                        scanf("%19s",temp.Year);
                    } while (!FormVerif(temp.Year,"Year"));
                    break;
                    case 5:
                    do {
                        printf("Enter the Average Rating: [Format:XX.XX or XX,XX]\n");
                        scanf("%19s",temp.ARating);
                    } while (!FormVerif(temp.ARating,"ARating"));
                    break;
                    case 0:
                    break;
                }
            }
            printf("Good!! the informations of the student you worked on became: \n Student Name: %s %s | Sector: %s | Year: %s | ARating: %s\n", temp.FName, temp.LName, temp.Sector, temp.Year, temp.ARating);
            fseek(file,-(long)sizeof(Student), SEEK_CUR);
            fwrite(&temp, sizeof(Student), 1, file);
            break;
        }
    }
}

void deleteS(FILE* file,char *FName, char *LName){
    rewind(file);
    long position;
    Student temp;
    while(fread(&temp, sizeof(Student),1,file)){
        if (strcmp(temp.FName, FName) == 0 &&
        strcmp(temp.LName, LName) == 0 ){
        position=ftell(file)-sizeof(Student);
        break;
        }
    }
    while(fread(&temp,sizeof(Student),1,file)){
        fseek(file,-2*(long)sizeof(Student),SEEK_CUR);
        fwrite(&temp,sizeof(Student),1,file);
        fseek(file,sizeof(Student),SEEK_CUR);
    }
    fseek(file,-(long)sizeof(Student),SEEK_END);
    if (truncate("Database.txt", ftell(file))){
        printf("error: %d\n",errno);
    }
}
