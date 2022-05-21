

#ifndef UNTITLED5_NODE_H
#define UNTITLED5_NODE_H

#include "Users.h"

class Node {
public:
    Users user;
    Node* left, *right;
    Node();
    explicit Node(Users val);
};
class UsersTree
{

    Node* root;
public:
    UsersTree();
    bool contains(int ID);
    Node* findNode(int ID);
    void insert(Users user);
    void traverse();
    void inOrder(Node* start);
    Node* deleteNode(Node* start, int ID);
    ~UsersTree();
    Node *deleteRoot(Node *root);
    int numOfUsers(Node *node);
    int numOfMales(Node* node);
    int numOfFemales(Node* node);
};

#endif //UNTITLED5_NODE_H
