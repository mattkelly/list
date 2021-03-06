/**
 * Circular doubly-linked generic list definitions.
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct list_hdr {
    struct list_hdr *next;
    struct list_hdr *prev;
};

/**
 * Portable (?) implementation of container_of.
 *
 * @param ptr Pointer to struct member
 * @param type Type of struct the member belongs to
 * @param member Name of the struct member
 */
#define container_of(ptr, type, member) \
    ((type *) ((char *)(ptr) - offsetof(type, member)))

/**
 * Get the pointer to the struct containing this list header.
 *
 * @param ptr Pointer to the list_hdr
 * @param type Type of struct the list_hdr belongs to
 * @param member Name of the list_hdr member
 */
#define list_entry(hdr, type, member) \
    container_of(hdr, type, member)

/**
 * Iterate over a list.
 *
 * @param head Pointer to the head of the list
 * @param pos Pointer to current element in list (entry type, not list_hdr type)
 */
#define list_for_each(head, pos) \
    for (pos = (head)->next; (pos) != (head); (pos) = (pos)->next)

/**
 * Iterate over a list with safety against deleting current item.
 *
 * @param head Pointer to the head of the list
 * @param pos Pointer to current element in list (entry type, not list_hdr type)
 * @param n Another position pointer for temporary storage
 */
#define list_for_each_safe(head, pos, n) \
    for (pos = (head)->next, n = (pos)->next; \
        (pos) != (head); \
        (pos) = n, n = (pos)->next)

/**
 * Iterate over a list backwards.
 *
 * @param head Pointer to the head of the list
 * @param pos Pointer to current element in list (entry type, not list_hdr type)
 */
#define list_for_each_prev(head, pos) \
    for (pos = (head)->prev; (pos) != (head); (pos) = (pos)->prev)

/**
 * Iterate over a list backwards with safety against deleting current item.
 *
 * @param head Pointer to the head of the list
 * @param pos Pointer to current element in list (entry type, not list_hdr type)
 * @param p Another position pointer for temporary storage
 */
#define list_for_each_prev_safe(head, pos, p) \
    for (pos = (head)->prev, p = (pos)->prev; \
        (pos) != (head); \
        (pos) = p, p = (pos)->prev)

/**
 * Initialize a new list.
 *
 * @param head Head of the new list
 */
void list_init(struct list_hdr *head);

/**
 * Check if a list is empty.
 *
 * @param head Head of the list
 * @return true if empty, else false
 */
bool list_empty(struct list_hdr *head);

/**
 * Insert a new entry just past the list tail (just before the head).
 * @param head Head of the list
 * @param entry New entry to insert
 */
void list_insert_tail(struct list_hdr *head, struct list_hdr *entry);

/**
 * Insert a new entry just after the list head.
 *
 * @param head Head of the list
 * @param entry New entry to insert
 */
void list_insert(struct list_hdr *head, struct list_hdr *entry);

/**
 * Delete an entry from a list.
 *
 * @param entry The entry to delete
 */
void list_delete(const struct list_hdr *entry);

