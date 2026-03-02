#include <stdio.h>
#define MAX 200

int main() {

    char str[MAX];
    int sum = 0;
    int i = 0;

    printf("Enter input: ");
    scanf("%[^\n]", str);

    while(str[i] != '\0') {

        if(str[i] >= '0' && str[i] <= '9') {
            sum += str[i] - '0';
        }

        i++;
    }

    printf("Sum of digit char: %d\n", sum);

    return 0;
}
