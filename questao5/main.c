#include <stdio.h>
#include <string.h>

void inverterString(char *str) {
    int tamanho = strlen(str);
    int i, j;

    for (i = 0, j = tamanho - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    const int MAX_TAMANHO = 100;
    char minhaString[MAX_TAMANHO];
    printf("Digite uma string: ");
    fgets(minhaString, MAX_TAMANHO, stdin);
    minhaString[strcspn(minhaString, "\n")] = '\0';
    inverterString(minhaString);
    printf("String invertida: %s\n", minhaString);

    return 0;
}
