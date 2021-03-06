#include "list.h"

#include <stdlib.h>
#include <stdio.h>

struct my_list {
    struct list_hdr hdr;
    int data;
};

void list_delete_all(struct list_hdr *head)
{
    struct list_hdr *pos, *tmp;

    list_for_each_safe(head, pos, tmp)
    {
        list_delete(pos);
    }
}

void list_print(struct my_list *list)
{
    struct list_hdr *pos;
    struct my_list *curr;

    list_for_each(&list->hdr, pos)
    {
        curr = list_entry(pos, struct my_list, hdr);
        printf("%d\n", curr->data);
    }
}

int main()
{
    struct my_list list;
    size_t i;

    list_init(&list.hdr);

    printf("list empty: %u\n", list_empty(&list.hdr));

    struct my_list new_entries[10];
    for (i = 0; i < 10; ++i)
    {
        new_entries[i].data = i;
        list_insert(&list.hdr, &new_entries[i].hdr);
    }

    list_print(&list);
    printf("list empty: %u\n", list_empty(&list.hdr));

    list_delete_all(&list.hdr);

    list_print(&list);
    printf("list empty: %u\n", list_empty(&list.hdr));

    return EXIT_SUCCESS;
}

