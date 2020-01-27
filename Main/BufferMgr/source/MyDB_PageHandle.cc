
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

void MyDB_PageHandleBase :: wroteBytes () {
    mPage->setIsDirty(true);
}

MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
}

#endif

