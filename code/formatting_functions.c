#ifndef _DEFNITIONS_H_
#include "definitions.h"
#endif

//The sum of the ASCII values of the string.
int addition_string(char *sentence)
{
    int i, sum = 0;
    for(i = 0; sentence[i] != '\0'; i++)
        sum += (int)sentence[i];
    return sum;
}

//Swaps two given characters.
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

 //Compares two characers, ignoring their cases.
int character_case_compare(char a, char b)     //1 on success, 0 on failure
{
    a = toupper(a);
    b = toupper(b);
    if(a == b)
        return 1;
    else
        return 0;
    
}

//Sentence capped.
char *upper_case(char* sentence)
{
    int i;
    for(i = 0; sentence[i] != '\0'; i++) sentence[i] = toupper(sentence[i]);
    return sentence;
}

//Fills a "quantity" of space with a certain "Character".
void FILL(int quantity, char characters)
{
    int i = 1;
    while(i <= quantity){
        putchar(characters);
        i++;
    }

}

//Returns first character.
char first_of(char *key)
{
    int i = 0;
    while(key[i] == ' ') i++;
    return key[i];
}

 //Breaks the last newline of a sentence.
void break_new_line(char **sentence){ 
    (*sentence)[strlen((*sentence)) - 1] = '\0';
}

//Checks if the sentence is made of basic numbers
int verify_number(char *sentence)
{
    int i;
    for(i = 0; sentence[i] != '\0'; i++){
        if((sentence[i] >= 48 && sentence[i] <= 57) || sentence[i] == ' ')
            return -1;
    }
    return 1;
}

//Caps Locks the first letter of the sentence.
char *caps_first(char *sentence)
{
    int i = 0;
    while(sentence[i] != '\0'){
        if(sentence[i-1] == ' ')    //If the following preceeding is a gap, make this cap.
            sentence[i] = toupper(sentence[i]);
        i++;
    }
    return sentence;
}

 //Removes the unncesssary spaces at the beginning of a sentenc
void no_spaces_first(char **sentence)
{
    int i = 0, j;
    while((*sentence)[i] == ' ') i++;
    for(j = 0; (*sentence)[i-1] != '\0'; i++, j++) (*sentence)[j] = (*sentence)[i];
}