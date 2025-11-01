#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node
 * @tree: Pointer to the node
 *
 * Return: Depth or 0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree && tree->parent)
    {
        tree = tree->parent;
        depth++;
    }
    return (depth);
}

/**
 * is_perfect_recursive - Recursively checks if tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of all leaves
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (is_perfect_recursive(tree->left, depth, level + 1) &&
        is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (tree == NULL)
        return (0);

    depth = binary_tree_depth(tree);
    return (is_perfect_recursive(tree, depth, 0));
}

