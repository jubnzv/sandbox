# Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
#
#     push(x) -- Push element x onto stack.
#     pop() -- Removes the element on top of the stack.
#     top() -- Get the top element.
#     getMin() -- Retrieve the minimum element in the stack.
#
# Example:
#
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
import bisect


class MinStack:

    def __init__(self):
        self._values = []
        self._sorted_values = []

    def push(self, x: int) -> None:
        self._values.append(x)
        bisect.insort(self._sorted_values, x)

    def pop(self) -> None:
        self._sorted_values.remove(self._values[-1])
        self._values = self._values[:-1]

    def top(self) -> int:
        return self._values[-1]

    def getMin(self) -> int:
        return self._sorted_values[0]
