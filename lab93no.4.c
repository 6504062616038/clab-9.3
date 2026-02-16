#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkLogin(char *login, char *passwd, char *logindb, char *passdb);
void countVowels(char *text);

int main() {

    char loginDB[5][64] = {"user1","user2","user3","user4","user5"};
    char passDB[5][64]  = {"pass1","pass2","pass3","pass4","pass5"};

    char login[64], password[64];

    printf("Enter login: ");
    fgets(login, sizeof(login), stdin);
    login[strcspn(login, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    int found = 0;

    for(int i = 0; i < 5; i++) {
        if(checkLogin(login, password, loginDB[i], passDB[i])) {
            found = 1;
            break;
        }
    }

    if(found) {
        printf("Welcome\n");
        countVowels(password);
    }
    else {
        printf("Incorrect login or password\n");
    }

    return 0;
}

int checkLogin(char *login, char *passwd, char *logindb, char *passdb) {

    if(strcmp(login, logindb) == 0 &&
       strcmp(passwd, passdb) == 0)
        return 1;
    else
        return 0;
}

void countVowels(char *text) {

    int a=0, e=0, i=0, o=0, u=0;

    for(int j = 0; text[j] != '\0'; j++) {

        char ch = tolower(text[j]);

        if(ch == 'a') a++;
        else if(ch == 'e') e++;
        else if(ch == 'i') i++;
        else if(ch == 'o') o++;
        else if(ch == 'u') u++;
    }

    printf("Vowel count:\n");
    printf("a = %d\n", a);
    printf("e = %d\n", e);
    printf("i = %d\n", i);
    printf("o = %d\n", o);
    printf("u = %d\n", u);
}

