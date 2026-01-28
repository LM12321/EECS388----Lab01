/*
---- EECS 388 Labs ----

Name: Logan Whitt
Student ID: 3152587

Lab: 01
Problem: #4
Date Created: 01/24/26
Date Last Edited: 01/28/26

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEXNUMBER_LENGTH 256


void convert_string_toupper(char *str);
int convert_hex_to_decimal(char hex);
void print_binary_number(char *str);

int convert_hex_to_decimal(char hex){
    //literally just return the given hex character to its decimal corresponding character
    //probably one of the most tedious ways to do this...
    //but it *does work* (tm)
    switch (hex)
    {
    case '0':
        
        return 0;
        break;
    case '1':

        return 1;
        break;
    case '2':

        return 2;
        break;
    case '3':

        return 3;
        break;
    case '4':

        return 4;
        break;
    case '5':

        return 5;
        break;
    case '6':

        return 6;
        break;
    case '7':

        return 7;
        break;
    case '8':

        return 8;
        break;
    case '9':

        return 9;
        break;
    case 'A':

        return 10;
        break;
    case 'B':

        return 11;
        break;
    case 'C':

        return 12;
        break;
    case 'D':

        return 13;
        break;
    case 'E':

        return 14;
        break;
    case 'F':

        return 15;
        break;
    
    default:
        return -1;
        break;
    }
    return -1;
}

void print_binary_number(char *str){
    int n = strnlen(str, MAX_HEXNUMBER_LENGTH); //get length of string
    int16_t decimal_array[n];   //create an array of signed 16 bit ints of length n
    //signed because -1 is invalid number
    int i, j, mask;
    for (i = 0; i < n; i++){
        decimal_array[i] = convert_hex_to_decimal(str[i]);
        if (decimal_array[i] == -1){
            puts("Invalid hex number received!");
            return;
        }

    }
    for (i = 0; i < n; i++){    //for number in array

        for (j = 3; j >= 0; j--){   //iterate through all 4 bits, starting with left most bit
            mask = 1 << j;  //get a mask at that value
            if ((mask & decimal_array[i]) != 0){   //if mask & array is not 0
                putchar('1');   //print 1
            }else{  //it's 0
                putchar('0');   //print 0
            }
        }
        if ((n-1) != i)
            putchar('_');
    }

    putchar('\n');  //newline for formatting


}

void convert_string_toupper(char *str){
    //set all strings to upper
    int n = strnlen(str, MAX_HEXNUMBER_LENGTH);
    for (int i = 0; i < n; i++){
        str[i] = toupper(str[i]);
    }
}

int main(){
    //char test_char = 'A';
    //printf("Output = %d\n", convert_hex_to_decimal(test_char));

    char usr_input[MAX_HEXNUMBER_LENGTH];
    
    //get usr input string
    printf("What is your input?: ");
    
    scanf(" %s", usr_input);
    getchar();  //remove new line
    
    convert_string_toupper(usr_input);  //convert the string to upper
    printf("\nHex: %s\nBinary: ", usr_input);   //print out hex and binary headers
    print_binary_number(usr_input); //print out binary

    return 0;
}