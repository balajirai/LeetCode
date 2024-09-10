class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *currNode = head, *nextNode = head->next;
        while(currNode != NULL && nextNode != NULL){
            int a = currNode->val, b = nextNode->val;
            ListNode* gcdNode = new ListNode(__gcd(a,b));
            currNode->next = gcdNode, gcdNode->next = nextNode;
            currNode = nextNode, nextNode = nextNode->next;
        }
        return head;
    }
};