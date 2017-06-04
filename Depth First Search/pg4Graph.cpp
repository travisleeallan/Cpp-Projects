/*
 *Name: Travis Allan
 *Date: 7/27/2014
 *Course: CSCE 2110
 *Title: Program 4
 *Description: DFS Program
 */

#include <iostream>
#include <cstring>
#include "pg4Nodes.h"
#include "pg4List.h"
#include "pg4Graph.h"
using namespace std;


int Graph::BuildGraph(int tempNode1, int tempNode2, int tempWeight) {
    int i = tempNode1;
    bigList[i].NodeWalk = bigList[i].NodeHead->NextNode; //based on algorithm
    if (bigList[i].nodeCount != 0) {
        while(bigList[i].NodeWalk != NULL) {
            if (tempNode2 == bigList[i].NodeWalk->node) {
                bigList[i].NodeWalk->weight = tempWeight;
                return 1;
            }
            else {
                bigList[i].NodeWalk = bigList[i].NodeWalk->NextNode; //based on algorithm
            }
            
        }
    
        bigList[i].NodeTail->NextNode = new Nodes; //based on algorithm
        bigList[i].NodeTail = bigList[i].NodeTail->NextNode; //based on algorithm
        bigList[i].NodeTail->NextNode = NULL; //based on algorithm
        
        bigList[i].NodeTail->node = tempNode2;
        bigList[i].NodeTail->weight = tempWeight;
        bigList[i].NodeTail->trav = 'u';
        bigList[i].NodeTail->edge = 'A';
        //for edgetype
        //if (
        
        return 1;
    }
    else {
        bigList[i].NodeTail->NextNode = new Nodes; //based on algorithm
        bigList[i].NodeTail = bigList[i].NodeTail->NextNode; //based on algorithm
        bigList[i].NodeTail->NextNode = NULL; //based on algorithm
        
        bigList[i].NodeTail->node = tempNode2;
        bigList[i].NodeTail->weight = tempWeight;
        bigList[i].NodeTail->trav = 'u';
        bigList[i].NodeTail->edge = 'A';
        bigList[i].nodeCount++;
        return 1;
    }
    
    return 0;
}

int Graph::InitializeGraph(int numNodes) {
    int i;
    //bigList = new List;
    for (i=0; i <= numNodes; i++) {
        bigList[i].NodeHead = new Nodes;  //based on algorithm
        bigList[i].NodeHead->node = i;
        bigList[i].NodeHead->trav = 'u';
        bigList[i].nodeCount = 0;
        
        bigList[i].NodeHead->NextNode = NULL; //based on algorithm
        bigList[i].NodeTail = bigList[i].NodeHead; //based on algorithm
    }
    //for (i=0; i <= numNodes; i++) {
    //    cout << bigList[i].NodeHead->node << endl;
    //}
    
    return 0;
}

void Graph::SortGraph() {
    //unused for now
}
void Graph::PrintGraph(int numNodes) {
    int i;
    cout << endl;
    for (i=0; i <= numNodes; i++) {
        bigList[i].NodeWalk = bigList[i].NodeHead->NextNode; //based on algorithm
        while(bigList[i].NodeWalk != NULL) {  //based on algorithm
            if (bigList[i].NodeWalk->node != -1) {
                cout << "(" << bigList[i].NodeHead->node << "," << bigList[i].NodeWalk->node << "," << bigList[i].NodeWalk->weight << ")";
                bigList[i].NodeWalk = bigList[i].NodeWalk->NextNode;  //based on algorithm
            }
            else {
                bigList[i].NodeWalk = bigList[i].NodeWalk->NextNode;  //based on algorithm
            }
        }
        
    }
    cout << endl;
}

int Graph::RemoveGraph(int tempNode1, int tempNode2, int numNodes) {
    int i, j;
    bigList[tempNode1].NodeWalk = bigList[tempNode1].NodeHead->NextNode; //based on algorithm
    while(bigList[tempNode1].NodeWalk != NULL) { //based on algorithm
        if (tempNode2 == bigList[tempNode1].NodeWalk->node) {
            bigList[tempNode1].NodeWalk->node = -1;
            bigList[tempNode1].NodeWalk->weight = -1;
            return 1;
        }
        else bigList[tempNode1].NodeWalk = bigList[tempNode1].NodeHead->NextNode;//based on algorithm
    }

    
    return 0;
}

