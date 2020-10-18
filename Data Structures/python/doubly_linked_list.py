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

    def insert_at_position(self,position,data):
        if position == 0:
            return self.insert_at_front(data)
        if self.head is None:
            return "List is already empty"
        new_node = Node(data)
        current_node = self.head
        for i in range(position):
            if current_node == self.tail:
                return "List does not have index!"
            current_node = current_node.nextNode
        
        new_node.nextNode = current_node.nextNode
        new_node.prevNode = current_node

        current_node.nextNode = new_node


          


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

    def delete_at_position(self,position):
        if self.head is None:
            return "List is already empty!"
        current = self.head
        
        for i in range(position):

            current = current.nextNode
        
        current.prevNode.nextNode = current.nextNode
        current.nextNode.prevNode = current.prevNode

        del current


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
    dll.insert_at_position(3,3)
    dll.delete_at_position(3)
    dll.print_forward()