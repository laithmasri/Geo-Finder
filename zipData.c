#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "zipData.h"
//Defining the constants.
#define COUNTRY_CODE_LENGTH 2
#define POSTAL_CODE_LENGTH 21
#define PLACE_NAME_LENGTH 181
#define ADMIN_NAME_ONE_LENGTH 101
#define ADMIN_CODE_ONE_LENGTH 21 
#define ADMIN_NAME_TWO_LENGTH 101
#define ADMIN_CODE_TWO_LENGTH 21
#define ADMIN_NAME_THREE_LENGTH 101
#define ADMIN_CODE_THREE_LENGTH 21
#define EARTH_RADIUS_KM 6371

/** This method is used to parse the file, and save data into strings.
*   It will be called inside every other method, in order to compare
*   if the parsed line contains the values that we're looking for.
*/
void readFile(FILE* in, char* countryCode, char* postalCode, char* placeName, char* adminNameOne, char* adminCodeOne, char* adminNameTwo, char* adminCodeTwo, char* adminNameThree, char* adminCodeThree, double *latitude, double *longitude, char* accuracy)
{
    //Zeroing the values of the strings, so that new data can be parsed in and saved.  
    countryCode[0] = '\0';
    postalCode[0] = '\0';
    placeName[0] = '\0';
    
    adminNameOne[0] = '\0';
    adminCodeOne[0] = '\0';
    
    adminNameTwo[0] = '\0';
    adminCodeTwo[0] = '\0';
    
    adminNameThree[0] = '\0';
    adminCodeThree[0] = '\0';

    accuracy[0] = '\0';

    fscanf(in, "%s\t", countryCode);
    fscanf(in, "%s\t", postalCode);
    fscanf(in, "%[^\t]", placeName);
    fgetc(in);
    fscanf(in, "%[^\t]", adminNameOne);
    fgetc(in);
    fscanf(in, "%[^\t]", adminCodeOne);
    fgetc(in);
    fscanf(in, "%[^\t]", adminNameTwo);
    fgetc(in);
    fscanf(in, "%[^\t]", adminCodeTwo);
    fgetc(in);
    fscanf(in, "%[^\t]", adminNameThree);
    fgetc(in);
    fscanf(in, "%[^\t]", adminCodeThree);
    fgetc(in);
    fscanf(in, "%lf", latitude);
    fscanf(in, "%lf", longitude);
    fscanf(in, "%[^\n]", accuracy);
    fgetc(in);
}

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   place name.
*/
void place(char* file1, FILE* file2, char* lookFor)
{  
    FILE* in = fopen(file1, "r");
    char countryCode[10] = "\0";
    char postalCode[50] = "\0";
    char placeName[PLACE_NAME_LENGTH] = "\0";
    
    char adminNameOne[ADMIN_NAME_ONE_LENGTH] = "\0";
    char adminCodeOne[ADMIN_CODE_ONE_LENGTH] = "\0";
    
    char adminNameTwo[ADMIN_NAME_TWO_LENGTH] = "\0";
    char adminCodeTwo[ADMIN_CODE_TWO_LENGTH] = "\0";
    
    char adminNameThree[ADMIN_NAME_THREE_LENGTH] = "\0";
    char adminCodeThree[ADMIN_CODE_THREE_LENGTH] = "\0";

    double latitude;
    double longitude;
    char accuracy[10] = "\0";
    int found = 0;
    while (!feof(in))
    {
        readFile(in, countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, &latitude, &longitude,accuracy);
        char* ptr = strstr(placeName, lookFor);
        if (ptr != NULL)
        {
            
            found++;
            fprintf(file2, "%s %s %s  %s %s %s %s %s %s %lf %lf %s\n", countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, latitude, longitude, accuracy);
        }    
    }
    if (found == 0)
    {
        fprintf(file2, "Sorry, place name %s was not found.\n", lookFor);
    }
}

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   county name.
*/
void county(char* file1, FILE* file2, char* lookFor)
{
    FILE* in = fopen(file1, "r");
    char countryCode[10] = "\0";
    char postalCode[50] = "\0";
    char placeName[PLACE_NAME_LENGTH] = "\0";
    
    char adminNameOne[ADMIN_NAME_ONE_LENGTH] = "\0";
    char adminCodeOne[ADMIN_CODE_ONE_LENGTH] = "\0";
    
    char adminNameTwo[ADMIN_NAME_TWO_LENGTH] = "\0";
    char adminCodeTwo[ADMIN_CODE_TWO_LENGTH] = "\0";
    
    char adminNameThree[ADMIN_NAME_THREE_LENGTH] = "\0";
    char adminCodeThree[ADMIN_CODE_THREE_LENGTH] = "\0";

    double latitude;
    double longitude;
    char accuracy[10] = "\0";
    int found = 0;
    while (!feof(in))
    {
        readFile(in, countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, &latitude, &longitude,accuracy);
        char* ptr = strstr(adminNameTwo, lookFor);
        
        if (ptr != NULL)
        {
            found++;
            fprintf(file2, "%s %s %s %s %s %s %s %s %s %lf %lf %s\n", countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, latitude, longitude, accuracy);
        }    
    }
    if (found == 0)
    {
        fprintf(file2, "Sorry, county %s was not found.\n", lookFor);
    }
}

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   postal code number.
*/
void postal(char* file1, FILE* file2, char* lookFor)
{
    FILE* in = fopen(file1, "r");
    char countryCode[10] = "\0";
    char postalCode[50] = "\0";
    char placeName[PLACE_NAME_LENGTH] = "\0";
    
    char adminNameOne[ADMIN_NAME_ONE_LENGTH] = "\0";
    char adminCodeOne[ADMIN_CODE_ONE_LENGTH] = "\0";
    
    char adminNameTwo[ADMIN_NAME_TWO_LENGTH] = "\0";
    char adminCodeTwo[ADMIN_CODE_TWO_LENGTH] = "\0";
    
    char adminNameThree[ADMIN_NAME_THREE_LENGTH] = "\0";
    char adminCodeThree[ADMIN_CODE_THREE_LENGTH] = "\0";

    double latitude;
    double longitude;
    char accuracy[10] = "\0";
    int found = 0;
    while (!feof(in))
    {
        readFile(in, countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, &latitude, &longitude,accuracy);
        int ptr = strcmp(postalCode, lookFor);
        
        if (ptr == 0)
        {
            
            found++;
            fprintf(file2, "%s %s %s %s %s %s %s %s %s %lf %lf %s\n", countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, latitude, longitude, accuracy);
        }    
    }
    if (found == 0)
    {
        fprintf(file2, "Sorry, postal code %s was not found.\n", lookFor);
    }
}

