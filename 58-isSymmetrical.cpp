/*对称二叉树
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
    /*
    bool isSymmetrical(TreeNode* pRoot)
    {
        TreeNode* tmp=pRoot;
        return help(pRoot,tmp);
    }
    bool help(TreeNode* r1,TreeNode* r2)
    {
        if (r1==nullptr && r2==nullptr)    return true;
        if (r1==nullptr || r2==nullptr)    return false;
        if (r1->val==r2->val)
            return help(r1->left,r2->right)&&help(r1->right,r2->left);
        return false;
    }
    */
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot==nullptr)    return true;
        stack<TreeNode*> s;
        s.push(pRoot->left);
        s.push(pRoot->right);
        while(!s.empty()){
            TreeNode* n1=s.top(); s.pop();
            TreeNode* n2=s.top(); s.pop();
            if (n1==nullptr && n2==nullptr)    continue;
            if (n1==nullptr || n2==nullptr)    return false;
            if (n1->val!=n2->val)    return false;
            s.push(n1->left);
            s.push(n2->right);
            s.push(n1->right);
            s.push(n2->left);
        }
        return true;
    }

};
