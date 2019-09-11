/*
序列化二叉树
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
    vector<int> buffer;
    void dfs(TreeNode* p)
    {
        if (!p)
            buffer.push_back(INT_MAX);
        else{
            buffer.push_back(p->val);
            dfs(p->left);
            dfs(p->right);
        }
    }
    char* Serialize(TreeNode *root) {
        buffer.clear();
        dfs(root);
        int *p=new int[buffer.size()];
        for(unsigned int i=0; i<buffer.size(); ++i)
            p[i]=buffer[i];
        return (char*)p;
    }
    
    TreeNode* help(int*& p)
    {
        if (*p==INT_MAX){
            p++;
            return NULL;
        }
        TreeNode *res=new TreeNode(*p);
        ++p;
        res->left=help(p);
        res->right=help(p);
        return res;
    }
    TreeNode* Deserialize(char *str) {
        int *p=(int*)str;
        return help(p);
    }
};
