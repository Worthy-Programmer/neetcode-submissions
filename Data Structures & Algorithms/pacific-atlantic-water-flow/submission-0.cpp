/*
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
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        unordered_map <Node*, Node*> old_new_nodes;
        return dfs(node, old_new_nodes);
        
    }

private:
    Node* dfs(Node* node,unordered_map <Node*, Node*> &old_new_nodes ) {
        if(node == nullptr) return nullptr;

        if (old_new_nodes.contains(node)) return old_new_nodes[node]; // Return already made nodes
        Node*  new_node = new Node(node->val);
        old_new_nodes[node] = new_node; // Always mark parent visited before branching
        for (auto neigh: node->neighbors) {
            new_node->neighbors.push_back(dfs(neigh, old_new_nodes));
        }

        return new_node;   
    }
};
