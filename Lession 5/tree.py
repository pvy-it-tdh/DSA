class TreeNode:
    def __init__(self, value, parent=None):
        self.value = value
        self.children = []
        self.parent = parent  # Thêm thuộc tính parent

    def add_child(self, child_node):
        child_node.parent = self  # Gán parent cho child
        self.children.append(child_node)

    def get_level(self):
        level = 0
        p = self.parent
        while p:
            level += 1
            p = p.parent
        return level

    def print_tree(self):
        spaces = ' ' * self.get_level() * 3
        prefix = spaces + "|__" if self.parent else ""
        print(prefix + self.value)
        if self.children:
            for child in self.children:
                child.print_tree()

def create_tree():
    root = TreeNode("Electronics")
    
    laptop = TreeNode("Laptop", root)
    laptop.add_child(TreeNode("Mac", laptop))
    laptop.add_child(TreeNode("Surface", laptop))
    laptop.add_child(TreeNode("Thinkpad", laptop))

    cellphone = TreeNode("Cell Phone", root)
    cellphone.add_child(TreeNode("iPhone", cellphone))
    cellphone.add_child(TreeNode("Google Pixel", cellphone))
    cellphone.add_child(TreeNode("Vivo", cellphone))

    tv = TreeNode("TV", root)
    tv.add_child(TreeNode("Samsung", tv))
    tv.add_child(TreeNode("LG", tv))
    tv.add_child(TreeNode("Sony", tv))

    root.add_child(laptop)
    root.add_child(cellphone)
    root.add_child(tv)

    return root  # Trả về cây đã tạo

if __name__ == '__main__':
    root = create_tree()
    root.print_tree()
