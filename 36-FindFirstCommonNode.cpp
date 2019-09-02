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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        while(p1!=p2){
            /*必须要走到nullptr,否则对于没有交点的两个链表会死循环*/
            p1=p1==nullptr?pHead2:p1->next;
            p2=p2==nullptr?pHead1:p2->next;
        }
        return p1;
    }
};
