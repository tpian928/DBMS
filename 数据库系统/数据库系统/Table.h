//
//  Table.h
//  theTable
//
//  Created by ������ on 15/5/11.
//  Copyright (c) 2015�� FreePlay. All rights reserved.
//

/* 
��������
interger 1
bool 2
double 3
varchar 4
datetime 5
*/

/*
�ֶ�˳��
0 ����
1 ����
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
    
    //��ӿձ��������κ��ֶεı�
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    void addBlankTable(const char *tableName);
    
    //����ֶΣ�ִ�иú���һ�ξ���tableĩβ���һ���ֶ�
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    //Columnһ��һ�е����
    //!!!!!!!!!Column��order�����ظ�!!!!!!!!!
    void addColumn(const char *tableName,Column c);
    
    //һ�м�¼дһ�У��м��ÿո�ֿ����� 13301020 ������ 99
    void addRecord(const char *tableName,const char *recordLine);
    
    //�õ��ñ��Columns����
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    std::list<Column> getColumns(const char *tableName);
    
    //�õ���¼
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    void getRecord(const char *tableName);
    
    //ɾ����
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    void deleteTable(const char *tableName);
    
    //�޸ı��ֶ�
    //tableNameΪ���ļ�·������student.tdf(studentΪ����)
    //ColumnΪ�ֶεĽṹ��
    void modifyColumn(const char *tableName,Column c);
    
    void deleteColumn(const char *tableName,Column c);
    
    //��������д���ߺ������㲻��Ҫ����
    //����дȡ�ļ�
    void writeLine(const char *fileName,const char *content);
    //���ж�ȡ�ļ�
    const char* getLine(const char *fileName);
};

#endif /* defined(__theTable__Table__) */
