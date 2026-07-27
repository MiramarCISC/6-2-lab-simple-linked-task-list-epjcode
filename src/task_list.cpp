#include "task_list.hpp"
#include <iostream>

using namespace std;

bool isValidPriority(int priority) {
    // TODO: Return true when priority is from 1 to 5.
    return priority >= 1 && priority <= 5;
}

Task createTask(string description, int priority) {
    Task task;

    task.description = description;
    if (isValidPriority(priority)) {
        task.priority = priority;
    } 
    else {
        task.priority = 1;
    }    
    task.completed = false;

    return task;
}

void insertFront(TaskNode*& head, Task task) {
    // TODO:
    // Dynamically allocate a new TaskNode.
    // Store task in the node.
    // Point the new node to the old head.
    // Update head.
    TaskNode* node = new TaskNode;
    node->data = task;
    node->next = head;
    head = node;
}

int countTasks(const TaskNode* head) {
    // TODO: Traverse the list and count nodes.
    int count = 0;
    const TaskNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
    return 0;
}

TaskNode* findTask(TaskNode* head, string description) {
    // TODO:
    // Traverse the list.
    // Return the first node whose task description matches.
    // Return nullptr if not found.
    TaskNode* node = head;

    while (node != nullptr) {
        if (node->data.description == description) {
            return node;
        }
        node = node->next;
    }

    return nullptr;
}

bool markTaskComplete(TaskNode* head, string description) {
    // TODO:
    // Find the task.
    // If found, set completed to true and return true.
    // Otherwise return false.
    TaskNode* target = findTask(head, description);

    if (target != nullptr) {
        target->data.completed = true;
        return true;
    }

    return false;
}

int removeCompletedTasks(TaskNode*& head) {
    // TODO:
    // Remove all completed tasks.
    // Return the number of removed nodes.
    // Be sure to handle completed tasks at the head of the list.
    int removed = 0;

    while (head != nullptr && head->data.completed) {
        TaskNode* oldHead = head;
        head = head->next;
        delete oldHead;
        removed++;
    }

    TaskNode* node = head;

    while (node != nullptr && node->next != nullptr) {
        if (node->next->data.completed) {
            TaskNode* doomed = node->next;
            node->next = doomed->next;
            delete doomed;
            removed++;
        } 
        else{
            node = node->next;
        }
    }

    return removed;
}

void clearTasks(TaskNode*& head) {
    // TODO:
    // Delete every node in the list.
    // Set head to nullptr.
    while (head != nullptr) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void printTask(const Task& task) {
    cout << task.description
         << " | priority " << task.priority
         << " | " << (task.completed ? "complete" : "not complete")
         << endl;
}

void printTasks(const TaskNode* head) {
    if (head == nullptr) {
        cout << "No tasks." << endl;
        return;
    }

    const TaskNode* current = head;

    while (current != nullptr) {
        printTask(current->data);
        current = current->next;
    }
}
