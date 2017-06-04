/*
 *Name: Travis Allan
 *Date: 7/27/2014
 *Course: CSCE 2110
 *Title: Program 4
 *Description: DFS Program
 References: CSCE1040 Lab Handout "List It, Stack It, Queue it" Handout 2014
 *I used the algorithm for making a list as the basis for all of my list operations. All list operations derived or taken from that algorithm are denoted with the comment "//based on algorithm".
 */

//headers
#include <iostream>
#include <cstring>
#include "pg4Nodes.h"
#include "pg4List.h"
#include "pg4Graph.h"
using namespace std;





//main
int main() {

    //value declarations
    char comm[10];
    char create[7] = "create";
    char insert[7] = "insert";
    char quit[5] = "quit";
    char remove[7] = "remove";
    char print[6] = "print";
    int tempNode1, tempNode2, tempWeight, numNodes, addCount, i, j, k;
    //new variables
    int nodeStart, key, runCount, space, toggle;
    
    Graph graphArray;
    
    
    addCount = 0;
    numNodes = 0;
    nodeStart = 0;
     k = 0;
    
    //user message
    cout << endl;
    cout << "Important! Don't use the input DFS(#) for the DFS command, use DFS # instead." << endl;
    cout << "Example input: DFS 0" << endl;
    
    
    do {
        key = nodeStart;
        runCount = 0;
        cout << "graph_DFS>";
        cin >> comm;
        
 
        
        
        if (strcmp(comm, create) == 0) {
            cin >> numNodes;
            if (numNodes > 15) {
                cout << "Fatal Error: This program can only hold up to 15 nodes" << endl;
                return 0;
            }
            //cout << endl;
            graphArray.InitializeGraph(numNodes);
            //cout << "good" << endl;
        }
        else if (strcmp(comm, insert) == 0) {
            cin >> tempNode1 >> tempNode2 >> tempWeight;
            //put limit on edge here
            if (tempNode1 > numNodes || tempNode2 > numNodes) {
                cout << "Error#2: One of these nodes doesn't exist" << endl;
            }
            else {
                if (tempNode1 > 0 && k == 0) {
                    cout << "Error#3: You must start with the initial node 0" << endl;
                }
                
                else {
                    if (graphArray.BuildGraph(tempNode1, tempNode2, tempWeight) == 1) {
                        k++;
                        //cout << k << endl;
                    }
                    else cout << "Error#2: Node doesn't exist" << endl;
                }
            }
        }
        
        else if (strcmp(comm, print) == 0) {
            graphArray.PrintGraph(numNodes);
        }
        
        else if (strcmp(comm, remove) == 0) {
            cin >> tempNode1 >> tempNode2;
            if (graphArray.RemoveGraph(tempNode1, tempNode2, numNodes) != 1) {
                cout << "Error 4: The path between those two nodes could not be found" << endl;
            }
        }
        
        else if (strcmp(comm, "DFS") == 0) {
            cin >> nodeStart;
            graphArray.space = 0;
            toggle = 0;
            cout << endl;
            graphArray.bigList[nodeStart].NodeWalk = graphArray.bigList[nodeStart].NodeHead;
            if (graphArray.DFS(nodeStart, numNodes, toggle) == 1) {
                cout << "DFS performed successfully" << endl;
            }
            
            else graphArray.DFS(nodeStart, numNodes, toggle);
        }
        
        else if (strcmp(comm, "Postorder") == 0) {
            cout << endl;
            if (graphArray.Postorder(numNodes, key, runCount) != 1) {
                cout << "Error#6: Postorder failed" << endl;
            }
            cout << endl;
        }
        else if (strcmp(comm, "EdgeType") == 0) {
            cout << endl;
            if (graphArray.EdgeType(numNodes) != 0) {
                cout << "The graph has a cycle!" << endl;
            }
            else cout << "The graph has no cycles." << endl;
            cout << endl;
        }
        else if (strcmp(comm, quit) == 0) {
            cout << "Have a nice day!" << endl;
        }
         else cout << "Error#1: The command recieved is not supported." << endl;
    }while (strcmp(comm, quit) != 0);
    
    return 0;
}

