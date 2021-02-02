#ifndef _DEFNITIONS_H_
#include "definitions.h"
#endif

//The sum of the ASCII values of the string.
int addition_string(char *sentence)
{
    int i, sum = 0;
    for(i = 0; *(sentence+i) != '\0'; i++)
        sum += (int)(*(sentence+i));
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
    for(i = 0; *(sentence+i) != '\0'; i++) *(sentence+i) = toupper(*(sentence+i));
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
    while(*(key+i) == ' ') i++;
    return *(key+i);
}

 //Breaks the last newline of a sentence.
void break_new_line(char **sentence){ 
    (*sentence)[strlen((*sentence)) - 1] = '\0';
}

//Checks if the sentence is made of basic numbers
int does_not_contain_number(char *sentence)
{
    int i;
    for(i = 0; *(sentence+i) != '\0'; i++){
        if(*(sentence+i) >= 48 && *(sentence+i) <= 57)
            return 0;
    }
    return 1;
}

//Checks if a sentence contains any letter.
int does_not_contain_letter(char *sentence){
    for(int i = 0; i < strlen(sentence); i++){
        if((*(sentence+i) >= 65 && *(sentence+i) <= 90) || (*(sentence+i) >= 97 && *(sentence+i) <= 122)){
            return false;
        }
    }
    return true;
}

//checks if a sentence has any comma
int has_comma(char *sentence){
    for(int i = 0; i < strlen(sentence); i++){
        if(*(sentence+i) == ',')
            return true;
    }
    return false;
}

//Checks if a sentence contains any symbol whatsoever.
int does_not_contain_symbol(char *str){
   for(int i = 0; i < strlen(str); i++){
       if(str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$'
      || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*'
      || str[i] == '(' || str[i] == ')' || str[i] == '-' || str[i] == '{'
      || str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':'
      || str[i] == ';' || str[i] == '"' || str[i] == '\'' || str[i] == '<'
      || str[i] == '>' || str[i] == '.' || str[i] == '/' || str[i] == '?'
      || str[i] == '~' || str[i] == '`' ){
          return false;
      }
   }
    return true;
}

//Caps Locks the first letter of the sentence.
//WARNING: ALWAYS SEND ALLOCATED MEMORY IN THIS FUNCTION.
char *caps_first(char *sentence){
    char *copy_sentence = (char*)malloc(sizeof(char) * (strlen(sentence)+1));
    strcpy(copy_sentence, sentence);
    
    copy_sentence[0] = toupper(copy_sentence[0]);
    for(int i = 1; copy_sentence[i] != '\0'; i++){
        if(copy_sentence[i-1] == ' '){
            copy_sentence[i] = toupper(copy_sentence[i]);
        } else {
            copy_sentence[i] = tolower(copy_sentence[i]);
        }
    }
    free(sentence);
    return copy_sentence;
}

 //Removes the unncesssary spaces at the beginning of a sentenc
void no_spaces_first(char **sentence)
{
    int i = 0, j;
    while((*sentence)[i] == ' ') i++;
    for(j = 0; (*sentence)[i-1] != '\0'; i++, j++) (*sentence)[j] = (*sentence)[i];
}