/*
 *Name: Travis Allan
 *Date: 7/27/2014
 *Course: CSCE 2110
 *Title: Program 4
 *Description: DFS Program
 */

class Graph {
protected:
    
public:
    //int i;
    int postArray[15];
    int space;
    
    int BuildGraph(int tempNode1, int tempNode2, int tempWeight);
    int InitializeGraph(int numNodes);
    void PrintGraph(int numNodes);
    int RemoveGraph(int tempNode1, int tempNode2, int numNodes);
    void SortGraph();
    
    //DFS
    int DFS(int nodeStart, int numNodes, int toggle);
    int Postorder(int numNodes, int key, int runCount);
    int EdgeType(int numNodes);
    
    //array of head nodes
    List bigList[15];
    
};
