/*
  Noah Prime
  Course: CSCI 247 - Fall 2017
  File Name: Lab1.c
*/

//Preprocessor directives. Giving compiler instructions. Adding .h files
#include <stdio.h>
#include <string.h>

//Macro. Defines objects early on for use in rest of the program.
#define CHAR_DATA_TYPE "char"
#define INT_DATA_TYPE "int"
#define FLOAT_DATA_TYPE "float"
#define DOUBLE_DATA_TYPE "double"

//Forward Declaration. Compiler can recognize what type is being used.
//void, int, char all examples of keywords in C. Important types an functions built into C.
void DataTypeSizes(void);
char* GetStringFromStdin(char* str);
void DisplayString(const char* str);
char str[100];

int main(int argc,char* argv[])
{
  printf("Wow! This is my first C Program!\r\n");
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
  //Escape Character(/) used before a call for some action or to represent a value which will replace it
  //Operators here to format print. Evaluated at run-time.
  //Prints to stdout which in this case is the terminal.
  printf("\n\"%s\" is a standard C datatype. Size of a \"%s\" data type is =  %ld\r\n",CHAR_DATA_TYPE,CHAR_DATA_TYPE,sizeof(char));
  printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is =  %ld\r\n",INT_DATA_TYPE,INT_DATA_TYPE,sizeof(int));
  printf("Signed \"%s\" is a standard C datatype. Size of a signed \"%s\" data type is =  %ld\r\n",INT_DATA_TYPE,INT_DATA_TYPE,sizeof(signed int));
  printf("Unsigned \"%s\" is a standard C datatype. Size of an unsigned \"%s\" data type is =  %ld\r\n",INT_DATA_TYPE,INT_DATA_TYPE,sizeof(unsigned int));
  printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is =  %ld\r\n",FLOAT_DATA_TYPE,FLOAT_DATA_TYPE,sizeof(float));
  printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is =  %ld\r\n",DOUBLE_DATA_TYPE,DOUBLE_DATA_TYPE,sizeof(double));
  printf("Long \"%s\" is a standard C datatype. Size of a long \"%s\" data type is =  %ld\r\n",DOUBLE_DATA_TYPE,DOUBLE_DATA_TYPE,sizeof(long double));
}

char* GetStringFromStdin(char* str)
{
  printf("\n\nEnter a string: ");
  fgets(str,100, stdin);
}

void DisplayString(const char* str)
{
  printf("Here is your String: ");
  fputs(str, stdout);
}
