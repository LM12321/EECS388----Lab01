/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #7
Date Created: 01/24/26
Date Last Edited: 01/24/26

*/
#include <stdio.h>

int main(){
    //initalize variables
    int temp;
    int *temp_ptr;

    printf("What's your number?: ");
    scanf(" %i", &temp);    //get user number
    temp_ptr = &temp;   //set temp_ptr to temp's address
    printf("temp (var): %i\ntemp (deref): %i\ntemp (address): %p\ntemp_ptr (address): %p\n", temp, *temp_ptr, &temp, &temp_ptr);//print out everything
    return 0;
}
