#include <stdio.h>

struct node
{
    int type;
    struct node *next;
};
void read_graph(struct node *adj[], int no_of_nodes)
{
   struct node *new_node;
   int i,j,no_of_neighbors,val;
   for(i=0; i<no_of_nodes; ++i)
   {
       struct node *last = NULL;
       printf("\nEnter the number of neighbours of node %d", i+1);
       scanf("%d", &no_of_neighbors);
       for(j=0; j<no_of_neighbors; ++j)
       {
           printf("Enter the value of %d neighbour of %d", j+1, i+1);
           scanf("%d", &val);
           new_node = (struct node *)malloc(sizeof(struct node *));
           new_node->type = val;
           new_node->next = NULL;
           if(adj[i]==NULL)
           {
               adj[i] = new_node;
           }
           else
           {
               last->next =new_node;
           }
           last = new_node;
       }
   }
}

void print_graph(struct node *adj[], int no_of_nodes)
{
    struct node *ptr =NULL;
    int i;
    for(i=0; i<no_of_nodes; ++i)
    {
        ptr = adj[i];
        printf("\nThe neighbours of %d are: ", i+1);
        while(ptr!= NULL)
        {
            printf("%d\t", ptr->type);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int i,nodes;
    printf("Enter the nodes");
    scanf("%d", &nodes);

    struct node *adj[nodes];
    for(i =0; i<nodes; i++)
    {
        adj[i] = NULL;
    }
    read_graph(adj,nodes);
    print_graph(adj,nodes);
    return 0;
}
