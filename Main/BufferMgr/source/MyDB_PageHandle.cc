
#ifndef PAGE_HANDLE_C
#define PAGE_HANDLE_C

#include <memory>
#include "MyDB_PageHandle.h"

void *MyDB_PageHandleBase :: getBytes () {
}

//// @mPage needs to be written back
void MyDB_PageHandleBase :: wroteBytes () {
    mPage -> setIsDirty(true);
}

//// page's reference counter increases
MyDB_PageHandleBase::MyDB_PageHandleBase(MyDB_Page *page, MyDB_BufferManager *bufferManager) {
    mPage -> increRefCnt();
}
//// page's reference counter decreases
MyDB_PageHandleBase :: ~MyDB_PageHandleBase () {
    mPage -> decreRefCnt();
    // counter decreased to 0
    if (mPage->getRefCnt() == 0) {
        // need a buffer manager here
        mng.releaseMemory(mPage);
    }
}


#endif

