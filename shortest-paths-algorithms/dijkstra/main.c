#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minDistancecalc(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V];

    bool sptSet[V]; 
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    dist[src] = 0;
    printf("initial configuration\n");
    printSolution(dist,sptSet);
    printf("----------------------------------------------------------------------------------------\n");
    for (int nodes = 0; nodes < V; nodes++) {
        int minDistance = minDistancecalc(dist, sptSet);
	printf("min distance is node %i\n",minDistance);
        sptSet[minDistance] = true;
	printf("updating %i node neighboor\n",nodes);
        for (int possibleNeighboors = 0; possibleNeighboors < V; possibleNeighboors++)
	  {
	    printf("passing through weights of neighboor %i\n",possibleNeighboors);
            if (!sptSet[possibleNeighboors] && graph[minDistance][possibleNeighboors]
                && dist[minDistance] != INT_MAX
                && dist[minDistance] + graph[minDistance][possibleNeighboors] < dist[possibleNeighboors]){
	      printf("updating distance of %i from %i to %i\n ", possibleNeighboors, dist[possibleNeighboors],dist[minDistance] +graph[minDistance][possibleNeighboors]);
	      dist[possibleNeighboors] = dist[minDistance] + graph[minDistance][possibleNeighboors];
	    }
	  }
	printf("node %i updated on stp\n",minDistance);
	printSolution(dist,sptSet);
	printf("----------------------------------------------------------------------------------------\n");
    }
    printf("final solution: \n");
    printSolution(dist,sptSet);

}
int main()
{
  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },//0
		      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },//1
		      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },//2
		      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },//3 
		      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },//4
		      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },//5
		      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },//6
		      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },//7
		      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };//8 
 
    dijkstra(graph, 0);

    return 0;
}

void printSTPSET(bool stpSet[]){
  for (int i =0;i <V;i++){
    printf(stpSet[i]? "true\n":"false\n");
    }
}
void printSolution(int dist[],bool sptSet[]){
  	printf("distances of the source:\n ");
	printf("node \t\t\t\t weight\t\t\t\t calculated\n");
	for (int i=0;i <V;i++) {
		printf("%d \t\t\t\t %d\t\t\t\t", i, dist[i]);
		printf(sptSet[i]? "true\n":"false\n");
	}
}

  
