#include <stdio.h>
#include <string.h>

void char_to_hex(char*, char);

int main(){
    char file_name[50];
    scanf("%s", file_name);
    getchar();

    FILE* fp1 = fopen(file_name, "r");
    if(fp1 == NULL){
        fprintf(stderr, "Can't open this file! (%s)\n", file_name);
        return 1;
    }

    FILE* fp2 = fopen("after_translate.txt", "w");
    if(fp2 == NULL){
        fprintf(stderr, "Can't make a file!\n");
        fclose(fp1);
        return 2;
    }

    char c;
    char str[4];

    while(1){
        c = fgetc(fp1);
        if(c == EOF)
            break;
        char_to_hex(str, c);
        fputs(str, fp2);
    }

    printf("complete!\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
void char_to_hex(char* str, char c){
    int n, m , l;
    
    n = (int)c;
    m = n / 16;
    l = n % 16;

    m += 48;
    if(l >= 10 && l <= 15){
        l += 55;
    }
    else{
        l += 48;
    }
    
    char tmp_str[4] = {m, l, ' ', '\0'};
    strcpy(str, tmp_str);
}