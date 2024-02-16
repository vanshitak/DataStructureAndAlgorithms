/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

class node{

public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        data = d;
        left = right = NULL;
    }
};

//Preorder build of the tree
//Root, left, right

node* BuildTree(){
    int d;
    cin >> d;
    
    if(d==-1){
        return NULL;
    }
    
    node* n = new node(d);
    n->left = BuildTree();
    n->right = BuildTree();
    return n;
}

//Build tree by level order traversal
//level wise

node* LevelOrderBuild(){
    
    int d;
    cin >> d;
    
    node* root = new node(d);
    queue <node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        
        int c1, c2;
        cin >> c1 >> c2;
        
        if(c1!=-1){
            curr->left = new node(c1);
            q.push(curr->left);
        }
        
        if(c2!=-1){
            curr->right = new node(c2);
            q.push(curr->right);
        }
    }
    
    return root;
}

//Preorder traversal of the tree
//root, left, right

void printPreorder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

//Inorder traversal of the tree
//left, root, right

void printInorder(node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

//Postorder traversal of the tree
//left, right, root

void printPostorder(node* root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

//Level order traversal of tree
//Level wise print

void LevelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        
        if(temp=NULL){
            cout << endl;
            q.pop();
            
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout << temp->data << " ";
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//height of the tree O(n)

int height(node* root){
    if(root= NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    return 1 + max(h1,h2);
}

// Insert node into a Binary Search Tree
node* insert(node* root, int key){
    
    if(root==NULL){
        return new node(key);
    }
    
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }
    return root;
}

// Takes O(h) time to search BST
// log(N) < h < N
bool search(node* root, int key){
    
    if(root==NULL) return false;
    
    if(root->data == key) return true;
    
    if(key < root->data){
        return search(root->left, key);    
    }else {
        return search(root->right, key);
    }
}

// Find the smallest node in the right subtree of BST
node* findMin(node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

// Delete a node from Binary Search tree
node* deleteNode(node* root, int key){
    if(root==NULL){
        return NULL;
    }
    else if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        // The case when the current node matches with the key
        //1 - No children
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
        }
        //2 - Single child
        else if(root->left==NULL){
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        //3 - Two children
        else{
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Print all elements that lie in the range k1 & k2
void printRange(node* root, int k1, int k2){
    
    if(root==NULL) return;
    
    if(root->data >= k1 && root->data <= k2){
        //call on both sub trees
        printRange(root->left,k1,k2);
        printRange(root->right,k1,k2);
        cout << root->data << " ";
    }
    else if(root->data > k2){
        printRange(root->left,k1,k2);
    }
    else{
        // root->data < k1
        printRange(root->right,k1,k2);
    }
}

// Print all paths from the root to the leaf nodes
void printRoot2LeafPaths(node* root, vector<int> &path){
    
    //Base Cases
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL){
        for(int x:path){
            cout << x << "->";
        }
        cout << root->data<< " ";
        cout << endl;
        return;
    }
    
    // Recursion case
    path.push_back(root->data);
    printRoot2LeafPaths(root->left, path);
    printRoot2LeafPaths(root->right, path);
    
    // Backtracking
    path.pop_back();
    return;
}

int main()
{
    node* root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};
    
    for(int x: arr){
        root = insert(root,x);
    }
    printInorder(root);
    
    vector<int> path;
    printRoot2LeafPaths(root,path);
    return 0;
}



