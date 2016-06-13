/**
 * Circular doubly-linked generic list implementation.
 */
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

    struct list_hdr * const tail = head->prev;

    entry->next = head;
    entry->prev = tail->prev;

    tail->next = entry;
    head->prev = entry;
}

void list_insert(struct list_hdr *head, struct list_hdr *entry)
{
    if (NULL == head || NULL == entry)
    {
        return;
    }

    entry->next = head->next;
    entry->prev = head;

    head->next = entry;
}

