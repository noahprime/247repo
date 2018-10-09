#include <stdio.h>
#include <string.h>

#define BUFFSIZE 4096

char* itoa(int num, char* str, int base);

int main(int argc, char *argv[]) {
	int number, base;

	if (argc != 3) {
		printf("Usage: ./Lab2 <number> <base>\n");
		return 1;
	}

	int res = sscanf(argv[1], "%d", &number);
	if (!res || res == EOF) {
		printf("Could not parse %s\n", argv[1]);
		return 1;
	}

	res = sscanf(argv[2], "%d", &base);
	if (!res || res == EOF) {
		printf("Could not parse %s\n", argv[2]);
		return 1;
	} else if (!(2 <= base && base <= 36)) {
		printf("Base must be between 2 and 36\n");
		return 1;
	}

	char buf[BUFFSIZE];

	if (itoa(number, buf, base) != buf) {
		printf("Failed to convert %d to base %d\n", number, base);
		return 1;
	}

	printf("Here is %d converted to base %d:\n%s\n", number, base, buf);

	return 0;
}

char* itoa(int num, char* str, int base) {
  if(num == 0){
    str[0] = '0';
    return str;
  }
  else if(base <= 10){

    int i = 0;
    int j = 0;

    if(num < 0){
      str[i] = '-';
      i++;
      num = num*-1;
      j++;
    }

    while(num != 0){
      int rem = num%base;
			char c = rem + '0';
      num = num/base;
      str[i] = c;
      i++;
    }

      i--;

    while(i > j){
      char dummy = str[i];
      str[i] = str[j];
      str[j] = dummy;
      i--;
      j++;
    }

    return str;
  }
  //////////////////////////////////////////////////////////////
  //BASE GREATER THAN 10
  ///////////////////////////////////////////////////////////////
  else{
    int i = 0;
    int j = 0;

    if(num < 0){
      str[i] = '-';
      i++;
      num = num*-1;
      j++;
    }

    while(num != 0){
      int rem = num%base;
			char c;
      if(rem > 9){
        c = (rem - 10) + 'a';
      }
      else{
        c = rem + '0';
      }
      num = num/base;
      str[i] = c;
      i++;
    }

      i--;

    while(i > j){
      char dummy = str[i];
      str[i] = str[j];
      str[j] = dummy;
      i--;
      j++;
    }

    return str;
  }
}
