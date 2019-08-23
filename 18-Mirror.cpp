/*二叉树的镜像*/
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot==nullptr || (!pRoot->left && !pRoot->right))
            return;
        std::swap(pRoot->left,pRoot->right);
        if (pRoot->left)    Mirror(pRoot->left);
        if (pRoot->right)    Mirror(pRoot->right);
    }
};
