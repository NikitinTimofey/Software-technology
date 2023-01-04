#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int ADMIN_ROLE = 0;
const int USER_ROLE = 1;

struct user {
    char login[10];
    char password[10];
    int role; //0 - Admin, 1 - user
} users[100];
int users_num = 0;

struct theatre {
    char nameTheatre[40];
    char namePerf[40];
    int day;
    int year;
    int month;
    int sellTicket;
} theatres[100], buff[100], tmp;
int theatres_num = 0;

void showMessage(char *msg) {
    int i;
    while (1) {
        system("cls");
        printf("%s\n", msg);
        printf("Enter 0 to return:");
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }

}

int load() {
    FILE *f = fopen("db.dat", "rb");
    if (f) {
        fread(&users_num, sizeof(int), 1, f);
        fread(&theatres_num, sizeof(int), 1, f);
        if (users_num > 100 || theatres_num > 100) {
            printf("Invalid file format");
            exit(0);
        }
        if (users_num > 0) {
            fread(users, sizeof(struct user), users_num, f);
        }
        if (theatres_num > 0) {
            fread(theatres, sizeof(struct theatre), theatres_num, f);
        }
        fclose(f);
        return 1;
    }
    return 0;
}

void save() {
    FILE *f = fopen("db.dat", "wb");
    fwrite(&users_num, sizeof(int), 1, f);
    fwrite(&theatres_num, sizeof(int), 1, f);
    if (users_num > 0) {
        fwrite(users, sizeof(struct user), users_num, f);
    }
    if (theatres_num > 0) {
        fwrite(theatres, sizeof(struct theatre), theatres_num, f);
    }
    fclose(f);
}

int findUser(char login[10]) {
    for (int i = 0; i < users_num; i++) {
        if (strcmp(users[i].login, login) == 0) {
            return i;
        }
    }
    return -1;
}

void doUserList() {
    while (1) {
        system("cls");
        fflush(stdin);//clear input
        for (int i = 0; i < users_num; i++) {
            printf("%d. %s / %s (%s)\n", i + 1, users[i].login, users[i].password,
                    users[i].role == ADMIN_ROLE ? "admin" : "user");
        }
        printf("Enter 0 to return:");
        int i;
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }
}

void doAddUser() {
    system("cls");
    fflush(stdin);//clear input

    struct user u;
    printf("Enter login: ");
    scanf("%s", u.login);
    printf("Enter password: ");
    scanf("%s", u.password);
    printf("Enter role (0 - Admin, 1 - User): ");
    scanf("%d", &u.role);
    if (u.role != 0) {
        u.role = 1;
    }
    users[users_num++] = u;

    showMessage("User added");
}

void doRemoveUser() {
    system("cls");
    fflush(stdin);//clear input

    char login[100];
    printf("Enter login to remove: ");
    scanf("%s", login);
    int index = findUser(login);
    if (index < 0) {
        return;
    }
    printf("Are you sure you want to remove this user? (1 - yes, 0 - No):");
    int i;
    scanf("%d", &i);
    if (i != 0) {
        for (int i = index; i < users_num - 1; i++) {
            users[i] = users[i + 1];
        }
        users_num--;
        showMessage("User removed");
    }
}

void doUsers() {
    while (1) {
        system("cls");
        fflush(stdin);//clear input
        printf("0. Return\n");
        printf("1. List users\n");
        printf("2. Add user\n");
        printf("3. Remove user\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 0:
                return;
            case 1:
                doUserList();
                break;
            case 2:
                doAddUser();
                break;
            case 3:
                doRemoveUser();
                break;
        }
    }
}

void doListPerf() {
    while (1) {
        system("cls");
        fflush(stdin);//clear input
        for (int i = 0; i < theatres_num; i++) {
            struct theatre th = theatres[i];
            printf("No %d\n", i + 1);
            printf("Date - %d.%d.%d\n", th.day, th.month, th.year);  
            printf("Performance - %s\n", th.namePerf);
            printf("Theatre - %s\n", th.nameTheatre);
            printf("Number of tickets sold - %d\n", th.sellTicket); 
        }
        printf("Enter 0 to return:");
        int i;
        scanf("%d", &i);
        if (i == 0) {
            return;
        }
    }
}

