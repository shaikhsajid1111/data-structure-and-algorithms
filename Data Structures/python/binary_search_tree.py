class Tree:
    left = right = None
    data = ""
    def __init__(self,data):
        self.left = None
        self.right = None
        self.data = data




def new_node(root,data):
    new_branch = Tree(data)
    return new_branch
 
def insert(root,data):
    if root is None:
        return new_node(root,data)
    if data < root.data:
        root.left = insert(root.left,data)
    if data > root.data:
        root.right = insert(root.right,data)

def pre_order(root):
    """prints the data in root->left->right"""
    if root is not None:
        print(root.data)
        pre_order(root.left)
        pre_order(root.right)

def in_order(root):
    """prints the data from left->root->right"""
    if root is not None:
        in_order(root.left)
        print(root.data)
        in_order(root.right)

def post_order(root):
    """prints the data in left->right->root"""
    if root is not None:
        post_order(root.left)
        post_order(root.right)
        print(root.data)
def maximum(root):
    current = root
    while current.right is not None:
        current = current.right
    return current.data

def minimum(root):
    current = root
    while current.left is not None:
        current = current.left
    return current.data

def invert_bst(root):
    if root:
        temp = root.left
        root.left = root.right
        root.right = temp
        invert_bst(root.left)
        invert_bst(roo.right)
    return root
        

if __name__ == "__main__":
    BST = Tree(12)
    insert(BST,45)
    insert(BST,5)
    print(maximum(BST))