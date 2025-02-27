#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    int numbers[10];
    int count = 0;
    
    printf("Введiть 10 натуральных чисел:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }
    
    
    for (int i = 0; i < 10; i++) {
        switch (numbers[i]) {
            case 1:
            case 3:
            case 157:
            case 256:
            case 1000:
            count++;
            break;
        }
    }
    printf("Кiлькiсть чисел що дорiвнюють 1, 3, 157, 256, або 1000: %d\n", count);

    printf("Натисніть будь-яку клавішу для завершення...");
    getchar();
    return 0;
}