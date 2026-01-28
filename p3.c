/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #3
Date Created: 01/23/26
Date Last Edited: 01/23/26

*/

#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

int is_prime(int num, int *current_primes, int prime_counter){
    //0 for false; 1 for true
    //iterates through current primes to the prime coutner
    //if given num is divisible by any of the primes
    //it's not a valid prime
    //Also: 2 technically fails this check, but it's baked in the primes by default
    for (int i = 0; i < prime_counter; i++){
            #ifdef DEBUG
            printf("Current primes num: %i\n", current_primes[i]);
            #endif
            if ((num % current_primes[i] == 0)){
                return 0;   //it's NOT prime
            }
        }
    return 1;   //it's prime
}

void get_primes(int *primes, int max, int capacity){
    int prime_counter = 1;

    for (int i = 2; i <= max; i++){  //iterate through all numbers

        if (prime_counter == capacity){ //we've reached capacity
            puts("Reached capacity!");
            return; //end program early
        }
        #ifdef DEBUG
        printf("number i = %i\n", i);
        #endif

        

        //if number i is a valid prime
        if (is_prime(i, primes, prime_counter) == 1){
            primes[prime_counter] = i;  //add i to the array of primes
            prime_counter++;    //increment the prime counter by 1
        }

    }
}

void print_primes(int *primes, int capacity){
    //iterate through all primes
    //print the number if the number isn't -1
    //else end the printing
    for (int i = 0; i < capacity; i++){
        if (primes[i] == -1){
            break;
        }else{
            printf("%i ",primes[i]);
        }
    }
    putchar('\n');  //newline for formatting
}

int main(){
    //initialize variables
    int usr_number, capacity;

    //get usr_number
    printf("Enter your number: ");
    scanf(" %d", &usr_number);
    getchar(); // remove new line

    //get capacity for array
    printf("What is the limit of numbers to print?: ");
    scanf(" %d", &capacity);
    getchar();
    
    //check if inputs are valid
    if (usr_number < 0 || capacity <= 0){
        puts("Invalid number(s) receieved!");
        return 1;
    }

    //if usr_number is less than 2, no valid primes are found
    if (usr_number < 2){
        puts("No valid primes found!");
        return 0;
    }


    //allocate memory for array
    int *primes = (int*)malloc(sizeof(int) * capacity);     


    //set primes[0] to 2 and everything else to -1 for checking
    primes[0] = 2;
    for (int i = 1; i < capacity; i++){
        primes[i] = -1;
    }

    get_primes(primes, usr_number, capacity); //get the primes
    print_primes(primes, capacity); //print primes

    free(primes);   //free the memory

    return 0;
}