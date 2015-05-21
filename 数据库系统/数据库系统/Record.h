//
//  Record.h
//  theTable
//
//  Created by ������ on 15/5/18.
//  Copyright (c) 2015�� FreePlay. All rights reserved.
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
    
    //���캯��
    Record(const char *tableName);

    
    //д��¼����Ҫ�ȹ���
    void writeRecord(StringList recordList);
    
    //����¼,list���滹��һ��list�������Ǹ�list�������ÿ��column��column��һ����string��ɵ�list column[0],column[1]�Ⱦ���13301020 �����ɵ��ַ���
    list<ColumnList> getRecord();

    //�������������Ƿ�������������list���list����ô�����ַ���Ҳ���Կ��������
    list<ColumnList> search(int columnOrder,string searchContext);
    
    //ɾ��һ����¼,�統����Ϊ�����ɣ�columnOrder��1����Ӧ�ֶ�name��
    //deleteContext ����column��˳��һ���ַ������м��ÿո�ֿ�
    void deleteRecord(string deleteContext);
    
    //���¼�¼ ����ifOrder��ifContext ��
    void updateRecord(string sourceContext,string rContext);
    
    
    //���߷���
    StringList getLines();
    
};

#endif /* defined(__theTable__Record__) */
