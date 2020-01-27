
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include "MyDB_PageHandle.h"
#include "MyDB_BufferManager.h"

void *MyDB_PageHandleBase :: getBytes () {
    if(this->mPage->getIsInBuffer()){//Already in LRU
        this->bufferManager->updateLRU(this->mPage);
    }else{
        this->bufferManager->readFromDisk(this->mPage);
        this->bufferManager->updateLRU(this->mPage);
    }
    return this->mPage->getPageAddr();
}

//// @mPage needs to be written back
void MyDB_PageHandleBase :: wroteBytes () {
    mPage -> setIsDirty(true);
}

//// page's reference counter increases
MyDB_PageHandleBase::MyDB_PageHandleBase(MyDB_PagePtr page, MyDB_BufferManager* bufferManager) {
    this->bufferManager = bufferManager;
    this->mPage = page;
    mPage -> increRefCnt();
}

//// page's reference counter decreases
MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
    mPage -> decreRefCnt();
    // counter decreased to 0
    if (mPage->getRefCnt() == 0) {
        // need a buffer manager here
        bufferManager->releaseMemory(mPage);
    }
}


#endif

