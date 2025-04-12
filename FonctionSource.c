

void addStudent(FILE*fileR,FILE*fileW){
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

   if (isInDB(studentInfo,fileR)){
    printf("This Student is already in th DataBase");
   }
   else{
    // Display the result and add it to the DataBase
    printf("\n The following Student has been added : \nStudent Info: %s\n",studentInfo);
    fprintf(fileW, "%s\n", studentInfo);
   }

    free(studentInfo);

}

int isInDB(char* studentInfo,FILE*file){
    rewind(file);
    char line[100];
    //checking line by line for the possibility of a Duplicate
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';  //deleting the /0 at the end of the infos
        if (strcmp(line, studentInfo) == 0) return 1;
    }
    return 0;
}

void showAllS(FILE*file){
    rewind(file);
    int n=1;
    char line[100];

    printf("\n List of Students:\n");

    while(fgets(line,sizeof(line),file)){
    printf("Student %d: %s\n", n, line);
    n++;
    }
}

void searchS(FILE *file,char *student){
    rewind(file);
    char line[100];
    while(fgets(line, sizeof(line), file)){
        if (strstr(line, student) !=NULL){
            line[strcspn(line, "\n")] = '\0';
            printf("%s",line);
            return;
        }
    }
    printf("the Student you entered is not in the DataBase");
}