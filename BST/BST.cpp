//
// Created by Muhammed_Umit on 25.02.2024.
//


/**
* Title: Binary Search Trees
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 1
* Description : Source File for the implemenation of BST Class
*/
#include "BST.h"
#include <iostream>
#include <cmath>


// Main Functions
BST :: BST(int keys [], int size)
{
    root = nullptr;
    for (int i = 0; i < size ; i++)
    {
        int currentLevel = 1;
        insertKey(root, currentLevel,keys[i]);
    }
    cout << "BST with size " << size << " is created." << endl;
}
BST :: BST()
{
    root = nullptr;
}
BST:: ~BST()
{
    destroyTree(root);
}
void BST :: insertKey(int key)
{
    bool isExisted;
    isKeyExisted(root, key, isExisted);
    if(!isExisted)
    {
        int currentLevel = 1;
        insertKey(root, currentLevel, key);
        cout << "Key " << key << " is added." << endl;
    }

    else
        cout << "Key " << key << " is not added. It exists!" << endl;

}

void BST ::deleteKey(int key)
{
    bool isExisted;
    isKeyExisted(root, key, isExisted);
    if(isExisted) {
        deleteKey(root, key);
        cout << "Key " << key << " is deleted." << endl;
    }
    else
        cout << "Key " << key << " is not deleted. It does not exist!" << endl;

}

void BST :: displayInorder()
{
    string pathTitle = "Inorder display is: ";
    string path = "";
    inorder(root, constructReversedPath, path);
    path.erase(path.size()-2);
    cout << pathTitle << path << endl;

}
void BST :: findFullBTLevel()
{
    int level = 1;
    if(root -> leftChildPtr != nullptr && root -> rightChildPtr != nullptr)
    {
        level++;
        bool flag = false;
        HaveBalancedChildren(root,flag, level);
    }
    cout << "Full binary tree level is: " << level << endl;
}

void BST :: lowestCommonAncestor(int A, int B)
{
    Node* Aptr = nullptr;
    Node* Bptr = nullptr;
    findKey(root, A, Aptr);
    findKey(root, B, Bptr);
    bool AtoB = false;
    bool BtoA = false;
    isKeyExisted(Aptr, B, AtoB);
    isKeyExisted(Bptr, A, BtoA);
    int commonAncestor;
    if(AtoB)
        commonAncestor = A;
    else if(BtoA)
        commonAncestor = B;
    else
    {
        int arraySize = 0;
        findSize(root, arraySize);
        int ancestorArrayA[arraySize];
        int indexA = 0;
        int ancestorArrayB[arraySize];
        int indexB = 0;
        ancestorCollector(root, A, ancestorArrayA, indexA, arraySize, collector);
        ancestorCollector(root, B, ancestorArrayB, indexB, arraySize, collector);
        commonAncestor = lowestCommon(ancestorArrayA, ancestorArrayB,arraySize,arraySize);
    }
    cout << "Lowest common ancestor of " << A << " and " << B << " is: " << commonAncestor << endl;
}

void BST :: maximumSumPath()
{
    string maxSumPath = "Maximum sum path is: " + to_string(root -> key) + ", ";
    maximumSumPathSubTree(root, maxSumPath);
    maxSumPath.erase(maxSumPath.size() - 2);
    cout << maxSumPath << endl;
}

