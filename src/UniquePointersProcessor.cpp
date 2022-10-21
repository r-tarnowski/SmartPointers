#include <iostream>
#include <algorithm>
#include <UniquePointersProcessor.h>
#include <CommonVals.h>


using std::cout;
using std::endl;


UniquePointersProcessor::UniquePointersProcessor(unsigned int minIdVal, unsigned int maxIdVal)
        : minId( minIdVal ),
          maxId( maxIdVal ) {
    cout << "Constructor UniquePointersProcessor() called" << endl;
    //pSimpleProcessor = std::make_unique<SimpleProcessor>( SimpleProcessor( minIdVal ) );
    for ( unsigned int i = minId; i <= maxId; ++ i ) {
       processorIds.push_back( i );
    }
}

UniquePointersProcessor::~UniquePointersProcessor() {
    cout << "Destructor UniquePointersProcessor() called" << endl;
}

int UniquePointersProcessor::processId( unsigned int id ) {
    cout << "UniquePointersProcessor::processId( " << id
         << " ) called" << endl;

    auto pos = std::find( processorIds.begin(), processorIds.end(), id );
    if ( pos != processorIds.end() ) {
        //return SUCCESS_RETURN;
        return handleId( id );
    }
    else {
        cout << "UniquePointersProcessor::processId( " << id
             << " ) out of range: minId = " << minId
             << ", maxId = " << maxId << endl;
        return ERROR_RETURN;
    }
}

int UniquePointersProcessor::handleId( unsigned int id ) {
    cout << "UniquePointersProcessor::handleId( " << id
         << " ) called" << endl;

    auto pos = idProcessors.find( id );
    if ( ! ( pos != idProcessors.end() ) ) {
        cout << "UniquePointersProcessor::handleId( " << id
             << " ) processor not found" << endl;
        std::unique_ptr<SimpleProcessor> pSimpleProcessor = std::make_unique<SimpleProcessor>( id );
        try {
            cout << "UniquePointersProcessor::handleId( " << id
                 << " ) processor created" << endl;
            idProcessors.insert(std::pair< unsigned int,
                                           std::unique_ptr<SimpleProcessor> >( id, std::move( pSimpleProcessor) ) );
        }
        catch( std::exception & e ) {
            cout << "UniquePointersProcessor::handleId( " << id
                 << " ) error while creating SimpleProcessor object: "
                 << e.what() << endl;
            return ERROR_RETURN;
        }
    }

    return idProcessors.at( id )->processId( id );
}