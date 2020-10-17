class Queue:
    front = -1
    rear = 0
    array = []
    def __init__(self,data):
        self.front += 1
        self.rear += 1
        self.array.append(data)
    
    def enqueue(self,data):
        self.array.append(data)
        self.rear += 1

    def dequeue(self):
        self.front += 1
       

    def traverse(self):
        
        for i in range(self.front,self.rear):
            print(self.array[i])

q = Queue(12)
q.enqueue(54545)
q.enqueue(5454)
q.enqueue(545)

q.traverse()

