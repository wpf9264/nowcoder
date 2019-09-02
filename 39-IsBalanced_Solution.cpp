/*判断是否是平衡二叉树*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return depth(pRoot)!=-1;
    }
    /*如果是平衡树就返回最大深度,不是就返回-1*/
    int depth(TreeNode* node)
    {
        if (!node)    return 0;
        int left=depth(node->left);
        if (left==-1)    return -1;
        int right=depth(node->right);
        if (right==-1)    return -1;
        return abs(left-right)>1?-1:max(left,right)+1;
    }
};
