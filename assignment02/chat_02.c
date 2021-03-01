 #include "common.h"
int main() 
{ 
    int file_d1; 
    char * myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char string_input1[80], string_input2[80]; 
    while (1) 
    { 
        file_d1 = open(myfifo,O_RDONLY); 
        read(file_d1, string_input1, 80); 
        printf("User1: %s\n", string_input1); 
        close(file_d1); 
        file_d1 = open(myfifo,O_WRONLY); 
        fgets(string_input2, 80, stdin); 
        write(file_d1, string_input2, strlen(string_input2)+1); 
        close(file_d1); 
    } 
    return 0; 
} 