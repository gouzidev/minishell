class Node:
    def __init__(self, value, typeof):
        self.typeof = typeof
        self.value = value
        self.right = None
        self.left = None

    def do_op(self, root):
        if (root.value == '+'):
            root.value = root.right.value + root.left.value
            root.left = None
            root.right = None
            return root
        if (root.value == '-'):
            root.value = root.right.value - root.left.value
            root.left = None
            root.right = None
            return root
        if (root.value == '*'):
            root.value = root.right.value * root.left.value
            root.left = None
            root.right = None
            return root
        if (root.value == '/'):
            root.value = root.right.value / root.left.value
            root.left = None
            root.right = None
            return root

    def get_res(self, root):
        if (not root):
            raise "error give a valid root"
        if (not root.left):
            return (self.do_op(root))
        root.value = self.get_res(root.left) + self.get_res(root.right)


def main():
    root = Node('+', 'op')
    root.left = Node(3, 'num')
    root.right = Node('+', 2)
    root.right.left = Node(4, 'num')
    root.right.right = Node(1, 'num')

    print(root.get_res(root))

main()
