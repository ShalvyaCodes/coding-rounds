/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        
        // Phase 1: Detect if cycle exists and find the meeting point
        boolean hasCycle = false;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        
        // If no cycle, return null
        if (!hasCycle) {
            return null;
        }
        
        // Phase 2: Find the entry node of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next; // Both move 1 step at a time
        }
        
        return slow; // Points to the start of the cycle
    }
}