/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #6
Date Created: 01/24/26
Date Last Edited: 01/24/26

*/
#include <stdio.h>
#define MAX_STRING_LENGTH 256

int find_length_of_string(char *str){
    //got base of function from https://www.geeksforgeeks.org/c/c-program-to-print-the-length-of-a-string-using-pointers/
    int n = 0;  //initialize length of string to 0
    while (*str++){ //while we can still iterate through string pointer
        n++;    //increment length number
    }
    return n;   //return length
}

int main(){
    char usr_string[MAX_STRING_LENGTH];
    printf("What is your string?: ");
    scanf(" %s", usr_string);
    getchar(); //remove new line
    printf("Length of string is: %i\n", find_length_of_string(usr_string)); //print length

    return 0;
}