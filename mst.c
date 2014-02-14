#include <stdio.h>
#include <stdlib.h>


#define ROW_DELIM '\n'
#define NUM_DELIM ','


typedef struct{
	int **matrix;
	int *used;
	int *not;
	int n_left;
	int side;
} graph_t;

typedef struct{

	int x,y;

} pt;


void print_graph(graph_t *graph);
graph_t *new_graph(int side);
void load_graph(graph_t **graph,int side);
int get_num();
int is_used( graph_t * graph, int node);

int main(int argc, char **argv){
	int side;

	side = atoi(argv[1]);
	printf("Side: %d\n",side);
	graph_t *graph;
	graph_t *tree;
	tree = new_graph(side);
	graph = new_graph(side);
	load_graph(&graph,side);
	print_graph(graph);
	
	tree = mst(graph);


}

graph_t *mst(graph_t *graph){
	
	pt best;

	while(graph->n_left){
		
	}

}

pt best(graph_t *graph){
	int x,y;
	int i;

	for(i=0; i < graph->n_left; i++){
	
	}

}






int is_used( graph_t *graph, int node){
	if(graph->used[node]){
		return 1;
	}
	return 0;

}

int toggle_used(graph_t *graph, int node){
	int i;
	i = node;
	if(graph->used[i]){
		graph->used[i] = 0;
		graph->not[i] = 1;
		graph->n_left += 1;
	}else{
		graph->used[i] = 1;
		graph->not[i] = 0;
		graph->n_left -= 1;
	}
}

void print_graph(graph_t *graph){
	int i,j;
	for(i=0; i < graph->side; i++){
		for(j=0; j < graph->side; j++){
			printf("%d",graph->matrix[i][j]);
			if(j != graph->side-1) printf(",");


		}
		printf("\n");
	}	

}

graph_t *new_graph(int side){
	
	//printf("Making new graph struct.\n");
	int i;
	graph_t *newgraph;
	newgraph = calloc(1,sizeof(graph_t));
	newgraph->matrix = calloc(side,sizeof(graph_t*));
	for(i=0;i<side;i++){
		newgraph->matrix[i] = calloc(side,sizeof(int));
	}
	newgraph->side = side;
	newgraph->used = calloc(side,sizeof(int));
	newgraph->not = calloc(side,sizeof(int));
	newgraph->n_left = side;

	for(i=0; i < side; i++){
		newgraph->not[i] = 1;
	}

	return newgraph;

}

void load_graph(graph_t **graph,int side){
	int i,j;
	int num;
	*graph = new_graph(side);
	printf("Loading graph data from stdin.\n");
	for(i=0;i<side;i++){
		for(j=0;j<side;j++){
			num = get_num();
			//printf("loaded (%d,%d):\t%d\n",i,j,num);
			(*graph)->matrix[i][j] = num;

		}
	}

}

int get_num(){
	char string[5];
	char temp;
	int num;
	int count=0;

	while(1){
		count++;
		temp = (char)getchar();
//		printf("%c",temp);
		switch(temp){
			case(NUM_DELIM):
				string[count] = '\0';
				//printf("%s\n",string);
				num = strtol(&string[1],NULL,10);
				return num;
				break;
			case(ROW_DELIM):
				string[count] = '\0';
				num = strtol(&string[1],NULL,10);
				return num;
				break;
			default:
				string[count]=temp;
				break;

		}

	}

}
