#include <iostream>
#include <queue>
using namespace std;

class node{
public:
    node* left;
    node* right;
    int data;
    int height;

    node(int receiveData){
        data = receiveData;
        height = 1;
        left = right = nullptr;
    }
    node(){
        height = 1;
        data = -1;
        left = right = nullptr;
    }
};

class bst{
public:
    node* root = nullptr;

    void insert(int receiveValue){
        root = insert(root, receiveValue);
    }

    node* insert(node* receiveRoot, int receiveValue){
        node* newNode = new node(receiveValue);
        if(!receiveRoot){
            return newNode;
        }
        else if(receiveValue > receiveRoot->data){
            receiveRoot->right = insert(receiveRoot->right, receiveValue);
        }
        else if(receiveValue < receiveRoot->data){
            receiveRoot->left = insert(receiveRoot->left, receiveValue);
        }
        return receiveRoot;
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
    }

    void preOrderTraversal(node* receiveRoot){
        if(receiveRoot){
            cout << receiveRoot->data << " ";
            preOrderTraversal(receiveRoot->left);
            preOrderTraversal(receiveRoot->right);
        }
    }

    void levelOrderTraversal(){
        queue<node*> qOne;
        qOne.push(root);
        cout << root->data << " ";
        while(!qOne.empty()){
            node* dummy = qOne.front();
            qOne.pop();
            if(dummy->left){
                cout << dummy->left->data << " ";
                qOne.push(dummy->left);
            }
            if(dummy->right){
                cout << dummy->right->data << " ";
                qOne.push(dummy->right);    
            }
        }
    }

    node* search(int receiveData){
        return search(root, receiveData);
    }

    node* search(node* receiveRoot, int receiveData){
        if(!receiveRoot){
            return nullptr;
        }
        else if(receiveData > receiveRoot->data){
            return search(receiveRoot->right, receiveData);
        }
        else if(receiveData < receiveRoot->data){
            return search(receiveRoot->left, receiveData);
        }
        return receiveRoot;
    }

    node* invertTree(node* receiveRoot){
        if(!receiveRoot){
            return nullptr;
        }

        invertTree(receiveRoot->left);
        invertTree(receiveRoot->right);

        node* temp = receiveRoot->left;
        receiveRoot->left = receiveRoot->right;
        receiveRoot->right = temp;
    }

    void invertTree(){
        root = invertTree(root);
    }

};

int main(void){
    bst bOne;
    bOne.insert(10);
    bOne.insert(6);
    bOne.insert(12);
    bOne.insert(7);
    bOne.insert(8);
    bOne.insert(20);
    bOne.levelOrderTraversal();
    bOne.invertTree();
    cout << endl;
    bOne.levelOrderTraversal();
}