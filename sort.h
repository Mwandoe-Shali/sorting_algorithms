#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Print Helpers Functions. */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Algorithms Functions. */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

/* Quick Sort Helper Functions*/
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);

/*---Hoare Partititioning Quick Sort.---*/
void hoare_quick_sort(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);

/* Cocktail Sort Helper Functions. */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void forward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped);
void backward_pass(listint_t **list, listint_t *start, listint_t *end, int *swapped);


#endif /* SORT_H */