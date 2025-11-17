#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

// Node = one student record
struct Node
{
    int id; // auto-generated unique number
    string name;
    int age;
    char grade;
    Node *next; // next node
    Node *prev; // previous node
};

// Head points to the FIRST record in the circle (or null if empty).
Node *headPtr = nullptr;

// This counter goes up each time we add a student (1, 2, 3, ...).
int nextId = 1;

// Small helper: clear the console
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Flush the rest of a bad line
void flushLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Simple checks for inputs
bool validName(const string &s)
{
    if (s.empty())
        return false;
    for (char c : s)
    {
        if (!isalpha(static_cast<unsigned char>(c)) && !isspace(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }
    return true;
}

bool validAge(int a)
{
    return a >= 1 && a <= 123;
}

bool validGrade(char g)
{
    g = static_cast<char>(toupper(static_cast<unsigned char>(g)));
    return (g == 'A' || g == 'B' || g == 'C' || g == 'D' || g == 'F');
}

// Make and link a new node at the END of list (still circular). If list is empty, this becomes the only node.
void addRecord()
{
    clearScreen();
    cout << "=== Add New Record ===" << endl;

    // 1) Name
    string name;
    while (true)
    {
        cout << "Enter Name: ";
        getline(cin, name);
        if (validName(name))
            break;
        cout << "Name must have only letters/spaces." << endl;
    }

    // 2) Age
    int age;
    while (true)
    {
        cout << "Enter Age (1..123): ";
        if (cin >> age && validAge(age))
        {
            flushLine();
            break;
        }
        cout << "Age must be a whole number between 1 and 123." << endl;
        cin.clear();
        flushLine();
    }

    // 3) Grade
    char grade;
    while (true)
    {
        cout << "Enter Grade (A / B / C / D / F): ";
        if (cin >> grade)
        {
            flushLine();
            grade = static_cast<char>(toupper(static_cast<unsigned char>(grade)));
            if (validGrade(grade))
                break;
        }
        else
        {
            cin.clear();
            flushLine();
        }
        cout << "Grade must be either A / B / C / D / F." << endl;
    }

    // Make the new node
    Node *n = new Node;
    n->id = nextId++;
    n->name = name;
    n->age = age;
    n->grade = grade;

    // Insert into circular doubly linked list
    if (headPtr == nullptr)
    {
        // first node: points to itself
        n->next = n;
        n->prev = n;
        headPtr = n;
    }
    else
    {
        // Insert at the END (before headPtr)
        Node *last = headPtr->prev;
        n->next = headPtr;
        n->prev = last;
        last->next = n;
        headPtr->prev = n;
    }

    cout << "Successfully added. Assigned ID = " << n->id << endl
         << "Press Enter to return to menu ";
    cin.get();
}

// Remove a node by its ID. We search the circle once. If found, unlink and delete it. Update headPtr if needed.
void removeRecord()
{
    clearScreen();
    cout << "=== Remove Record ===" << endl;
    if (headPtr == nullptr)
    {
        cout << "DB is empty." << endl
             << "Press Enter";
        cin.get();
        return;
    }

    cout << "Enter ID to delete: ";
    int id;
    if (!(cin >> id))
    {
        cin.clear();
        flushLine();
        cout << "Invalid ID." << endl
             << "Press Enter";
        cin.get();
        return;
    }
    flushLine();

    Node *cur = headPtr;
    do
    {
        if (cur->id == id)
        {
            // Only one node
            if (cur->next == cur)
            {
                delete cur;
                headPtr = nullptr;
            }
            else
            {
                // Link around cur
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                // If we removed the head, move head forward
                if (cur == headPtr)
                    headPtr = cur->next;
                delete cur;
            }
            cout << "Successfully deleted." << endl
                 << "Press Enter ";
            cin.get();
            return;
        }
        cur = cur->next;
    } while (cur != headPtr);

    cout << "Record not found." << endl
         << "Press Enter ";
    cin.get();
}

/* Update a record by ID.
   - Show current values.
   - Let user leave a field blank to keep old value. */
void updateRecord()
{
    clearScreen();
    cout << "=== Update Record ===" << endl;
    if (headPtr == nullptr)
    {
        cout << "DB is empty." << endl
             << "Press Enter ";
        cin.get();
        return;
    }

    cout << "Enter ID to update: ";
    int id;
    if (!(cin >> id))
    {
        cin.clear();
        flushLine();
        cout << "Invalid ID." << endl
             << "Press Enter ";
        cin.get();
        return;
    }
    flushLine();

    // Find the node
    Node *cur = headPtr;
    Node *target = nullptr;
    do
    {
        if (cur->id == id)
        {
            target = cur;
            break;
        }
        cur = cur->next;
    } while (cur != headPtr);

    if (target == nullptr)
    {
        cout << "Record not found." << endl
             << "Press Enter ";
        cin.get();
        return;
    }

    // Show current
    cout << "Current:" << endl
         << "ID: " << target->id
         << " | Name: " << target->name
         << " | Age: " << target->age
         << " | Grade: " << target->grade << endl
         << "(Leave blank to keep the same)" << endl;

    // Name
    cout << "New Name [" << target->name << "]: ";
    string line;
    getline(cin, line);
    if (!line.empty())
    {
        if (validName(line))
            target->name = line;
        else
            cout << "Invalid name." << endl;
    }

    // Age
    cout << "New Age [" << target->age << "]: ";
    getline(cin, line);
    if (!line.empty())
    {
        try
        {
            int a = stoi(line);
            if (validAge(a))
                target->age = a;
            else
                cout << "Invalid age." << endl;
        }
        catch (...)
        {
            cout << "Invalid age." << endl;
        }
    }

    // Grade
    cout << "New Grade [" << target->grade << "]: ";
    getline(cin, line);
    if (!line.empty())
    {
        char g = static_cast<char>(toupper(static_cast<unsigned char>(line[0])));
        if (validGrade(g))
            target->grade = g;
        else
            cout << "Invalid grade.";
    }

    cout << "Updated:" << endl
         << "ID: " << target->id
         << " | Name: " << target->name
         << " | Age: " << target->age
         << " | Grade: " << target->grade << endl
         << "Press Enter ";
    cin.get();
}

// Display mode: show ONE record at a time. N=Next, P=Prev, M=Menu.
// When we wrap around to the FIRST record again, print in red.
void displayRecords()
{
    clearScreen();
    cout << "=== Display Records (N=Next, P=Prev, M=Menu) ===" << endl;
    if (headPtr == nullptr)
    {
        cout << "DB is empty." << endl
             << "Press Enter ";
        cin.get();
        return;
    }

    Node *first = headPtr;
    Node *cur = headPtr;
    bool wrapped = false; // becomes true after we loop back to first

    while (true)
    {
        clearScreen();
        cout << "=== Display Records (N=Next, P=Prev, M=Menu) ===" << endl
             << endl;

        bool highlight = (wrapped && cur == first);
        if (highlight)
            cout << "\033[1;31m"; // red + bold

        cout << "ID: " << cur->id
             << " | Name: " << cur->name
             << " | Age: " << cur->age
             << " | Grade: " << cur->grade << endl;

        if (highlight)
            cout << "\033[0m"; // reset color

        cout << endl
             << "Command [N/P/M]: ";
        string cmd;
        getline(cin, cmd);
        if (cmd.empty())
            continue;

        char c = static_cast<char>(toupper(static_cast<unsigned char>(cmd[0])));
        if (c == 'N')
        {
            Node *next = cur->next;
            if (cur != first && next == first)
                wrapped = true; // forward wrap
            cur = next;
        }
        else if (c == 'P')
        {
            Node *prev = cur->prev;
            if (cur == first && prev != first)
                wrapped = true; // backward wrap
            cur = prev;
        }
        else if (c == 'M')
        {
            break;
        }
    }
}

// Clean up all memory
void freeAll()
{
    if (headPtr == nullptr)
        return;
    Node *cur = headPtr->next;
    while (cur != headPtr)
    {
        Node *nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    delete headPtr;
    headPtr = nullptr;
}

// Main program
int main()
{
    while (true)
    {
        clearScreen();
        cout << "====== Main Menu ======" << endl
             << "A) Add new Record" << endl
             << "R) Remove Record" << endl
             << "U) Update Record" << endl
             << "D) Display Records" << endl
             << "E) Exit" << endl
             << "=======================" << endl
             << "Enter choice: ";

        string line;
        if (!getline(cin, line))
            break;
        if (line.empty())
            continue;

        char choice = static_cast<char>(toupper(static_cast<unsigned char>(line[0])));
        if (choice == 'A')
        {
            addRecord();
        }
        else if (choice == 'R')
        {
            removeRecord();
        }
        else if (choice == 'U')
        {
            updateRecord();
        }
        else if (choice == 'D')
        {
            displayRecords();
        }
        else if (choice == 'E')
        {
            freeAll();
            clearScreen();
            cout << "Goodbye!" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid option. Press Enter ";
            cin.get();
        }
    }
    freeAll();
    return 0;
}
