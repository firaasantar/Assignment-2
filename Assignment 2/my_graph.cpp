#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cstdio>
#include <map>

using namespace std;

class Graph
{
private:
    map<int, vector<int> > graph;

public:

    /*
    requires: requires 2 vectors of equal size and of type int
    effects: Constructs a Graph with the given set of edges, 
    where starts and ends represent the ordered list of edges’ 
    start and endpoints
    testing strategy: 
    1) passing two emtpy vectors
    2) passing two vectors of different sizes
    3) passing two of vectors of the same size
    */
    Graph(const vector<int> &starts, const vector<int> &ends)
    {
        if (starts.size() != ends.size())
        {
            throw invalid_argument("The two vectors are not the same length.");
        }
        for (int i = 0; i < starts.size(); i++)
        {
            graph[starts[i]].push_back(ends[i]);
        }
    }
    
    /*
    requires: a const integer
    effects: returns the number of outgoing edges from nodeID
    testing strategy: 
    1) passing a nodeID thats is not found
    2) passing a nodeID with 0 outgoing destinations
    */
    int numOutgoing(const int nodeID) const
    {
        if (graph.find(nodeID) == graph.end())
        {
            throw invalid_argument("The nodeID provided does not actually exist in the graph.");
        }
        return graph.at(nodeID).size();
    }

    /*
    requires: a const integer
    effects: Returns a reference to the list of nodes to which 
    nodeID has outgoing edges
    testing strategy: 
    1) passing a nodeID thats is not found
    2) passing a nodeID with 0 outgoing destinations
    */
    const vector<int> &adjacent(const int nodeID) const
    {
        if (graph.find(nodeID) == graph.end())
        {
            throw invalid_argument("The nodeID provided does not actually exist in the graph.");
        }
        return graph.at(nodeID);
    }
};

int main()
{
    vector<int> starts = {0, 0, 0, 4, 4, 3};
    vector<int> ends = {1, 2, 3, 3, 1, 1};
    Graph graph(starts, ends);
    cout << graph.numOutgoing(0) << endl;
    cout << graph.numOutgoing(4) << endl;
    cout << graph.numOutgoing(3) << endl;
    cout << graph.numOutgoing(1) << endl;
    cout << graph.numOutgoing(2) << endl;
    cout << graph.numOutgoing(5) << endl;
    return 0;
}