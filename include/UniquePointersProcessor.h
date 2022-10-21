#ifndef UNIQUE_POINTERS_PROCESSOR_H
#define UNIQUE_POINTERS_PROCESSOR_H

#include <SimpleProcessor.h>
#include <memory>
#include <vector>
#include <map>

class UniquePointersProcessor {

public:

    UniquePointersProcessor() = delete;
    UniquePointersProcessor( unsigned int minIdVal, unsigned int maxIdVal );
    ~UniquePointersProcessor();

   int processId( unsigned int id );

private:

   std::vector< unsigned int > processorIds;
   std::map< unsigned int, std::unique_ptr<SimpleProcessor> > idProcessors;
   //std::unique_ptr<SimpleProcessor> pSimpleProcessor;
   unsigned int minId;
   unsigned int maxId;

   int handleId( unsigned int id );
};

#endif