void doAddTheatre() {
    system("cls");
    fflush(stdin);//clear input

    struct theatre th;
    printf("Enter name theatre: ");
    scanf("%s", th.nameTheatre);
    printf("Enter name performance: ");
    scanf("%s", th.namePerf);
    th.day = -1;
    while(th.day<=0 || th.day>31) {
        printf("Enter day: ");
        scanf("%d", &th.day);
    }
    th.month = -1;
    while(th.month < 0 || th.month > 12) {
        printf("Enter month: ");
        scanf("%d", &th.month);
    }
    th.year = -1;
    while(th.year < 2020) {
        printf("Enter year: ");
        scanf("%d", &th.year);
    }
    th.sellTicket = -1;
    while(th.sellTicket < 0) {
        printf("Enter the number of tickets sold: ");
        scanf("%d", &th.sellTicket);
    }
    theatres[theatres_num] = th;
    theatres_num++;
    showMessage("Performance added");
}

void doEditPerf() {
    system("cls");
    fflush(stdin);//clear input

    int num;
    printf("Enter performance number to edit: ");
    scanf("%d", &num);
    if (num > theatres_num) {
        return;
    }
    struct theatre th;
    printf("Enter name theatre: ");
    scanf("%s", th.nameTheatre);
    printf("Enter name performance: ");
    scanf("%s", th.namePerf);
    th.day = -1;
    while(th.day<=0 || th.day>31) {
        printf("Enter day: ");
        scanf("%d", &th.day);
    }
    th.month = -1;
    while(th.month < 0 || th.month > 12) {
        printf("Enter month: ");
        scanf("%d", &th.month);
    }
    th.year = -1;
    while(th.year < 2020) {
        printf("Enter year: ");
        scanf("%d", &th.year);
    }
    th.sellTicket = -1;
    while(th.sellTicket < 0) {
        printf("Enter the number of tickets sold: ");
        scanf("%d", &th.sellTicket);
    }

    theatres[num - 1] = th;
    showMessage("Performance edited");
}

void doRemovePerf() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter peformance number to remove: ");
    scanf("%d", &num);
    if (num > theatres_num) {
        return;
    }
    printf("Are you sure you want to remove this performance? (1 - yes, 0 - No):");
    int i;
    scanf("%d", &i);
    if (i != 0) {
        int index = num - 1;
        for (i = index; i < theatres_num - 1; i++) {
            theatres[i] = theatres[i + 1];
            theatres_num--;
            showMessage("Performance removed");
        }
    }
}

void doBuyTicket() {
    system("cls");
    fflush(stdin);

    int num;
    printf("Enter performance number to buy ticket: ");
    scanf("%d", &num);
    if (num > theatres_num) {
        return;
    }
    theatres[num-1].sellTicket++;
    printf("You buy ticket on %s, see you soon!\n", theatres[num-1].namePerf);
    int i;
    printf("Enter some digit ");
    scanf("%d", &i);
}

void doSortBuff() {
    for(int i = 0; i<theatres_num; i++) {
        buff[i] = theatres[i];
    }
    for(int i = 0 ; i < theatres_num - 1; i++) { 
       for(int j = 0 ; j < theatres_num - i - 1 ; j++) {  
           if(buff[j].sellTicket < buff[j+1].sellTicket) {            
              tmp = buff[j];
              buff[j] = buff[j+1] ;
              buff[j+1] = tmp; 
           }
        }
    }
}

void doSortPerf() {
    system("cls");
    fflush(stdin);
    doSortBuff();

    struct perf {
        char name[40];
        int rate;
    } per[theatres_num], tmp2;

    int per_num = theatres_num;
    for (int i = 0; i < theatres_num; i++) {
        strcpy(per[i].name, buff[i].namePerf);
    } 
    
    for(int i = 0 ; i < per_num - 1; i++) { 
        for(int j = 0 ; j < per_num - 1 ; j++) {  
            if(strcmp(per[i].name,per[j].name) == 0 && i != j) {            
                tmp2 = per[per_num-1];
                per[per_num-1] = per[j];
                per[j] = tmp2; 
                per_num--;
            }
        }
    }
    
    printf("\n");
    for(int i = 0; i < per_num; i++) {
        printf("name - %s\n", per[i].name);
    }

    int numMonth = -1;
    while(numMonth < 0 || numMonth > 12) {
        printf("Enter month: ");
        scanf("%d", &numMonth);
    }
    for(int i = 0; i < per_num; i++) {
        per[i].rate = 0;
        for (int j = 0; j < theatres_num; j++) {
            if ((strcmp(per[i].name, buff[j].namePerf) == 0) && (numMonth == buff[j].month)) {
                per[i].rate += buff[j].sellTicket;
            }
        }
    }
    for(int i = 0 ; i < per_num - 1; i++) { 
        for(int j = 0 ; j < per_num - i - 1 ; j++) {  
            if(per[j].rate < per[j+1].rate) {            
                tmp2 = per[j];
                per[j] = per[j+1];
                per[j+1] = tmp2; 
            }
        }
    }
    for(int i = 0; i < per_num; i++) {
        printf("name - %s rate = %d\n", per[i].name, per[i].rate);
    }

    int i;
    printf("Enter some digit ");
    scanf("%d", &i);
}

