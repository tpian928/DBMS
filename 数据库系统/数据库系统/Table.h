//
//  Table.h
//  theTable
//
//  Created by 王怡飞 on 15/5/11.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//

/* 
数据类型
interger 1
bool 2
double 3
varchar 4
datetime 5
*/

/*
字段顺序
0 升序
1 降序
*/


#ifndef __theTable__Table__
#define __theTable__Table__

#include <stdio.h>
#include <list>

class Table
{
public:
    
    struct Column {
        int order;
        char name[20];
        int type;
        int param;
        char mtime[50];
        int integrities;
    };
    
    int cNum;
    
    //添加空表（不包含任何字段的表）
    //tableName为表文件路径，如student.tdf(student为表名)
    void addBlankTable(const char *tableName);
    
    //添加字段，执行该函数一次就在table末尾添加一个字段
    //tableName为表文件路径，如student.tdf(student为表名)
    //Column一行一行的添加
    //!!!!!!!!!Column的order不可重复!!!!!!!!!
    void addColumn(const char *tableName,Column c);
    
    //一行记录写一行，中间用空格分开，如 13301020 王怡飞 99
    void addRecord(const char *tableName,const char *recordLine);
    
    //得到该表的Columns数组
    //tableName为表文件路径，如student.tdf(student为表名)
    std::list<Column> getColumns(const char *tableName);
    
    //得到记录
    //tableName为表文件路径，如student.tdf(student为表名)
    void getRecord(const char *tableName);
    
    //删除表
    //tableName为表文件路径，如student.tdf(student为表名)
    void deleteTable(const char *tableName);
    
    //修改表字段
    //tableName为表文件路径，如student.tdf(student为表名)
    //Column为字段的结构体
    void modifyColumn(const char *tableName,Column c);
    
    void deleteColumn(const char *tableName,Column c);
    
    //以下是我写工具函数，你不需要调用
    //逐行写取文件
    void writeLine(const char *fileName,const char *content);
    //逐行读取文件
    const char* getLine(const char *fileName);
};

#endif /* defined(__theTable__Table__) */
