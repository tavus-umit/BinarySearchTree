//
// Created by Muhammed_Umit on 25.02.2024.
//

/**
* Title: Binary Search Trees
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 1
* Description : Source File for the implemenation of Node Class
*/

#include "Node.h"
Node :: Node()
{
    key = 0;
    level = 0;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}
Node :: Node(int value, int levelVal, Node* leftPtr, Node* rightPtr)
{
    key = value;
    level = levelVal;
    leftChildPtr = leftPtr;
    rightChildPtr = rightPtr;
}
Node :: Node(Node& copyNode)
{
    key = copyNode.key;
    level = copyNode.level;
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}
Node :: ~Node()
{
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}
