#include "binary_trees.h"

/**
 *binary_tree_nodes - counts the nodes with at least one child in a binary tree
 *@tree: pointer to the root node of the tree to count number of nodes
 *Return: number of nodes with children
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (
		binary_tree_nodes(tree->left) +
		((tree->left == NULL && tree->right != NULL) ||
		 (tree->left != NULL && tree->right == NULL) ||
		 (tree->left != NULL && tree->right != NULL) ? 1 : 0) +
		binary_tree_nodes(tree->right)
		);
}
