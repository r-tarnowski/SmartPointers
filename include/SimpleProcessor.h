#ifndef SIMPLE_PROCESSOR_H
#define SIMPLE_PROCESSOR_H

class SimpleProcessor {

public:

    SimpleProcessor() = delete;

    SimpleProcessor( unsigned int initId );
    virtual ~SimpleProcessor();

    virtual int processId( unsigned int idVal );

protected:
    unsigned int id;

};

#endif