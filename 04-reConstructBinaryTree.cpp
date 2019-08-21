/*重建二叉树*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty())    return nullptr;
        return help(pre.begin(),pre.end()-1,vin.begin(),vin.end()-1);
    }
    /*返回前序[ps,pe],中序[vs,ve]范围内的数组所构造的二叉树根节点*/
    typedef vector<int>::iterator Iter;
    TreeNode* help(Iter ps, Iter pe, Iter vs, Iter ve)
    {
        if (ps>pe || vs>ve)    return nullptr;
        /*前序的第一个值为根节点*/
        TreeNode* root=new TreeNode(*ps);
        Iter tmp=vs;
        while(tmp<=ve){
            if (*ps==*tmp){
                /*切记迭代器之间不能相加,要加括号*/
                root->left =help(ps+1,ps+(tmp-vs),vs,tmp-1);
                root->right=help(ps+(tmp-vs)+1,pe,tmp+1,ve);
                break;
            }
            tmp++;
        }
        return root;
    }
};
