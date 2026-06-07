class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> child;

        for (auto &d : descriptions) {
            int parent = d[0];
            int node = d[1];
            int isLeft = d[2];

            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            if (!nodes.count(node))
                nodes[node] = new TreeNode(node);

            if (isLeft)
                nodes[parent]->left = nodes[node];
            else
                nodes[parent]->right = nodes[node];

            child[node]++;
        }

        for (auto &d : descriptions) {
            if (!child.count(d[0]))
                return nodes[d[0]];
        }

        return nullptr;
    }
};