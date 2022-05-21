
#include "Node.h"
#include "Users.h"
#include <iostream>
#include <cassert>
using namespace std;
Node::Node()
{
    left=right= nullptr;
}

Node::Node(Users val)
{
    user=val;
    left=right= nullptr;
}
UsersTree::UsersTree()
{
    root= nullptr;
}
bool UsersTree::contains(int ID)
{
    Node* tmp=findNode(ID);

    return (tmp!= nullptr);
}

Node* UsersTree::findNode(int ID)
{
    Node* tmp=root;

    while((tmp!= nullptr)&&(tmp->user.id != ID))
        if(tmp->user.id > ID)
            tmp=tmp->left;
        else
            tmp=tmp->right;
    return tmp;
}
void UsersTree::insert(Users user)
{
    assert(!contains(user.id));
    Node* tmp=root;
    Node* newNode=new Node(user);
    if(root== nullptr)
        root=newNode;
    else
    {
        while(true)
        {
            if(tmp->user.id > user.id)
                if(tmp->left== nullptr)
                {
                    tmp->left=newNode;
                    break;
                }
                else
                    tmp=tmp->left;
            else
            if(tmp->right== nullptr)
            {
                tmp->right=newNode;
                break;
            }
            else
                tmp=tmp->right;
        }
    }
}

void UsersTree::traverse()
{
    inOrder(root);
}
void UsersTree::inOrder(Node* start)
{
    if (start != nullptr)
    {
        inOrder(start->left);
        cout << start->user.id << endl;
        inOrder(start->right);
    }
}

UsersTree::~UsersTree()
{
}

Node* UsersTree::deleteNode(Node* start, int ID) {
    if(start == nullptr || start->user.id == ID) return deleteRoot(start);
    Node* curr = start;
    while(true) {
        int x = curr->user.id;
        if(ID < x){
            if(curr->left == nullptr || curr->left->user.id == ID){
                curr->left = deleteRoot(curr->left);
                break;
            }
            curr = curr->left;
        } else {
            if(curr->right == nullptr || curr->right->user.id == ID){
                curr->right = deleteRoot(curr->right);
                break;
            }
            curr = curr->right;
        }
    }
    return start;
}

Node* UsersTree::deleteRoot(Node* root){
    if(!root || root->user.id == 0)return nullptr;
    if(root->right == nullptr) return root->left;
    Node* x = root->right;
    while(x->left)x = x->left;
    x->left = root->left;
    return root->right;
}
int UsersTree::numOfUsers(Node* node)
{
    if (node == nullptr)
        return 0;
    else
        return(numOfUsers(node->left) + 1 + numOfUsers(node->right));
}
int UsersTree::numOfMales(Node* node){
    if (node == nullptr)
        return 0;
    else if(node->user.gender=="male") {
        if (root->user.gender == "male") {
            return (numOfUsers(node->left) + 1 + numOfUsers(node->right));
        }
        else {
            return (numOfUsers(node->left) + numOfUsers(node->right));
        }
    }
    else{
        numOfUsers(node);
    }
}
int UsersTree::numOfFemales(Node* node){
    return numOfUsers(node) - numOfMales(node);
}

