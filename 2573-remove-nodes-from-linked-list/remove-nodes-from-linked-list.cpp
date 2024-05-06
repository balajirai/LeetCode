class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>st;
        ListNode* curr = head;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }

        curr = st.top();
        st.pop();
        int maxNode = curr->val;
        ListNode* resultHead = new ListNode(curr->val);

        while(!st.empty()){
            curr = st.top();
            st.pop();
            if(curr->val >= maxNode){
                ListNode* newNode = new ListNode(curr->val);
                newNode->next = resultHead;
                resultHead = newNode;
                maxNode = curr->val;
            }
        }
        
        return resultHead;
    }
};