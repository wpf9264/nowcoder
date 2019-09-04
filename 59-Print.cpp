/*
 * 之字序打印二叉树
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot==nullptr)    return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        bool isRight=false;
        while(!q.empty()){
            int num=q.size();
            vector<int> tmp;
            for(int i=0; i<num; ++i){
                TreeNode* node = q.front();
                if(node->left!=nullptr)     q.push(node->left);
                if(node->right!=nullptr)    q.push(node->right);
                q.pop();
                tmp.push_back(node->val);
            }
            if (isRight)    reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            isRight=isRight?false:true;
        }
        return res;
    }
    */
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot==nullptr)    return res;
        stack<TreeNode*> s;
        queue<TreeNode*> q;//用与对该层节点排序,
        bool isRight=true;//标示下一次需要从右往左
        q.push(pRoot);
        while(!q.empty()){
            int num=q.size();
            vector<int> tmp;
            for(int i=0; i<num; ++i){
                TreeNode* node=q.front();
                tmp.push_back(node->val);
                q.pop();
                if (isRight){
                    if(node->left!=nullptr)     s.push(node->left);
                    if(node->right!=nullptr)    s.push(node->right);
                }else{
                    if(node->right!=nullptr)    s.push(node->right);
                    if(node->left!=nullptr)     s.push(node->left);
                }
            }
            while(!s.empty()){
                q.push(s.top());
                s.pop();
            }
            isRight=isRight?false:true;
            res.push_back(tmp);
        }
        return res;
    }
    
};