/** This method will be taking four parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, the third and the
*   fourth represent the data we're looking for.
*   In this method, we are looking for two postal
*   code numbers, and then finding the distance 
*   between them using the latitude and the longitude.
*/
void distance(char* file1, FILE* file2, char* lookFor1, char* lookFor2)
{
    FILE* in = fopen(file1, "r");
    char countryCode[10] = "\0";
    char postalCode[50] = "\0";
    char placeName[PLACE_NAME_LENGTH] = "\0";
    
    char adminNameOne[ADMIN_NAME_ONE_LENGTH] = "\0";
    char adminCodeOne[ADMIN_CODE_ONE_LENGTH] = "\0";
    
    char adminNameTwo[ADMIN_NAME_TWO_LENGTH] = "\0";
    char adminCodeTwo[ADMIN_CODE_TWO_LENGTH] = "\0";
    
    char adminNameThree[ADMIN_NAME_THREE_LENGTH] = "\0";
    char adminCodeThree[ADMIN_CODE_THREE_LENGTH] = "\0";

    double latitude;
    double longitude;

    double lat1;
    double lat2;
    double long1;
    double long2;

    char accuracy[10] = "\0";
    int found1 = 0;
    int found2 = 0;
    while (!feof(in))
    {
        readFile(in, countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, &latitude, &longitude,accuracy);
        int ptr1 = strcmp(postalCode, lookFor1);
        int ptr2 = strcmp(postalCode, lookFor2);
        if ((ptr1 == 0) && (found1 < 1))
        {
            found1++;
            fprintf(file2, "%s %s %s %s %s %s %s %s %s %lf %lf %s\n", countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, latitude, longitude, accuracy);
            lat1 = latitude;
            long1 = longitude;
        }
        else if ((ptr2 == 0) && (found2 < 1))
        {
            found2++;
            fprintf(file2, "%s %s %s %s %s %s %s %s %s %lf %lf %s\n", countryCode, postalCode, placeName, adminNameOne, adminCodeOne, adminNameTwo, adminCodeTwo, adminNameThree, adminCodeThree, latitude, longitude, accuracy);
            lat2 = latitude;
            long2 = longitude;
        }
        if ((ptr1 == 0) && (ptr2 == 0))
        {
            break;
        }
    }
    
    if ((found1 != 0) && (found2 != 0))
    {
        double result = haversine(lat1, long1, lat2, long2);
        fprintf(file2, "Distance: %lf km\n", result);
    }
    else if ((found1 == 0) && (found2 == 0))
    {
        fprintf(file2, "Sorry, postal code %s was not found.\n", lookFor1);
        fprintf(file2, "Sorry, postal code %s was not found.\n", lookFor2);
    }
    else if (found1 == 0)
    {
        fprintf(file2, "Sorry, postal code %s was not found.\n", lookFor1);
    }
    else if (found2 == 0)
    {
        fprintf(file2, "Sorry, postal code %s was not found.\n", lookFor2);
    }
}

/** This method is used to calculate the distance between two places.
*   In order to calculate the distance, we need to access both of the
*   latitude and longitude for the two places. These values will be 
*   passed into the method as parameters, and calculations will be made.
*/
double haversine(double firstLatitude, double firstLongitude, double secondLatitude, double secondLongitude)
{
    double lat_;
    double long_;

    double firstFormula;
    double secondFormula;

    lat_ = (secondLatitude - firstLatitude) * (M_PI / 180);
    long_ = (secondLongitude - firstLongitude) * (M_PI / 180);

    firstFormula = (sin(lat_ / 2) * sin(lat_ / 2)) + (cos(firstLatitude * M_PI / 180) * cos(secondLatitude * M_PI / 180)) * ((sin(long_ / 2) * sin(long_ / 2)));
    secondFormula = 2 * atan2(sqrt(firstFormula), sqrt(1 - firstFormula));

    return (secondFormula * EARTH_RADIUS_KM);
}

    

    
