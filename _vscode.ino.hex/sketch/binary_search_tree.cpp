#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\binary_search_tree.cpp"
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d = 0) : data(d), left(NULL), right(NULL){};
};
node *create(node *root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }
    if (d < root->data)
    {
        root->left = create(root->left, d);
    }
    else
    {
        root->right = create(root->right, d);
    }
    return root;
}
node* maxnode(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->right==NULL)
    {
        return root;
    }
    return maxnode(root->right);
}
node* minnode(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL)
    {
        return root;
    }
    return minnode(root->left);
}
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
node *remove(node *root, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (d < root->data)
    {
        root->left = remove(root->left, d);
    }
    else if (d > root->data)
    {
        root->right = remove(root->right, d);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}
bool search(node *root, int d)
{
    if (root == NULL)
    {
        return false;
    }
    if (d < root->data)
    {
        return search(root->left, d);
    }
    else if (d > root->data)
    {
        return search(root->right, d);
    }
    else
    {
        return true;
    }
}
int main()
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        root = create(root, d);
    }
    inorder(root);
    cout << endl;
    root=remove(root, 5);
    inorder(root);
    /* preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);
    cout << endl; */
    return 0;
}