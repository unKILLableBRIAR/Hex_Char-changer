#include <stdio.h>
#include <string.h>

int main(){

    char hex_str[3] = "4A";

    int num = 0;
    num += (int)hex_str[0] * 16;
    if((int)hex_str[1] >= 48 && (int)hex_str[1] <= 57){
        num += (int)hex_str[1] - 48;
    }
    else if((int)hex_str[1] >= 97 && (int)hex_str[1] <= 122){
        num += (int)hex_str[1] - 87;
    }
    else{
        num += (int)hex_str[1] - 55;
    }

    printf("%c\n",num);

    return 0;
}