//
//  Database.h
//  theTable
//
//  Created by ������ on 15/5/13.
//  Copyright (c) 2015�� FreePlay. All rights reserved.
//

#ifndef __theTable__Database__
#define __theTable__Database__

#include <stdio.h>
#include <string>
#include <string.h>
#include <list>

using namespace std;

//ע�⣡ʹ�ô���ʱ��Ҫ���#include <string> #include <string.h> �Լ�#include <list.h>
//���� using namespace std;

class Database
{
public:
    
    //����database�����ļ������������������Щdatabase
    //dbname�����ݿ��ļ���·������.td��β����student.db
    void addDatabase(const char* dbname);
    
    //�������ļ��л�ȡ����Щdatabase
    //����ֵ�����ݿ��ļ�·����database
    list<string> getDatabases();
    
    //ɾ�����ݿ�
    void deleteDatabase(const char* dbname);
    
    //�õ����ݿ��еı�
    list<string> getTables(const char* dbname);
    
private:
    
    ////�����ļ�freeplay.pz
    //char peizhiPath[100]="/Users/TPIAN/Desktop/freeplay.pz";
    
};

#endif /* defined(__theTable__Database__) */
