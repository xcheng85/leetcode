class Solution
{
  public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        Node *leftHead = treeToDoublyList(root->left);
        Node *rightHead = treeToDoublyList(root->right);

        root->left = root;
        root->right = root;

        return connect(connect(leftHead, root), rightHead);
    }

    Node *connect(Node *n1, Node *n2)
    {
        if (n1 == nullptr)
        {
            return n2;
        }
        if (n2 == nullptr)
        {
            return n1;
        }

        Node *tail1 = n1->left;
        Node *tail2 = n2->left;

        tail1->right = n2;
        n2->left = tail1;

        tail2->right = n1;
        n1->left = tail2;

        return n1;
    }
};