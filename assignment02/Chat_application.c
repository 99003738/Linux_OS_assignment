#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int file_d; 
    char * myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char array_input1[80], array_input2[80]; 
    while (1) 
    { 
        file_d = open(myfifo, O_WRONLY); 
        fgets(array_input2, 80, stdin); 
        write(file_d, array_input2, strlen(array_input2)+1); 
        close(file_d); 
        file_d = open(myfifo, O_RDONLY); 
        read(file_d, array_input1, sizeof(array_input1)); 
        printf("User2: %s\n", array_input1); 
        close(file_d); 
    } 
    return 0; 
} 