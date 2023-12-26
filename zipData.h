#include <math.h>

/** This method is used to parse the file, and save data into strings.
*   It will be called inside every other method, in order to compare
*   if the parsed line contains the values that we're looking for.
*/
void readFile(FILE* file1, char* countryCode, char* postalCode, char* placeName, char* adminNameOne, char* adminCodeOne, char* adminNameTwo, char* adminCodeTwo, char* adminNameThree, char* adminCodeThree, double *latitude, double *longitude, char* accuracy);

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   place name.
*/
void place(char* file1, FILE* file2, char* search);

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   county name.
*/
void county(char* file1, FILE* file2, char* search);

/** This method will be taking three parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, and the third
*   one represents the data we're looking for.
*   In this method, we are looking for a certain
*   postal code number.
*/
void postal(char* file1, FILE* file2, char* search);

/** This method will be taking four parameters.
*   The first one represents a file name, the second
*   one represents a file pointer, the third and the
*   fourth represent the data we're looking for.
*   In this method, we are looking for two postal
*   code numbers, and then finding the distance 
*   between them using the latitude and the longitude.
*/
void distance(char* file1, FILE* file2, char* lookFor1, char* lookFor2);

/** This method is used to calculate the distance between two places.
*   In order to calculate the distance, we need to access both of the
*   latitude and longitude for the two places. These values will be 
*   passed into the method as parameters, and calculations will be made.
*/
double haversine(double lat1, double long1, double lat2, double long2);

