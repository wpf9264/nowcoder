/*
删除链表中重复的节点
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* dump = new ListNode(0);
        dump->next=pHead;
        ListNode* tail=dump;
        ListNode* cur=pHead;
        
        while(cur!=nullptr && cur->next!=nullptr){
            if (cur->val==cur->next->val){
                int val=cur->val;
                while(cur!=nullptr && cur->val==val)
                    cur=cur->next;
                //跳过重复节点,将前面已经确认不重复的tail接上后边的部分,再对接上来的部分进行判断
                tail->next=cur;
            }else{
                tail=cur;
                cur=cur->next;
            }
        }
        return dump->next;
    }
};
