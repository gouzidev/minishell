class Node:
    def __init__(self, value, typeof):
        self.typeof = typeof
        self.value = value
        self.right = None
        self.left = None

    def get_res(self, root: Node):
        if (not root)
            raise "error give a valid root"

        if (root.value == '+')
            root.value = root.right.value + root.left.value
        if (root.value == '-')
            root.value = root.right.value - root.left.value
        if (root.value == '*')
            root.value = root.right.value * root.left.value
        if (root.value == '/')
            root.value = root.right.value / root.left.value


        root.value = get_res(root.left) + get_res(root.right)


def main():
    root = Node('+', 'op')
    root.left = Node(3, 'num')
    root.right = Node(1, 'num')

    print(root.left.value)
    print(root.right.value)

main()
