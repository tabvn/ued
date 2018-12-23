#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

struct Node {

    int value;
    int numOfChildren;
    int sum; // sum of node with it's children value

    Node *root, *left, *right;

    Node(int value) {
        this->value = value;
        this->sum = 0;
        this->numOfChildren = 0;
        this->root = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

struct Tree {

    Node *root;
    std::vector<Node *> nodes; // store all nodes in an array of vector
    std::unordered_map<int, std::vector<Node *> > map; // store array of nodes by Node value, use for fast access later

    Tree() {
        this->root = NULL;
    }

    /**
     * Update parent sum and num of children
     * @param node
     * @param newNode
     */
    void updateRoot(Node *node, Node *newNode) {

        if (node->root == NULL) {
            return;
        }

        node->root->numOfChildren++;
        node->root->sum += newNode->value;

        this->updateRoot(node->root, newNode);

    }

    /**
     * Find all node with value
     *
     * @param node
     * @return std::vector<node*>
     */

    std::vector<Node *> find(Node *node) {

        std::vector<Node *> v;

        std::unordered_map<int, std::vector<Node *> >::iterator it = this->map.find(node->value);
        if (it != this->map.end()) {
            return it->second;
        }

        return v;
    }

    /**
     * Add new node to map
     * @param node
     */
    void addNodeToMap(Node *node) {

        std::unordered_map<int, std::vector<Node *> >::iterator it = this->map.find(node->value);
        if (it != this->map.end()) {
            it->second.push_back(node);
        } else {
            std::vector<Node *> v;
            v.push_back(node);
            this->map[node->value] = v;
        }

    }

    /**
     * Add new node to tree
     * @param root
     * @param node
     * @param addToLeft
     */
    void addNode(Node *root, Node *node, bool addToLeft) {

        // append new node to array of nodes
        this->nodes.push_back(node);

        // we also add to map to access later by value


        // if the tree is empty add this as root node.
        if (this->root == NULL) {
            this->root = node;

            return;
        }

        // add to the left value
        if (addToLeft) {
            root->left = node;
        } else {
            root->right = node;
        }

        node->root = root;

        // let update parent NumOfChildren and value

        root->numOfChildren++;
        root->sum += node->value;

        // update parent of this node with new sum and numOfChildren
        this->updateRoot(root, node);
    }

    /**
     * Add new node to left of node in the tree
     * @param root
     * @param node
     */
    void addLeftNode(Node *root, Node *node) {
        this->addNode(root, node, true);
    }

    /**
     * Add new node to right of node in the tree
     * @param root
     * @param node
     */
    void addRightNode(Node *root, Node *node) {
        this->addNode(root, node, false);
    }

    /**
     * Sort node order by numOfChildren Descending
     * @param node
     * @param otherNode
     * @return
     */
    static bool sortTreeCallback(Node *node, Node *otherNode) {
        return node->numOfChildren > otherNode->numOfChildren;
    }

    /**
     * Sort tree
     */

    void sort() {
        std::sort(this->nodes.begin(), this->nodes.end(), sortTreeCallback);
    }


};

int main() {

    return 0;
}