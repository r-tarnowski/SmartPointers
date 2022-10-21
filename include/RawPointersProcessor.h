#ifndef RAW_POINTERS_PROCESSOR_H
#define RAW_POINTERS_PROCESSOR_H

#include <SimpleProcessor.h>
#include <vector>
#include <map>

class RawPointersProcessor {

public:

    RawPointersProcessor() = delete;
    RawPointersProcessor( unsigned int minIdVal, unsigned int maxIdVal );
    ~RawPointersProcessor();

    int processId( unsigned int id );

private:

    std::vector< unsigned int > processorIds;
    std::map< unsigned int, SimpleProcessor * > idProcessors;

    unsigned int minId;
    unsigned int maxId;

    int handleId( unsigned int id );

};

#endif
