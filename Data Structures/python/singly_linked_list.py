class Node:
    data = ""
    nextNode = None
    def __init__(self,data):
        self.data = data
        self.nextNode = None

class LinkedList:
    head = None
    tail = None
    def __init__(self,data):
        """makes a new instance of linkedlist"""
        new_node = Node(data)
        self.head = new_node
        self.tail = new_node
    
    def insert(self,data):
        """inserts data at the last of the linked list"""
        new_node = Node(data)   #init a node
        if self.head is None:  
             #if it is a first node
            ##head and tail both will be pointing towards new node as it is the only node available
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.nextNode = new_node
            self.tail = new_node
            new_node.nextNode = None


    def insert_at_front(self,data):
        """inserts data at the beginning of the linked list"""
        new_node = Node(data)   #create a node
        new_node.nextNode = self.head   #link the newnode to linked list
        self.head = new_node    

    def insert_at_position(self,data,position):
        """insert data at given position of linked list"""
        if position == 0:
            self.insert_at_front(data)
            return
        new_node = Node(data)
        current = self.head
        prev = self.head
        
        try:
            for i in range(position):
                prev = current
                current = current.nextNode
        except AttributeError:
            print("Index does not exist!")
            return
        if current is None:
            self.insert(data)
            return
        prev.nextNode = new_node
        new_node.nextNode = current
        
        
    def delete_at_last(self):
        """delete node at last of the linked list"""
        current = self.head
        prev = self.head
        while current.nextNode is not None:
            prev = current
            current = current.nextNode
        prev.nextNode = None
        del current
        self.tail = prev

    def delete_at_front(self):
        """delete node at front of the linked list"""
        temp = self.head.nextNode
        del self.head
        self.head = temp        
           
    def delete_at_position(self,position):
        """delete node at given position"""
        current = self.head 
        prev = self.head
        for i in range(position):
            prev = current
            current = current.nextNode

        prev.nextNode = current.nextNode
        del current
    
    def reverse(self):
        prevNode = None
        nextNode = None
        currentNode = self.head

        while currentNode is not None:
            nextNode = currentNode.nextNode
            
            currentNode.nextNode = prevNode

            prevNode = currentNode
            currentNode = nextNode
        self.head = prevNode

    def exists(self,data):
        """return True if given data exists, else False"""
        temp = self.head
        while temp is not None:
            if temp.data == data:
                return True
            temp = temp.nextNode
        return False

    def indexOf(self,data,start = 0):
        """returns index of given data in linkedlist"""
        
        counter = 0

        if start == 0:
            temp = self.head
            while temp is not None:
                if temp.data == data:
                    return counter
                counter += 1
                temp = temp.nextNode
        else:
            current = self.head

            for i in range(start):
                current = current.nextNode
                counter += 1
            while current is not None:
                if current.data == data:
                    return counter
                current = current.nextNode
                counter += 1

        return -1

    def count(self,data):
        """returns the counts of data occured in linked list"""
        counter = 0
        temp = self.head
        while temp is not None:
            if temp.data == data:
                counter += 1
            temp = temp.nextNode
        return counter
    
    def merge(self,l1):
        if self.head is None:
            return l1
        elif l1 is None:
            return self.head
        self.tail.nextNode = l1.head
        return self.head

    def has_cycle(self):
        if self.head is None:
            return False
        slow_pointer = self.head
        fast_pointer = self.head.nextNode

        while slow_pointer != fast_pointer:
            if fast_pointer is None or fast_pointer.nextNode is None:
                return False
            slow_pointer = slow_pointer.nextNode
            fast_pointer = fast_pointer.nextNode.nextNode

        return True 

    def print(self):
        """prints the linked list"""
        temp = self.head
        while temp is not None:
            print(temp.data)
            temp = temp.nextNode
    
    def find_n_th_element_from_backward(self,position):
        current = self.head   #starts from head 
        runner = self.head      #starts from head
        for i in range(0,position):     #first move runner to position from head
            runner = runner.nextNode
        #now move runner to last node,and current node to its next until the runner reaches the last 
        # when runner reaches last node than current is already have reached position from backward 
        while runner.nextNode is not None:  
            current = current.nextNode
            runner = runner.nextNode
        return current.data
        
if __name__ == "__main__":
    ll = LinkedList('s')
    ll.insert('a')
    ll.insert('j')
    ll.insert('i')
    ll.insert('d')
    ll.insert('a')
    ll.insert('a')
    print(ll.find_n_th_element_from_backward(4))
    