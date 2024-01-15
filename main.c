#include <stdio.h>
#include <string.h>

char hex_to_char(char*);

int main(){
    char file_name[100];
    scanf("%s", file_name);

    FILE* fp1 = fopen(file_name, "r");
    FILE* fp2 = fopen("after_translate.txt", "w");

    if(fp1 == NULL){
        fprintf(stderr, "Can't open this file! (%s)\n", file_name);
        return 1;
    }

    if(fp2 == NULL){
        fprintf(stderr, "Can't make a file!\n");
        return 2;
    }

    char hex_str[3];
    char end_code[3] = "00"; 
    int chk_end_code = 0;
    char c;

    while(fscanf(fp1, "%s", hex_str) != EOF){
        c = hex_to_char(hex_str);
        fprintf(fp2 ,"%c", c);
    }

    printf("complete!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}

char hex_to_char(char* hex_str){
    int num = 0;
    num += (int)hex_str[0] * 16;
    if((int)hex_str[1] >= 48 && (int)hex_str[1] <= 57){
        num += (int)hex_str[1] - 48;
        return num;
    }
    else if((int)hex_str[1] >= 97 && (int)hex_str[1] <= 122){
        num += (int)hex_str[1] - 87;
        return num;
    }
    else{
        num += (int)hex_str[1] - 55;
        return num;
    }
}