#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdbool.h> // bool
#include <stdint.h>  // uint32_t
#include "../../../commonIncludes/serverMessages.h"

typedef enum testResponses
{
    TEST_OK = 0,
    TEST_ERROR_SENDING_REQUEST,
    TEST_ERROR_RECIVE_RESPONSE,
    TEST_ERROR_NOT_EXPECTED_VALUE,
    TEST_ERROR_NOT_EXPECTED_STATUS,
    TEST_ERROR_SEGMENTATION
} testResponses_t;

typedef struct wholeTestResponse
{
    uint8_t passTest;
    uint8_t numberOfTests;
} wholeTestResponse_t;

testResponses_t TestSingleRequestWithUint32Response( 
    uint8_t instance, 
    attributesToGet_t attribute, 
    int responseQueueId, 
    int serverQueueId,
    bool validateResponseValue, 
    uint32_t expectedResponse,
    shortConfirmationValues_t expectedStatus,
    uint32_t requestId );
testResponses_t TestSingleRequestShortConfirmationResponse( 
    uint8_t instance, 
    attributesToGet_t attribute, 
    int responseQueueId, 
    int serverQueueId,
    shortConfirmationValues_t expectedStatus,
    uint32_t requestId );
testResponses_t TestResetRequestWithShortConfirmationResponse( 
    uint8_t instance, 
    attributesToGet_t attribute, 
    int responseQueueId, 
    int serverQueueId,
    shortConfirmationValues_t expectedStatus,
    uint32_t requestId );



void PrintTestResults( wholeTestResponse_t result, const char * testPath );
void PrintTestResponse( testResponses_t response );
void ParseTestResponse( testResponses_t singleTestResponse, wholeTestResponse_t * pWholeTestResponse );

int TestUtilGetServerQueue( void );
int TestUtilGetAndPrepareTestQueue( const char * testPath );
#endif //TEST_UTILS_H