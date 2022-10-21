#ifndef PROCESSOR_TYPE_B_H
#define PROCESSOR_TYPE_B_H

#include <SimpleProcessor.h>

class ProcessorTypeB : public SimpleProcessor {
public:

    ProcessorTypeB() = delete;

    ProcessorTypeB( unsigned int initId );
    virtual ~ProcessorTypeB();

    virtual int processId( unsigned int idVal );
};

#endif
