#include "Util.h"

void RunC100() {
    _5_1_InsertSortBinarySearch();
    _5_2_ShellSort();
    _5_3_QuickSort();
    _5_4_StableQuickSort();
    _5_5_IterativeQuickSort();
    _5_6_FindMedian();
    _5_7_HeapSort();
    _5_8_HeapSort2();
    _5_9_MergeSort(); 
    _5_10_BucketSort();  
    _5_11_SingleDuplicate();
    _5_12_EvenDuplicate();
    _5_13_HeapMerge();
    _5_14_Unique();
    _5_15_ZeroSum();
    _8_1_MagicSquareOdd(5);
    _8_5_EightQueen();
    _8_6_KnightTour(5, 5);    
    _8_7_HamiltonCycle();
    _8_8_EulerTrial();
    _8_9_HonoiTower(4);  
    _8_10_GameOfLife(6, 5);
}

void RunUt() {
    Ut();
}

int main() {
    RunC100();    
    Ut();    
    
    printf("main() ended\n");
}