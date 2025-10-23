#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node
 * @value: value to store in the new node
 * Return: pointer to the new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *NewNode = malloc(sizeof(binary_tree_t));

	if (NewNode == NULL)
		return (NULL);
	NewNode->parent = parent;
	NewNode->n = value;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return (NewNode);
}

