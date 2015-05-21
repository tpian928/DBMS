//
//  Record.h
//  theTable
//
//  Created by 王怡飞 on 15/5/18.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//

#ifndef __theTable__Record__
#define __theTable__Record__

#include <stdio.h>
#include <string>
#include "string.h"
#include <list>

using namespace std;

typedef list<string> StringList;
typedef list<string> ColumnList;

class Record{
    
private:
    
    const char *tableName;
    
public:
    
    //构造函数
    Record(const char *tableName);

    
    //写记录，需要先构造
    void writeRecord(StringList recordList);
    
    //读记录,list里面还有一个list，外面那个list储存的是每个column，column是一个有string组成的list column[0],column[1]等就是13301020 王怡飞等字符串
    list<ColumnList> getRecord();

    //搜索结果，结果是符合搜索条件到list里的list，怎么遍历字符串也可以看这个函数
    list<ColumnList> search(int columnOrder,string searchContext);
    
    //删除一条记录,如当姓名为王怡飞（columnOrder＝1，对应字段name）
    //deleteContext 按照column的顺序一个字符串，中间用空格分开
    void deleteRecord(string deleteContext);
    
    //更新记录 条件ifOrder＝ifContext 将
    void updateRecord(string sourceContext,string rContext);
    
    
    //工具方法
    StringList getLines();
    
};

#endif /* defined(__theTable__Record__) */
