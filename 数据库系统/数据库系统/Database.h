//
//  Database.h
//  theTable
//
//  Created by 王怡飞 on 15/5/13.
//  Copyright (c) 2015年 FreePlay. All rights reserved.
//

#ifndef __theTable__Database__
#define __theTable__Database__

#include <stdio.h>
#include <string>
#include <string.h>
#include <list>

using namespace std;

//注意！使用此类时需要添加#include <string> #include <string.h> 以及#include <list.h>
//另外 using namespace std;

class Database
{
public:
    
    //创建database配置文件，里面包含具体有哪些database
    //dbname是数据库文件的路径，以.td结尾，如student.db
    void addDatabase(const char* dbname);
    
    //从配置文件中获取有哪些database
    //返回值是数据库文件路径的database
    list<string> getDatabases();
    
    //删除数据库
    void deleteDatabase(const char* dbname);
    
    //得到数据库中的表
    list<string> getTables(const char* dbname);
    
private:
    
    ////配置文件freeplay.pz
    //char peizhiPath[100]="/Users/TPIAN/Desktop/freeplay.pz";
    
};

#endif /* defined(__theTable__Database__) */
