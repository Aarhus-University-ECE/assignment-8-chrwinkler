#include "insertion_sort.h"
#include "linked_list.h"
#include <assert.h>

void sort(linked_list *llPtr)
{
    // Add your sort function here

    // pre-condition
    assert(0 <= llPtr->head);

    /* post-condition: x[0..n] is sorted */
    for (int i = 1; i < llPtr->head; i = i + 1)
    {
        int j = i;
        /* insert  next element j into
         * ordered position
         */
        for (; j > 0; j = j + 1)
        {
            if (llPtr->head > llPtr->head->next)
                break; /* jth element is in correct position */
            else
            {
                swap(llPtr->head, llPtr->head->next);
            }
        }
    }
}