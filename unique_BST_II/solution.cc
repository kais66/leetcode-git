#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *> *> trees(n+1, new vector<TreeNode *>());
        TreeNode *nd = NULL;
        trees[0]->push_back(nd);
        cout << "trees_0 size: " << trees[0]->size() << endl;

        if (n > 0) { 
            TreeNode *nd = new TreeNode(1);
            vector<TreeNode *> *v = trees[1];
            //trees[1]->push_back(new TreeNode(1));
            v->push_back(new TreeNode(1));
            //trees[1]->push_back(nd);
        }

        /*
        for (int i=2; i<=n; ++i) {
            for (int j=0; j<=i-1; ++j) {
                for (int m=0; m<trees[j]->size(); ++m) {
                    for (int n=0; n<trees[i-1-j]->size(); ++n) {
                        TreeNode *root = new TreeNode(j+1);
                        root->left = copyTree(trees[j]->at(m), 0);
                        root->right = copyTree(trees[i-1-j]->at(n), j+1);
                        trees[i]->push_back(root);
                    }
                }
            }
        }
        */
        
        cout << " trees_0 size: " << trees[0]->size() << endl;
        cout << " trees_1 size: " << trees[1]->size() << endl;

        vector<TreeNode *> ret = *(trees[n]);
        cout << "here, n: " << n << endl;
        delete (trees[n]);
        trees[n] = NULL;

        cout << "here2" << endl;
        for (int i=0; i<n; ++i) {
            cout << "i: " << i << ", trees_i size: " << trees[i]->size() << endl;
            for (int j=0; j<trees[i]->size(); ++j) {
                cout << "i :" << i << " , j: " << j << endl;
                deleteTree(trees[i]->at(j));
            }
            cout << "here3" << endl;
            delete trees[i];
        }
        return ret;
    }

    TreeNode* copyTree(TreeNode *root, int offset) {
        if (!root) return NULL;
        TreeNode *r2 = new TreeNode(root->val + offset);
        r2->left = copyTree(root->left, offset);
        r2->right = copyTree(root->right, offset);
        return r2;
    }

    void deleteTree(TreeNode *root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    Solution s;
    s.generateTrees(1);
}
