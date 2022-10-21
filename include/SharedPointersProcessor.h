#ifndef SHARED_POINTERS_PROCESSOR_H
#define SHARED_POINTERS_PROCESSOR_H

#include <SimpleProcessor.h>
#include <vector>
#include <map>
#include <memory>

class SharedPointersProcessor {

public:
    SharedPointersProcessor() = delete;
    SharedPointersProcessor( unsigned int minIdVal, unsigned int maxIdVal );
    ~SharedPointersProcessor();

    int processId( unsigned int id );

private:

    std::vector< unsigned int > processorIds;
    std::map< unsigned int, std::shared_ptr<SimpleProcessor> > idProcessors;
    unsigned int minId;
    unsigned int maxId;

    int handleId( unsigned int id );

};

#endif
