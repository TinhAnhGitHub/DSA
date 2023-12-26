class MyQueue:

    def __init__(self):
        self.stack = []
        self.tmp = []

    def push(self, x: int) -> None:
        self.stack.append(x)

    def pop(self) -> int:
        ans = self.stack[0]
        while len(self.stack) >1:
            self.tmp.append(self.stack.pop())
        self.stack.pop()
        while self.tmp:
            self.stack.append(self.tmp.pop())
        return ans

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return not len(self.stack)

obj = MyQueue()
obj.push(1)
obj.push(2)
obj.peek()
obj.pop()
obj.empty()
