#include <stdio.h>
#define MAX 100

int parent[MAX];

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

void displaySets(int n) {
    printf("\nElement:   ");
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\nParent:    ");
    for (int i = 0; i < n; i++) {
        printf("%d ", parent[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, x, y;

    printf("Enter the number of elements (max %d):\n", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements. Maximum allowed is %d.\n", MAX);
        return 1;
    }

    initialize(n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display Sets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union (0 to %d): ", n - 1);
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    unionSets(x, y);
                } else {
                    printf("Invalid input. Elements must be in the range 0 to %d.\n", n - 1);
                }
                break;

            case 2:
                printf("Enter an element to find its set (0 to %d): ", n - 1);
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    printf("Set representative for element %d is %d\n", x, find(x));
                } else {
                    printf("Invalid input. Element must be in the range 0 to %d.\n", n - 1);
                }
                break;

            case 3:
                displaySets(n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}