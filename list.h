#include <stddef.h>
#include <stdlib.h>

struct list_hdr {
    struct list_hdr *next;
    struct list_hdr *prev;
};

// Portable (?) implementation of container_of
#define container_of(ptr, type, member) \
    ((type *) ((char *)(ptr) - offsetof(type, member)))

#define list_entry(head, type, member) \
    container_of(head, type, member)

#define list_for_each(head, pos) \
    for (pos = (head)->next; (pos) != (head); (pos) = (pos)->next)

/**
 * @TODO
 */
void list_init(struct list_hdr *hdr);

/**
 * @TODO
 */
void list_insert_tail(struct list_hdr *head, struct list_hdr *entry);

/**
 * @TODO
 */
void list_insert(struct list_hdr *head, struct list_hdr *entry);

