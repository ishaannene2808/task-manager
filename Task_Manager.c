/*
Task Manager Application:
Create a simple command-line task manager where users can add, delete, update, and view tasks. 
Each task can be represented as a node in a singly linked list. 
The list can be dynamically managed to reflect changes in the user's tasks.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int Sl_No;
    char description[100];
    int priority;
    int completion;
    struct node* next;
} task_struct;

void update_Sl_No(task_struct **task_list){
    task_struct *task = *task_list;
    int i = 1;
    while(task->next!=NULL){
        task->Sl_No = i;
        task = task->next;
        i++;
    }
}

void Sort_Based_On_Sl_No(task_struct **task_list) {
    if (*task_list == NULL || (*task_list)->next == NULL) {
        return;
    }

    int swapped;
    task_struct *ptr1;
    task_struct *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *task_list;

        while (ptr1->next != lptr) {
            if (ptr1->Sl_No > ptr1->next->Sl_No) {
                task_struct *temp = ptr1;
                ptr1 = ptr1->next;
                temp->next = ptr1->next;
                ptr1->next = temp;
                if (lptr == NULL) {
                    *task_list = ptr1;
                } else {
                    lptr->next = ptr1;
                }
                swapped = 1;
            }
            lptr = ptr1;
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

void Sort_Based_On_Priority(task_struct **task_list){
    if (*task_list == NULL || (*task_list)->next == NULL) {
        return;
    }
    int swapped;
    task_struct *ptr1;
    task_struct *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *task_list;

        while (ptr1->next != lptr) {
            if (ptr1->priority > ptr1->next->priority) {
                task_struct *temp = ptr1;
                ptr1 = ptr1->next;
                temp->next = ptr1->next;
                ptr1->next = temp;
                if (lptr == NULL) {
                    *task_list = ptr1;
                } else {
                    lptr->next = ptr1;
                }
                swapped = 1;
            }
            lptr = ptr1;
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

void Sort_Based_On_Completion(task_struct **task_list) {
    if (*task_list == NULL || (*task_list)->next == NULL) {
        return;
    }
    int swapped;
    task_struct *ptr1;
    task_struct *lptr = NULL;
    do{
        swapped = 0;
        ptr1 = *task_list;

        while (ptr1->next != lptr) {
            if (ptr1->completion > ptr1->next->completion) {
                task_struct *temp = ptr1;
                ptr1 = ptr1->next;
                temp->next = ptr1->next;
                ptr1->next = temp;
                if (lptr == NULL) {
                    *task_list = ptr1;
                } else {
                    lptr->next = ptr1;
                }
                swapped = 1;
            }
            lptr = ptr1;
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

void Sort_Based_On_Description(task_struct **task_list) {
    if (*task_list == NULL || (*task_list)->next == NULL) {
        return;
    }
    int swapped;
    task_struct *ptr1;
    task_struct *lptr = NULL;

    do{
        swapped = 0;
        ptr1 = *task_list;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->description,ptr1->next->description)) {
                task_struct *temp = ptr1;
                ptr1 = ptr1->next;
                temp->next = ptr1->next;
                ptr1->next = temp;
                if (lptr == NULL) {
                    *task_list = ptr1;
                } else {
                    lptr->next = ptr1;
                }
                swapped = 1;
            }
            lptr = ptr1;
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

/*
Add Task
Delete Task
Update Task
View Tasks
Int main Switch Choices
*/



void Add_task_at_position(task_struct** task_list, int position, int priority, int completion, char* description) {
    task_struct* new_task = (task_struct*)malloc(sizeof(task_struct));
    if (new_task == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_task->Sl_No = position;
    new_task->priority = priority;
    new_task->completion = completion;
    strncpy(new_task->description, description, sizeof(new_task->description));
    new_task->description[sizeof(new_task->description) - 1] = '\0';

    if (position == 1) {
        new_task->next = *task_list;
        *task_list = new_task;
    } 
    else {
        task_struct* current = *task_list;
        for (int i = 1; i < position - 1 && current != NULL; ++i) {
            current = current->next;
        }

        if (current == NULL) {
            fprintf(stderr, "Invalid position\n");
            free(new_task);
            return;
        }

        // Insert the new node
        new_task->next = current->next;
        current->next = new_task;
    }
}

void Update_task_at_position(task_struct** task_list, int position, int priority, int completion, char* description) {
    task_struct* current = *task_list;
    int currentPosition = 1;

    while (current != NULL) {
        if (currentPosition == position) {
            current->priority = priority;
            current->completion = completion;
            strncpy(current->description, description, sizeof(current->description));
            printf("Task at position %d updated successfully.\n", position);
            return;
        }
        current = current->next;
        currentPosition++;
    }

    printf("Position is out of bounds. Task could not be updated.\n");
}

int main() {
    task_struct* task_list = NULL; 
    Add_task_at_position(&task_list, 1, 3, 0, "Task A");
    Add_task_at_position(&task_list, 2, 1, 0, "Task B");
    Add_task_at_position(&task_list, 2, 2, 0, "Task C");
    task_struct* current = task_list;
    while (current != NULL) {
        printf("Sl_No: %d, Description: %s, Priority: %d, Completion: %d\n",
               current->Sl_No, current->description, current->priority, current->completion);
        current = current->next;
    }
    current = task_list;
    while (current != NULL) {
        task_struct* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
