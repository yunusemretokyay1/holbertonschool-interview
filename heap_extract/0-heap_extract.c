#include "binary_trees.h"

/**
 * swap - swaps the values of two nodes
 * @a: first node
 * @b: second node
 */
void swap(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify - heapifies a binary tree
 * @root: root of the binary tree
 */
void heapify(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left && left->n > largest->n)
        largest = left;
    if (right && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap(root, largest);
        heapify(largest);
    }
}

/**
 * get_last_node - gets the last node of a binary tree
 * @root: root of the binary tree
 *
 * Return: pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    if (!root)
        return (NULL);

    heap_t **queue = malloc(1024 * sizeof(heap_t *));
    int front = 0, rear = 0;

    queue[rear++] = root;

    heap_t *current;
    while (front < rear)
    {
        current = queue[front++];

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }

    free(queue);
    return (current);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: the value stored in the root node, or 0 if failed
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    heap_t *last_node = get_last_node(*root);
    int value = (*root)->n;

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    swap(*root, last_node);

    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
    heapify(*root);

    return (value);
}
