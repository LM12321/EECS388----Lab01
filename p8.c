/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #8
Date Created: 01/24/26
Date Last Edited: 01/24/26

*/
#include <stdio.h>


int is_bit_set(int num, int bit){
    /*
    each step in return
    1) set a mask at the given bit
    2) and that bit with the given num
    3) bit shift that num down so that it is either 1 or 0
    4) return that number
    */
    return (num & (1 << bit)) >> bit;
}


int main(){
    unsigned int usr_num, usr_bit;  //initialize unsigned usr_num and usr_bit

    //get user number
    printf("What's your number?: ");
    scanf(" %i", &usr_num);
    getchar();  //clear newline

    //get user bit
    printf("What's the bit you're checking?: ");
    scanf(" %i", &usr_bit);
    getchar();  //clear newline


    //if the bit is 1, print out TRUE
    //else, print out FALSE
    if (is_bit_set(usr_num, usr_bit) == 1){
        puts("TRUE");
    }else{  //the bit at num is 0
        puts("FALSE");
    }

    return 0;   

}