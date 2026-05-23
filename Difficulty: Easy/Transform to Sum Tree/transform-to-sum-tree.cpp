/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    int computeSubtreeSumAndUpdate(Node* currentNode) {
        if (!currentNode) {
            return 0;
        }

        int originalNodeValue = currentNode->data;

        int leftSubtreeSum = computeSubtreeSumAndUpdate(currentNode->left);
        int rightSubtreeSum = computeSubtreeSumAndUpdate(currentNode->right);

        currentNode->data = leftSubtreeSum + rightSubtreeSum;

        //returning the aggregate sum of the original subtree state to the parent caller.
        return originalNodeValue + leftSubtreeSum + rightSubtreeSum;
    }
  public:
    void toSumTree(Node *root) {
        // code here
        if (!root) {
            return;
        }
        
        computeSubtreeSumAndUpdate(root);
    }
};