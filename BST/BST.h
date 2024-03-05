//
// Created by Muhammed_Umit on 25.02.2024.
//

/**
* Title: Binary Search Trees
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 1
* Description : Header File for the implemenation of BST Class
*/

#ifndef BST_BST_H
#define BST_BST_H

#include "Node.h"
#include <string>
using namespace std;


class BST{
    typedef void (*FunctionType)(Node* node, string& string);
    typedef void (*FunctionType2)(Node* node, int& integer);
    typedef void(*FunctionType3)(Node* node, int collection[], int& index, int size);
    typedef void (*FunctionType4)(Node* node, Node* nodeCollection[], int&index, int size);
public:

    // Main Functions
    BST(int keys [], int size);
    BST();
    ~BST();
    void insertKey(int key);
    void deleteKey(int key);
    void displayInorder();
    void findFullBTLevel();
    void lowestCommonAncestor(int A, int B);
    void maximumSumPath();
    void maximumWidth();
    void pathFromAtoB(int A, int B);

    friend class analysis;

private:
    Node* root;

    // Traversal Functions
    void inorder(Node* node, FunctionType visit, string& path);
    void inorder2(Node* node, FunctionType2 visit2, int& number);
    void inorderNodeCollector(Node *node, Node* nodeCollection[], int& index, int maxSize, FunctionType4 collect);

    // Helper Static Functions
    static void constructPath(Node* node, string& nodeKey);
    static void constructReversedPath(Node *node, string &nodeKey);
    static void calculateTreeSize(Node* node, int&size);
    static void calculateTreeHeight(Node* node, int&level);
    static void calculatePathSum(Node* node, int&sum);
    static void collector(Node* node, int collection[], int& index, int size);
    static void nodeCollector(Node* node, Node* nodeCollection[], int&index, int maxSize);

    // Helper Non-Static Functions
    void insertKey(Node*& targetPtr, int& level, int key);
    void insertKeyWithoutMessages(int key);
    void deleteKey(Node*& targetPtr, int key);
    void deleteNode(Node*& targetPtr);
    void destroyTree(Node*& nodePtr);
    void goLeftMostNode(Node*& targetPtr, int&replacementKey);
    void isKeyExisted(Node* targetPtr, int key, bool& isExisted);
    void constructPathAtoB(Node* APtr, int Bkey, string& path, FunctionType pathMaker);
    void maximumSumPathSubTree(Node* subRoot, string& maxPath);
    void HaveBalancedChildren(Node* node, bool& flag, int&level);
    int lowestCommon(int A [], int B [], int sizeA, int sizeB);
    void ancestorCollector(Node* APtr, int Bkey, int collection[], int& index, int size, FunctionType3 collect);

    // "Find" Functions
    void findKey(Node* startPtr, int key, Node*& tagPtr);
    void findSize(Node* root, int&size);
    void findHeight(Node* root, int&level);






};
#endif //BST_BST_H
