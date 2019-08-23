/*二叉搜索树与双向链表*/
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> s;
        TreeNode* head=nullptr;
        TreeNode* cur=pRootOfTree;
        TreeNode* pre=nullptr;
        while(!s.empty() || cur){
            if (!s.empty()){
                cur=s.top();
                if (pre!=nullptr){
                    pre->right=cur;    //与上次出栈的节点建立连接
                    cur->left=pre;
                }
                if (head==nullptr)    //记录第一次出栈的节点,就是头结点
                    head=cur;
                s.pop();
                pre=cur;              //记录最后出栈的节点
                cur=cur->right;
            }
            while(cur!=nullptr){
                s.push(cur);
                cur=cur->left;
            }
        }
        return head;
    }
};


class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        //左边已经转换为双链表的最后一个结点，用于和自身连接
        TreeNode* lastNode = NULL;
        convertNode(pRootOfTree,&lastNode);
        //现在需要找到该双向链表的头节点
        TreeNode* pHead = lastNode;
        while(pHead->left)
            pHead = pHead->left;
        return pHead;
    }
    void convertNode(TreeNode* pNode,TreeNode** lastNode)
    {
        if(pNode == NULL)
            return;
        TreeNode* pCur = pNode;
        //建立与左侧结点的双向链接
        if(pCur->left != NULL)
            convertNode(pCur->left,lastNode);
        pCur->left = *lastNode;
        if(*lastNode != NULL)
            (*lastNode)->right = pCur;
        //此时当前结点已经加入了有序链表中，因此当前结点变为最后一个结点
        *lastNode = pCur;
        //建立与右侧结点的双向连接
        if(pCur->right != NULL)
            convertNode(pCur->right,lastNode);
    }
};


