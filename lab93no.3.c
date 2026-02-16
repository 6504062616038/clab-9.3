#include <stdio.h>
#include <string.h>

int checkLogin(char *login, char *passwd, char *logindb, char *passdb);

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

    if(found)
        printf("Welcome\n");
    else
        printf("Incorrect login or password\n");

    return 0;
}

int checkLogin(char *login, char *passwd, char *logindb, char *passdb) {

    if(strcmp(login, logindb) == 0 &&
       strcmp(passwd, passdb) == 0)
        return 1;
    else
        return 0;
}