void BST :: maximumWidth()
{
    int maxHeight = 1;
    findHeight(root, maxHeight);
    int** keys;
    keys = new int* [maxHeight];
    for(int i = 0; i < maxHeight ; i++)
    {
        int levelSize = pow(2,i);
        keys[i] = new int [levelSize];
    }
    int maxSize = 0;
    findSize(root,maxSize);
    int index = 0;
    Node* nodes [maxSize];
    inorderNodeCollector(root,nodes,index,maxSize,nodeCollector);
    for(int i = 0; i < maxHeight ; i++)
    {
        int levelSize = pow(2,i);
        for (int j = 0; j <levelSize ;) {
            for (int k = 0; k < maxSize; k++) {

                if(nodes[k] != nullptr) {
                    if (nodes[k]->level == (i + 1)) {
                        keys[i][j] = nodes[k]->key;
                        j++;
                        nodes[k] = nullptr;
                    }
                }

            }
            if(j < levelSize)
            {
                for (; j < levelSize; j++) {
                    keys[i][j] = -1;
                }
            }
        }
    }

    int maxWidth = -1;
    int maxWidthLevel = -1;
    for(int i = 0; i < maxHeight ; i++)
    {
        int levelCount = 0;
        int levelSize = pow(2,i);
        for (int j = 0; j < levelSize ; j++) {
            if(keys[i][j] != -1)
                levelCount++;
        }
        if(levelCount > maxWidth)
        {
            maxWidth = levelCount;
            maxWidthLevel = i;
        }
    }
    string maxWidthDisplay = "";
    int levelSize = pow(2,maxWidthLevel);

    for (int i = 0; i < levelSize ; i++) {
        maxWidthDisplay = maxWidthDisplay + to_string(keys[maxWidthLevel][i])  + ", ";
    }
    maxWidthDisplay.erase(maxWidthDisplay.size() - 2);
    cout  << "Maximum level is: " << maxWidthDisplay << endl;
    for(int i = 0; i < maxHeight ; i++)
    {
        delete[] keys[i];
    }
    delete[] keys;
}

void BST :: pathFromAtoB(int A, int B)
{
    Node* startPtr = nullptr;
    Node* stationPtr = nullptr;
    findKey(root, A, startPtr);
    findKey(root, B, stationPtr);
    bool AtoB = false;
    bool BtoA = false;
    isKeyExisted(startPtr, B, AtoB);
    isKeyExisted(stationPtr, A, BtoA);
    string path = "";
    if(AtoB)
    {
        constructPathAtoB(startPtr, B, path, constructReversedPath);
    }
    else if(BtoA)
    {
        constructPathAtoB(stationPtr, A, path, constructPath);
    }
    else
    {
        string part1 = "";
        string part2 = "";
        if(B > (root -> key))
        {

            constructPathAtoB(root, A, part1, constructPath);
            constructPathAtoB(root -> rightChildPtr, B, part2, constructReversedPath);
            path = part1 + part2;

        }
        else
        {
            constructPathAtoB(root, A, part1, constructPath);
            constructPathAtoB(root -> leftChildPtr, B, part2, constructReversedPath);
            path = part1 + part2;
        }

    }
    path.erase(path.size() - 2);
    cout << "Path from " << A << " to " << B << " is: " << path << endl;

}

// Traversal Functions

void BST :: inorder(Node* node, FunctionType visit, string& path)
{
    if(node != nullptr)
    {
        inorder(node->leftChildPtr, visit, path);
        visit(node,path);
        inorder(node->rightChildPtr, visit,path);
    }
}

void BST::inorder2(Node *node, BST::FunctionType2 visit2, int &number) {
    if(node != nullptr)
    {
        inorder2(node->leftChildPtr, visit2, number);
        visit2(node,number);
        inorder2(node->rightChildPtr, visit2,number);
    }
}

void BST::inorderNodeCollector(Node *node, Node* nodeCollection[], int& index, int maxSize, FunctionType4 collect) {
    if(node != nullptr)
    {
        inorderNodeCollector(node->leftChildPtr, nodeCollection, index,  maxSize, collect);
        collect(node,nodeCollection,index,maxSize);
        inorderNodeCollector(node->rightChildPtr, nodeCollection, index,  maxSize, collect);

    }
}

// Helper Static Functions

void BST::constructPath(Node *node, string &nodeKey)
{
    nodeKey = to_string(node->key) + ", " + nodeKey;
}
void BST::constructReversedPath(Node *node, string &nodeKey)
{
    nodeKey = nodeKey + to_string(node->key) + ", ";
}

void BST::calculateTreeSize(Node *node, int &size)
{
    size++;
}

void BST::calculateTreeHeight(Node* node, int&level)
{
    if(node -> level > level)
        level = node -> level;
}

void BST::calculatePathSum(Node *node, int &sum)
{
    sum = sum + node->key;
}

