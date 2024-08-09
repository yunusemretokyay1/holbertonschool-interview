#include "binary_trees.h"


/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value to put in the new node
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * is_balanced - checks if a binary tree is balanced
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is balanced, 0 otherwise
 */
int is_balanced(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_balanced(tree->left) && is_balanced(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (!is_balanced(tree))
		return (0);

	return (1);
}