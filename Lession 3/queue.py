from collections import deque

class Dequeue:
    def __init__(self):
        self.elements = deque()
    def add_front(self, element):
        self.elements.appendleft(element)
        print(f"Added {element} to the front")
    def enqueue(self, element):
        self.elements.append(element)
        print(f"Enqueued {element}")
    def dequeue(self):
        if not self.is_empty():
            item = self.elements.popleft()
            print(f"Dequeued {item}")
            return item
        else:
            print("Queue is empty")
            return None
    def peek(self):
        if not self.is_empty():
            return self.elements[0]
        else:
            print("Queue is empty")
            return None
    def is_empty(self):
        return len(self.elements) == 0
    def display(self):
        print(self.elements)
if __name__ == "__main__":
    queue = Dequeue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.enqueue(4)
    queue.display()
    queue.enqueue(5)
    queue.display()
    queue.enqueue(6)
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
    queue.dequeue()
    queue.display()
