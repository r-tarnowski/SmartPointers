#include <iostream>
#include <algorithm>
#include <SharedPointersProcessor.h>
#include <CommonVals.h>

using std::cout;
using std::endl;


SharedPointersProcessor::SharedPointersProcessor(unsigned int minIdVal, unsigned int maxIdVal)
        : minId( minIdVal ),
          maxId( maxIdVal ) {
    cout << "Constructor SharedPointersProcessor() called" << endl;
    for ( unsigned int i = minId; i <= maxId; ++ i ) {
        processorIds.push_back( i );
    }
}

SharedPointersProcessor::~SharedPointersProcessor() {
    cout << "Destructor SharedPointersProcessor() called" << endl;
}

int SharedPointersProcessor::processId( unsigned int id ) {
    cout << "SharedPointersProcessor::processId( " << id
         << " ) called" << endl;

    auto pos = std::find( processorIds.begin(), processorIds.end(), id );
    if ( pos != processorIds.end() ) {
        return handleId( id );
    }
    else {
        cout << "SharedPointersProcessor::processId( " << id
             << " ) out of range: minId = " << minId
             << ", maxId = " << maxId << endl;
        return ERROR_RETURN;
    }
}

int SharedPointersProcessor::handleId( unsigned int id ) {
    cout << "SharedPointersProcessor::handleId( " << id
         << " ) called" << endl;

    auto pos = idProcessors.find( id );
    if ( ! ( pos != idProcessors.end() ) ) {
        cout << "SharedPointersProcessor::handleId( " << id
             << " ) processor not found" << endl;
        std::shared_ptr<SimpleProcessor> pSimpleProcessor = std::make_shared<SimpleProcessor>( id );
        try {
           cout << "SharedPointersProcessor::handleId( " << id
                << " ) processor created" << endl;
           idProcessors.insert(std::pair< unsigned int,
                                          std::shared_ptr<SimpleProcessor> >( id, pSimpleProcessor ) );
        }
        catch( std::exception & e ) {
            cout << "SharedPointersProcessor::handleId( " << id
                 << " ) error while creating SimpleProcessor object: "
                 << e.what() << endl;
            return ERROR_RETURN;
        }
    }

    return idProcessors.at( id )->processId( id );
}