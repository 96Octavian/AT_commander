#include<fcntl.h>       //header file for file operations
#include<stdio.h>
#include<stdlib.h>

main(int argc, char*argv[]){
        if(argc != 2){ //checks if two arguments are present
                printf("The syntax should be as follows:");
                printf("\nCommandname filetoread\n");
                exit(1);
        }
        int fd, count;
        char buffer[4096]; //characer buffer to store the bytes
        fd = open(argv[1], O_RDONLY);
        if(fd == -1){
                printf("cannot open file");
                exit(1);
        }
        count = read(fd, buffer, sizeof(buffer));
        while(count > 0){ //displaying the content
                printf("%s\n", buffer);
                count = read(fd, buffer, sizeof(buffer));
        }
        exit(0);
}
