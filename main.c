#include <stdio.h>
#include <string.h>

char hex_to_char(char*);

int main(){
    char hex_str[3];
    char end_code[3] = "00";
    int chk_end_code = 0;
    char c;

    while(1){
        scanf("%s", hex_str);
        chk_end_code = strcmp(hex_str, end_code);
        if(chk_end_code == 0){
            break;
        }
        c = hex_to_char(hex_str);
        printf("%c\n", c);
    }

    printf("complete!\n");

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