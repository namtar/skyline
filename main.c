/* 
 * File:   main.c
 * Author: Matthias Drummer <s0542834>
 *
 * Created on November 21, 2013, 4:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct House House;
typedef struct Point Point;

House *houses;

/**
 * Function to input the houses of the skyline from console.
 * 
 * @return an errorCode if some input operation fails
 */
int inputHouses();

/**
 * Function to output the skyline.
 * 
 * @return an errorCode if anything went wrong
 */
int outputSkyline();

/**
 * Functions transforms the list of houses to the skyline.
 */
void transformHousesToSkyline();

/**
 * Struct that represents one house of the skyline.
 */
struct House {
    int startX;
    int y;
    int endX;
    House *nextHouse;
};

/**
 * Struct that represents one coordiate.
 */
struct Point {
    int x;
    int y;
};

/**
 * Function clears the stdin.
 */
void clrstdin() {
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

/*
 * Main function.
 */
int main(int argc, char** argv) {

    houses = NULL;
    
    inputHouses();
    transformHousesToSkyline();
    outputSkyline();

    return (EXIT_SUCCESS);
}

int inputHouses() {

    short finished = 0;
    do {

        House *house = (House*) malloc(sizeof (House));
        printf("\nGeben Sie ein Haus ein:");
        printf("\nGeben Sie startX ein:");
        scanf("%i", &(house->startX));
        clrstdin(); 

        printf("\nGeben Sie y ein:");
        scanf("%i", &(house->y));
        clrstdin(); 

        printf("\nGeben Sie endX ein:");
        scanf("%i", &(house->endX));
        clrstdin(); 

        house->nextHouse = NULL;
        
        if(houses == NULL) {
            houses = house;
        } else {
            House* iterator = houses;
            while(iterator->nextHouse != NULL) {
                iterator = iterator->nextHouse;
            }
            iterator->nextHouse = house;
        }
        
        printf("Wollen Sie ein weiteres Haus eingeben? 1 für ja, 2 für Nein");
        int again = 0;
        scanf("%i", &again);
        if (again != 1) {
            finished = 1;
        }
        clrstdin();        

    } while (finished == 0);
}

int outputSkyline() {
    
}

void transformHousesToSkyline() {
    
}

