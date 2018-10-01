/*
  Noah Prime
  Course: CSCI 247 - Fall 2017
  File Name: Lab1.c
*/

//Preprocessor directives. Giving compiler instructions.
#include <stdio.h>
#include <string.h>

//Macro. Defines objects early on for use in rest of the program.
#define CHAR_DATA_TYPE "char"

//Forward Declaration. Compiler can recognize what type is being used.
//void, int, char all examples of keywords in C. Important types an functions built into C.
void DataTypeSizes(void);
char* GetStringFromStdin(char* str);
void DisplayString(const char* str);
char str[100];

int main(int argc,char* argv[])
{
  printf("argc: %d, argv: ",argc);
  for(int i = 0; i < argc; i = i + 1)
    {
      printf(argv[i]);
    }
  //Function call. Allows us to break up functionality and make code easier to read/follow.
  GetStringFromStdin(str);
  DisplayString(str);
  DataTypeSizes();
  return(0);
}

void DataTypeSizes(void)
{
  //Escape Characters used to signify the end of   characters meant for the printf function.
  //Operators here to format print. Evaluated at run-time.
  //Prints to stdout which in this case is the terminal.
  printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is =  %Id\r\n",CHAR_DATA_TYPE,CHAR_DATA_TYPE,sizeof(char));
}

char* GetStringFromStdin(char* str)
{
  printf("\nEnter a string: ");
  fgets(str,100, stdin);
}

void DisplayString(const char* str)
{
  printf("Here is your String: ");
  fputs(str, stdout);
}


