// 641. Design Circular Deque
// Difficulty: Medium

// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

//     MyCircularDeque(int k) Initializes the deque with a maximum size of k.
//     boolean insertFront() Adds an item at the front of Deque. Returns true if
//     the operation is successful, or false otherwise. boolean insertLast()
//     Adds an item at the rear of Deque. Returns true if the operation is
//     successful, or false otherwise. boolean deleteFront() Deletes an item
//     from the front of Deque. Returns true if the operation is successful, or
//     false otherwise. boolean deleteLast() Deletes an item from the rear of
//     Deque. Returns true if the operation is successful, or false otherwise.
//     int getFront() Returns the front item from the Deque. Returns -1 if the
//     deque is empty. int getRear() Returns the last item from Deque. Returns
//     -1 if the deque is empty. boolean isEmpty() Returns true if the deque is
//     empty, or false otherwise. boolean isFull() Returns true if the deque is
//     full, or false otherwise.

// Example 1:

// Input
// ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront",
// "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
// [[3], [1], [2], [3], [4], [], [], [], [4], []]
// Output
// [null, true, true, true, false, 2, true, true, true, 4]

// Explanation
// MyCircularDeque myCircularDeque = new MyCircularDeque(3);
// myCircularDeque.insertLast(1);  // return True
// myCircularDeque.insertLast(2);  // return True
// myCircularDeque.insertFront(3); // return True
// myCircularDeque.insertFront(4); // return False, the queue is full.
// myCircularDeque.getRear();      // return 2
// myCircularDeque.isFull();       // return True
// myCircularDeque.deleteLast();   // return True
// myCircularDeque.insertFront(4); // return True
// myCircularDeque.getFront();     // return 4

// Constraints:

//     1 <= k <= 1000
//     0 <= value <= 1000
//     At most 2000 calls will be made to insertFront, insertLast, deleteFront,
//     deleteLast, getFront, getRear, isEmpty, isFull.

#include <algorithm>
#include <fmt/ranges.h>
#include <vector>

class MyCircularDeque {
    int elems[1000];
    int k, front, back, len;

  public:
    MyCircularDeque(int k) : k(k), front(0), back(k - 1), len(0) {}

    bool insertFront(int value) {
        if (len == k) {
            return false;
        }
        front        = (front == 0) ? k - 1 : front - 1;
        elems[front] = value;
        len++;
        return true;
    }

    bool insertLast(int value) {
        if (len == k) {
            return false;
        }
        back        = (back == k - 1) ? 0 : back + 1;
        elems[back] = value;
        len++;
        return true;
    }

    bool deleteFront() {
        if (len == 0) {
            return false;
        }
        front = (front == k - 1) ? 0 : front + 1;
        len--;
        return true;
    }

    bool deleteLast() {
        if (len == 0) {
            return false;
        }
        back = (back == 0) ? k - 1 : back - 1;
        len--;
        return true;
    }

    int getFront() { return len == 0 ? -1 : elems[front]; }

    int getRear() { return len == 0 ? -1 : elems[back]; }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == k; }
};

int main(int argc, char *argv[]) {}
