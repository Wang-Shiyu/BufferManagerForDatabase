
#ifndef BUFFER_MGR_C
#define BUFFER_MGR_C

#include "MyDB_BufferManager.h"
#include <MyDB_Page.h>
#include <MyDB_PageHandle.h>
#include <stdlib.h>
#include <string>

using namespace std;

MyDB_PageHandle MyDB_BufferManager :: getPage (MyDB_TablePtr whichTable, long pageNum) {
    //check whether the page has already been in buffer.
    auto it = this->loadedPages.find(make_pair(whichTable->getName(),pageNum));

    //not found, load it from disk
    if(it == this->loadedPages.end()){
        MyDB_Page* availablePage = getAvailablePage();



    }else{//found, create a corresponding handle
        MyDB_PageHandle new_handle = make_shared<MyDB_PageHandleBase>(it->second,this);

        return new_handle;
    }
}

MyDB_PageHandle MyDB_BufferManager :: getPage () {
	return nullptr;
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage (MyDB_TablePtr, long) {
	return nullptr;		
}

MyDB_PageHandle MyDB_BufferManager :: getPinnedPage () {
	return nullptr;		
}

void MyDB_BufferManager :: unpin (MyDB_PageHandle unpinMe) {
}

MyDB_BufferManager :: MyDB_BufferManager (size_t pageSize, size_t numPages, string tempFile) {

    //Initialize some attributes.
    this->pageSize = pageSize;
    this->numPages = numPages;
    this->tempFile = tempFile;

    //Initialize linked list.
    this->head = NULL;
    this->rear = NULL;

    //allocate memory at once.
    for(int i = 0; i < this->numPages; i++){
        void* new_addr = malloc(this->pageSize);
        if(new_addr==NULL){
            printf("Allocating failed...");
            exit(1);
        }
        this->availBufferPool.push(new_addr);
    }
}

MyDB_BufferManager :: ~MyDB_BufferManager () {
}
	
#endif


