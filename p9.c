/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #9
Date Created: 01/24/26
Date Last Edited: 01/24/26

*/
#include <stdio.h>
//#define DEBUG

int is_override_valid(int override){
    //check if override is valid
    //1 for true
    //0 for false
    if (override == 1 || override == 0){
        return 1;
    }else{
        return 0;
    }
}

int override_bit(unsigned int num, unsigned int bit, unsigned int override){
    unsigned int mask;
    //check override
    //if 0, get an invert of the mask and bitwise and it to the given number
    //if 1, the mask is or'd with the given number
    switch (override)
    {
    case 0:
       
        mask = ~(1 << bit); //get the mask (EX 11101111)
        #ifdef DEBUG
        printf("mask %u\n", mask);
        #endif
        return num & mask;
        break;
    case 1:
        mask = 1 << bit;    //get the mask (EX 00010000)
        return num | mask;
        break;
    default:    //invalid number is recieved
        puts("Invalid number received!");
        return -1;
        break;
    }
    return -1;
}


int main(){
    unsigned int usr_num, usr_bit, usr_override;

    //get user number
    printf("What's your number?: ");
    scanf(" %i", &usr_num);
    getchar();  //clear newline

    //get user bit
    printf("What's the bit you're checking?: ");
    scanf(" %i", &usr_bit);
    getchar();  //clear newline

    //get user override
    printf("What's the override value (0 or 1)?: ");
    scanf(" %i", &usr_override);
    getchar();  //clear newline

    if (is_override_valid(usr_override) != 1){  //is false
        puts("Invalid override received!");
        return 1;
    }
    usr_num = override_bit(usr_num, usr_bit, usr_override); //set usr_num to whatever they override it to
    printf("New number = %i\n", usr_num);   //print the new number

    return 0;

}