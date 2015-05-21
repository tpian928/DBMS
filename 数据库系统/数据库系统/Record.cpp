//
//  Record.cpp
//  theTable
//
//  Created by 王怡飞 on 15/5/18.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//
#include "stdafx.h"
#include "Record.h"
#include "Table.h"
#include <iostream>
#include "Func.h"


Record::Record(const char *tableName){
	    this->tableName=tableName;
}

void Record::writeRecord(StringList recordList){
    
    Table myTable;
    
    for (StringList::const_iterator ci = recordList.begin(); ci != recordList.end(); ++ci){
        
        //加入配置文件中
        char line[1024];
        string haha = *ci;
        strncpy(line, haha.c_str(), sizeof(line));
        line[sizeof(line) - 1] = 0;
        myTable.writeLine(tableName, line);
        
    }
    
}

list<ColumnList> Record::getRecord(){
    
    ColumnList theColumnList;
    list<ColumnList> resultList;
    
    StringList everyLine = getLines();
    
    for (StringList::const_iterator ci = everyLine.begin(); ci != everyLine.end(); ++ci){
        StringList temp = getStringsSpiteByBlank(*ci);
        for (StringList::const_iterator zz = temp.begin(); zz != temp.end(); ++zz){
            theColumnList.push_back(*zz);
        }
        resultList.push_back(theColumnList);
    }
    
    return resultList;
}

StringList Record::getLines(){
    
    StringList returnLsit;
    
    FILE *fp;
    char StrLine[1024];             //每行最大读取的字符数
    if((fp = fopen(tableName,"r")) == NULL) //判断文件是否存在及可读
    {
        printf("error!");
    }
    
    while (!feof(fp))
    {
        fgets(StrLine,1024,fp);  //读取一行
        string str(StrLine);
        if (str!="\n") {
            returnLsit.push_back(str);
        }
        
    }
    fclose(fp);//关闭文件
    
    return returnLsit;
}

list<ColumnList> Record::search(int columnOrder, string searchContext){
    
    list<ColumnList> resultList;
    
    StringList everyLine = getLines();
    
    for (StringList::const_iterator ci = everyLine.begin(); ci != everyLine.end(); ++ci){
        StringList temp = getStringsSpiteByBlank(*ci);// temp包含每一行的list
        int i = 0;
        for (StringList::const_iterator zz = temp.begin(); zz != temp.end(); ++zz){
            if (i==columnOrder&&searchContext==*zz) {
                resultList.push_back(temp);
            }
            i++;
        }
    }
    
    cout<<"resultList size is "<<resultList.size()<<endl;
    return resultList;
}

void Record::deleteRecord(string deleteContext){
    
    StringList everyLine = getLines();
    
    //删除原纪录文件
    if( remove(tableName) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
    
    list<ColumnList> storeList;
    
    for (StringList::const_iterator ci = everyLine.begin(); ci != everyLine.end(); ++ci){
        
        if (*ci==deleteContext+"\n") {
            cout<<"enqual\n";
        }
        else{
            char contextText[1024];
            strcpy(contextText, ci->c_str());
            writeLine(tableName, contextText);
        }
    }
    
}

void Record::updateRecord(string sourceContext,string rContext){
    
    StringList everyLine = getLines();
    
    //删除原纪录文件
    if( remove(tableName) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );
    
    list<ColumnList> storeList;
    
    for (StringList::const_iterator ci = everyLine.begin(); ci != everyLine.end(); ++ci){
        
        if (*ci==sourceContext+"\n") {
            cout<<"enqual\n";
            char contextText[1024];
            strcpy(contextText, rContext.c_str());
            writeLine(tableName, contextText);
        }
        else{
            char contextText[1024];
            strcpy(contextText, ci->c_str());
            writeLine(tableName, contextText);
        }
    }
    
}



