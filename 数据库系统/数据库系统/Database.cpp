#include "stdafx.h"

//
//  Database.cpp
//  theTable
//
//  Created by 王怡飞 on 15/5/13.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//

#include "Database.h"
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <iostream>

typedef list<string> StringList;

void Database::addDatabase(const char *dbname){
    
    FILE *fp;
    if ((fp=fopen(dbname,"a"))==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp,"%s","\0");
    fclose(fp);
    
    //加入配置文件中
    FILE *fp2;
    if ((fp2=fopen("freeplay.pz","a"))==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp2,"%s\n",dbname);
    fclose(fp2);
    


}

list<string> Database::getDatabases(){
    
    list<string> mylist;
    
    FILE *fp;

    if((fp = fopen("freeplay.pz","r")) == NULL)
    {
        printf("error!");
    }
	else
	{

		char StrLine[1024];
		while (fgets(StrLine,1024,fp))
			{
				string str(StrLine);
				if (str!="\n")
				{
				mylist.push_back(str);
				}

			}
			fclose(fp);
	}
    
    return mylist;
}

void Database::deleteDatabase(const char* dbname){
    
    //从注册表里删除这个database
    StringList mylist;
    mylist=getDatabases();
    //
    
    
    //从文件里删除配置文件
    if( remove(dbname) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
    
    //创建一个空的配置文件
    
    //从文件里删除这个database
    if( remove("freeplay.pz") != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
    
    string str(dbname);
    str=str+"\n";
    
    for (StringList::const_iterator ci = mylist.begin(); ci != mylist.end(); ++ci){
        
        if (*ci==str) {
            cout<<str;
        }
        else{
            
            //加入配置文件中
            char newdbname[100];
            
            string haha = *ci;
            strncpy(newdbname, haha.c_str(), sizeof(newdbname));
            newdbname[sizeof(newdbname) - 1] = 0;

            FILE *fp2;
            if ((fp2=fopen("freeplay.pz","a"))==NULL)
            {
                printf("Open Failed.\n");
                return;
            }
            else{
                fprintf(fp2,"%s\n",newdbname);
            }
                

            fclose(fp2);
        }
        
    }
    
}

list<string> Database::getTables(const char *dbname){
    
    list<string> mylist;
    
    FILE *fp;
    char StrLine[1024];
    if((fp = fopen(dbname,"r")) == NULL)
    {
        printf("error!");
    }
    
	else{

		while (fgets(StrLine,1024,fp))
		{
			string str(StrLine);
			if (str!="\n")
			{
			mylist.push_back(str);
			}
		}
		fclose(fp);
	}
    
    
    
    return mylist;
    
}



