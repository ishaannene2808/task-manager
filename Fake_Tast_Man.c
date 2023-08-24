//Fake_Tast_Man.c
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int Sl_No;
    char description[100];
    int priority;
    int completion;
    struct node* next;
} task_struct;

void find_task_based_on_Sl_No(task_struct** task, int sl_no){
    task_struct* task_finder;
    task_finder = *task;
    
}

void find_task_based_on_priority(task_struct** task, int priority){

}

void find_task_based_on_completion(task_struct** task, int completion){

}

void find_task_based_on_descripation(task_struct** task, char ch ){

}