struct Node {
    double value;
    Node* parent;
    Node() : parent(this) {}
    Node(double v) : value(v), parent(this) {}
};

class Solution {
    unordered_map<string, Node*> m;

    Node* find(Node* n) {
        if (n->parent != n) {
            n->parent = find(n->parent);
        }
        return n->parent;
    }
   
    void merge(Node* n1, Node* n2, double val) {
        Node* p1 = find(n1);
        Node* p2 = find(n2);
        double ratio = n2->value * val / n1->value;
        for (auto it : m) {
            if (find(it.second) == p1) {
                it.second->value *= ratio;
            }
        } 
        p1->parent = p2;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (m.find(a) == m.end()) m[a] = new Node(values[i]);
            if (m.find(b) == m.end()) m[b] = new Node(1.0);
            merge(m[a], m[b], values[i]);
        }
        vector<double> res;
        for (auto q : queries) {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end() || find(m[q[0]]) != find(m[q[1]])) {
                res.push_back(-1);
            } else {
                res.push_back(m[q[0]]->value / m[q[1]]->value);
            }
        }
        return res;
    }
};