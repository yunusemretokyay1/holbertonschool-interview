#include "binary_trees.h"
heap_t **heap_end(heap_t **root, int value)
{
    if(root == NULL)
    return (NULL);
    
    heap_t **left = heap_end((*root)->left);
    heap_t **right = heap_end((*root)->right);
   
   if (*left == NULL)
		return (*left);
	if (*right == NULL)
		return (*right);
    
    
  }

  heap_t **heap_insert_place(heap_t **root, int value) {
	if (root == NULL)
		return (NULL);

	heap_t **left = heap_end((*root));
}

heap_t *heap_insert(heap_t **root, int value)
{
	if (root == NULL)
		return (NULL);

	/* make node */

	heap_t *new = malloc(sizeof(heap_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	/* find place to insert node */

	heap_t **insert_place = root;

	while (*insert_place != NULL
		&& insert_place->n > value)
	{

		insert_place = (*insert_place)->
	}

	heap_t *insert_place_parent = (*insert_place)->parent;
	heap_t *insert_place_left = (*insert_place)->left;
	heap_t *insert_place_right = (*insert_place)->right;

	new->parent = insert_place_parent;
	new->left = insert_place_left;
	new->right = insert_place_right;

	(*insert_place)
}