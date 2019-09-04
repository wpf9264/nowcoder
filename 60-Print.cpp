/*层序遍历
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            queue<TreeNode*> q;
            vector<vector<int>> res;
            if (pRoot==nullptr)    return res;
            q.push(pRoot);
            while(!q.empty()){
                int num=q.size();
                vector<int>tmp;
                for(int i=0; i<num; ++i){
                    TreeNode* node=q.front();
                    q.pop();
                    tmp.push_back(node->val);
                    if (node->left)    q.push(node->left);
                    if (node->right)    q.push(node->right);
                }
                res.push_back(tmp);
            }
            return res;
        }
    
};
