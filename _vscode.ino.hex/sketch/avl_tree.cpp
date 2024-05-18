#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\avl_tree.cpp"
#include <bits/stdc++.h>

using namespace std;

// AVL Tree node
class Node
{
public:
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int height(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int balanceFactor(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to rotate right at a node
Node *rotateRight(Node *node)
{
    Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Function to rotate left at a node
Node *rotateLeft(Node *node)
{
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Function to insert a node into the AVL tree
Node *insert(Node *node, int key)
{
    if (node == nullptr)
    {
        return new Node(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = balanceFactor(node);
    if (bf > 1 && key < node->left->key)
    {
        return rotateRight(node);
    }
    if (bf < -1 && key > node->right->key)
    {
        return rotateLeft(node);
    }
    if (bf > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Function to print the inorder traversal of the AVL tree
void inorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->key << " ";
    inorderTraversal(node->right);
}

// Function to print the preorder traversal of the AVL tree
void preorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->key << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function to print the postorder traversal of the AVL tree
void postorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->key << " ";
}

// Function to print the level order traversal of the AVL tree
void levelorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->key << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

// Function to search for a node in the AVL tree
Node *search(Node *node, int key)
{
    if (node == nullptr || node->key == key)
    {
        return node;
    }
    if (key < node->key)
    {
        return search(node->left, key);
    }
    else
    {
        return search(node->right, key);
    }
}

// Function to find the minimum node in a subtree
Node *minNode(Node *node)
{
    Node *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

// Function to find the maximum node in a subtree
Node *maxNode(Node *node)
{
    Node *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
}
// Function to delete a node from the AVL tree
Node *deleteNode(Node *node, int key)
{
    if (node == nullptr)
    {
        return node;
    }
    if (key < node->key)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = deleteNode(node->right, key);
    }
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            Node *temp = node->left ? node->left : node->right;
            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = minNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    if (node == nullptr)
    {
        return node;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = balanceFactor(node);
    if (bf > 1 && balanceFactor(node->left) >= 0)
    {
        return rotateRight(node);
    }
    if (bf > 1 && balanceFactor(node->left) < 0)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && balanceFactor(node->right) <= 0)
    {
        return rotateLeft(node);
    }
    if (bf < -1 && balanceFactor(node->right) > 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Driver code
int main()
{
    Node *root = nullptr;

    // Insert some nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    // Print the inorder traversal of the AVL tree
    cout << "Inorder traversal of the AVL tree is: ";
    inorderTraversal(root);
    cout << endl;
    // Print the preorder traversal of the AVL tree
    cout << "Preorder traversal of the AVL tree is: ";
    preorderTraversal(root);
    cout << endl;
    // Print the postorder traversal of the AVL tree
    cout << "Postorder traversal of the AVL tree is: ";
    postorderTraversal(root);
    cout << endl;
    // Print the level order traversal of the AVL tree
    cout << "Level order traversal of the AVL tree is: ";
    levelorderTraversal(root);
    cout << endl;
    // delete a node from the AVL tree
    root = deleteNode(root, 20);
    // Print the level order traversal of the AVL tree
    cout << "Level order traversal of the AVL tree after deletion is: ";
    levelorderTraversal(root);
    cout << endl;
    return 0;
}