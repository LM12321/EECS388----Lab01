/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #5
Date Created: 01/24/26
Date Last Edited: 01/24/26

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int is_number_in_array(int *set_of_numbers, int number, int numbers_in_set){
    //iterate through all numbers currently in the set
    //see if the given number is in the set
    for (int i = 0; i < numbers_in_set; i++){
        if (set_of_numbers[i] == number){
            return 1;    //it is in array
        }
    }
    return 0;   //it is NOT in array

}

int main(){
    //intialize all numbers used
    int numbers_in_set = 0, number_of_duplicates = 0, array_size, usr_element, i;

    //get the array size
    printf("How big is the array?: ");
    scanf("%i", &array_size);

    int *set_of_numbers = (int*)malloc(sizeof(int)*array_size);    //intialize_set_of_numbers


    //for each number in array
    for (i = 0; i < array_size; i++){

        //get the user number
        printf("Enter element #%i: ", i + 1);
        scanf(" %i", &usr_element); 
        getchar();  //clear new line

        //check if the number is in the current set of numbers we have

        if (is_number_in_array(set_of_numbers, usr_element, numbers_in_set) == 0){
            //it is NOT in set of numbers
            set_of_numbers[numbers_in_set] = usr_element;   //add number to set
            numbers_in_set++;   //increment the amount of numbers in set
        }else{
            //we have a duplicate
            number_of_duplicates++; //incremement duplicates count
        }
    }   
    //tell user the result
    printf("The number of duplicates in the set is %i\n", number_of_duplicates);
    free(set_of_numbers);   //free memory

    return 0;
}
