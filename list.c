/**
 * Circular doubly-linked generic list implementation.
 */
#include "list.h"

void list_init(struct list_hdr *head)
{
    if (NULL == head)
    {
        return;
    }

    head->next = head;
    head->prev = head;
}

bool list_empty(struct list_hdr *head)
{
    if (NULL == head)
    {
        return true;
    }

    return head->next == head;
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

    head->next->prev = entry;
    head->next = entry;
}

void list_delete(const struct list_hdr *entry)
{
    if (NULL == entry)
    {
        return;
    }

    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
}

