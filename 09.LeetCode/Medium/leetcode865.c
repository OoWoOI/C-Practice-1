/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct Node{
    struct TreeNode *node;
    int depth;
} Node;

Node def(struct TreeNode *root) {
    if (root == NULL) return (Node){NULL, 0};
    Node left = def(root->left);
    Node right = def(root->right);

    if (left.depth > right.depth) {
        return (Node){left.node, left.depth + 1};
    }

    if (left.depth < right.depth) {
        return (Node) {right.node, right.depth + 1};
    }
    return (Node) {root, left.depth + 1};
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root){
    return def(root).node;
}
