/*Write program using functions for binary tree traversals: Pre-order, In-order and Post
order using recursive approach*/
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }

    void preOrderTraversal(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(Node *root)
    {
        if (!root)
            return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
    void inOrderTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
        }
    }
};

Node *buildTree()
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    Node *root = new Node(data);
    cout << "Enter left branch data of " <<data<< endl;
    root->left = buildTree();
    
    cout << "Enter right branch data of " <<data<< endl;
    root->right = buildTree();
    return root;
}

void buildTreeFromArray(int arr[]){
    cout<<"Enter root element"<<endl;
    int root;
    cin>>root;
    arr[1]=root;
    int size = 1;
    int temp = 1;
    while(size<100&& temp<=size){
        cout<<"enter left child of "<<arr[temp]<<endl;
        int left;
        cin>>left;
        if(left!=-1){
            size++;
            arr[2*temp] = left;
        }
        cout<<"enter right child of "<<arr[temp]<<endl;
        int right;
        cin>>right;
        if(right!=-1){
            arr[2*temp + 1] = right;
            size++;
        }
        temp++;
    }
}

int main()
{
    // int arr[100]={-1};
    // buildTreeFromArray(arr);
    // cout<<endl;
    // for(int i = 0 ; i < 8 ; i++){
    //     cout<<arr[i]<<" ";
    // }
       Node *root = buildTree();
    cout<<endl<<"inOrder"<<endl;
    root->inOrderTraversal(root);
    cout<<endl<<"preOrder"<<endl;
    root->preOrderTraversal(root);
    cout<<endl<<"postOrder"<<endl;
    root->postOrderTraversal(root);

}