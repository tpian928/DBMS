//
//  Func.h
//  theTable
//
//  Created by ������ on 15/5/18.
//  Copyright (c) 2015�� FreePlay. All rights reserved.
//

#ifndef __theTable__Func__
#define __theTable__Func__


#include <stdio.h>
#include <string>
#include <list>
#include <vector>

using namespace std;

typedef list<string> StringList;
typedef vector<string> StringVector;

StringList getStringsSpiteByBlank(string sourceString);

//����дȡ�ļ�
void writeLine(const char *fileName,const char *content);

#endif /* defined(__theTable__Func__) */
