/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #1
Date Created: 01/23/26
Date Last Edited: 01/28/26

*/

#include <stdio.h>  
#include <math.h>   //for exponents

#define MAX_STRING_LENGTH 255   //arbitrary number to prevent most accidental incidents

//#define DEBUG




int is_exponentional_equation(char operation){
    //checks if operation symbol is an exponential
    //1 for true
    //0 for false
    if (operation == 'c' || operation == 's'){
        return 1;
    }else{
        return 0;
    }
}

int get_operation_status(char operation){
    //checks if operation symbol is valid
    //2 for exponent
    //1 for one of the four basic operations
    //0 for invalid operation
    
    switch (operation){
        case '+':
            //addition
            return 1;
            break;
        case '-':
            //subtraction
            return 1;
            break;
        case '*':
            //multiplication
            return 1;
            break;
        case '/':
            //division
            return 1;
            break;
        case 's':
            //squaring
            return 2;
            break;
        case 'c':
            //cubing
            return 2;
            break;
        default:
            puts("Invalid operation symbol given!");
            return 0;
            break;
    }
    return 0;
}

int exponential_equations(char operation, int operand){
    //checks if operation is s or c
    if (operation == 's'){  //squaring
        return pow(operand, 2); //returns operand ^2
    }else if (operation == 'c'){
        return pow(operand, 3); //returns operand ^3
    }else{  //neither
        //shouldn't happen because preceding checks before this
        puts("ERROR - invalid operation given!");
        return -1; 
    }
}


float four_basic_operations(char operation, int operand_one, int operand_two){
    //goes through all 4 basic operations: (+, -, *, and /)
    //checks operation symbol
    //different case for each operation
    
    switch (operation){
        case '+':   //addition
            return operand_one + operand_two;
            break;
        case '-':
            //subtraction
            return operand_one - operand_two;
            break;
        case '*':
            //multiplication
            return operand_one * operand_two;
            break;
        case '/':
            //division
            return (float)operand_one / operand_two;
            break;
        default:
            //none of the above; invalid symbol given
            //shouldn't happen because checks before this, but just in case
            puts("Invalid operation symbol given!");
            return -1;      //returns a junk number
            break;
    }

    return -1;
}



int main(){
    //initialize variables
    char usr_operation_string[MAX_STRING_LENGTH];
    char operation_symbol;
    int operand_one;
    float result;
    
    //get operation symbol
    printf("Enter operation: ");
    scanf(" %s", usr_operation_string);

    //was only one character given
    if (usr_operation_string[1] != '\0'){
        //more than one character was given, invalid input

        puts("Invalid operation symbol given!");
        return 0;
    }else{  //only one character was given
        operation_symbol = usr_operation_string[0];
    }

    int operation_check = get_operation_status(operation_symbol);   //check operation

    
    
    /*
    operation_check meanings
    0 - invalid operation
    1 - non-exponent
    2 is exponent
    */


    if (operation_check == 0){ // check if operation symbol was valid
        return 1;   //exit program
    }




    //get 1st operand
    printf("Enter 1st operand: ");
    scanf(" %d", &operand_one);
    getchar();  //gets rid of '\n'



    if (operation_check == 2 ){ //2 means it's 
        result = exponential_equations(operation_symbol, operand_one);
    }else{  //it was 1, it's basic math
        //get 2nd operand
        int operand_two;
        printf("Enter 2nd operand: ");
        scanf(" %d", &operand_two);
        getchar();  //gets rid of '\n'

        //check if dividing by 0
        if ((operand_two == 0) && (operation_symbol == '/')){
            puts("Cannot divide by 0!");
            return 1;
        }

        result = four_basic_operations(operation_symbol, operand_one, operand_two); //get result
    }
    
    printf("Result is %.2f.\n", result);    //print out result to 2 decimals
    #ifdef DEBUG
    printf("%c %i %i", operation_symbol, operand_one, operand_two);
    #endif
    return 0;
}