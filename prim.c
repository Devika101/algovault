
#include <stdio.h>
#include <limits.h>

#define MAX 10


int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX][MAX], int n) {
    int totalDistance = 0;
    printf("Location\tDistance\n");

    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            printf("%d -> %d\t\t\t%d km\n", parent[i], i, graph[i][parent[i]]);
            totalDistance += graph[i][parent[i]];
        }
    }
    printf("Minimum total distance: %d km\n", totalDistance);
}


void primMST(int graph[MAX][MAX], int n) {
    int parent[MAX];  
    int key[MAX];     
    int mstSet[MAX];   

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;       
    parent[0] = -1;   

 
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);  
        mstSet[u] = 1;  


        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

  
    printMST(parent, graph, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

  
    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

  
    primMST(graph, n);

    return 0;
}