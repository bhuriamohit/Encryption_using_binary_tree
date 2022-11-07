#include <stdio.h>
#include <stdlib.h>

size_t len = 0;
char *inputString(FILE *fp, size_t size)
{
    // The size is extended by the input with the value of the provisional
    char *str;
    int ch;

    str = realloc(NULL, sizeof(*str) * size); // size is start size
    if (!str)
        return str;
    while (EOF != (ch = fgetc(fp)) && ch != '\n')
    {
        str[len++] = ch;
        if (len == size)
        {
            str = realloc(str, sizeof(*str) * (size += 16));
            if (!str)
                return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(*str) * len);
}
void encrypt(void)
{
    char *m;
    printf("\nInput the message you want to encrypt: \n");
    scanf("\n");
    m = inputString(stdin, 10);
    // printf("%s\n", m);
    //  printf("%d",len);
    if (len % 2 != 0)
    {
        len--;
    }
    int a[len + 1];
    a[0] = 0;
    for (int i = 0; i < len;)
    {
        int temp = (int)m[i] + i + 2;
        a[i + 1] = temp;
        i++;
        temp = (int)m[i] + i;
        a[i + 1] = temp;
        i++;
    }
    free(m);
    // for (int i = 1; i <= len; i++)
    // {
    //     printf("%c", a[i]);
    // }
    for (int i = 2; i <= len;)
    {
        if (i + 1 <= len)
        {
            int d = a[i];
            a[i] = a[i + 1];

            a[i + 1] = d;
        }
        i = i + 2;
    }
    printf("\nyOUR encrypted message is:\n");
    for (int i = 1; i <= len; i++)
    {
        printf("%c", a[i]);
    }
}
void decrypt(void)
{
    char *m;

    printf("\nInput the message you want to decrypt:\n ");
    scanf("\n");
    m = inputString(stdin, 10);

    len--;
    int a[len + 1];
    a[0] = 0;
    for (int i = 0; i < len;)
    {
        int temp = (int)m[i];
        a[i + 1] = temp;
        i++;
        temp = (int)m[i];
        a[i + 1] = temp;
        i++;
    }
    free(m);
    //   printf("\n");

    for (int i = 2; i <= len;)
    {
        if (i + 1 <= len)
        {
            int d = a[i];
            a[i] = a[i + 1];

            a[i + 1] = d;
        }
        i = i + 2;
    }
    //  for (int i = 1; i <= len; i++)
    // {
    //     printf("%c", a[i]);
    // }
    for (int i = 1; i <= len;)
    {
        int temp = a[i];
        a[i] = temp - i - 1;

        temp = a[i + 1];
        a[i + 1] = temp - i;
        i++;
        i++;
    }
    printf("\nyOUR decrypted message is:\n");
    for (int i = 1; i <= len; i++)
    {
        printf("%c", a[i]);
    }
}
int main(void)
{
    

    
    char c;
    printf("Welcome to Bhuria Security Agency\n");
        printf("\n1. To encrypt\n2. to decrypt\n3. quit");
        printf("\nEnter the choice(1 or 2 or 3)\n");
        scanf("\n%c", &c);
        
        if (c == '1')
        {
            encrypt();
        }
        else if (c == '2')
        {
            decrypt();
        }
        else
        {
            printf("\nQuited.....\n");
            return 0;
        }
       
    return 0;
}