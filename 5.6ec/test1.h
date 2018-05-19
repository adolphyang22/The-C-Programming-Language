#include <stdio.h>

#include <ctype.h>

#include <string.h>

#define NUMBER '0'	/* signal that a number was found */
#define BUFSIZE 100 

int getline_test(char *, int);

int atoi_test(char *);
void itoa_test(int , char *);
double atof_test(char *);

void reverse_test(char *);

int strindex_test(char *, char *);

int getch_test(void);

void ungetch_test(int);

int getop_test(char *);

