/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #2
Date Created: 01/23/26
Date Last Edited: 01/23/26

*/

#include <stdio.h>
#include <stdlib.h>

int find_max(int array[10]){
    //given array with 10 inputs
    int max = array[0]; //set the starting max to the first position

    //iterate through all numbers in array
    //if number is greater than current max, set that to the new max
    //return the max
    for (int i = 1; i < 10; i++){
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

int find_min(int array[10]){
    //given array with 10 inputs
    int min = array[0]; //set min to the first element
    //iterate through all elements and find the lowest

    for (int i = 1; i < 10; i++){
        if (array[i] < min)
            min = array[i];
    }
    return min; //return the min
}


int main(){
    int array[10] = {500, 1, 255, 7, -12, 40, 42, 999, 50, 227};    //initialize array
    int max, min;   //initialize max and min
    char usr_choice;    //inititalize usr_choice char

    //get usr_choice
    printf("What choice? (m, n, or b): "); 
    usr_choice = getchar();
    switch (usr_choice) //switch case for user choice
    {
    case 'm': //max
        max = find_max(array);
        printf("Max = %d\n", max);
        break;
    case 'n':    //min
        min = find_min(array);
        printf("Min = %d\n", min);
        break;
    case 'b':   //both
        max = find_max(array);
        min = find_min(array);
        printf("Max = %d, Min = %d\n", max, min);
        break;
    default:    //invalid choice
        puts("Invalid choice received!");
        return 1;
        break;
    }

    return 0;   //end valid program

}