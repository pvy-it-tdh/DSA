class TextEditor:
    def __init__(self):
        self.text = ""
        self.undoStack = [self.text]  # Initialize with the empty state
        self.redoStack = []

    def type_text(self, text):
        self.text += text
        self.undoStack.append(self.text)
        self.redoStack.clear()  # Clear the redo stack whenever new text is typed

    def undo(self):
        if len(self.undoStack) > 1:  # Ensure at least one state remains in the stack
            self.redoStack.append(self.undoStack.pop())
            self.text = self.undoStack[-1]
        else:
            print("Nothing to undo")

    def redo(self):
        if self.redoStack:
            self.text = self.redoStack.pop()
            self.undoStack.append(self.text)
        else:
            print("Nothing to redo")

if __name__ == "__main__":
    editor = TextEditor()
    editor.type_text("Hello")
    editor.type_text(" World")
    print(editor.text)  # Output: Hello World
    editor.undo()
    print(editor.text)  # Output: Hello
    editor.redo()
    print(editor.text)  # Output: Hello World
    editor.redo()
    print(editor.text)  # Output: Hello World (No change, as redo stack is empty)
    editor.undo()
    print(editor.text)  # Output: Hello
    editor.undo()
    print(editor.text)  # Output: (Empty string)
    editor.undo()        # Nothing to undo
