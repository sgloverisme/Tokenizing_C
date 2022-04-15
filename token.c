#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    //filename to be used
    char* filename = (char *)malloc(4096 * sizeof(char)); // char filename[20] does the same thing
    char *myfile= (char *)malloc(16384 * sizeof(char)); // char myfile[20] does the same thing


    printf("Welcome to Epic Software Systems Lab: Sarah Glover \n");
    printf("Enter the name of the file to be tokenized: ");
    scanf("%s", filename); //capturing file name
    FILE* specialdata = fopen(filename, "r"); // reading file 

    // reading the file, going from file -> array // 
    int j = 0; //for loop file 
    int onebyte; //for loop file 

    while((onebyte = fgetc(specialdata))!= EOF) {
        putchar(onebyte);
        myfile[j]=onebyte; 
        j++; 
    }
    printf("\n");

    // going through the array (myfile) and counting the # of characters // 
    int counting=0; // counting the length of array
    for( int i = 0; myfile[i]!='\0'; i++){ 
        //printf("%c", myfile[i] );	//print array 
        counting++;
    } 
    printf("%d", counting); //display array length
    printf(" characters were found in the file. \n");
    printf("The tokenizing is ready to begin. \n");

    char* sep=(char*) malloc(10 * sizeof(char)); // the user's separator
    printf("Enter the separator characters which may include white space and press enter: ");

    scanf("%s", sep); // saving user input
    
    printf("\nConfirmation: This is the separator => %s", sep);
    printf("\n"); 
    printf("Tokenizing has finished. \nHere is the complete list of tokens: \n");
    
    
    // making the tokens 

    char* token; 
    int num=0; //num of tokens 
    //first token
    token=strtok(myfile, sep);  // the acutal token being made

    //walking through file
    while(token!= NULL){
        printf("Token number %d", num);
        printf(" %s\n", token);
        num++;
        token=strtok(NULL, sep);
    }
    
    printf("\nTotal number of tokens is %d", num); 
    printf("\nHave a nice evening.");

    fclose(specialdata); 
    return 0;
}; //end of main 