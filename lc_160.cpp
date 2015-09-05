#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        if (headA == headB) return headA;
        ListNode *res = init(headA, headB);
        if (res) return res;
        if (!isIntersect(headA, headB)) res = NULL;
        else res = findIntersect(headA);
        restore(headA, headB);
        return res;
    }
    
    ListNode *init(ListNode *headA, ListNode *headB)
    {
        ListNode * node = headA;
        while(node->next) node = node->next;
        if (node == headB) return node;
        else node->next = headB;
        last_node = node;
        return NULL;
    }
    
    void restore(ListNode *headA, ListNode *headB)
    {
        last_node->next = NULL;
//        ListNode * node = headA;
//        while(node->next != headB) node = node->next;
//        node->next = NULL;
    }
    
    bool isIntersect(ListNode *headA, ListNode *headB)
    {
        ListNode * node = headB->next;
        while (node)
        {
            if (node == headB) return true;
            node = node->next;
        }
        return false;
    }
    
    ListNode *findIntersect(ListNode* head)
    {
        ListNode *slow, *fast;
        slow = head->next;
        fast = head->next->next;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    
private:
    ListNode * last_node;
};

int main()
{
    struct ListNode* A = new ListNode(3);
    struct ListNode* B = new ListNode(2);
    B->next = A;
    Solution slt;
    cout << slt.getIntersectionNode(A, B)->val << endl;
    return 0;
}
