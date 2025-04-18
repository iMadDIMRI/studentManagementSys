
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

void editS(FILE* file,char* student){

}

