//
// Created by Muhammed_Umit on 25.02.2024.
//

/**
* Title: Binary Search Trees
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 1
* Description : Header File for the implemenation of Node Class
*/

#ifndef BST_NODE_H
#define BST_NODE_H


class Node {
private:
        int key;
        int level;
        Node* leftChildPtr;
        Node* rightChildPtr;
public:

        Node(); // Default Constructor
        Node(int value, int levelVal, Node* leftPtr, Node* rightPtr); // Constructor with arguments
        Node(Node& copyNode); // Copy constructor
        ~Node(); // Destructor

        friend class BST;
};


#endif //BST_NODE_H
