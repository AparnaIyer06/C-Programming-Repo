/*Experiment 10: Write a program in C to implement Depth First Search using linked representation
of graph. */
#include<stdio.h>
int adj[10][10]= {
				 {0,1,1,1,0},
				 {1,0,1,0,0},
				 {1,1,0,0,1},
				 {1,0,0,0,0},
				 {0,0,1,0,0},
};
int i,j, visited[10], queue[10], front= -1, rear=-1;
int vertex = 5;

void insert (int v)
{
	//if freont and rear both are at -1 iterate to 0 position to insert at 0 position
	// front to releaswe and rear to enter data
	if(rear ==-1 && front == -1){
		rear = front=0;
	}
	else {
		rear++;
	}
	queue[rear]=v;
}
int deletion(){
	int data = queue [front];
	if(front==rear){
		front=rear=-1;
	}
	else{
		front++;
	}
	return data;
}
void BFS(){
	int S = 0; // vertex to be start
	visited[S]=0;
	// when front and rear is at -1 queue is empty 
	insert(S);

	while(rear!=-1){ 
		int data = deletion();
		printf("%d",data);
		for(i=0;i<vertex;i++){
			if(adj[data][i]!=0 && visited[i]==-1){
				visited[i]=0;
				insert(i);
			}
		}
    }
	
}
// Front and rear ar -1 to know that queue is empty 
// rear ++ when 
//when front and rear are at same position only 1 empty in the list 
int main(){
	for(i=0;i<vertex;i++){
		visited [i]= -1;
	}
	
	
	BFS();
return 1;
}

