#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    Node(int weight, int from, int to)
    : _weight(weight), _from(from), _to(to) {}

    int _weight;
    int _from;
    int _to;
};

int
main(void)
{
    Node node1(1, 1, 1);
    Node node2(1, 2, 3);
    vector<Node &> nodes;
    nodes.push_back(node1);

    return 0;
}