void BST::collector(Node* node, int collection[], int& index, int size)
{
    if(index < size)
    {
        collection[index] = node->key;
        index++;
    }
}
void BST :: nodeCollector(Node* node, Node* nodeCollection[], int&index, int maxSize)
{
    if(index < maxSize )
    {
        nodeCollection[index] = node;
        index++;
    }
}

// Helper Non-Static Functions

void BST ::insertKey(Node*& targetPtr, int& level, int key)
{
    if (targetPtr == nullptr) {
        targetPtr = new Node(key, level,  nullptr, nullptr);
    }
    else if (targetPtr->key > key) {
        level++;
        insertKey(targetPtr->leftChildPtr, level, key);
    }
    else {
        level++;
        insertKey(targetPtr->rightChildPtr, level, key);
    }
}

void BST :: insertKeyWithoutMessages(int key)
{
    bool isExisted;
    isKeyExisted(root, key, isExisted);
    if(!isExisted)
    {
        int currentLevel = 1;
        insertKey(root, currentLevel, key);
    }
}

void BST::deleteKey(Node *&targetPtr, int key)
{
    if(targetPtr == nullptr){}

    else if(key == targetPtr -> key)
        deleteNode(targetPtr);
    else if(key < targetPtr->key)
        deleteKey(targetPtr->leftChildPtr, key);
    else
        deleteKey(targetPtr->rightChildPtr, key);

}

void BST::deleteNode(Node *&targetPtr)
{
    Node* delPtr;
    int replacementKey;

    if((targetPtr->leftChildPtr == nullptr) && (targetPtr->rightChildPtr == nullptr))
    {
        delete targetPtr;
        targetPtr = nullptr;
    }
    else if(targetPtr -> leftChildPtr == nullptr)
    {
        delPtr = targetPtr;
        targetPtr = targetPtr -> rightChildPtr;
        delPtr -> rightChildPtr = nullptr;
        delete delPtr;
    }
    else if(targetPtr -> rightChildPtr == nullptr)
    {
        delPtr = targetPtr;
        targetPtr = targetPtr -> leftChildPtr;
        delPtr -> leftChildPtr = nullptr;
        delete delPtr;
    }
    else
    {
        goLeftMostNode(targetPtr->rightChildPtr, replacementKey);
        targetPtr -> key = replacementKey;
    }
}

void BST :: destroyTree(Node*& nodePtr)
{
    if(nodePtr != nullptr)
    {
        destroyTree(nodePtr->leftChildPtr);
        destroyTree(nodePtr->rightChildPtr);
        delete nodePtr;
        nodePtr = nullptr;
    }
}

