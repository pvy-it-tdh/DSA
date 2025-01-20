# Julia implementation of the TextEditor

mutable struct TextEditor
    text::String
    undoStack::Vector{String}
    redoStack::Vector{String}

    function TextEditor()
        text = ""
        undoStack = [text]  # Initialize with the empty state
        redoStack = String[]
        new(text, undoStack, redoStack)
    end
end

function typeText(editor::TextEditor, newText::String)
    editor.text *= newText
    push!(editor.undoStack, editor.text)
    empty!(editor.redoStack)  # Clear the redo stack whenever new text is typed
end

function undo(editor::TextEditor)
    if length(editor.undoStack) > 1 # Ensure at least one state remains in the stack
        push!(editor.redoStack, pop!(editor.undoStack))
        editor.text = editor.undoStack[end]
    else
        println("Nothing to undo")
    end
end

function redo(editor::TextEditor)
    if !isempty(editor.redoStack)
        editor.text = pop!(editor.redoStack)
        push!(editor.undoStack, editor.text)
    else
        println("Nothing to redo")
    end
end

function printText(editor::TextEditor)
    println(editor.text)
end

# Main function to demonstrate the TextEditor
function main()
    editor = TextEditor()

    typeText(editor, "Hello")
    typeText(editor, " World")
    printText(editor) # Output: Hello World

    undo(editor)
    printText(editor) # Output: Hello

    redo(editor)
    printText(editor) # Output: Hello World

    redo(editor)
    printText(editor) # Output: Hello World (No change, as redo stack is empty)

    undo(editor)
    printText(editor) # Output: Hello

    undo(editor)
    printText(editor) # Output: (Empty string)

    undo(editor) # Nothing to undo
end

main()
