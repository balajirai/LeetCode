class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> listParts(k, nullptr);
        // calculting the length of the linked list
        int len = 0;
        for(ListNode* temp=head; temp; temp=temp->next){
            len++;
        }
        // minimum parts size and extra nodes
        int n = len/k;
        int r = len%k;

        ListNode* node = head;
        ListNode* prev = nullptr;

        int i=0;
        while(i<k && node!=NULL){
            listParts[i]=node;
            int j=0;
            while(j < n + (r>0)){
                prev = node;
                node = node->next;
                j++;
            }
            // breaking the part of linked list
            prev->next = NULL;
            i++, r--;
        }
        return listParts;
    }
};