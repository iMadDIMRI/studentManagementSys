
typedef struct {
    char FName[20];
    char LName[20];
    char Sector[7];
    char Year[5];
    char ARating[6];
} Student;

void addStudent(FILE *file){
    Student *temp = (Student *)malloc(sizeof(Student));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    //taking All informations about the student to add in DB

    printf("Enter the first Name:\n");
    scanf("%19s",temp->FName);
    
    printf("Enter the Last Name:\n");
    scanf("%19s",temp->LName);
    
    printf("Enter the Sector:\n");
    scanf("%6s",temp->Sector);

    printf("Enter the Year:\n");
    scanf("%4s",temp->Year);

    printf("Enter the ARating:\n");
    scanf("%5s",temp->ARating);

   if (isInDB(file,temp)){
    printf("This Student is already in th DataBase");
   }
   else{
    // Display the result and add it to the DataBase
    printf("\n The following Student has been added : \nStudent Info: %s %s\n",temp->FName,temp->LName);
    fwrite(temp, sizeof(Student),1,file);
   }
   free(temp);
}

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

void showAllS(FILE*file){
    rewind(file);
    int n=1;
    Student temp;

    printf("\n List of Students:\n");

    while(fread(&temp,sizeof(Student),1,file)){
    printf("Student %d: %s %s | Sector: %s | Year: %s | ARating: %s\n",n, temp.FName, temp.LName, temp.Sector, temp.Year, temp.ARating);   
    n++;
    }
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
                    printf("Please enter the new First Name:\n");
                    scanf("%s",temp.FName);
                    break;
                    case 2:
                    printf("Please enter the new Last Name:\n");
                    scanf("%s",temp.LName);
                    break;                
                    case 3:
                    printf("Please enter the new Sector:\n");
                    scanf("%s",temp.Sector);
                    break;
                    case 4:
                    printf("Please enter the new Year:\n");
                    scanf("%s",temp.Year);
                    break;
                    case 5:
                    printf("Please enter the new Average Rating:\n");
                    scanf("%s",temp.ARating);
                    break;
                    case 0:
                    break;
                }
            }
            printf("Good!! the informations of the student you worked on became: \n Student Name: %s %s | Sector: %s | Year: %s | ARating: %s\n", temp.FName, temp.LName, temp.Sector, temp.Year, temp.ARating);
            fseek(file,-sizeof(Student), SEEK_CUR);
            fwrite(&temp, sizeof(Student), 1, file);
        }
    }
}

