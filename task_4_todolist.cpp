#include <iostream>
using namespace std;

struct Task {
    string name;
    bool status = false;
    Task* next;
};

Task* head = nullptr;

void addTask(string name) {
    Task* newTask = new Task();
    newTask->name = name;
    newTask->next = nullptr;

    if (head == nullptr) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != nullptr) {
            // Check for duplicate task
            if (temp->name == name) {
                cout << "Task already exists!" << endl;
                delete newTask; // Clean up memory
                return;
            }
            temp = temp->next;
        }
        temp->next = newTask;
    }
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Task* temp = head;
    int num = 1;
    while (temp != nullptr) {
        cout << "Task #" << num << ": " << temp->name << " ["
             << (temp->status ? "Completed" : "Pending") << "]" << endl;
        temp = temp->next;
        num++;
    }
}

void markCompleted(int n) {
    Task* temp = head;
    int num = 1;
    while (temp != nullptr) {
        if (num == n) {
            temp->status = true;
            cout << "Task #" << n << " marked as completed!" << endl;
            return;
        }
        temp = temp->next;
        num++;
    }
    cout << "No such task exists!" << endl;
}

void removeTask(int n) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Task* temp = head;
    if (n == 1) { // Remove head
        head = head->next;
        delete temp;
        cout << "Task deleted!" << endl;
        return;
    }

    Task* prev = nullptr;
    int num = 1;
    while (temp != nullptr && num < n) {
        prev = temp;
        temp = temp->next;
        num++;
    }

    if (temp == nullptr) {
        cout << "No such task exists!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Task deleted!" << endl;
}

int main() {
    char choice;
    do {
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task Completed\n4. Remove Task\nAny other key to exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == '1') {
            string name;
            cout << "Enter task name: ";
            cin >> name;
            addTask(name);
        } else if (choice == '2') {
            viewTasks();
        } else if (choice == '3') {
            int n;
            cout << "Enter task number to mark as completed: ";
            cin >> n;
            markCompleted(n);
        } else if (choice == '4') {
            int n;
            cout << "Enter task number to remove: ";
            cin >> n;
            removeTask(n);
        }
    } while (choice >= '1' && choice <= '4');

    cout << "Program ended." << endl;
    return 0;
}