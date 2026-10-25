/* Q23: Bucket sort for numbers in the range [0, 1)
   Expected time: O(n) for reasonably uniform input.
   Worst-case time: O(n^2) if many values land in one bucket.
   Auxiliary space: O(n).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node *next;
} Node;

void insertSorted(Node **head, double value) {
    Node *node = malloc(sizeof(Node));
    if (!node) { perror("malloc"); exit(EXIT_FAILURE); }
    node->value = value;
    node->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        node->next = *head;
        *head = node;
        return;
    }
    Node *cur = *head;
    while (cur->next != NULL && cur->next->value < value)
        cur = cur->next;
    node->next = cur->next;
    cur->next = node;
}

void freeBuckets(Node **buckets, int n) {
    for (int i = 0; i < n; i++) {
        Node *cur = buckets[i];
        while (cur) {
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}

int bucketSort(double arr[], int n) {
    if (n <= 0) return 1;
    Node **buckets = calloc((size_t)n, sizeof(Node *));
    if (!buckets) return 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0.0 || arr[i] >= 1.0) {
            freeBuckets(buckets, n);
            free(buckets);
            return 0;
        }
        int index = (int)(arr[i] * n);
        if (index >= n) index = n - 1;
        insertSorted(&buckets[index], arr[i]);
    }

    int pos = 0;
    for (int i = 0; i < n; i++) {
        Node *cur = buckets[i];
        while (cur) {
            arr[pos++] = cur->value;
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(buckets);
    return 1;
}

int main(void) {
    double arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (!bucketSort(arr, n)) {
        printf("Error: all values must be in [0, 1).\\n");
        return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\\n");
    return 0;
}
