#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zipData.h"

/** This is the main method, where all methods are
*   called within it, depending on the situation.
*   It takes two parameters that represent the number
*   of arguments, and the actual arguments.
*/
int main (int argc, char* argv[])
{
    //Checking if the number or arguments is acceptable or not.
    if (argc != 3)
    {
        fprintf(stderr, "The number of arguments is incorrect.\n");
        exit(1);
    }
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    //Defining local strings.
    char command[10];
    char search[50];
    char fileName[50];
    char distance1[100];
    char distance2[100];
    
    fscanf(input, "%s", command);
    fscanf(input, "%s", fileName);
    //Print out the file name that we'll be parsing through.
    fprintf(output, "%s %s\n", command, fileName);
    
    //Keep parsing the file, and comparing the command until the end of the file.
    while (!feof(input))
    {
        char command[10] = "\0";
        fscanf(input, "%s", command);
        if (strcmp(command, "postal") == 0)
        {
            fgetc(input);
            fscanf(input, "%[^\n]", search);
            fprintf(output, "%s %s\n", command, search);
            postal(fileName, output, search);
        }
        else if (strcmp(command, "place") == 0)
        {
            fgetc(input);
            fscanf(input, "%[^\n]", search);
            fprintf(output, "%s %s\n", command, search);
            place(fileName, output, search);
        }
        else if (strcmp(command, "county") == 0)
        {
            fgetc(input);
            fscanf(input, "%[^\n]", search);
            fprintf(output, "%s %s\n", command, search);
            county(fileName, output, search);
        }
        else if (strcmp(command, "filename") == 0)
        {
            fscanf(input, "%s", fileName);
        }
        else if (strcmp(command, "distance") == 0)
        {
            fscanf(input, "%s %s", distance1, distance2);
            fprintf(output, "%s %s %s\n", command, distance1, distance2);
            distance(fileName, output, distance1, distance2);
        }
    }
    fclose(input); 
}