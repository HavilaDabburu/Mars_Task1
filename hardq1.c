#include <stdio.h>
#include <stdlib.h>
#define N 11 // Size of the arena (11x11)
int arena[N][N]; // Matrix to represent the arena (1 = open, 0 = obstacle)
int visited[N][N]; // To keep track of visited cells
// Movement directions: North, East, South, West
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// Structure to represent each cell in the path
struct Node
{
    int x; // row
    int y; // column
    int d; // distance from start
};
// Queue to use in BFS
struct Node q[N*N];
int f = 0, r = 0; // front and rear for queue
// Function to add a node to the queue
void enq(int x, int y, int d) 
{
    q[r].x = x;
    q[r].y = y;
    q[r].d = d;
    r++;
}
// Function to remove a node from the queue
struct Node deq() 
{
    return q[f++];
}
// Check if the cell is inside the arena and not visited or blocked
int valid(int x, int y) 
{
    return x >= 0 && x < N && y >= 0 && y < N && arena[x][y] == 1 && !visited[x][y];
}
// Function to mark obstacles from the file data
void obs(int o[100][4], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        // Mark North
        for (int j = 1; j <= o[i][0]; j++)
        {    
            if (0 - j >= 0)
            arena[0 - j][0] = 0;
        }
        // Mark East
        for (int j = 1; j <= o[i][1]; j++)
        { 
            if (j < N)
            arena[0][j] = 0;
        }
        // Mark South
        for (int j = 1; j <= o[i][2]; j++)
        { 
            if (j < N)
            arena[j][0] = 0;
        }
        // Mark West
        for (int j = 1; j <= o[i][3]; j++)
        {   
            if (0 - j >= 0)
            arena[0][0 - j] = 0;
        }
    }
}
// Function to find the shortest path from (0,0) to (10,10) using BFS
int path() 
{
    enq(0, 0, 0); // Start from top-left corner
    visited[0][0] = 1;
    while (f < r) 
    {
        struct Node cur = deq(); // Get the current node
        if (cur.x == 10 && cur.y == 10) // If we reach the destination
        return cur.d; // Return distance
        // Check all 4 directions
        for (int i = 0; i < 4; i++) 
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (valid(nx, ny)) 
            {
                visited[nx][ny] = 1;
                enq(nx, ny, cur.d + 1); // Move to next cell
            }
        }
    }
    return -1; // No path found
}
// Main function
int main() 
{
    FILE *fp = fopen("obstacles.txt", "r"); // Open the file with obstacles
    if (!fp) 
    {
        printf("File error.\n");
        return 1;
    }
    // Initially set all cells as open (1)
    for (int i = 0; i < N; i++)
    {    
        for (int j = 0; j < N; j++)
        {    
            arena[i][j] = 1;
        }
    }
    // Read obstacle data from file
    int o[100][4], n = 0;
    while (fscanf(fp, "%d %d %d %d", &o[n][0], &o[n][1], &o[n][2], &o[n][3]) == 4)
        n++;
    fclose(fp); // Close the file
    obs(o, n); // Mark obstacles in the arena
    // Print the arena to see blocked and open paths
    printf("Arena:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        printf("%d ", arena[i][j]);
        printf("\n");
    }
    // Call BFS to find shortest path
    int res = path();
    if (res != -1)
    printf("Shortest path: %d\n", res);
    else
    printf("No path.\n");
    return 0;
}




