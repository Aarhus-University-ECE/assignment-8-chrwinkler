
// Add the header files required to run your main
#include "list_queue.h"

#include <assert.h>
#include <stdio.h>

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    // Test case A
    queue q;
    init_queue(&q);
    assert(empty(&q) == 1);

    // Test case B
    int x = 7;
    enqueue(&q, x);
    int y = dequeue(&q);
    assert(empty(&q));

    // Test case C
    int x0 = 4;
    int x1 = 8;
    enqueue(&q, x0);
    enqueue(&q, x1);
    int y0 = dequeue(&q);
    int y1 = dequeue(&q);
    assert(empty(&q) == 1 && x0 == y0 && x1 == y1);

    printf("\033[0;32n");
    printf("All tests passed\n");
    printf("\033[0;32n");

    return 0;
}