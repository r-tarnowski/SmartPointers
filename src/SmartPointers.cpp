#include <iostream>
#include <memory>
#include <RawPointersProcessor.h>
#include <UniquePointersProcessor.h>
#include <SharedPointersProcessor.h>
#include <ProcessorTypeA.h>
#include <ProcessorTypeB.h>

using std::cout;
using std::endl;


void printHeader() {
   cout << endl;
   cout << "===============================================" << endl;
   cout << "My own experiments with smart pointers" << endl;
   cout << "===============================================" << endl;
   cout << endl;
}
template < typename T >
std::shared_ptr<T> createSharedPtr( int idVal ) {
    cout << "===============================================" << endl;
    cout << "createSharedPtr( int idVal ) - start" << endl;

    cout << "std::shared_ptr<T> createSharedPtr( " << idVal << " ) called." << endl;
    std::shared_ptr< T > pProcessor = std::make_shared<T>(idVal);
    cout << "std::shared_ptr<T> createSharedPtr( " << idVal << " ) pProcessor.use_count = "
         << pProcessor.use_count() << endl;

    cout << "createSharedPtr( int idVal ) - end" << endl;
    cout << "===============================================" << endl;
    return pProcessor;
}

void sharedPtrsTests() {

    cout << endl << "===============================================" << endl;
    cout << "sharedPtrsTests() - start" << endl << endl;

    cout << "sharedPtrsTests: calling createSharedPtr< SimpleProcessor >( 1 )" << endl;
    std::shared_ptr< SimpleProcessor > pSimpleProcessor = createSharedPtr< SimpleProcessor >( 1 );
    cout << "sharedPtrsTests: pSimpleProcessor.use_count =  " << pSimpleProcessor.use_count() << endl;

    cout << "sharedPtrsTests: copying shated_ptr" << endl;
    std::shared_ptr< SimpleProcessor > pSimpleProcessorBis = pSimpleProcessor;
    cout << "sharedPtrsTests: pSimpleProcessor.use_count =  " << pSimpleProcessor.use_count() << endl;
    cout << "sharedPtrsTests: pSimpleProcessorBis.use_count =  " << pSimpleProcessorBis.use_count() << endl;

    cout << "sharedPtrsTests: calling pSimpleProcessor->processId( 10 )" << endl;
    pSimpleProcessor->processId( 10 );

    cout << "sharedPtrsTests: calling pSimpleProcessorBis->processId( 20 )" << endl;
    pSimpleProcessorBis->processId( 20 );

    if ( pSimpleProcessor == nullptr ) {
        cout << "sharedPtrsTests: pSimpleProcessor equal to nullptr" << endl;
    }
    else {
        cout << "sharedPtrsTests: pSimpleProcessor NOT equal to nullptr" << endl;
    }

    cout << "sharedPtrsTests: calling pSimpleProcessor.reset()" << endl;
    pSimpleProcessor.reset();

    if ( pSimpleProcessor == nullptr ) {
        cout << "sharedPtrsTests: pSimpleProcessor equal to nullptr" << endl;
    }
    else {
        cout << "sharedPtrsTests: pSimpleProcessor NOT equal to nullptr" << endl;
    }

    cout << "sharedPtrsTests: pSimpleProcessor.use_count =  " << pSimpleProcessor.use_count() << endl;
    cout << "sharedPtrsTests: pSimpleProcessorBis.use_count =  " << pSimpleProcessorBis.use_count() << endl;

    cout << "sharedPtrsTests: calling pSimpleProcessorBis.reset()" << endl;
    pSimpleProcessorBis.reset();

    cout << "sharedPtrsTests: pSimpleProcessor.use_count =  " << pSimpleProcessor.use_count() << endl;
    cout << "sharedPtrsTests: pSimpleProcessorBis.use_count =  " << pSimpleProcessorBis.use_count() << endl;

    cout << endl << "sharedPtrsTests() - end" << endl;
    cout << "===============================================" << endl;

}

void memoryViolationExample() {
    cout << endl << "===============================================" << endl;
    cout << "memoryViolationExample() - start" << endl << endl;

   cout << "memoryViolationExample: creating raw pointer to SimpleProcessor: " << endl;
   SimpleProcessor * pSimpleProcessor = new SimpleProcessor( 2 );

   cout << "memoryViolationExample: creating shared pointers, both based on the same raw pointer: " << endl;
   std::shared_ptr< SimpleProcessor > shrPtr1( pSimpleProcessor );
   std::shared_ptr< SimpleProcessor > shrPtr2( pSimpleProcessor );
   cout << "memoryViolationExample: shrPtr1.use_count =  " << shrPtr1.use_count() << endl;
   cout << "memoryViolationExample: shrPtr2.use_count =  " << shrPtr2.use_count() << endl;

   cout << "memoryViolationExample: calling shrPtr1->processId( 10 ):" << endl;
   shrPtr1->processId( 10 );
   cout << "memoryViolationExample: calling shrPtr2->processId( 20 ):" << endl;
   shrPtr2->processId( 20 );

   cout << "memoryViolationExample: resetting shrPtr1" << endl;
   shrPtr1.reset();
   cout << "memoryViolationExample: shrPtr1.use_count =  " << shrPtr1.use_count() << endl;
   cout << "memoryViolationExample: shrPtr2.use_count =  " << shrPtr2.use_count() << endl;

   cout << "memoryViolationExample: EXPECT MEMORY VIOLATION!" << endl;
   cout << "memoryViolationExample: calling shrPtr2->processId( 20 ):" << endl;
   shrPtr2->processId( 20 );

   cout << endl << "memoryViolationExample() - end" << endl;
   cout << "===============================================" << endl;
}

int main( int argc, char *argv[] ) {
   printHeader();

   memoryViolationExample();

   //sharedPtrsTests();

/*
   RawPointersProcessor rawPointersProcessor( 1, 3 );
   UniquePointersProcessor uniquePointersProcessor( 11, 13 );
   SharedPointersProcessor sharedPointersProcessor( 21, 23 );
   cout << endl;

   rawPointersProcessor.processId( 2 );
   cout << endl;
   rawPointersProcessor.processId( 1 );
   cout << endl;
   rawPointersProcessor.processId( 2 );

   cout << endl << "===============================================" << endl;
   sharedPointersProcessor.processId( 22 );
   cout << endl;
   sharedPointersProcessor.processId( 23 );
   cout << endl;
   sharedPointersProcessor.processId( 22 );

   cout << endl << "===============================================" << endl;
   uniquePointersProcessor.processId( 12 );
   cout << endl;
   uniquePointersProcessor.processId( 13 );
   cout << endl;
   uniquePointersProcessor.processId( 12 );
*/
/*
   //cout << endl << "===============================================" << endl;
   std::shared_ptr< ProcessorTypeA > pProcessorTypeA = std::make_shared< ProcessorTypeA >( 123 );
   pProcessorTypeA->processId( 123 );
   //cout << endl << "===============================================" << endl;
   std::shared_ptr< SimpleProcessor > pSimpleProcessor = pProcessorTypeA;
   pSimpleProcessor->processId( 123 );

   cout << endl << "===============================================" << endl;
   std::shared_ptr< ProcessorTypeB > pProcessorTypeB = std::make_shared< ProcessorTypeB >( 456 );
   pProcessorTypeB->processId( 456 );

   pSimpleProcessor = pProcessorTypeB;
   pSimpleProcessor->processId( 456 );
*/
   cout << endl << "===============================================" << endl;
   cout << endl;
   return 0;
}
