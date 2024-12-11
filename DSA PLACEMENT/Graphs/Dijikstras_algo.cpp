#include <bits/stdc++.h>
using namespace std;
vector<int> dijikstras(vector<vector<int>> &vec, int vertex, int edge, int src) // vec kya hai bhai?
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edge; i++)
    {
        int node1 = vec[i][0];
        int node2 = vec[i][1];
        int w = vec[i][2];

        adj[node1].push_back(make_pair(node2, w));
        adj[node2].push_back(make_pair(node1, w));
    }

    vector<int> dist(vertex); // distance vector banaya
    for (int i = 0; i < vertex; i++)
    {
        dist[i] = INT_MAX; // infinity se mark kar diya
    }
    set<pair<int, int>> st;       // set banaya
    dist[src] = 0;                // source ko dist ko zero kiya
    st.insert(make_pair(0, src)); // set mai daal diya
    while (!st.empty())
    {
        auto top = *(st.begin()); // set ka top eleemnt nikal liya
        int nodedis = top.first;  // segregation
        int topnode = top.second;

        // select kar liya to hatana ahai selected ko set se
        st.erase(st.begin());

        // traverse neighbour
        for (auto neigh : adj[topnode])
        {
            if (nodedis + neigh.second < dist[neigh.first]) // jis node pe hoon uska weight +dusre node[neigh.second] k beech ka weight agar mere predefined node[dist[node.first]] k dist se kam hai
            {
                auto record = st.find(make_pair(dist[neigh.first], neigh.first)); //-?matlab?
                if (record != st.end())
                {
                    st.erase(record);
                }

                // min distance ko update karo
                dist[neigh.first] = nodedis + neigh.second;
                // abhi min distance ko set mai daal diya
                st.insert(make_pair(dist[neigh.first], neigh.first));
            }
        }
    }
    return dist;//apna vector return kar diya
}
int main()
{
    int vertex = 4; // example vertex count
    int edges = 5;  // example edge count
    vector<vector<int>> vec = {
        {0, 1, 5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2}, {2, 3, 6}}; // example edges with weights

    int src = 0; // source node
    vector<int> result = dijikstras(vec, vertex, edges, src);

    cout << "Shortest distances from source " << src << " are:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << " : " << result[i] << endl;
    }

    return 0;
}

// Shortest distances from source 0 are:
// Node 0 : 0
// Node 1 : 5
// Node 2 : 8
// Node 3 : 7