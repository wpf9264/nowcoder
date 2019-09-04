/*二叉树的下一个节点
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode==nullptr)    return nullptr;
        /*先判断孩子*/
        if (pNode->right!=nullptr){
            pNode=pNode->right;
            while(pNode->left!=nullptr){
                pNode=pNode->left;
            }
            return pNode;
        }
        /*再判断父亲*/
        while(pNode->next!=nullptr){
            if (pNode==pNode->next->left)
                return pNode->next;
            pNode=pNode->next;
        }
        return nullptr;
    }
};
