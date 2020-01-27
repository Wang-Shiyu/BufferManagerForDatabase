//
// Created by 欧欣祺 on 2020-01-25.
//

#ifndef A1_MYDB_PAGE_H
#define A1_MYDB_PAGE_H

#include "MyDB_BufferManager.h"
#include "MyDB_Table.h"


using namespace std;


class MyDB_Page{

public:
    MyDB_Page* next;
    MyDB_Page* prev;
    MyDB_Page(void* addr, MyDB_TablePtr whichTable, long offset);
    bool getIsDirty();
    void setIsDirty(bool isDirty);
    bool getIsPinned();
    void setIsPinned(bool isPinned);
    bool getIsAnonymous();
    void* getPageAddr();
    MyDB_TablePtr getWhichTable();
    long getOffset();
    void setIsAnonymous(bool isAnonymous);
    bool getIsInBuffer();
    void setIsInBuffer(bool isInBuffer);
    void increRefCnt();
    void decreRefCnt();
    int getRefCnt();
    void setPageAddr(void*PageAddr);

    //get page address. If page not in memory, load it to memory.

    ~MyDB_Page();
private:
    void* PageAddr;
    MyDB_TablePtr whichTable;
    MyDB_BufferManager mng;
    long offset;
    int refCnt;
    bool isInBuffer;
    bool isDirty; //whether the page is dirty
    bool isPinned;//whether the page is pinned at the moment
    bool isAnonymous;//whether the page is anonymous


};
#endif //A1_MYDB_PAGE_H
