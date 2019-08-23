/*树的子结构*/
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        /*  1.输入为空，返回false
            2.遍历A，找到与B根节点相等的位置
            3.结点数值相同，在接着判断B的左右子树是不是也属于A
        */
        bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL)
        {
            //主函数用于遍历TreeA，找到与TreeB根节点相等的结点
            if(pRoot1->val == pRoot2->val)
                result = help(pRoot1,pRoot2);
            //如果找不到，那么就再去root的左儿子当作起点，去判断时候包含Tree2
            if(!result)
                result = HasSubtree(pRoot1->left,pRoot2);
            //如果还找不到，那么就再去root的右儿子当作起点，去判断时候包含Tree2
            if(!result)
                result = HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    bool help(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //子函数用于递归判断TreeB的左右子树是否也属于TreeA某节点的相应子树
        //如果Tree2已经遍历完了都能对应的上，返回true
        if(pRoot2 == NULL)
            return true;
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if(pRoot1 == NULL)
            return false;
        //如果其中有一个点没有对应上，返回false
        if (pRoot1->val != pRoot2->val) 
            return false;
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return  help(pRoot1->left,pRoot2->left) && 
                help(pRoot1->right,pRoot2->right);
    }
};
