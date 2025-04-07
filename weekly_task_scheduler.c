#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int priority; 
    char* description; 
} Task;
typedef struct {
    Task* array;
    int capacity; 
    int size; 
} PriorityQueue;
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->array = (Task*)malloc(capacity * sizeof(Task));
    return pq;
}
void swapTasks(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left].priority < pq->array[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->array[right].priority < pq->array[smallest].priority)
        smallest = right;

    if (smallest != idx) {
        swapTasks(&pq->array[idx], &pq->array[smallest]);
        heapify(pq, smallest);
    }
}
void enqueue(PriorityQueue* pq, Task task) {
    if (pq->size == pq->capacity) {
        printf("Priority queue is full!\n");
        return;
    }

    int i = pq->size++;
    pq->array[i] = task;

    while (i != 0 && pq->array[(i - 1) / 2].priority > pq->array[i].priority) {
        swapTasks(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
Task dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty!\n");
        Task null_task = {0, "NULL"};
        return null_task;
    }

    Task root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return root;
}
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    PriorityQueue* pq = createPriorityQueue(100);
    printf("Enter tasks priority-wise (Enter priority followed by description, separated by space. Enter -1 to finish):\n");
    int priority;
    char description[100];

    while (1) {
        scanf("%d", &priority);
        if (priority == -1)
            break;
        scanf(" %[^\n]s", description);
        Task task = {priority, strdup(description)};
        enqueue(pq, task);
    }
    char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    PriorityQueue* weeklyTasks[7];

    for (int i = 0; i < 7; ++i) {
        weeklyTasks[i] = createPriorityQueue(100);
    }
    int dayIndex = 0;
    while (!isEmpty(pq)) {
        Task task = dequeue(pq);
        if (task.priority == 1 && dayIndex != 0) {
            dayIndex = 0;
        }
        enqueue(weeklyTasks[dayIndex], task);
        dayIndex = (dayIndex + 1) % 7; 
    }
    printf("\nWeekly To-Do List:\n");
    for (int i = 0; i < 7; ++i) {
        printf("\n%s:\n", days[i]);
        while (!isEmpty(weeklyTasks[i])) {
            Task task = dequeue(weeklyTasks[i]);
            printf("Priority: %d, Description: %s\n", task.priority, task.description);
            free(task.description); 
        }
        free(weeklyTasks[i]->array);
        free(weeklyTasks[i]);
    }
    free(pq->array);
    free(pq);

    return 0;
}
