/*
 * 构造图
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph
{
public:
    class Edge;
    class Node
    {
    public:
        Node(int value)
        : _value(value), _in(0), _out(0)
        {}

        int _value;
        int _in; // 该点的入度
        int _out; // 该点的出度
        vector<Node *> _nexts; // 与该点直接相连的结点
        vector<Edge *> _edges; // 与该点直接相接的边
    };

    class Edge
    {
    public:
        Edge(int weight, Node * from, Node * to)
        : _weight(weight), _from(from), _to(to) {}
        int _weight;
        Node * _from;
        Node * _to;
    };

    unordered_map<int, Node *> nodes;
    unordered_set<Edge *> edges;

    // 构造函数，根据传入的matrix生成图，matrix中为二维数组，其中的一个数组表示边的weight，from，to
    Graph(const vector<vector<int>> & matrix)
    {
        for (int i = 0; i < matrix.size(); i++) {
            int weight = matrix[i][0];
            int from = matrix[i][1];
            int to = matrix[i][2];

            if (nodes.find(from) == nodes.end()) {
                nodes[from] = new Node(from);
            }
            if (nodes.find(to) == nodes.end()) {
                nodes[to] = new Node(to);
            }
            Node * fromNode = nodes[from];
            Node * toNode = nodes[to];
            Edge * newEdge = new Edge(weight, fromNode, toNode);
            fromNode->_nexts.push_back(toNode);
            fromNode->_out++;
            toNode->_in++;
            fromNode->_edges.push_back(newEdge);
            edges.insert(newEdge);
        }
    }
    ~Graph()
    {
        // edges.erase();
    }

    Node * getNode(int value)
    {
        Node * node = nodes[value];
        return node;
    }

    // 广度优先遍历
    void BFS(Node * node)
    {
        cout << "fore: " << endl;
        for (auto elem : nodes) {
            cout << elem.first << " ";
        }
        cout << endl;

        if (!node) return;
        queue<Node *> helpQue;
        unordered_set<Node *> markSet;
        helpQue.push(node);
        markSet.insert(node);

        while (!helpQue.empty()) {
            Node * cur = helpQue.front();
            helpQue.pop();
            cout << "while: " << cur->_value << endl;
            cout << cur->_value << endl;
            for (auto elem : node->_nexts) {
                cout << "for: " << elem->_value << endl;
                if (markSet.find(elem) == markSet.end()) {
                    helpQue.push(elem);
                    markSet.insert(elem);
                }
            }
        }
    }

    // 深度优先遍历
    void DFS(Node * node)
    {
        cout << node->_value << endl;
        _markSet.insert(node);
        for (auto elem : node->_nexts) {
            if (_markSet.find(elem) == _markSet.end()) {
                DFS(elem);
            }
        }
    }
    unordered_set<Node *> _markSet;
};


int
main(void)
{
    vector<vector<int>> matrix{{1, 1, 2}, {3, 1, 4}, {4, 1, 3},
                            {1, 2, 1}, {2, 2, 4},
                            {4, 3, 1}, {8, 3, 4}, {5, 3, 5},
                            {2, 4, 2}, {3, 4, 1}, {8, 4, 3}, {6, 4, 5},
                            {5, 5, 3}, {6, 5, 4}};
    Graph graph(matrix);
    Graph::Node * node = graph.getNode(1);

    cout << "BFS: " << endl;
    graph.BFS(node);

    cout << "DFS:" << endl;
    graph.DFS(node);
    return 0;
}