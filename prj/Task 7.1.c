#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LENGTH 1000

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    char sentence[MAX_LENGTH];
    char word[] = "комп'ютер";
    int found = 0;
    int i;
    
    printf("Введіть речення (завершіть /, // або |): ");
    gets(sentence);

    int len = strlen(sentence);
    if (sentence[len-1] != '/' && sentence[len-1] != '|') {
        if (!(sentence[len-2] == '/' && sentence[len-1] == '/')) {
            printf("Помилка! Речення має закінчуватись /, // або |\n");
            return 1;
        }
    }

    for(i = 0; sentence[i] != '\0'; i++) {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] = sentence[i] + 32;
        }
    }

    if (strstr(sentence, word) != NULL) {
        found = 1;
    }

    if (found == 1) {
        printf("Слово \"комп'ютер\" знайдено!\n");
    } else {
        printf("Слово \"комп'ютер\" не знайдено!\n");
    }
    
    printf("Натисніть будь-яку клавішу для завершення...");
    getchar();
    
    return 0;
}