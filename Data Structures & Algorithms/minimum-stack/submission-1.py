class MinStack:

    def __init__(self):
        self.mn = float('inf')
        self.arr = []

    def push(self, val: int) -> None:
        self.mn = min(self.mn,val)
        self.arr.append((val,self.mn))

    def pop(self) -> None:
        self.arr.pop()
        if self.arr:
            self.mn = self.arr[-1][1]
        else:
            self.mn = float('inf')

    def top(self) -> int:
        return self.arr[-1][0]

    def getMin(self) -> int:
        return self.mn
