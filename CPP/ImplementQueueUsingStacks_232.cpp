// Difficulty: Easy
// Implement a first in first out (FIFO) queue using only two stacks. The
// implemented queue should support all the functions of a normal queue (push,
// peek, pop, and empty).

// Implement the MyQueue class:
//     void push(int x) Pushes element x to the back of the queue.
//     int pop() Removes the element from the front of the queue and returns it.
//     int peek() Returns the element at the front of the queue.
//     boolean empty() Returns true if the queue is empty, false otherwise.

// Notes:
//     You must use only standard operations of a stack, which means only push
//     to top, peek/pop from top, size, and is empty operations are valid.
//     Depending on your language, the stack may not be supported natively. You
//     may simulate a stack using a list or deque (double-ended queue) as long
//     as you use only a stack's standard operations.

// Example 1:
// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false

// Constraints:
//     1 <= x <= 9
//     At most 100 calls will be made to push, pop, peek, and empty.
//     All the calls to pop and peek are valid.

// Follow-up: Can you implement the queue such that each operation is amortized
// O(1) time complexity? In other words, performing n operations will take
// overall O(n) time even if one of those operations may take longer.

#include <algorithm>
#include <fmt/ranges.h>
#include <iostream>
#include <stack>

// Push O(1), pop & peek O(n)
// class MyQueue {
//   public:
//     void push(int x) { stack.push(x); }

//     int pop() {
//         std::stack<int> temp;
//         while (stack.size() != 1) {
//             temp.push(stack.top());
//             stack.pop();
//         }

//         int result = stack.top();
//         stack.pop();

//         while (!temp.empty()) {
//             stack.push(temp.top());
//             temp.pop();
//         }

//         return result;
//     }

//     int peek() {
//         std::stack<int> temp;
//         while (stack.size() != 1) {
//             temp.push(stack.top());
//             stack.pop();
//         }

//         int result = stack.top();

//         while (!temp.empty()) {
//             stack.push(temp.top());
//             temp.pop();
//         }

//         return result;
//     }

//     bool empty() { return stack.empty(); }

//   private:
//     std::stack<int> stack;
// };

// Push O(n), pop & peek O(1)
class MyQueue {
  public:
    void push(int x) {
        std::stack<int> temp;
        while (!stack.empty()) {
            temp.push(stack.top());
            stack.pop();
        }

        stack.push(x);

        while (!temp.empty()) {
            stack.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int result = stack.top();
        stack.pop();
        return result;
    }

    int peek() { return stack.top(); }

    bool empty() { return stack.empty(); }

  private:
    std::stack<int> stack;
};

int main(int argc, char *argv[]) {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << q.pop() << std::endl;
    q.push(5);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;

    // q.push(1);
    // q.push(2);
    // std::cout << q.peek() << std::endl;
    // std::cout << q.pop() << std::endl;
    // std::cout << q.empty() << std::endl;

    return 0;
}