void doSortTheatres() {
    system("cls");
    fflush(stdin);
    doSortBuff();

    struct theat {
        char name[40];
        int rate;
    } tht[theatres_num], tmp2;

    int tht_num = theatres_num;
    for (int i = 0; i < theatres_num; i++) {
        strcpy(tht[i].name, buff[i].nameTheatre);
    } 
    for (int k = 0; k < tht_num; k++) {
        for(int i = 0 ; i < tht_num - 1; i++) { 
            for(int j = 0 ; j < tht_num - 1 ; j++) {  
                if(strcmp(tht[i].name,tht[j].name) == 0 && i != j) {            
                    tmp2 = tht[j];
                    tht[j] = tht[tht_num-1];
                    tht[tht_num-1] = tmp2; 
                    tht_num--;
                }
            }
        }
    }
    for (int i = 0; i < tht_num-1; i++) {
        if(strcmp(tht[i].name, tht[theatres_num-1].name) == 0 ) {
            tht_num--;
        }
    }

    printf("\n");
    for(int i = 0; i < tht_num; i++) {
        printf("name - %s\n", tht[i].name);
    }

    int numMonth = -1;
    while(numMonth < 0 || numMonth > 12) {
        printf("Enter month: ");
        scanf("%d", &numMonth);
    }
    for(int i = 0; i < tht_num; i++) {
        tht[i].rate = 0;
        for (int j = 0; j < theatres_num; j++) {
            if ((strcmp(tht[i].name, buff[j].nameTheatre) == 0) && (numMonth == buff[j].month)) {
                tht[i].rate += buff[j].sellTicket;
            }
        }
    }
    for(int i = 0 ; i < tht_num - 1; i++) { 
        for(int j = 0 ; j < tht_num - i - 1 ; j++) {  
            if(tht[j].rate < tht[j+1].rate) {            
                tmp2 = tht[j];
                tht[j] = tht[j+1];
                tht[j+1] = tmp2; 
            }
        }
    }
    for(int i = 0; i < tht_num; i++) {
        printf("name - %s rate = %d\n", tht[i].name, tht[i].rate);
    }

    int i;
    printf("Enter some digit ");
    scanf("%d", &i);
}

void doPerf() {
    while (1) {
        system("cls");
        fflush(stdin);
        printf("0. Return\n");
        printf("1. List performances\n");
        printf("2. Add performance\n");
        printf("3. Edit performance\n");
        printf("4. Remove performance\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 0:
                return;
            case 1:
                doListPerf();
                break;
            case 2:
                doAddTheatre();
                break;
            case 3:
                doEditPerf();
                break;
            case 4:
                doRemovePerf();
                break;
        }
    }
}

void doAdmin() {
    while (1) {
        system("cls");
        fflush(stdin);//clear input
        printf("1. Users\n");
        printf("2. Performances\n");
        printf("3. Exit\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                doUsers();
                break;
            case 2:
                doPerf();
                break;
            case 3:
                return;
        }
    }
}

void doUser() {
    while (1) {
        system("cls");
        fflush(stdin);//clear input
        printf("1. Performances\n");
        printf("2. To buy ticket\n");
        printf("3. To sort theaters by popularity and month\n");
        printf("4. To sort performances by popularity and month\n");
        printf("5. Exit\n");
        int i;
        printf("Select item: ");
        scanf("%d", &i);
        switch (i) {
            case 1:
                doListPerf();
                break;
            case 2:
                doBuyTicket();
                break;
            case 3:
                doSortTheatres();
                break;
            case 4:
                doSortPerf();
                break;
            case 5:
                return;
        }
    }
}

void doLogin() {
    char login[100];
    char password[100];
    printf("Login: ");
    scanf("%s", login);
    int i = findUser(login);
    if (i < 0) {
        printf("User not found");
        return;
    }
    struct user u = users[i];
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(u.password, password) != 0) {
        printf("Invalid password");
        return;
    }
    if (u.role == ADMIN_ROLE) {
        doAdmin();
    } else {
        doUser();
    }
}

void createDefaultAdmin() {
    system("cls");
    fflush(stdin);

    struct user u = {"admin", "pass", ADMIN_ROLE};
    users[users_num++] = u;

    printf("New database with default admin created. Use 'admin' for login and 'pass' for password\n");
}

int main(void) {
    if (load()) {
        //file loaded successfully
        doLogin();
    } else {
        //file doesn't exist
        createDefaultAdmin();
    }
    save();
}
