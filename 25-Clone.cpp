/*复杂链表的复制*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)    return nullptr;
        /*复制所有的节点，将其插在原节点的后面*/
        RandomListNode* p1=pHead;
        while(p1!=nullptr){
            RandomListNode* tmp = new RandomListNode(p1->label);
            tmp->next=p1->next;
            p1->next=tmp;
            p1=p1->next->next;
        }
        /*连接随机节点*/
        p1=pHead;
        while(p1!=nullptr){
            p1->next->random= (p1->random==nullptr)?nullptr:p1->random->next;
            p1=p1->next->next;
        }
        /*拆分*/
        RandomListNode* newHead=pHead->next;
        RandomListNode* p2=newHead;
        p1=pHead;
        while(p1){
            p1->next=p1->next->next;
            p2->next=(p1->next==nullptr)?nullptr:p1->next->next;
            p2=p2->next;
            p1=p1->next;
        }
        return newHead;
    }
};
