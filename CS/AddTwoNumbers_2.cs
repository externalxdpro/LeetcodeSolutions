namespace LeetcodeSolutions
{
    // Difficulty: Medium
    // You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    // You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    // Example 1:
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    // Explanation: 342 + 465 = 807.

    // Example 2:
    // Input: l1 = [0], l2 = [0]
    // Output: [0]

    // Example 3:
    // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]
    
    // Constraints:
    // The number of nodes in each linked list is in the range [1, 100].
    // 0 <= Node.val <= 9
    // It is guaranteed that the list represents a number that does not have leading zeros.

    public class AddTwoNumbers_2
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode counter1 = l1, counter2 = l2;
            int count1 = 0, count2 = 0;

            while (counter1 != null)
            {
                count1++;
                counter1 = counter1.next;
            }
            while (counter2 != null)
            {
                count2++;
                counter2 = counter2.next;
            }

            ListNode p1 = l1, p2 = l2;

            if (count1 >= count2)
            {
                if (p1.next == null)
                {
                    p1.val += p2.val;

                    if (p1.val >= 10)
                    {
                        ListNode newNode = new ListNode(1);
                        p1.next = newNode;
                        p1.val -= 10;
                    }
                }
                else
                {
                    while (p1 != null)
                    {
                        if (p2 != null) p1.val += p2.val;

                        if (p1.val >= 10)
                        {
                            if (p1.next == null)
                            {
                                ListNode newNode = new ListNode(1);
                                p1.next = newNode;
                            }
                            else
                            {
                                p1.next.val++;
                            }

                            p1.val -= 10;
                        }

                        p1 = p1.next;
                        if (p2 != null) p2 = p2.next;
                    }
                }

                return l1;
            }
            else
            {
                if (p2.next == null)
                {
                    p2.val += p1.val;

                    if (p2.val >= 10)
                    {
                        ListNode newNode = new ListNode(1);
                        p2.next = newNode;
                        p2.val -= 10;
                    }
                }
                else
                {
                    while (p2 != null)
                    {
                        if (p1 != null) p2.val += p1.val;

                        if (p2.val >= 10)
                        {
                            if (p2.next == null)
                            {
                                ListNode newNode = new ListNode(1);
                                p2.next = newNode;
                            }
                            else
                            {
                                p2.next.val++;
                            }

                            p2.val -= 10;
                        }

                        p2 = p2.next;
                        if (p1 != null) p1 = p1.next;
                    }
                }

                return l2;
            }
        }
    }
}