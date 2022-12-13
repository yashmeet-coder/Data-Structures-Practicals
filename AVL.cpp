#include <queue>
#include <iostream>
template <typename t>
class Node
{
    public:
    t data;
    Node* lchild;
    Node* rchild;
    int height;
    Node();
    Node(t);
};
template <typename t> Node<t>::Node()
{
    data = 0;
    lchild = NULL;
    rchild = NULL;
    height = 0;
}
template <typename t> Node<t>::Node(t value)
{
    data = value;
    lchild = NULL;
    rchild = NULL;
    height = 0;
}
template <typename t>
class avlTree
{
    private:
    Node<t>* rotateRight(Node<t>*);
    Node<t>* rotateLeft(Node<t>*);
    public:
    Node<t>* root;
    avlTree();
    avlTree(t);
    Node<t>* insert(Node<t>*,t);
    int height(Node<t>*);
    int getBalance(Node<t>*);
    void inorder(Node<t>*);
    void preorder(Node<t>*);
    void postorder(Node<t>*);
    void level_order(Node<t>*);
    bool check_element(t);      //Checks if an element exists in the avlTree.
    Node<t>* search(t);         //Returns the parent node of the node with the given value.
};
template <typename t> avlTree<t>::avlTree()
{
    root = new Node<t>();
}
template <typename t> avlTree<t>::avlTree(t value)
{
    root = new Node<t>(value);
}
template <typename t> Node<t>* avlTree<t>::insert(Node<t>* node, t key)
{
    if(node == NULL)
    {
        Node<t>* temp = new Node<t>(key);
        return temp;
    }
    if (key < node -> data)
    {
        node->lchild = insert(node->lchild, key);
    }
    else if (key > node -> data)
    {
        node->rchild = insert(node->rchild, key);
    }
    else
    {
        return node;
    }
    node -> height = 1 + std::max(height(node->lchild), height(node->rchild));
    int balance = getBalance(node);
    if (balance > 1 && key < node -> lchild -> data)
    {
        return rotateRight(node);
    }
    if (balance < -1 && key > node -> rchild -> data)
    {
        return rotateLeft(node);
    }
    if (balance > 1 && key > node->lchild->data)
    {
        node->lchild = rotateLeft(node->lchild);
        return rotateRight(node);
    }
    if (balance < -1 && key < node -> rchild -> data)
    {
        node->rchild = rotateRight(node->rchild);
        return rotateLeft(node);
    }
    return node;
}
template <typename t> int avlTree<t>::height(Node<t>* n)
{
    if(n == NULL)
    {
        return 0;
    }
    else 
    {
        int lheight = height(n->lchild);
        int rheight = height(n->rchild);
        if(lheight > rheight)
        {
            return(lheight + 1);
        }
        else
        {
            return(rheight + 1);
        }     
    }
}
template <typename t> int avlTree<t>::getBalance(Node<t>* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->lchild) - height(node->rchild);
}
template <typename t> Node<t>* avlTree<t>::rotateRight(Node<t>* node)
{
    Node<t>* temp = node->lchild;
    Node<t>* T2 = temp->rchild;
    temp -> rchild = node;
    node->lchild = T2;
    node->height = std::max(height(node->lchild), height(node->rchild)) + 1;
    temp->height = std::max(height(temp->lchild), height(temp->rchild)) + 1;
    return temp;
}
template <typename t> Node<t>* avlTree<t>::rotateLeft(Node<t>* node)
{
    Node<t>* temp = node->rchild;
    Node<t>* T2 = temp->lchild;
    temp -> lchild = node;
    node -> rchild = T2;
    node->height = std::max(height(node->lchild), height(node->rchild)) + 1;
    temp->height = std::max(height(temp->lchild), height(temp->rchild)) + 1;
    return temp;
}
template <typename t> void avlTree<t>::inorder(Node<t>* temp)
{
    if(temp == NULL)
    {
        return ;
    }
    inorder(temp -> lchild);
    std::cout<<temp -> data<<" ";
    inorder(temp -> rchild);
}
template <typename t> void avlTree<t>::preorder(Node<t>* temp)
{
    if(temp == NULL)
    {
        return ;
    }
    std::cout<<temp -> data<<" ";
    preorder(temp -> lchild);
    preorder(temp -> rchild);
}
template <typename t> void avlTree<t>::postorder(Node<t>* temp)
{
    if(temp == NULL)
    {
        return ;
    }
    postorder(temp -> lchild);
    postorder(temp -> rchild);
    std::cout<<temp -> data<<" ";
}
template <typename t> void avlTree<t>::level_order(Node<t>* temp)
{
    if(temp == NULL)
    {
        return;
    }
    std::queue<Node<t>*> q;
    q.push(temp);
    while(q.empty() == false)
    {
        Node<t>* node = q.front();
        std::cout<<node ->data<<" ";
        q.pop();
        if(node -> lchild != NULL)
        {
            q.push(node -> lchild);
        }
        if(node -> rchild != NULL)
        {
            q.push(node -> rchild);
        }
    }
}
template <typename t> bool avlTree<t>::check_element(t element)
{
    Node<t>* temp = root;
    while(temp != NULL)
    {
        if(temp->data > element)
        {
            temp = temp -> lchild;
        }
        else if(temp->data < element)
        {
            temp = temp -> rchild;
        }
        else
        {
            return true;
        }
    }
    return false;
}
template <typename t> Node<t>* avlTree<t>::search(t value)
{
    Node<t>* parent_node = NULL;
    Node<t>* temp = root;
    while(temp != NULL)
    {
        if(temp -> data > value)
        {
            parent_node = temp;
            temp = temp -> lchild;
        }
        else if(temp -> data < value)
        {
            parent_node = temp;
            temp = temp -> rchild;
        }
        else
        {
            return parent_node;
        }
    }
    return nullptr;
}
int main()
{
    avlTree<int> t(30);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 25);
    std::cout<<"Level by level display:- ";
    t.level_order(t.root);
}