/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
public class Solution {
    public ListNode partition(ListNode head, int x) {
        // Create dummy heads for the two partitions
        ListNode beforeHead = new ListNode(0);
        ListNode before = beforeHead;
        
        ListNode afterHead = new ListNode(0);
        ListNode after = afterHead;
        
        // Traverse the original list
        ListNode curr = head;
        while (curr != null) {
            if (curr.val < x) {
                before.next = curr;
                before = before.next;
            } else {
                after.next = curr;
                after = after.next;
            }
            curr = curr.next;
        }
        
        // Important: Terminate the 'after' list to avoid a cycle
        after.next = null;
        
        // Connect the 'before' list tail to the 'after' list head
        before.next = afterHead.next;
        
        return beforeHead.next;
    }
}