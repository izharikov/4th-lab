//
//  db_options.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include <stdio.h>
#include "db_options.h"

void insertInTable(sqlite3 * db, char* sql, char* zErrMsg)
{
    char firstname[15], lastname[15], middlename[15], birthday[15], town[30], address[30], department[10], job[15], dateOfDeployment[15], photoName[100], country[20];
    printf ("\n-----INSERT-----\n");
    printf("Enter first name: ");
    scanf("%s", firstname);
    printf("Enter middle name: ");
    scanf("%s", middlename);
    printf("Enter last name: ");
    scanf("%s", lastname);
    printf("Enter date of birthday: ");
    scanf("%s", birthday);
    printf("Enter town of birth: ");
    scanf("%s", town);
    printf("Enter country of birth: ");
    scanf("%s", country);
    printf("Enter department: ");
    scanf("%s", department);
    printf("Enter job: ");
    scanf("%s", job);
    printf("Enter date of deployment: ");
    scanf("%s", dateOfDeployment);
    printf("Enter address: ");
    scanf("%s", address);
    sql = "INSERT INTO empl_table(firstName, middleName, lastName, dateOfBirthDay, town, country, department, job, dateOfEmployment, address) VALUES('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');";
    char *str = malloc (sizeof(char) * 300);
    sprintf(str, sql,firstname, middlename,lastname,dateOfDeployment,town, country, department, job, dateOfDeployment, address) ;
    int rc = -1;
    rc = sqlite3_exec(db, str, callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK)
    {
        printf ("SQL ERROR: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        
    }
    else
    {
        printf ("\nRecords is successfull add!\n");
        
    }
    free(str);
    //IMG
    printf("Enter way to photo: ");
    scanf("%s", photoName);
    FILE *fp = fopen(photoName, "rb");
     
     if (fp == NULL) {
     
     fprintf(stderr, "Cannot open image file %s\n", photoName);
     return;
     }
     
     fseek(fp, 0, SEEK_END);
     
     int flen = ftell(fp);
     
     fseek(fp, 0, SEEK_SET);
     
     char data[flen+1];
     int size = fread(data, 1, flen, fp);
     fclose(fp);
     
     
     sqlite3_stmt *pStmt;
     
     char str1[150]= "UPDATE empl_table SET photo = ? WHERE firstName = '%s' AND lastName = '%s'";
     sprintf(str1,str1,firstname, lastname);
     
     rc = sqlite3_prepare(db, str1, -1, &pStmt, 0);
     
     if (rc != SQLITE_OK) {
     
     fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
     
     return;
     }
     else{
         printf("Success adding photo\n");
     }
     sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);
     
     rc = sqlite3_step(pStmt);
     
     if (rc != SQLITE_DONE) {
     
     printf("execution failed: %s", sqlite3_errmsg(db));
     }
     
     sqlite3_finalize(pStmt);
    
    // IMG.end
    
}

void deleteFromTable(sqlite3*db, char*sql, char*zErrMsg){
    printf("All records:\n");
    selectFromTable(db, sql, zErrMsg);
    printf("Enter id of item to delete: ");
    int id;
    scanf("%d", &id);
    char str[300];
    sql = "delete from empl_table where id = %d";
    sprintf(str, sql, id);
    int rc = -1;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK)
    {
        printf ("SQL ERROR: %s\n", sqlite3_errmsg(db));
        sqlite3_free(zErrMsg);
        
    }
    else
    {
        printf ("Record successfully removed!");
        
    }
}

void selectFromTable(sqlite3 *db, char* sql, char* zErrMsg){
    int rc;
    sql = "select * from empl_table;";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if ( rc != SQLITE_OK){
        printf("Error select: %s\n", sqlite3_errmsg(db) );
    }
    else{
        printf("Success select\n");
    }
}

int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void parameterizedQuery(sqlite3* db, char* sql, char* zErrMsg)
{
    int choice = -1;
    
    printf("Choise a parameter of selecting:\n");
    printf("0.id\n");
    printf("1.Last name\n");
    printf("2.Country of birth\n");
    printf("3.Cancel\n");
    scanf("%d", &choice);
    char str[300];
    char param[15];
    switch (choice) {
            
        case 3:
            return;
        case 0:
            printf("Enter id: ");
            sql = "SELECT * FROM empl_table WHERE id = %s;";
            break;
            
        case 1:
            printf("Enter lastname: ");
            sql = "SELECT * FROM empl_table WHERE lastName = '%s';";
            break;
            
        case 2:
            printf("Enter country: ");
            sql = "SELECT * FROM empl_table WHERE country = '%s';";
            break;
            
        default:
            printf("Invalid parameter.\n");
            break;
            
    }
    scanf("%s", param);
    sprintf(str, sql, param);
    int rc = sqlite3_exec(db, str, callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK)
    {
        printf ("SQL ERROR: %s\n", sqlite3_errmsg(db));
        sqlite3_free(zErrMsg);
        
    }
    else{
        printf("Success!\n");
    }
}
void photoInFile(sqlite3* db, char* sql, char* zErrMsg)
{
    char id[3];
    printf("Enter id user: ");
    scanf("%s", id);
    
    FILE *fp = fopen("/Users/admin/4th-lab/4th lab/photo.jpg", "wb");
    
    if (fp == NULL) {
        
        fprintf(stderr, "Cannot open image file\n");
        return;
    }
    
    int rc = -1;
    sql = "SELECT photo FROM empl_table WHERE photo IS NOT NULL AND id = %s";
    char str[300];
    sprintf(str,sql,id);
    
    sqlite3_stmt *pStmt;
    rc = sqlite3_prepare_v2(db, str, -1, &pStmt, 0);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to prepare statement\n");
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        
        sqlite3_close(db);
        
        return;
    }
    
    rc = sqlite3_step(pStmt);
    
    int bytes = 0;
    
    if (rc == SQLITE_ROW) {
        
        bytes = sqlite3_column_bytes(pStmt, 0);
    }
    
    int c;
    c = fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, fp);
    
    if (c < 1)
        printf("\nThe photo of this user is empty!\n");
    else
    {
        printf("\nYou can view the photo photo.jpg\n");
    }
    
    if (ferror(fp)) {
        
        fprintf(stderr, "fwrite() failed\n");
        
        return;
    }
    
    int r = fclose(fp);
    
    if (r == EOF) {
        fprintf(stderr, "Cannot close file handler\n");
    }
    
    rc = sqlite3_finalize(pStmt);
    
    
}

