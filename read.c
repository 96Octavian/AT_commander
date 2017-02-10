#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LINELEN 256

FILE *fp;

void copy_file(int writeLineNumbers);

int main (int argc, char *argv[]) {
    char cpr[]= "-n";
    if(argc>2) {
        perror("Too much arguments");
        exit(1);
    }
    if((fp= fopen("/dev/ttyUSB0", "r"))!=NULL) {
        if(argc == 2) {
            if(strcmp(cpr,argv[1])==0) {
                copy_file(1);
                exit(1);
            }
            else {
                perror("Unrecognized option");
                exit(1);
            }
        }
        else {
            copy_file(0);
            exit(1);
        }
    }
    else {
        perror("could not open the file.");
        exit(1);
    }
}

void copy_file (int writeLineNumbers) {
    char line[LINELEN];
    int lineno = 1;

    while (fgets(line, LINELEN, fp))
    {
        if (writeLineNumbers)
            printf("%d ", lineno);

        if (fputs(line, stdout) == EOF)
        {
            perror("Write to stdout failed.");
            return;
        }

        ++lineno;
    }
}
