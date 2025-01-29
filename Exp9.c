/* Write a program to implement Dijkstra’s shortest path algorithm for a given directed
Graph.*/

#include <stdio.h>

int i, j, r, c, adj[10][10] = {0}, cp[10][10], v[10], vf[10] = {0};

void relax(int i, int j) {
    if (v[j] >= v[i] + cp[i][j]) {
        v[j] = v[i] + cp[i][j];
        vf[j] = i;
    }
}

void DjAlgorithm() {
    int s = 1;
    v[s] = 0;
    for (i = s; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (adj[i][j] != 0) {
                relax(i, j);
            }
        }
    }
}

int main() {
    // Dj's Algorithm

    printf("\nEnter the no. of rows and columns :");
    scanf("%d %d", &r, &c);
    printf("\nEnter the cost matrix of the graph : ");
    for (i = 1; i <= r; i++) {  // Start from 1, not 0
        v[i] = 999;
        for (j = 1; j <= c; j++) {  // Start from 1, not 0
            printf("\nEnter the cost of %d -> %d : ", i, j);
            scanf("%d", &cp[i][j]);
            if (cp[i][j] != 0) {
                adj[i][j] = 1;
            }
        }
    }
    DjAlgorithm();
    for (i = 1; i <= r; i++) {  // Start from 1, not 0
        printf("%d  ", v[i]);
    }
    printf("\n");
    for (i = 1; i <= r; i++) {  // Start from 1, not 0
        printf("%d  ", vf[i]);
    }
    return 0;  // Use 0 to indicate successful execution
}


