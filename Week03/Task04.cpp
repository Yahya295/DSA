#include <iostream>
#include <string>
using namespace std;

class StringStack 
{
private:
    string arr[100];   
    int topIndex;

public:
    StringStack() 
    {
        topIndex = -1;
    }

    bool isEmpty() const 
    {
        return topIndex == -1;
    }

    bool isFull() const 
    {
        return topIndex == 99;
    }

    void push(const string& s) 
    {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = s;
    }

    string pop() 
    {
        if (isEmpty()) 
        {
            return "";
        }
        return arr[topIndex--];
    }

    string top() const 
    {
        if (isEmpty()) return "";
        return arr[topIndex];
    }
};

class TextEditor 
{
private:
    string text;
    StringStack undoStack;
    StringStack redoStack;

public:
    void type(const string& newText) 
    {
        undoStack.push(text);     
        text += newText;          
        while (!redoStack.isEmpty()) redoStack.pop();
    }

    void deleteChars(int n)
    {
        if (n > (int)text.size()) n = text.size();
        undoStack.push(text);     
        text.erase(text.size() - n, n);
        while (!redoStack.isEmpty()) redoStack.pop();
    }

    void undo() 
    {
        if (undoStack.isEmpty())
        {
            cout << "Nothing to undo!" << endl;
            return;
        }
        redoStack.push(text);     
        text = undoStack.pop();   
    }

    void redo() 
    {
        if (redoStack.isEmpty()) 
        {
            cout << "Nothing to redo!" << endl;
            return;
        }
        undoStack.push(text);     
        text = redoStack.pop();   
    }

    void showText() const 
    {
        cout << "Current Text: " << text << endl;
    }
};

int main() 
{
    TextEditor editor;
    int choice;
    string input;
    int n;

    do {
        cout << "\n--- Text Editor Menu ---\n";
        cout << "1. Type text\n";
        cout << "2. Delete characters\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Show current text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter text to type: ";
            cin.ignore();
            getline(cin, input);
            editor.type(input);
            break;
        case 2:
            cout << "Enter number of characters to delete: ";
            cin >> n;
            editor.deleteChars(n);
            break;
        case 3:
            editor.undo();
            break;
        case 4:
            editor.redo();
            break;
        case 5:
            editor.showText();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
