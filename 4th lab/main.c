#include <stdio.h>
#include <sqlite3.h>
#include "db_options.h"

void showMenu();
int init();
sqlite3 *db;
char *zErrMsg = 0;
int rc;
char *sql;

int main(int argc, char* argv[])
{
    char *data = "Select from table";
    /* Open database */
    if ( init() == 0){
        showMenu();
    }
    else{
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    sqlite3_close(db);
}

int init(){
    rc = sqlite3_open("/Users/admin/Documents/4th lab/4th lab/empl.db", &db);
    if ( !rc){
        return CONNECT_SUCCESS;
    }
    return CONNECT_ERROR;
}

void showMenu(){
    int choose = -1;
    printf("0.Select\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Execute parameterized query\n");
    printf("4.Photo in file\n");
    printf("5.Exit\n");
    printf("Choose command: ");
    scanf("%d", &choose);
    switch (choose) {
        case 0:
            selectFromTable(db, sql, zErrMsg);
            break;
        case 1:
            insertInTable(db, sql, zErrMsg);
            break;
        case 2:
            deleteFromTable(db, sql,zErrMsg);
            break;
        case 3:
            parameterizedQuery(db, sql, zErrMsg);
            break;
        case 4:
            photoInFile(db, sql, zErrMsg);
            break;
        case 5:
            return;
        default:
            break;
    }
    showMenu();
}

