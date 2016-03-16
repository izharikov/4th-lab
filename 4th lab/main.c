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
    printf("Choose command: ");
    int choose = -1;
    printf("0.Select\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Update\n");
    printf("4.Execute parametrized query\n");
    scanf("%d", &choose);
    switch (choose) {
        case 0:
            selectFromTable(db, sql, zErrMsg);
            break;
        case 1:
            insertInTable(db, sql, zErrMsg);
        case 2:
            deleteFromTable(db, sql,zErrMsg);
            break;
        default:
            break;
    }
}

/*
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";
    
    /* Open database */
    /*rc = sqlite3_open("/Users/admin/Documents/4th lab/4th lab/empl.db", &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create merged SQL statement */
    /*sql = "DELETE from empl_table where ID=6; " \
    "SELECT * from empl_table";
    
    /* Execute SQL statement */
   /* rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}*/
