#ifndef A1_MYDB_PAGE_C
#define A1_MYDB_PAGE_C

#include "MyDB_Page.h"
#include <MyDB_BufferManager.h>

MyDB_Page::MyDB_Page(void* addr, MyDB_TablePtr whichTable, long offset){
    this->PageAddr = addr;
    this->whichTable = whichTable;
    this->offset = offset;
    this->isAnonymous = false;
    this->isDirty = false;
    this->isPinned = false;
    this->isInBuffer = false;
    this->refCnt = 0;
}

bool MyDB_Page::getIsDirty(){
    return this->isDirty;
}

void MyDB_Page::setIsDirty(bool isDirty){
    this->isDirty = isDirty;
}

bool MyDB_Page::getIsPinned(){
    return isPinned;
}
void MyDB_Page::setIsPinned(bool isPinned){
    this->isPinned = isPinned;
}
bool MyDB_Page::getIsAnonymous(){
    return isAnonymous;
}
void MyDB_Page::setIsAnonymous(bool isAnonymous){
    this->isAnonymous = isAnonymous;
}
bool MyDB_Page::getIsInBuffer(){
    return this->isInBuffer;
}
void* MyDB_Page::getPageAddr(){
    return this->PageAddr;
}
void MyDB_Page::setIsInBuffer(bool isInBuffer){
    this->isInBuffer = isInBuffer;
}

void MyDB_Page::increRefCnt() {
    this -> refCnt++;
    // output here for debugging
}

void MyDB_Page::decreRefCnt() {
    this -> refCnt--;
    // output here for debugging
}

int MyDB_Page::getRefCnt() {
    return refCnt;
}

void MyDB_Page::setPageAddr(void* PageAddr){
    this->PageAddr = PageAddr;
}
MyDB_TablePtr MyDB_Page::getWhichTable(){
    return this->whichTable;
}
long MyDB_Page::getOffset(){
    return this->offset;
}

MyDB_Page::~MyDB_Page() {

}




#endif //A1_MYDB_PAGE_C