#include <iostream>
#include <stack>
#include <string>

class TextEditor
{
private:
    std::string text;
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;

public:
    TextEditor()
    {
        text = "";
        undoStack.push(text); // Initialize with the empty state
    }

    void typeText(const std::string &newText)
    {
        text += newText;
        undoStack.push(text);
        while (!redoStack.empty())
        {
            redoStack.pop(); // Clear the redo stack whenever new text is typed
        }
    }

    void undo()
    {
        if (undoStack.size() > 1)
        { // Ensure at least one state remains in the stack
            redoStack.push(undoStack.top());
            undoStack.pop();
            text = undoStack.top();
        }
        else
        {
            std::cout << "Nothing to undo" << std::endl;
        }
    }

    void redo()
    {
        if (!redoStack.empty())
        {
            text = redoStack.top();
            redoStack.pop();
            undoStack.push(text);
        }
        else
        {
            std::cout << "Nothing to redo" << std::endl;
        }
    }

    void printText() const
    {
        std::cout << text << std::endl;
    }
};

int main()
{
    TextEditor editor;

    editor.typeText("Hello");
    editor.typeText(" World");
    editor.printText(); // Output: Hello World

    editor.undo();
    editor.printText(); // Output: Hello

    editor.redo();
    editor.printText(); // Output: Hello World

    editor.redo();
    editor.printText(); // Output: Hello World (No change, as redo stack is empty)

    editor.undo();
    editor.printText(); // Output: Hello

    editor.undo();
    editor.printText(); // Output: (Empty string)

    editor.undo(); // Nothing to undo

    return 0;
}
