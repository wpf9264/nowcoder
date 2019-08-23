/*二叉树和为某一值的路径*/
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
    vector<vector<int>>  res;
    vector<int> path;
    /*从节点root开始求和expectNumber*/
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root!=nullptr){
            path.push_back(root->val);
            expectNumber-=root->val;
            if (expectNumber==0 && !root->left && !root->right){
                res.push_back(path);
            }
            if (expectNumber!=0){
                FindPath(root->left,expectNumber);
                FindPath(root->right,expectNumber);
            }
            path.pop_back();
        }
        return res;
    }
    
};
