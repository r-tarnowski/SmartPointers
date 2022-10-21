#include <iostream>
#include <ProcessorTypeB.h>
#include <CommonVals.h>

using std::cout;
using std::endl;


ProcessorTypeB::ProcessorTypeB( unsigned int initId )
        : SimpleProcessor( initId ) {
    cout << "Constructor ProcessorTypeB( " << initId <<  " ) called" << endl;
}

ProcessorTypeB::~ProcessorTypeB() {
    cout << "Destructor ProcessorTypeB() called, id = " << id << endl;
}


int ProcessorTypeB::processId( unsigned int idVal ) {
    cout << "ProcessorTypeB::processId( " << idVal << " ) called, id = " << id << endl;
    return SUCCESS_RETURN;
}


