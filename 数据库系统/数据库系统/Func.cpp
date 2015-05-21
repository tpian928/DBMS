//
//  Func.cpp
//  theTable
//
//  Created by Íõâù·É on 15/5/18.
//  Copyright (c) 2015Äê FreePlay. All rights reserved.
//
#include "stdafx.h"
#include "Func.h"
#include <vector>
#include <sstream>
#include <algorithm>



StringList getStringsSpiteByBlank(string sourceString){
    
    StringList returnList;
    istringstream iss(sourceString);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(returnList));
    
    return returnList;
}

void writeLine(const char *fileName, const char *content){
    
    FILE *fp;
    if ((fp=fopen(fileName,"a"))==NULL)
    {
        printf("Open Failed.\n");
        return;
    }
    fprintf(fp,"%s\n",content);
    fclose(fp);
}
