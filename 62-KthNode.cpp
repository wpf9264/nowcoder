/*
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        stack<TreeNode*> s;
        int i=0;
        TreeNode* node=pRoot;
        while(!s.empty() || node!=nullptr){
            while(node!=nullptr){
                s.push(node);
                node=node->left;
            }
            TreeNode* tmp=s.top();
            s.pop();
            i++;
            if (i==k)
                return tmp;
            node=tmp->right;
        }
        return nullptr;
    }
    */
	/*在没找到目标是,返回的是nullptr*/
    int count=0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot){
            TreeNode* res=KthNode(pRoot->left,k);
            if (res)
                return res;
            if (++count==k)
                return pRoot;
            res=KthNode(pRoot->right,k);
            if (res)
                return res;
        }
        return nullptr;
    }

    
};
