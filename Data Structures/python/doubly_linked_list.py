class Node:
    def __init__(self,data):
        self.data = data
        self.nextNode = None
        self.prevNode = None

class Doubly_linked_list:
    head = None
    tail = None
    def __init__(self,data):
        new_node = Node(data)
        self.head = new_node
        self.tail = new_node
    def insert_at_front(self,data):
        new_node = Node(data)
        if self.head is None:
            new_node.nextNode = None
            self.head = new_node
            self.tail = new_node
            return
        
        new_node.nextNode = self.head
        self.head.prevNode = new_node
        self.head = new_node

    def insert_at_last(self,data):
        new_node = Node(data)
        if self.head is None:
            new_node.nextNode = None
            self.head = new_node
            self.tail = new_node
            return
        new_node.prevNode = self.tail
        self.tail.nextNode = new_node
        self.tail = new_node

    def delete_at_front(self):
        temp = self.head
        self.head.nextNode.prevNode = None
        self.head = self.head.nextNode
        del temp

    def delete_at_last(self):
        temp = self.tail
        self.tail.prevNode.nextNode = None
        self.tail = self.tail.prevNode
        del temp

    def print_forward(self):
        temp = self.head
        while temp is not None:
            print(temp.data) 
            temp = temp.nextNode
        
if __name__ == "__main__":
    dll = Doubly_linked_list(12)
    dll.insert_at_front(1)
    dll.insert_at_last(100)
    dll.insert_at_last(200)
    dll.insert_at_front(250)
    dll.delete_at_front()
    dll.delete_at_front()
    dll.insert_at_front(250)
    dll.delete_at_last()
    dll.print_forward()