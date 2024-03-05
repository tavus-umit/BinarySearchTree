//
// Created by Muhammed_Umit on 4.03.2024.
//

/**
* Title: Binary Search Trees
* Author : Muhammed Umit TAVUS
* ID: 22203317
* Section : 2
* Homework : 1
* Description : Source File for the implemenation of BST Class
*/

#include "analysis.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

void analysis :: timeAnalysis()
{
    const int MAX_SIZE = 10000;
    int keys [MAX_SIZE];

    srand((unsigned) time(0)); // Needed to generate different random numbers

    for (int i = 0; i < MAX_SIZE; i++)
        keys[i] = rand() % 10000; // Generating numbers from 0 to 9999

    BST bst;

    const int CHECKPOINT = 1000; // Determines the number of insertion for one period
    int treeLevel = 1;
    clock_t begin = clock();
    for (int i = 0; i < MAX_SIZE; i++) {
        if ((i + 1) % CHECKPOINT == 0) // Detecting whether we reach to the checkpoint
        {
            clock_t end = clock();
            cout << i + 1 << " insertions take " << (((end - begin) / (float)(CLOCKS_PER_SEC))) << " seconds." << endl;
            begin = end;
            treeLevel = 1;
            bst.findHeight(bst.root, treeLevel);
            cout << "Tree Height: " << treeLevel << endl;
        }
        bst.insertKeyWithoutMessages(keys[i]);
    }
}
