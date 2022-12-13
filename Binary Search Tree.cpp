#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
    int element;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int data)
    {
        element = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    queue<BSTNode *> q1;
    int left_height, right_height = 0;
    BSTNode *insert(BSTNode *root, int data)
    {
        if (root == NULL)
        {
            return new BSTNode(data);
        }
        if (data < root->element)
        {
            root->left = insert(root->left, data);
        }
        else
            root->right = insert(root->right, data);
    }

    void inOrder(BSTNode *root)
    {
        if (root == NULL)
            return;

        else
        {
            inOrder(root->left);
            cout << root->element << " ";
            inOrder(root->right);
        }
    }

    void preOrder(BSTNode *root)
    {
        if (root == NULL)
            return;
        cout << root->element << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(BSTNode *root)
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->element << " ";
    }

    bool search(BSTNode *root, int target)
    {
        if (root == NULL)
            return false;
        if (root->element == target)
            return true;
        if (target > root->element)
            search(root->right, target);
        if (target < root->element)
            search(root->left, target);
    }

    BSTNode *deleteElement(BSTNode *temp, int data)
    {
        if (temp->element == data && temp->left == NULL && temp->right == NULL)
        {
            temp = NULL;
            return temp;
        }
        else if (temp->element == data && (temp->left != NULL || temp->right != NULL))
        {
            cout << "The given node is not a leaf.";
        }
        else if (temp->element > data)
        {
            temp->left = deleteElement(temp->left, data);
        }
        else if (temp->element < data)
        {
            temp->right = deleteElement(temp->right, data);
        }
    }

    BSTNode *deletionByMerging(BSTNode *curr,int data)
    {
        BSTNode *temp = curr;
        if (temp->element == data)
        {
            temp = temp->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            int k = temp->element;
            deleteElement(curr,temp->element);
            curr->element = k;
            return curr;
        }
        if (curr->element > data)
        {
            curr->left = deletionByMerging(curr->left, data);
        }
        else
        {
            curr->right = deletionByMerging(curr->right, data);
        }

    }

    void bfs(BSTNode *root)
    {
        if (root != NULL)
            q1.push(root);
        while (!q1.empty())
        {
            BSTNode *temp = q1.front();
            cout << temp->element << " ";
            if (temp->left != NULL)
            {
                q1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q1.push(temp->right);
            }
            q1.pop();
        }
    }

    int height(BSTNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            left_height = height(root->left);
            right_height = height(root->right);

            return left_height > right_height ? left_height + 1 : right_height + 1;
        }
    }
};

int main()
{
    BST obj;
    int choice;
    BSTNode *root = NULL;
    root = obj.insert(root, 5);
    while (true)
    {
        cout << "Enter 1 to insert in the tree.\nEnter 2 to delete an element.\nEnter 3 to search for an element.\nEnter 4 to print the tree in inorder, preorder and postorder.\nEnter 5 to display tree level by level.\nEnter 6 to display height of the tree.\nEnter 0 to exit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            root = obj.insert(NULL, 20);
            obj.insert(root, 12);
            obj.insert(root, 10);
            obj.insert(root, 8);
            obj.insert(root, 7);
            obj.insert(root, 6);
            obj.insert(root, 30);
            obj.insert(root, 35);
            obj.insert(root, 32);
            obj.insert(root, 43);
            obj.insert(root, 38);
            obj.insert(root, 41);
            obj.insert(root, 50);
            break;

        case 2:
            obj.deletionByMerging(root, 43);
            break;

        case 3:
            int elem;
            cout << "Enter the element to search: ";
            cin >> elem;
            if (obj.search(root, elem))
                cout << "Element Found.\n";
            else
                cout << "Element not found\n";
            break;

        case 4:
            cout << "Inorder Traversal: ";
            obj.inOrder(root);
            cout << endl;
            cout << "Preorder Traversal: ";
            obj.preOrder(root);
            cout << endl;
            cout << "Postorder Traversal: ";
            obj.postOrder(root);
            cout << endl;
            break;

        case 5:
            cout << "Level by level display: ";
            obj.bfs(root);
            cout << endl;
            break;

        case 6:
            cout << "The height of the tree is: " << obj.height(root);
            cout << endl;
            break;

        case 0:
            cout << "Exiting..";
            exit(0);

        default:
            break;
        }
    }
}
