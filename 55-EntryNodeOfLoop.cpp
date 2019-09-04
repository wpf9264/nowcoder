/*链表中环的入口节点*/
/*
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* p1=pHead;
        ListNode* p2=pHead;
        while(p2!=nullptr && p2->next!=nullptr){
            p1=p1->next;
            p2=p2->next->next;
            if (p1==p2){
                p1=pHead;
                while(p1!=p2){
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1;
            }
        }
        return nullptr;
    }
};
