import sys
sys.stdout.reconfigure(encoding='utf-8')
class Stack:
    def __init__(self):
        self.elements = []
    def push(self, element):
        self.elements.append(element)
        print(f"Pushed {element}")  
    def pop(self):
        if not self.is_empty():
            item = self.elements.pop() 
            print(f"Popped {self.elements.pop()}")
            return item
        else:
            print("Stack is empty")
            return None
    def peek(self):
        if not self.is_empty():
            return self.elements[-1]
        else:
            print("Stack is empty")
            return None 
    def is_empty(self):
        return len(self.elements) == 0
    def size(self):
        return len(self.elements) 
    def display(self):
        print(self.elements)
if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.push(4)
    stack.display()
    stack.push(5)
    stack.display()
    stack.push(6)
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()
    stack.pop()
    stack.display()