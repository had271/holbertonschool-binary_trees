#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of the leftmost leaf
 * @tree: Pointer to the node
 *
 * Return: Depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree)
    {
        depth++;
        tree = tree->left;
    }

    return (depth);
}

/**
 * binary_tree_is_perfect_helper - Recursively checks if tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of all leaves
 * @level: Current level in the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect_helper(const binary_tree_t *tree,
    size_t depth, size_t level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect_helper(tree->left, depth, level + 1) &&
        binary_tree_is_perfect_helper(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (tree == NULL)
        return (0);

    depth = binary_tree_depth(tree);
    return (binary_tree_is_perfect_helper(tree, depth, 0));
}
