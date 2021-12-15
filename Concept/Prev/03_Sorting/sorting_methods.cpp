#pragma region
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include <string>

#include <algorithm>
#include <functional>
#include <utility>
#include <random>
#define SWAP(a, b, type) { type temp = a; a = b; b = temp; }
using namespace std;

typedef unsigned int ui;

const int MN = 7;
const int MOD = 1004;
const char *sortFuncNames[8] = {"Bubble Sort", "Selection Sort", "Insertion Sort",
                                "Quick Sort", "Merge Sort", "Heap Sort", "Radix Sort", "Counting Sort"};

string divStr = "------------------";
int arr[MN];

void setDiv()
{
    string concat = "-----";
    for (int i = 0; i < MN; i++)
    {
        divStr += concat;
    }
}

void printDiv()
{
    printf("%s\n", divStr.c_str());
}

void setArr()
{
    srand((ui)time(NULL));

    for (int i = 0; i < MN; i++)
    {
        int num = rand() % MOD;
        arr[i] = num;
    }
}

void printArr()
{
    printDiv();
    printf("idx : ");
    for (int i = 0; i < MN; i++)
    {
        printf("%4d ", i);
    }
    printf("\n");

    printf("arr : ");
    for (int i = 0; i < MN; i++)
    {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

void printRound(int round)
{
    if (round == 1)
    {
        printDiv();
    }
    printf("\t[round %d]\n", round);
    printf("\tarr : ");
    for (int i = 0; i < MN; i++)
    {
        printf("%4d ", arr[i]);
    }
    printf("\n");
}

/*
    0. [x] 거품 정렬(Bubble Sort)
    1. [x] 선택 정렬(Selection Sort)
    2. [x] 삽입 정렬(Insertion Sort)
    3. [] 퀵 정렬(Quick Sort)
    4. [] 병합 정렬(Merge Sort)
    5. [] 힙 정렬(Heap Sort)
    6. [] 기수 정렬(Radix Sort)
    7. [] 계수 정렬(Counting Sort)
*/
void bubbleSort()
{
    for (int i = 0; i < MN - 1; i++)
    {
        for (int j = 1; j < MN - i; j++)
        {
            if (arr[j] < arr[j - 1])
                SWAP(arr[j - 1], arr[j], int);
        }
        printRound(i + 1);
    }
}

void selectionSort()
{
    for (int i = 0; i < MN - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < MN; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        SWAP(arr[i], arr[minIdx], int);
        printRound(i + 1);
    }
}

void insertionSort()
{
    for (int i = 1; i < MN; i++)
    {
        int pick = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > pick)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = pick;

        printRound(i);
    }
}
void quickSort()
{
    int i = 1, left = 0, right = MN-1;
    function<void(int, int)> qSort;
    function<int(int, int)> partition;

    partition = [&arr](int left, int right) -> int {
        int pivot = arr[left];
        int i=left, j = right;

        while(i<j) {
            while(pivot < arr[j]){
                j--;
            }
            while(i<j&&pivot>=arr[i]){
                i++;
            }
            SWAP(arr[i], arr[j], int);
        }
        arr[left] = arr[i];
        arr[i] = pivot;

        return i;
    };

    qSort = [&](int left, int right) {
        if(left >= right) return;
        printf("%d, %d ", left, right);

        int pivotIdx = partition(left, right);
        printRound(i++);

        qSort(left, pivotIdx-1);
        qSort(pivotIdx+1, right);
    };

    qSort(left, right);    
}

void mergeSort()
{
    int arr2[MN];
    int round=1;
    function<void(int, int)> merge;
    function<void(int, int)> partition;

    partition = [&partition, &merge](int left, int right) {
        if(left<right) {
            int mid = (left + right) / 2;
            partition(left, mid);
            partition(mid+1, right);
            merge(left, right);
        }
    };

    merge = [&](int left, int right) {
        printf("%d, %d", left, right);
        int mid = (left+right)/2;
        int i=left, j=mid+1, k=left;

        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                arr2[k++] = arr[i++];
            }
            else {
                arr2[k++] = arr[j++];
            }
        }
        int tmp = i>mid ? j : i;
        while(k<=right) {arr2[k++] = arr[tmp++];}
        for(i=left; i<=right; i++) {arr[i]=arr2[i];}
        printRound(round++);
    };

    partition(0, MN-1);
}

void heapSort()
{
    int round = 1;
    function<void(int, int)> heapify;
    function<void(int)> heapsort;

    // 최대힙
    heapify = [&](int last, int i) {
        int p=i;
        int l=2*p+1;
        int r=2*p+2;

        if(l<last&&arr[p]<arr[l])
            p=l;
        if(r<last&&arr[p]<arr[r])
            p=r;

        if(p!=i){
            SWAP(arr[p], arr[i], int);
            heapify(last, p);
        }
    };

    heapsort = [&](int last) {
        // 최대힙 구성
        for(int p=last/2-1; p>=0; p--){
            heapify(last, p);
        }
        printRound(round++);     

        for(int i=last-1; i>0; i--){
            SWAP(arr[0], arr[i], int);
            heapify(i, 0);
            printRound(round++);            
        }
    };
    heapsort(MN);
}
#pragma endregion

void radixSort()
{
    
}

void countingSort()
{
}

void (*sortFuncs[8])() = {bubbleSort, selectionSort, insertionSort, quickSort, mergeSort, heapSort, radixSort, countingSort};

void solve()
{
    setDiv();
    int cmd;
    while (scanf("%d", &cmd))
    {
        if (cmd == -1)
        {
            break;
        }
        printf(">>>%s\n", sortFuncNames[cmd]);
        setArr();
        printArr();

        sortFuncs[cmd]();
        printArr();
        printf("\n");
    }
}

int main()
{
    solve();

    return 0;
}