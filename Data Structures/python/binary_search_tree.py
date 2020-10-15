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
        return new_node(data)
    if data < root.data:
        root.left = new_node(root.left,data)
    elif data > root.data:
        root.right = new_node(root.right,data)
    return root

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

def minimum(root):
    current = root
    while current.left is not None:
        current = current.left
    return current.data

if __name__ == "__main__":
    BST = Tree(12)
    insert(BST,45)
    in_order(BST)
    print(minimum(BST))