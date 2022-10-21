#include <iostream>
#include <algorithm>
#include <RawPointersProcessor.h>
#include <CommonVals.h>

using std::cout;
using std::endl;

RawPointersProcessor::RawPointersProcessor(unsigned int minIdVal, unsigned int maxIdVal)
                     : minId( minIdVal ),
                       maxId( maxIdVal ) {
    cout << "Constructor RawPointersProcessor() called" << endl;
    for ( unsigned int i = minId; i <= maxId; ++ i ) {
        processorIds.push_back( i );
    }
}

RawPointersProcessor::~RawPointersProcessor() {
    cout << "Destructor RawPointersProcessor() called" << endl;
    if ( ! idProcessors.empty() ) {
        for (auto & idProcessor : idProcessors) {
            delete idProcessor.second;
        }
    }
}

int RawPointersProcessor::processId( unsigned int id ) {
    cout << "RawPointersProcessor::processId( " << id
         << " ) called" << endl;

    auto pos = std::find( processorIds.begin(), processorIds.end(), id );
    if ( pos != processorIds.end() ) {
        return handleId( id );
    }
    else {
        cout << "RawPointersProcessor::processId( " << id
             << " ) out of range: minId = " << minId
             << ", maxId = " << maxId << endl;
        return ERROR_RETURN;
    }
}

int RawPointersProcessor::handleId( unsigned int id ) {
    cout << "RawPointersProcessor::handleId( " << id
         << " ) called" << endl;

    auto pos = idProcessors.find( id );
    if ( ! ( pos != idProcessors.end() ) ) {
        cout << "RawPointersProcessor::handleId( " << id
             << " ) processor not found" << endl;
        try {
            auto pSimpleProcessor = new SimpleProcessor( id );
            cout << "RawPointersProcessor::handleId( " << id
                 << " ) processor created" << endl;
            idProcessors.insert( std::pair< unsigned int, SimpleProcessor * > ( id, pSimpleProcessor ) );
        }
        catch ( std::exception & e ){
            cout << "RawPointersProcessor::handleId( " << id
                 << " ) error while creating SimpleProcessor object: "
                 << e.what() << endl;
            return ERROR_RETURN;
        }
    }

    return idProcessors.at( id )->processId( id );
}