void BST::goLeftMostNode(Node *&targetPtr, int &replacementKey)
{
    if(targetPtr -> leftChildPtr == nullptr)
    {
        replacementKey = targetPtr -> key;
        Node* delPtr = targetPtr;
        targetPtr = targetPtr -> rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    else
        goLeftMostNode(targetPtr -> leftChildPtr, replacementKey);

}

void BST::isKeyExisted(Node* targetPtr, int key, bool &isExisted)
{
    if(targetPtr == nullptr)
        isExisted = false;
    else if(targetPtr->key == key)
        isExisted = true;
    else if (targetPtr->key < key)
        isKeyExisted(targetPtr->rightChildPtr, key, isExisted);
    else
        isKeyExisted(targetPtr->leftChildPtr, key, isExisted);

}

void BST::constructPathAtoB(Node* APtr, int Bkey, string& path, FunctionType pathMaker) {
    if (APtr->key != Bkey && APtr != nullptr) {
        pathMaker(APtr, path);
        if (APtr->key > Bkey)
            constructPathAtoB(APtr->leftChildPtr, Bkey, path, pathMaker);
        else
            constructPathAtoB(APtr->rightChildPtr, Bkey, path, pathMaker);
    } else
        pathMaker(APtr, path);
}

void BST::maximumSumPathSubTree(Node *subRoot, string &maxPath) {
    if((subRoot->leftChildPtr != nullptr) && (subRoot->rightChildPtr != nullptr))
    {
        int sumLeft = 0;
        int sumRight = 0;
        inorder2(subRoot->leftChildPtr, calculatePathSum, sumLeft);
        inorder2(subRoot->rightChildPtr, calculatePathSum, sumRight);

        if(sumLeft <= sumRight)
        {
            maxPath = maxPath + to_string(subRoot -> rightChildPtr ->  key) + ", ";
            maximumSumPathSubTree(subRoot -> rightChildPtr, maxPath);
        }
        else
        {
            maxPath = maxPath + to_string(subRoot ->leftChildPtr -> key) + ", ";
            maximumSumPathSubTree(subRoot -> leftChildPtr, maxPath);
        }

    }
    else if ((subRoot->leftChildPtr == nullptr) && (subRoot->rightChildPtr != nullptr))
    {
        maxPath = maxPath + to_string(subRoot -> rightChildPtr ->  key) + ", ";
        maximumSumPathSubTree(subRoot -> rightChildPtr, maxPath);
    }
    else if ((subRoot->leftChildPtr != nullptr) && (subRoot->rightChildPtr == nullptr))
    {
        maxPath = maxPath + to_string(subRoot ->leftChildPtr -> key) + ", ";
        maximumSumPathSubTree(subRoot -> leftChildPtr, maxPath);
    }
}

void BST::HaveBalancedChildren(Node *node, bool &flag, int&level) {
    if((node -> leftChildPtr != nullptr) && (node->rightChildPtr != nullptr))
    {
        flag = true;
        bool leftFlag;
        bool rightFlag;
        HaveBalancedChildren(node -> leftChildPtr, leftFlag, level);
        HaveBalancedChildren(node -> rightChildPtr, rightFlag, level);
        if(leftFlag && rightFlag)
            level++;
    }
    else
        flag = false;
}

int BST::lowestCommon(int A [], int B [], int sizeA, int sizeB)
{
    int maxSize;
    if(sizeA >= sizeB)
        maxSize = sizeA;
    else
        maxSize = sizeB;
    int commonKeys [maxSize];
    int commonIndex = 0;
    for(int i = 0; i < sizeA; i++)
    {
        if(A[i] != -1)
        {
            for (int j = 0; j < sizeB; j++) {

                if(B[j] != -1) {

                    if (A[i] == B[j]) {
                        commonKeys[commonIndex] = B[j];
                        commonIndex++;
                    } else {
                        commonKeys[commonIndex] = -1;
                        commonIndex++;
                    }
                }
            }
        }
    }
    for (; commonIndex < maxSize; commonIndex++)
    {
        commonKeys[commonIndex] = -1;
    }

    int minCommon = commonKeys[0];
    for (int i = 1; i < maxSize; i++)
    {
        if(commonKeys[i] != -1)
        {
            if(commonKeys[i] < minCommon)
                minCommon = commonKeys[i];
        }
    }
    return minCommon;
}

void BST::ancestorCollector(Node* APtr, int Bkey, int collection[], int& index, int size, FunctionType3 collect)
{
    if(APtr -> key != Bkey && APtr != nullptr)
    {
        collect(APtr, collection, index, size);
        if (APtr->key > Bkey)
            ancestorCollector(APtr -> leftChildPtr, Bkey, collection, index, size, collect);
        else
            ancestorCollector(APtr -> rightChildPtr, Bkey, collection, index, size, collect);
    }
    for(; index < size ; index++)
    {
        collection[index] = -1;
    }
}

// "Find" Functions
void BST::findKey(Node* startPtr, int key, Node*& tagPtr)
{
    if(startPtr != nullptr)
    {
        if(startPtr -> key == key)
            tagPtr = startPtr;
        else if (startPtr->key < key)
            findKey(startPtr->rightChildPtr, key, tagPtr);
        else
            findKey(startPtr->leftChildPtr, key, tagPtr);
    }
}

void BST::findSize(Node *root, int &size) {

    inorder2(root, calculateTreeSize, size);
}
void BST::findHeight(Node* root, int&level)
{
    inorder2(root, calculateTreeHeight, level);
}














