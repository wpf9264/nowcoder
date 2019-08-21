/*从头到尾打印链表*/
/*
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> res;
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head!=nullptr){
            printListFromTailToHead(head->next);
            res.push_back(head->val);
        }
        return res;
    }
};
