/*二叉树层序遍历*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root){
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left)    q.push(node->left);
                if (node->right)    q.push(node->right);
            }
        }
        return res;
    }
};
