// 133. Clone Graph
// my recurrence method
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
 
 
class Solution {
public:
    unordered_map<int, Node*> map;
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return nullptr;
        }

        auto it = map.find(node -> val);
        Node* ans;
        if (it != map.end()) 
        {
            //找到
            ans = map[node -> val];
        } 
        else 
        {
            //找不到
            ans = new Node(node -> val);
            map[ans -> val] = ans;
        }
 
        
        for (int idx = 0; idx < (node -> neighbors).size(); idx++)
        {
            auto it = map.find(node -> neighbors[idx] -> val);
            if (it != map.end())
            {
                ans -> neighbors.push_back(it -> second);
            }
            else
            {
                Node* add = new Node(node -> neighbors[idx] -> val); 
                ans -> neighbors.push_back(add);
                map[add -> val] = add;
                cloneGraph(node -> neighbors[idx]);
            }
        }
        return ans;
    }

    void show_neighbors(Node* node)
    {
        for (int idx = 0; idx < node -> neighbors.size(); idx++)
        {
            cout << node -> neighbors[idx] -> val << " ";
        }
    }
};
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n4 -> neighbors.push_back(n1);
    n4 -> neighbors.push_back(n3);
    n3 -> neighbors.push_back(n2);
    n3 -> neighbors.push_back(n4);
    n1 -> neighbors.push_back(n2);
    n1 -> neighbors.push_back(n4);
    n2 -> neighbors.push_back(n1);
    n2 -> neighbors.push_back(n3);
    Solution abc;
    Node* test = abc.cloneGraph(n1);
    abc.show_neighbors(test);
    cout << endl;
    cout << test -> neighbors[1] -> val << endl;
    cout << test -> neighbors[1] -> neighbors.size() << endl;
    abc.show_neighbors(test -> neighbors[1]);



 
    return 0;
}