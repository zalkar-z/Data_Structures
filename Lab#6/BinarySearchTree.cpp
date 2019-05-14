/*
 * Simple Binary Search Tree Implementation
 * Author: Andrew Cencini (acencini@bennington.edu)
 * Date: 4/30/2019
 */

#include <iostream>

using namespace std;

template <class Item>
class BinarySearchTree {
private:
    /*
     * Represents a node in our tree.  It's a binary search tree so we only have left and right subtrees.
    */
    struct TreeNode {
        Item data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(Item d, TreeNode* l, TreeNode* r) {
            data = d;
            left = l;
            right = r;
        }
    };

    TreeNode* root;     // the root of our binary search tree

public:
    BinarySearchTree() {
        // our constructor is pretty lamecore
        root = NULL;
    }

    /*
     * findOrInsert
     * Takes a value to find or insert into the BST
     * Returns: 0 if the value was not found and was instead inserted.
     *          1 if the value was found!
     */
    int findOrInsert(Item value) {
        TreeNode* pTn = new TreeNode(value, NULL, NULL);

        if (root == NULL) {
            root = pTn;     // there's nothing in the tree so set the root to this new node
            return 0;      // return that the value was not found and instead inserted
        }

        TreeNode* curr = root;
        while (value != curr->data) {
            if (value < curr->data) {   // try left
                if (curr->left == NULL) {
                    curr->left = pTn;   // there was nothing there so this is the place to insert our value!
                    return 0;       // return that the value was not found and instead inserted (left subtree, here)
                }
                curr = curr->left;
            }
            else {                      // try right
                if (curr->right == NULL) {
                    curr->right = pTn;  // there was nothing there so this is the place to insert our value!
                    return 0;       // return that the value was not found and instead inserted (right subtree, here)
                }
                curr = curr->right;
            }
        }
        // otherwise value = curr->data so the value was found so we return 1 indicating value is present!
        return 1;
    }


};


int main() {
    BinarySearchTree<char> *bst = new BinarySearchTree<char>();

    char inValue;

    cout << "Enter a character to find or insert into the tree, or '@' to stop and do an inOrder traversal: " << endl;
    cin >> inValue;

    while (inValue != '@') {
        if (bst->findOrInsert(inValue)) {
            cout << "Value found in the BST already!" << endl;
        } else {
            cout << "Value added to the BST - thank you!" << endl;
        }

        cin >> inValue;
    }

    // uncomment this once you have an inOrder traversal in place.  behold the magic.
    //bst->inOrder();

    return 0;
}