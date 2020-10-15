class Node:
    def __init__(self,data):
        self.data = data
        self.nextNode = None

class Single_circular_linked_list:
    first_node = None
    def __init__(self,data):
        new_node = Node(data)
        self.first_node = new_node
        new_node.nextNode = self.first_node
    
    def insert_at_last(self,data):
        new_node = Node(data)
        if self.first_node is None:
            self.first_node = new_node
            new_node.nextNode = self.first_node
            return
        new_node.nextNode = self.first_node.nextNode
        self.first_node.nextNode = new_node
        self.first_node = new_node

    def insert_at_front(self,data):
        if self.first_node is None:
            return "List is empty!"
        new_node = Node(data)
        new_node.nextNode = self.first_node.nextNode
        self.first_node.nextNode = new_node

    def print(self):
        temp = self.first_node
        while temp.nextNode != self.first_node:
            print(temp.data)
            temp = temp.nextNode
        print(temp.data)
cll = Single_circular_linked_list(54)
cll.insert_at_last(54)
cll.insert_at_front(0)
cll.print()
    
