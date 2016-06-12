#include "list.h"

#include <stdlib.h>

void list_init(struct list_hdr *head)
{
    head->next = head;
    head->prev = head;
}

void list_insert_tail(struct list_hdr *head, struct list_hdr *entry)
{
    if (NULL == head || NULL == entry)
    {
        return;
    }

    if (head->next == head) {
        // List is empty
    }
    entry->next = head;
    entry->prev = head->prev;

    head->prev->next = entry;
    head->prev = entry;
}
