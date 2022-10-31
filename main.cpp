// taking from tests

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <assert.h>

extern "C"
{
#include "linked_list.h"
#include "insertion_sort.h"
#include "list_queue.h"
}

// Add the header files required to run your main
void testLinkedListInsertionSort(int randomArray[], int sortedArray[], int linkedListArray[], int arraySize)
{
    linked_list *llPtr = convertArrayToLinkedList(randomArray, arraySize);
    convertLinkedListToArray(llPtr, linkedListArray);
    assert(compareArrays(randomArray, linkedListArray, arraySize) == true); // checks array and linked list are equal
    sort(llPtr);
    convertLinkedListToArray(llPtr, linkedListArray);
    REQUIRE(compareArrays(sortedArray, linkedListArray, arraySize) == true); // check sorted array and sorted linked list are equal
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    TEST_CASE("linked_queue")
    {
        // Test inserting random values into queue and check size
        int valuesToInsert[4] = {-5, 10, 0, 5};
        queue qq;
        init_queue(&qq);
        int queueSize = 0;
        REQUIRE(empty(&qq) == 1);
        for (int i = 0; i < 4; ++i)
        {
            enqueue(&qq, valuesToInsert[i]);
            REQUIRE(qq.size == ++queueSize);
        }

        // Test empty function with empty queue
        queue q;
        init_queue(&q);
        REQUIRE(empty(&q) == 1);

        // Test empty function with non-empty queue
        queue q1;
        init_queue(&q1);
        enqueue(&q1, 5);
        REQUIRE(empty(&q1) == 0);
        dequeue(&q1);
        REQUIRE(empty(&q1) == 1);

        // Test enqueue then dequeue
        enqueue(&q1, -5);
        enqueue(&q1, 10);
        enqueue(&q1, 0);
        enqueue(&q1, 5);

        REQUIRE(-5 == dequeue(&q1));
        REQUIRE(10 == dequeue(&q1));
        REQUIRE(0 == dequeue(&q1));
        REQUIRE(5 == dequeue(&q1));
    }
}
