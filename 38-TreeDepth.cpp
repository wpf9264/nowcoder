/*二叉树的深度*/
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
    /*
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)    return 0;
            return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
    */
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)    return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int res=0;
        while(!q.empty()){
            res++;
            int num=q.size();
            while(num--){
                TreeNode* node=q.front();
                if (node->left)     q.push(node->left);
                if (node->right)    q.push(node->right);
                q.pop();
            }
        }
        return res;
    }
    
};
