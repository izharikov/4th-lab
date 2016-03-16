//
//  insert.c
//  4th lab
//
//  Created by Admin on 16.03.16.
//  Copyright © 2016 Admin. All rights reserved.
//

#include "db_options.h"
    
    void insertInTable(sqlite3 * db, char* sql, char* zErrMsg)
    {
        char firstname[15], lastname[15], middlename[15], birthday[15], town[30], address[30], department[10], job[15], dateOfDeployment[15], photoName[50], country[20];
        printf ("\n-----INSERT-----\n");
        printf("Enter first name: ");
        scanf("%s", firstname);
        printf("Enter middle name: ");
        scanf("%s", middlename);
        printf("Enter last name: ");
        scanf("%s", lastname);
        printf("Enter date of birthday: ");
        scanf("%s", dateOfDeployment);
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
        printf(str);
        printf("\n");
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
        /*
        FILE *fp = fopen(photoName, "rb");
        
        if (fp == NULL) {
            
            fprintf(stderr, "Cannot open image file\n");
            return;
        }
        
        fseek(fp, 0, SEEK_END);
        
        int flen = ftell(fp);
        
        fseek(fp, 0, SEEK_SET);
        
        char data[flen+1];
        int size = fread(data, 1, flen, fp);
        fclose(fp);
        
        
        sqlite3_stmt *pStmt;
        
        char str1[150]= "UPDATE worker SET photo = ? WHERE firstName = '%s' AND lastName = '%s'";
        sprintf(str1,str1,firstname, lastname);
        printf(str1);
        
        rc = sqlite3_prepare(db, str1, -1, &pStmt, 0);
        
        if (rc != SQLITE_OK) {
            
            fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
            
            return;
        }
        
        sqlite3_bind_blob(pStmt, 1, data, size, SQLITE_STATIC);
        
        rc = sqlite3_step(pStmt);
        
        if (rc != SQLITE_DONE) {
            
            printf("execution failed: %s", sqlite3_errmsg(db));
        }
        
        sqlite3_finalize(pStmt);
        */
        
        // IMG.end
        
}