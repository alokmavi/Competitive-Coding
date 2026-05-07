/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isIdentical(Node* node1, Node* node2) {
        // If both nodes are null, they are identical
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }
        // If one is null and the other isn't, they are not identical
        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }
        // Check if current nodes match and recursively check left and right subtrees
        return (node1->data == node2->data) &&
               isIdentical(node1->left, node2->left) &&
               isIdentical(node1->right, node2->right);
    }

    bool isSubTree(Node* root1, Node* root2) {
        // If S is empty, it is considered a subtree of any tree
        if (root2 == nullptr) {
            return true;
        }
        // If T is empty but S is not, S cannot be a subtree
        if (root1 == nullptr) {
            return false;
        }

        // Check if the current node in T matches S
        if (isIdentical(root1, root2)) {
            return true;
        }

        // Recursively check left and right subtrees of T
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
    }
};