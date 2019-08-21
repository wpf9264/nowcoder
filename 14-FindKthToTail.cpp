/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*链表中倒数第k个结点*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* pNode= pListHead;
        while(k>0 && pNode!=nullptr){
            pNode=pNode->next;
            k--;
        }
        if (k>0)    return nullptr;
        while(pNode!=nullptr){
            pNode=pNode->next;
            pListHead=pListHead->next;
        }
        return pListHead;
    }
};
