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
        this->root = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct Tree {
    Node *root;
    std::vector<Node *> nodes; // store all nodes in an array of vector
    std::unordered_map<int, std::vector<Node *> > map; // store array of nodes by Node value, use for fast access later

    Tree() {
        this->root = nullptr;
    }

    /**
     * Update parent sum and num of children
     * @param node
     * @param newNode
     */
    void updateRoot(Node *node, Node *newNode) {
        if (node->root == nullptr) {
            return;
        }

        node->root->numOfChildren++;
        node->root->sum += newNode->value;

        this->updateRoot(node->root, newNode);

    }

    /**
     * Find nodes by values
     * @param value
     * @return
     */

    std::vector<Node *> findByValue(int value) {
        std::vector<Node *> v;
        std::unordered_map<int, std::vector<Node *> >::iterator it = this->map.find(value);
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
    void addNode(Node *root, Node *node, char ch) {
        // append new node to array of nodes
        this->nodes.push_back(node);

        // if the tree is empty add this as root node.
        if (this->root == nullptr) {
            this->root = node;

            return;
        }
        // add to the left value
        if (ch == 'L') {
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

        if (!this->nodes.empty()) {
            std::sort(this->nodes.begin(), this->nodes.end(), sortTreeCallback);
        }

    }


};

/**
 *
 * @param largeTree
 * @param smallTree
 * @return
 */
Node *_findLargeSubTree(Tree *largeTree, Tree *smallTree) {

    for (int i = 0; i < smallTree->nodes.size(); ++i) {
        Node *currentNode = smallTree->nodes[i];
        std::vector<Node *> largeTreeNodes = largeTree->findByValue(currentNode->value);

        if (largeTreeNodes.empty()) {
            // not found same node value in large tree. so we skip it.
            continue;
        }

        for (int j = 0; j < largeTreeNodes.size(); ++j) {
            
        }


    }
}

/**
 *
 * @param t1
 * @param t2
 * @return
 */
Node *findLargeSubTree(Tree *t1, Tree *t2) {

    if (t1->nodes.empty() || t2->nodes.empty()) {
        return nullptr;
    }
    if (t1->nodes.size() > t2->nodes.size()) {
        return _findLargeSubTree(t1, t2);
    }

    return _findLargeSubTree(t2, t1);
}

void example1() {

/*

        1                    1
       /  \                /   \
      2    3              2     3
     /    / \            / \   / \
    4     4  5          3   4  5  4

*/

    Tree *t1 = new Tree();
    t1->addNode(nullptr, new Node(1), 'L');
    t1->addNode(t1->root, new Node(2), 'L');
    t1->addNode(t1->root->left, new Node(4), 'L');

    t1->addNode(t1->root, new Node(3), 'R');
    t1->addNode(t1->root->right, new Node(4), 'L');
    t1->addNode(t1->root->right, new Node(5), 'R');
    t1->sort();


    Tree *t2 = new Tree();

    t2->addNode(nullptr, new Node(1), 'L');
    t2->addNode(t2->root, new Node(2), 'L');
    t2->addNode(t2->root->left, new Node(3), 'L');
    t2->addNode(t2->root->left, new Node(4), 'R');

    t2->addNode(t2->root, new Node(3), 'R');
    t2->addNode(t2->root->right, new Node(5), 'L');
    t2->addNode(t2->root->right, new Node(4), 'R');

    t2->sort();

    Node *n = findLargeSubTree(t1, t2);
}

int main() {

    example1();


    return 0;
}