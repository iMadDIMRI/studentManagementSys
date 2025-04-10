

void addStudent(void){
    char FName[20],LName[20],Sector[7],Year[5],ARating[6];
    char *studentInfo=(char*)malloc(100*sizeof(char));

    if (studentInfo == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    //taking All informations about the student to add in DB

    printf("Enter the first Name:\n");
    scanf("%19s",FName);
    
    printf("Enter the Last Name:\n");
    scanf("%19s",LName);
    
    printf("Enter the Sector:\n");
    scanf("%6s",Sector);

    printf("Enter the Year:\n");
    scanf("%4s",Year);

    printf("Enter the ARating:\n");
    scanf("%5s",ARating);

    // Combine all the info into studentInfo
    snprintf(studentInfo, 100, "%s %s %s %s %s", FName, LName, Sector, Year, ARating);


    // Open file in Both mode R for checking for Duplicate and A for adding the new student
    FILE *fileR = fopen("Database.txt", "r");
    if (fileR == NULL) {
        printf("Error opening file!\n");
        free(studentInfo);
        return;
    }
    FILE *fileW = fopen("Database.txt", "a");
    if (fileW == NULL) {
        printf("Error opening file!\n");
        free(studentInfo);
        return;
    }


   if (isInDB(studentInfo,fileR)){
    printf("This Student is already in th DataBase");
   }
   else{
    // Display the result and add it to the DataBase
    printf("\n The following Student has been added : \nStudent Info: %s\n",studentInfo);
    fprintf(fileW, "%s\n", studentInfo);
   }

   //Close files and free the allocated memory
    fclose(fileW);
    fclose(fileR);
    free(studentInfo);

}

int isInDB(char* studentInfo,FILE*file){
    char line[100];
    //checking line by line for the possibility of a Duplicate
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  //deleting the /0 at the end of the infos
        if (strcmp(line, studentInfo) == 0) return 1;
    }
    return 0;
}

void showAllS(void){
    FILE *file = fopen("DataBase.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int n=1;
    char line[100];

    printf("\n List of Students:\n");

    while(fgets(line,sizeof(line),file)){
    printf("Student %d: %s\n", n, line);
    n++;
    }
    fclose(file);
}