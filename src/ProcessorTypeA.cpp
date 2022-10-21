
#include <iostream>
#include <ProcessorTypeA.h>
#include <CommonVals.h>

using std::cout;
using std::endl;


ProcessorTypeA::ProcessorTypeA( unsigned int initId )
        : SimpleProcessor( initId ) {
    cout << "Constructor ProcessorTypeA( " << initId <<  " ) called" << endl;
}

ProcessorTypeA::~ProcessorTypeA() {
    cout << "Destructor ProcessorTypeA() called, id = " << id << endl;
}


int ProcessorTypeA::processId( unsigned int idVal ) {
    cout << "ProcessorTypeA::processId( " << idVal << " ) called, id = " << id << endl;
    return SUCCESS_RETURN;
}

