#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void markAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void displayTasks() {
        cout << "\nCurrent Tasks:" << endl;
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << "[" << i+1 << "] ";
                if (tasks[i].completed) {
                    cout << "[X] ";
                } else {
                    cout << "[ ] ";
                }
                cout << tasks[i].description << endl;
            }
        }
    }

    // Function to get number of tasks
    size_t getSize() const {
        return tasks.size();
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    bool exit = false;

    cout << "Welcome to the To-Do List Application!" << endl;

    while (!exit) {
        cout << "\nMenu:\n";
        cout << "1. Add a task\n";
        cout << "2. Mark a task as completed\n";
        cout << "3. View current tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore();  // Ignore newline character from previous input
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                if (todoList.getSize() > 0) {
                    int index;
                    cout << "Enter task index to mark as completed (1-" << todoList.getSize() << "): ";
                    cin >> index;
                    if (index >= 1 && index <= todoList.getSize()) {
                        todoList.markAsCompleted(index - 1);  // Adjust index to 0-based
                    } else {
                        cout << "Invalid task index!" << endl;
                    }
                } else {
                    cout << "No tasks available to mark as completed." << endl;
                }
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                exit = true;
                cout << "Exiting application..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
