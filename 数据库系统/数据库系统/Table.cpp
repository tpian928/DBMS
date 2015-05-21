#include "stdafx.h"
//
//  Table.cpp
//  theTable
//
//  Created by 王怡飞 on 15/5/11.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//

#include "Table.h"
#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

void Table::addColumn(const char *tableName,Column c){
    
    char order[3];
    char type[3];
    char param[4];
    char integrities[3];
    sprintf(order,"%d",c.order);
    sprintf(type,"%d",c.type);
    sprintf(param,"%d",c.param);
    sprintf(integrities,"%d",c.integrities);
    
    writeLine(tableName,order);
    writeLine(tableName,c.name);
    writeLine(tableName,type);
    writeLine(tableName,param);
    writeLine(tableName,c.mtime);
    writeLine(tableName,integrities);
}

void Table::addRecord(const char *tableName, const char *recordLine){
    
    string name = string(tableName);
    name=name+".tdf";
    char nameChar[50];
    strcpy(nameChar, name.c_str());
    
    writeLine(nameChar, recordLine);
}

void Table::writeLine(const char *fileName, const char *content){
    
    FILE *fp;
    if ((fp=fopen(fileName,"a"))==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp,"%s\n",content);
    fclose(fp);
}

const char* Table::getLine(const char *fileName){
    
    
    FILE *fp;
    char StrLine[1024];             //每行最大读取的字符数
    if((fp = fopen(fileName,"r")) == NULL) //判断文件是否存在及可读
    {
        printf("error!");
    }
    
    while (!feof(fp))
    {
        fgets(StrLine,1024,fp);  //读取一行
        printf("%s", StrLine); //输出
    }
    fclose(fp);                     //关闭文件
    
    char *result = StrLine;
    
    return result;
    
    
}

std::list<Table::Column> Table::getColumns(const char *tableName){
    
    std::list<Column> mylist;
    Column tempColumn;
    
    FILE *fp;
    char StrLine[1024];
    if((fp = fopen(tableName,"r")) == NULL)
    {
        printf("error!");
    }
	else
	{
		int count = 0;
		int tmpeColumnNum = 0;
		while (fgets(StrLine,1024,fp))
		{
			fgets(StrLine,1024,fp);
			switch (count) {
				case 0:
					tempColumn.order=atoi(StrLine);
					break;
				case 1:

					strncpy(tempColumn.name, StrLine, strlen(StrLine)-1);
                
					break;
                
				case 2:
					tempColumn.type=atoi(StrLine);
					break;
                
				case 3:
					tempColumn.param=atoi(StrLine);
					break;
                
				case 4:
					strncpy(tempColumn.mtime, StrLine, strlen(StrLine)-1);
					break;
                
				case 5:
					tempColumn.integrities=atoi(StrLine);
					mylist.push_back(tempColumn);
					tmpeColumnNum++;
					count=-1;
					break;
				default:
					break;
			}
			count++;
    }
    
    fclose(fp);
    cNum=tmpeColumnNum;
	}
   
    return mylist;

}

void Table::deleteTable(const char *tableName){
    
    if( remove(tableName) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
    
}

void Table::modifyColumn(const char *tableName, Column c){
    
    list<Table::Column> mylist = getColumns(tableName);

    deleteTable(tableName);
    
    std::vector<int>::size_type size = mylist.size();
    
    for (int i =0; i<size; i++) {
        
        if (mylist.back().order==c.order) {

            Column tempColumn;
            tempColumn.order=c.order;
            strncpy(tempColumn.name, c.name, 20);
            tempColumn.type=c.type;
            tempColumn.param=c.param;
            strncpy(tempColumn.mtime, c.mtime, 20);
            tempColumn.integrities=c.integrities;
            addColumn(tableName, tempColumn);
        }
        else{
            addColumn(tableName, mylist.back());
        }
        
        mylist.pop_back();

    }
    

    
}

void Table::addBlankTable(const char *tableName){
    
    FILE *fp;
    if ((fp=fopen(tableName,"a"))==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp,"%s","\0");
    fclose(fp);
    
}





