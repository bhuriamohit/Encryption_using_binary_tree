#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reChar(char **, int *);
void readLine(char **, int *);

int main() {
    char *palabra = NULL;
    int largo = 0;

    reChar(&palabra, &largo);
    readLine(&palabra, &largo);
    printf("palabra=%s\n", palabra, largo);

    system("pause");
    return 0;
}

void reChar(char **lst, int *largo) {
    (*largo) += 4;
    char *temp = (char*) realloc(*lst, (*largo) * sizeof (char));

    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        puts("error (re)allocating memory");
        exit(1);
    }
}

void readLine(char **lst, int *largo) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if ((pos + 1) % 4 == 0) {
            reChar(lst, largo);
        }
        (*lst)[pos] =(char) c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}