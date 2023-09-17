#include "ArrayList.h"
#include "LinkedList.h"
#include "Util.h"

static int LeftEdges(ArrayList* edges) {
    for (int i = 0; i < edges->size; i++) {
        LinkedList* edge = edges->Get(edges, i);
        if (edge->size != 0)
            return i;
    }

    return -1;
}

static void GetTrail(LinkedList* trail, int node, ArrayList* edges) {
    trail->Append(trail, node);
    
    LinkedList* nextEdge = edges->Get(edges, node);
    if (nextEdge->size != 0) {
        int nextNode = nextEdge->head->value;
        nextEdge->Delete(nextEdge, nextEdge->head);
        GetTrail(trail, nextEdge, edges);
    }
}

static void EulerTrial2(ArrayList* edges) {
    LinkedList* allTrials = NewLinkedList();

    int node = LeftEdges(edges);
    while (node != -1) {
        LinkedList* trail = NewLinkedList();
        trail->Append(trail, node);

        GetTrail(trail, node, edges);
        allTrials->Append(allTrials, trail);

        node = LeftEdges(edges);
    }
}

static void EularTrailAllEven() {
    ArrayList* edges = NewArrayList();

    LinkedList* edge0 = NewLinkedList();
    edge0->Append(edge0, 1);
    edge0->Append(edge0, 2);
    edge0->Append(edge0, 3);
    edge0->Append(edge0, 4);
    edges->Append(edges, edge0);

    LinkedList* edge1 = NewLinkedList();
    edge1->Append(edge1, 0);
    edge1->Append(edge1, 2);
    edge1->Append(edge1, 3);
    edge1->Append(edge1, 4);
    edges->Append(edges, edge1);    

    LinkedList* edge2 = NewLinkedList();
    edge2->Append(edge2, 0);
    edge2->Append(edge2, 1);
    edge2->Append(edge2, 3);
    edge2->Append(edge2, 5);
    edges->Append(edges, edge2);  

    LinkedList* edge3 = NewLinkedList();
    edge3->Append(edge3, 0);
    edge3->Append(edge3, 1);
    edge3->Append(edge3, 3);
    edge3->Append(edge3, 4);
    edges->Append(edges, edge3);     

    LinkedList* edge4 = NewLinkedList();
    edge4->Append(edge4, 0);
    edge4->Append(edge4, 1);
    edge4->Append(edge4, 3);
    edge4->Append(edge4, 5);
    edges->Append(edges, edge4);            

    LinkedList* edge5 = NewLinkedList();
    edge5->Append(edge5, 2);
    edge5->Append(edge5, 4);
    edges->Append(edges, edge5);        

    EulerTrial2(edges);
    
    for (int i = 0; i < edges->size; i++)
        DeleteLinkedList(edges->Get(edges, i));
    DeleteArrayList(edges);
}

void _8_8_EulerTrial() {
    EularTrailAllEven();
}