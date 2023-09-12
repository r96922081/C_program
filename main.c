#include "stdio.h"
#include "stdlib.h"
#include "util/util.h"
#include "ds/LinkedList.h"
#include "ds/ArrayList.h"
#include "c100/_8_5_EightQueen.h"
#include "c100/_8_1_MagicSquareOdd.h"

int main(){
    //Solve8Queens();
    MagicSquareOdd(5);


    ArrayList *list = malloc(sizeof(ArrayList));
    InitArrayList(list);
    list->Append(list, 5);
    list->Append(list, 11);
    int x = list->Get(list, 0);
    int y = list->Get(list, 1);
    DeleteArrayList(list);

    //ArrayListUt();
    //LinkedListUt();
    


    printf("main() ended\n");
}