#include "insertion_sort.h"
#include "linked_list.h"
#include <assert.h>

void sort(linked_list *llPtr)
{
    // Add your sort function here
    // pre-condition
    // first called pointer to find our
    node_t *current = llPtr->head; // starting node

    // post-condition
    /*
     * first we have the howl loop that initioalize the loop
     * sellect and stores the elemts
     * next loop stores the last elemt that has been sorted
     * next again loops through all already sortet elements
     * then and if statement for if the samllest and thus firt numbeer is smaller than the number current being sortet and will be the first elemnt.
     * else if does the same but the curent node wont be the first eleemnt.
     * last part updates which nu,ber was last.
     */

    while (current->next != NULL)
    {
        current = current->next;                 // points to next
        node_t *newest = llPtr->head;            // newest elemt
        node_t *latest = malloc(sizeof(node_t)); // lattest elemnt
        node_t *unsorted = llPtr->head;
        while (unsorted->next != NULL && unsorted->data <= unsorted->next->data)
        {
            unsorted = unsorted->next;
        }
        while (newest != current)
        {
            if (current->data < newest->data && newest == llPtr->head)
            {
                unsorted->next = current->next;
                llPtr->head = current;
                current->next = newest;
                break;
            }
            else if (current->data < newest->data)
            {
                unsorted->next = current->next;
                latest->next = current;
                current->next = newest;
                break;
            }
            latest = newest;
            newest = newest->next;
        }
    }
}