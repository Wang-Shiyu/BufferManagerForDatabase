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
    MyDB_Page(void* addr);
    bool getIsDirty();
    void setIsDirty(bool isDirty);
    bool getIsPinned();
    void setIsPinned(bool isPinned);
    bool getIsAnonymous();
    void setIsAnonymous(bool isAnonymous);

    //get page address. If page not in memory, load it to memory.
    void *getBytes ();
    char* readDisk(int descriptor, int offset, int size);
    void writeDisk(int descriptor, int offset, int size);

    ~MyDB_Page();
private:
    MyDB_Page* next;
    MyDB_Page* prev;
    void* PageAddr;
    MyDB_TablePtr whichTable;
    long offset;
    bool isDirty; //whether the page is dirty
    bool isPinned;//whether the page is pinned at the moment
    bool isAnonymous;//whether the page is anonymous


};
#endif //A1_MYDB_PAGE_H
