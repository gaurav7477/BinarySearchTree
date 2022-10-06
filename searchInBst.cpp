#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        // constructor
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* minimumVal(Node* root){
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node* maximumVal(Node* root){
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
    
}
Node* deleteFromBst(Node* root,int key){
    //base case
    if(root == NULL) return root;

    else if(root->data == key){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 1 right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 left and right child
        if(root->left != NULL && root->right != NULL){
            int mini = minimumVal(root->right) ->data;
            root->data = mini;
            root->right = deleteFromBst(root->right,mini);
            return root;
        }
        
    }
    else if(root->data > key){
        root->left = deleteFromBst(root->left,key);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right,key);
        return root;
    }
    return root;
}

// we know that in inorder BST we got a data in sorted order
// check to left for getting minimum value
// check to right for getting maximum value

void inOrderTraversal(Node* root){
    if(root == NULL) return;

    inOrderTraversal(root->left);
    cout<<root->data<< " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root){
    if(root == NULL) return;

    cout<<root->data<< " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Node* root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<< " ";
}

// travesal by level order 
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
Node* inserIntoBst(Node* root,int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d < root->data){
        root->left = inserIntoBst(root->left,d);
    }
    else{
        root->right = inserIntoBst(root->right,d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = inserIntoBst(root,data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST "<< endl;
    takeInput(root);
    cout<<"printing the BST "<< endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"printing inOrderTraversal the BST "<< endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing preOrderTraversal the BST "<< endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing postOrderTraversal the BST "<< endl;
    postOrderTraversal(root);
    cout<<endl;

    cout<<" minimal value of BST :"<<minimumVal(root) ->data <<endl;
    cout<<" maiximal value of BST :"<<maximumVal(root) ->data <<endl;
    // deletion node
    root = deleteFromBst(root,20);

    cout<<"printing the BST "<< endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"printing inOrderTraversal the BST "<< endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing preOrderTraversal the BST "<< endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing postOrderTraversal the BST "<< endl;
    postOrderTraversal(root);
    cout<<endl;

    cout<<" minimal value of BST :"<<minimumVal(root) ->data <<endl;
    cout<<" maiximal value of BST :"<<maximumVal(root) ->data <<endl;


    
}