//leetcode 20-06-2023, problem: 1971. Find if Path Exists in Graph


bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    bool* visited = (bool*)malloc(n * sizeof(bool));  
    memset(visited, false, n * sizeof(bool));  

    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0;
    int rear = 0;
    
    queue[rear++] = source;  
    visited[source] = true;  
    
    while (front != rear) {
        int currentVertex = queue[front++];
        
        if (currentVertex == destination) {
            free(queue);
            free(visited);
            return true;  
        }
        for (int i = 0; i < edgesSize; i++) {
            if (edges[i][0] == currentVertex && !visited[edges[i][1]]) {
                queue[rear++] = edges[i][1];  
                visited[edges[i][1]] = true; 
            } else if (edges[i][1] == currentVertex && !visited[edges[i][0]]) {
                queue[rear++] = edges[i][0];  
                visited[edges[i][0]] = true;  
            }
        }
    }
    
    free(queue);
    free(visited);
    return false;
}