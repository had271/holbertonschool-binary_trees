#include "binary_trees.h"

/**
 *binary_tree_height - function measures the height of binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: value to return
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (0);
	else if (tree->parent != NULL)
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		return (1 + (l_height > r_height ? l_height : r_height));
	}
	return (binary_tree_height(tree->left));
	return (binary_tree_height(tree->right));
}
