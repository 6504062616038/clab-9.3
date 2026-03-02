#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char str1[MAX], str2[MAX];
    char result[MAX];
    int i, j, k;
    int found;

    printf("Enter the First string:\n");
    fgets(str1, MAX, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the Second string:\n");
    fgets(str2, MAX, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    printf("\n--- Summary ---\n");

    for(i = 0; str1[i] != '\0'; i++)
    {
        found = 0;
        k = 0;

        for(j = 0; str2[j] != '\0'; j++)
        {
            if(str2[j] == str1[i])
            {
                found++;  
            }
            else
            {
                result[k++] = str2[j];
            }
        }

        result[k] = '\0';
        strcpy(str2, result);

        if(found > 0)
            printf("Character '%c' removed %d time(s)\n", str1[i], found);
        else
            printf("Character '%c' not found\n", str1[i]);
    }

    printf("\nFinal second string: %s\n", str2);

    return 0;
}
