#include <stdio.h>
#define INF 9999

int tree_array_size = 20;
int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_right_child(int A[], int index) {
  if((((2*index)+1) < tree_array_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int A[], int index) {
    if(((2*index) < tree_array_size) && (index >= 1))
        return 2*index;
    return -1;
}

int get_parent(int A[], int index) {
  if ((index > 1) && (index < tree_array_size)) {
    return index/2;
  }
  return -1;
}

void max_heapify(int A[], int index) {
  int left_child_index = get_left_child(A, index);
  int right_child_index = get_right_child(A, index);
  int largest = index;

  if ((left_child_index <= heap_size) && (left_child_index>0)) {
    if (A[left_child_index] > A[largest]) {
      largest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size) && (right_child_index>0)) {
    if (A[right_child_index] > A[largest]) {
      largest = right_child_index;
    }
  }

  if (largest != index) {
    swap(&A[index], &A[largest]);
    max_heapify(A, largest);
  }
}

void build_max_heap(int A[]) {
  int i;
  for(i=heap_size/2; i>=1; i--) {
    max_heapify(A, i);
  }
}

int maximum(int A[]) {
  return A[1];
}

int extract_max(int A[]) {
  int maxm = A[1];
  A[1] = A[heap_size];
  heap_size--;
  max_heapify(A, 1);
  return maxm;
}

void increase_key(int A[], int index, int key) {
  A[index] = key;
  while((index>1) && (A[get_parent(A, index)] < A[index])) {
    swap(&A[index], &A[get_parent(A, index)]);
    index = get_parent(A, index);
  }
}

void decrease_key(int A[], int index, int key) {
  A[index] = key;
  max_heapify(A, index);
}

void insert(int A[], int key) {
  heap_size++;
  A[heap_size] = -1*INF;
  increase_key(A, heap_size, key);
}

void print_heap(int A[]) {
  int i;
  for(i=1; i<=heap_size; i++)
    printf("%d ",A[i]);
  printf("\n");
}

int main() {
    int A[tree_array_size];
    int n, element;

    printf("Enter the size of the array: ");
        scanf("%d", &n);

    printf("Enter the elements of the array: ");
        for(int i = 0; i < n; i++) {
            scanf("%d", &element);
            insert(A, element);
        }

    int sorted[n], i=0, m=n;
    while (m > 0) {
        sorted[i] = extract_max(A);
        m--;
        i++;
    }

    int start = 0, end = n-1, temp;
    while (start < end) {
        temp = sorted[start];
        sorted[start] = sorted[end];
        sorted[end] = temp;
        start++;
        end--;
    }

    for(int i=0; i<n; i++)
        printf("%d ", sorted[i]);

    return 0;
}
