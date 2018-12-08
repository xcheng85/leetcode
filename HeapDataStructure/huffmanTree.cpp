// Build a Huffman Tree from input characters with their frequency.

/* 1. Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue. 
The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root) */
//2. Extract two nodes with the minimum frequency from the min heap.
//3. Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
//Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
//Repeat steps#2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete.
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    char c; // character
    int val; // frequency
    struct Node *left;
    struct Node *right;
};

typedef struct Node *p_Node;
class cmp
{
  public:
    bool operator()(p_Node const &p1, p_Node const &p2)
    {
        return p1->val > p2->val;
    }
};

p_Node createNode(int val, p_Node left, p_Node right)
{
    p_Node node = (p_Node)malloc(sizeof(struct Node));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

// input charactor
p_Node buildTree(int *vec, int n)
{
    priority_queue<p_Node, vector<p_Node>, cmp> forest;
    for (int i = 0; i < n; i++)
    {
        p_Node node = createNode(vec[i], NULL, NULL);
        forest.push(node);
    }
    while (forest.size() > 1)
    {
        p_Node node1 = forest.top();
        forest.pop();
        p_Node node2 = forest.top();
        forest.pop();
        cout << node1->val << "  " << node2->val << endl;
        p_Node new_node = createNode(node1->val + node2->val, node1, node2);
        forest.push(new_node);
    }
    return forest.top();
}