//DFS
int Graph::DFS(int nodeStart, int numNodes, int toggle) {
    //postArray[0] = nodeStart;
    if (toggle == 1) { //made unuseful with the shortening of the function
        bigList[nodeStart].NodeWalk = bigList[nodeStart].NodeHead; //based on algorithm
    }
    if (bigList[nodeStart].NodeHead->trav == 'u') {
        toggle = 1;
        bigList[nodeStart].NodeHead->trav = 'v';
        cout << "Visitied " << bigList[nodeStart].NodeWalk->node << endl;
        postArray[space] = bigList[nodeStart].NodeWalk->node;
        space++;
        
        while(bigList[nodeStart].NodeWalk->NextNode != NULL) {//based on algorithm
            bigList[nodeStart].NodeWalk = bigList[nodeStart].NodeWalk->NextNode; //based on algorithm
            DFS(bigList[nodeStart].NodeWalk->node, numNodes, toggle);
            //cout << "check1" << endl;
        }
    
    }
    else if (bigList[nodeStart].NodeHead->trav == 'v') {
        return space;
    }

    return 1;
}

int Graph::Postorder(int numNodes, int key, int runCount) {
    int i, j;
    //test
    //for (i=0; i<=15; i++) {
    //    cout << postArray[i] << endl;
    //}
    j = 1;
    for (i=numNodes; i>=0; i--) {
        if (i > 0) {
            cout << j << "," << postArray[i] << " " << "-" << " ";
            j++;
        }
        else cout << j << "," << postArray[i] << endl;
    }
    
        return 1;
}

int Graph::EdgeType(int numNodes) {
    int i, j, edge, run;
    edge = 0;
    run = 1;
    for (i=0; i <= numNodes; i++) {
        for (j=0; j <= numNodes; j++) {
            bigList[j].NodeWalk3 = bigList[j].NodeHead->NextNode; //based on algorithm
            bigList[j].NodeWalk2 = bigList[j].NodeHead->NextNode; //based on algorithm
            bigList[i].NodeWalk = bigList[i].NodeHead->NextNode; //based on algorithm
            while(bigList[j].NodeWalk2 != NULL) {  //based on algorithm
                if (bigList[j].NodeWalk2->node == bigList[i].NodeHead->node && bigList[i].NodeWalk->node == bigList[j].NodeHead->node) {
                    bigList[j].NodeWalk2->edge = 'B';
                    cout << "(" << bigList[i].NodeWalk->node << "," << bigList[j].NodeWalk2->node << "," << bigList[j].NodeWalk2->edge << ")";
                    bigList[j].NodeWalk2 = bigList[j].NodeWalk2->NextNode; //based on algorithm
                    //cout << "check1" << endl;
                    edge++;
                }
                else if (bigList[j].NodeWalk2->edge == 'A') {
                    
                    if (bigList[i].NodeWalk->node == bigList[j].NodeHead->node) {
                       
                            bigList[j].NodeWalk2->edge = 'F';
                            cout << "(" << bigList[i].NodeHead->node << "," << bigList[j].NodeWalk2->node << "," << bigList[j].NodeWalk2->edge << ")";
                            bigList[j].NodeWalk2 = bigList[j].NodeWalk2->NextNode; //based on algorithm
                        
                    }
                    else {
                        if (run <= numNodes){
                                bigList[j].NodeWalk2->edge = 'T';
                                cout << "(" << bigList[j].NodeHead->node << "," << bigList[j].NodeWalk2->node << "," << bigList[j].NodeWalk2->edge << ")";
                                bigList[j].NodeWalk2 = bigList[j].NodeWalk2->NextNode; //based on algorithm
                                
                        }
                        else {
                            if (bigList[i].NodeWalk->node != bigList[j].NodeHead->node) {
                                bigList[j].NodeWalk2->edge = 'C';
                                cout << "(" << bigList[i].NodeHead->node << "," << bigList[j].NodeWalk2->node << "," << bigList[j].NodeWalk2->edge << ")";
                                bigList[j].NodeWalk2 = bigList[j].NodeWalk2->NextNode; //based on algorithm
                            }
                            
                        }
                    }
                }
                else bigList[j].NodeWalk2 = bigList[j].NodeWalk2->NextNode; //based on algorithm
            }
            bigList[i].NodeWalk = bigList[i].NodeWalk->NextNode;
            run++;
        }
    }

    return edge;
}