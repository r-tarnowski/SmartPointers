#ifndef PROCESSOR_TYPE_A_H
#define PROCESSOR_TYPE_A_H

#include <SimpleProcessor.h>

class ProcessorTypeA : public SimpleProcessor {
public:

    ProcessorTypeA() = delete;

    ProcessorTypeA( unsigned int initId );
    virtual ~ProcessorTypeA();

    virtual int processId( unsigned int idVal );
};

#endif
