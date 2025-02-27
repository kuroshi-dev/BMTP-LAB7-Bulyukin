#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LENGTH 1000

void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    setlocale(LC_ALL, "");  // Enable Unicode support
    char sentence[MAX_LENGTH];
    int found = 0;
    
    printf("Введіть речення (завершіть /, // або |): ");
    gets(sentence);
    
    // Check if sentence ends with valid terminators
    int len = strlen(sentence);
    if (len < 1 || (sentence[len-1] != '/' && sentence[len-1] != '|' && 
        !(len >= 2 && sentence[len-2] == '/' && sentence[len-1] == '/'))) {
        printf("Помилка: речення має закінчуватися /, // або |\n");
        return 1;
    }
    
    // Convert sentence to lowercase for case-insensitive search
    char lowerSentence[MAX_LENGTH];
    strcpy(lowerSentence, sentence);
    toLowerCase(lowerSentence);
    
    // Search for the word "комп'ютер"
    const char *word = "комп'ютер";
    if (strstr(lowerSentence, word) != NULL) {
        found = 1;
    }
    
    // Output result
    if (found) {
        printf("Слово \"комп'ютер\" знайдено в реченні.\n");
    } else {
        printf("Слово \"комп'ютер\" не знайдено в реченні.\n");
    }
    
    return 0;
}