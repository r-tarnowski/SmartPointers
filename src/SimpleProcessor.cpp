#include <iostream>
#include <SimpleProcessor.h>
#include <CommonVals.h>

using std::cout;
using std::endl;


SimpleProcessor::SimpleProcessor( unsigned int initId )
            : id( initId ) {
    cout << "Constructor SimpleProcessor( " << initId <<  " ) called" << endl;
}

SimpleProcessor::~SimpleProcessor() {
    cout << "Destructor SimpleProcessor() called, id = " << id << endl;
}


int SimpleProcessor::processId( unsigned int idVal ) {
    cout << "SimpleProcessor::processId( " << idVal << " ) called, id = " << id << endl;
    return SUCCESS_RETURN;
}
