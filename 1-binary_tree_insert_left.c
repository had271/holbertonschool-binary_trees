#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: what to store in the new node
 * Return: pointer to created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		temp = parent->left;
		parent->left = SetNewNode(value);
		if (parent->left == NULL)
			return (NULL);
		parent->left->parent = parent;
		parent->left->left = temp;
		temp->parent = parent->left;
	} else
	{
		parent->left = SetNewNode(value);
		if (parent->left == NULL)
			return (NULL);
		parent->left->parent = parent;
	}
	return (parent->left);
}
