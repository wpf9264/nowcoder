/*合并两个有序链表*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    /*返回合并后的头结点,该问题可以化简为子问题,递归 */
    /*
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1==nullptr)    return pHead2;
        if (pHead2==nullptr)    return pHead1;
        ListNode* head=nullptr;
        if (pHead1->val<=pHead2->val){
            head=pHead1;
            head->next=Merge(pHead1->next,pHead2);
        }else{
            head=pHead2;
            head->next=Merge(pHead1,pHead2->next);
        }
        return head;
    }
    */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1==nullptr)    return pHead2;
        if (pHead2==nullptr)    return pHead1;
        ListNode* pre1,*cur1,*pre2,*cur2;
        pre1=cur1=pHead1;
        pre2=cur2=pHead2;
        while(cur1 && cur2){
            if (cur1->val>cur2->val){
                pre1->next=cur2;
                while(cur2 && cur2->val<cur1->val){
                    pre2=cur2;
                    cur2=cur2->next;
                }
                pre2->next=cur1;
            }else{
                pre1=cur1;
                cur1=cur1->next;
            }
        }
        if (cur1==nullptr)    pre1->next=cur2;
        if (cur2==nullptr)    pre2->next=cur1;
        return pHead1;
    }    
};
