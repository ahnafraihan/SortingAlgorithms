// Sorting Algorithms - main.cpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void insertionSort (int A[], long length);
void mergeSort(int A[], int p, int r);
void quickSort(int A[], int p, int r);
void randomizedQuickSort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);
int partition(int A[], int p, int r);
int randomizedPartition(int A[], int p, int r);

/* insertionSort is a sorting algorithm that is best for sorting small sets of data. Insertion sort works by taking an unsorted array and removing one member at a time and relocating it into its sorted spot. Insertion Sort takes an Unsorted array of integers A[] and a length containing the length of the array. We assume length is non-negative. */

void insertionSort (int A[], long length) {
    int j, temp; // j is used as a key, temp is used as a temporary integer to hold array value
    for (int i = 0; i < length; i++){
        j = i;
        //insert unsorted number into sorted sequence
        while (j > 0 && A[j] < A[j - 1]){ //Move numbers greater than key to correct position
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j--;
        }
    }
}

/* mergeSort is a sorting algorithm that is based on the divide and conquer method of programming. We use subarray A for the algorithm. For the algorithm our base case is an array with 0 or 1 element (sorted), otherwise we divide the array in half into 2 subarrays. We then recursively "conquer" the 2 subarrays. mergeSort then combines the now sorted subarrays into our original array using the merge helper function. A[] is our array to be sorted, p is the left index and r is right index of the subarray of A to sort. We assume p and r are non-negative. */

void mergeSort(int A[], int p, int r) {
    int q; // q used to hold result of divide step
    if(p < r) {  // Base case
        q = (p + r) / 2; // Divide
        mergeSort(A, p, q); // Conquer (sort A[p...q])
        mergeSort(A, q + 1, r); // Conquer (sort A[q+1...r])
        merge(A, p, q, r); // merge it together
    }
}

/* the quickSort function is the implementation of the quick sort sorting algorithm. Quick Sort works by choosing a pivot point in the array around which to partition the array into 2 subarrays, where the subarray to the left of the pivot point conatins values less than the pivot value and the subarray to the right of the pivot point contains values greater than the pivot value. It is a divide and conquer strategy so once we have the original array split up into two partitions, we recursively call quickSort on each of those subarrays. The function takes in as parameters an original array to sort, A[], a beginning array index, p, and an ending array index, r */

void quickSort(int A[], int p, int r) {
    // if the starting index is less than the ending index
    if (p < r) {
        // q is the pivot point around which to create the partitions
        // capture the pivot value by calling the partition function, sending in the
        // original array to be sorting, and it's starting and ending indexes
        int q = partition(A,p,r);
        // at this point we have our pivot value of q
        // so recursively call quicksort on both the left partition and the right partition
        // the left partition is the portion of the array from the starting index to q -1
        // the right partition is the portion of the arry from q + 1 to the ending index
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

/* the partition is called from the quickSort function. the partition function does the actual work of separating the array into 2 subarrays, with the subarray on the left containing all values less than the pivot and with the subarray on the right containing all values greater than the pivot. the partition function takes in the original array to be sorted, A[], and a starting index p and an ending index, r */

int partition(int A[], int p, int r) {
    // declare i to be used in the for loop
    // declare q to hold the pivot index, q initially set to -1
    // declare temp variable to hold temporary values when moving elements in the array
    int q = p - 1, i;
    int temp = 0;
    // loop through entire array
    for (i = p; i < r; i++) {
        // whenever the ith element is less or equal to the pivot value
        // which is the last item in the array, r
        // increment q, and swap the qth element with the ith element
        if (A[i] <= A[r]) {
            ++q;
            temp = A[q];
            A[q] = A[i];
            A[i] = temp;
        }
    }
    
    // now that we've set up the array into the two partitions, we need to move
    // our pivot point to the index that is in between the two partitions
    ++q;
    temp = A[q];
    A[q] = A[r];
    A[r] = temp;
    
    // return the index of where our partition splits
    return q;
}

/* the randomizedQuickSort function is the implementation of the random quick sort sorting algorithm. Random quick sort works exactly the same as quick sort except we randoming choose an index for the pivot point instead of always choosing the last item in the array as we do in quick sort. It is a divide and conquer strategy so once we have the original array split up into two partitions, we recursively call quickSort on each of those subarrays. The function takes in as parameters an original array to sort, A[], a beginning array index, p, and an ending array index, r */

void randomizedQuickSort(int A[], int p, int r) {
    // if the beginning index is less than the ending index
    if (p < r) {
        // capture the index around which to partition by calling randomizedPartition
        // we send in the original array A[] to be sorted, the beginning index q and the
        // ending index r
        int q = randomizedPartition(A,p,r);
        // at this point we have our pivot value of q
        // so recursively call randomizedQuickSort on both the left partition and the
        // right partition
        // the left partition is the portion of the array from the starting index to q -1
        // the right partition is the portion of the arry from q + 1 to the ending index
        randomizedQuickSort(A, p, q - 1);
        randomizedQuickSort(A, q + 1, r);
    }
}

/* the randomizedPartition is called from the randomizedQuickSort function. the partition function does the actual work of separating the array into 2 subarrays, with the subarray on the left containing all values less than the randomly selected pivot and with the subarray on the right containing all values greater than the randomly selected pivot. the partition function takes in the original array to be sorted, A[], and a starting index p and an ending index, r */

int randomizedPartition(int A[],int p,int r) {
    // declare i to be used in the for loop
    // declare q to eventually hold the pivot index, q initially set to -1
    // declare temp variable to hold temporary values when moving elements in the array
    // declare a random number between the start index and end index to be used at the pivot index
    int q = p - 1, i;
    int temp = 0;
    int randomNum = (rand() % (r - p)) + p;
    
    // temp will hold the value at the randomly generated index
    // move the end index to where the randomNum index was
    // and move the randomNum index value to the end of the array
    temp = A[randomNum];
    A[randomNum] = A[r];
    A[r] = temp;
    
    // loop through the entire array
    for (i = p; i < r; i++) {
        // whenever the ith element is less or equal to the pivot value
        // which is the last item in the array, r, although r was randomly selected this time
        // increment q, and swap the qth element with the ith element
        if (A[i] <= A[r]) {
            ++q;
            temp = A[q];
            A[q] = A[i];
            A[i] = temp;
        }
    }
    
    // now that we've set up the array into the two partitions, we need to move
    // our pivot point to the index that is in between the two partitions
    ++q;
    temp = A[q];
    A[q] = A[r];
    A[r] = temp;
    
    // return the index of where our partition splits
    return q;
}

/* merge is used as a helper function for the mergeSort function. It serves as the combine step to mergeSort's divide and conquer strategy. Merge takes two parts L and R and combines them back together to create A[]. merge combines two subarrays of A[], the first subarray being A[l...m] and the second being A[m+1...r]. p, q, and r are used to index into A. Assume p, q, and r are non-negative. */

void merge(int A[], int p, int q, int r) {
    // create index values
    int n1 = q - p + 1;
    int n2 = r - q;
    
    // create temporary arrays L and R
    int L[n1 + 1];
    int R[n2 + 1];
    
    // copy data from A into temporary arrays L and R
    for(int i = 1; i <= n1; i++) {
        L[i] = A[p + i - 1];
    }
    for(int j = 1; j <= n2; j++) {
        R[j] = A[q + j];
    }
    
    L[n1 + 1] = 999;
    R[n2 + 1] = 999;
    
    int i = 1, j = 1;
    
    // merge temporary arrays back into original array A
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

int main(int argc, char *argv[]) {
    
    // assign random value to variable "seed" to use when generating random numbers
    // to be put in the random test case array
    unsigned long seed = time(NULL);
    srand(seed);
    
    // array to hold results of insertion sort tests on reverse order arrays
    double insertion_sort_reverse[4];
    
    
    // ======================== TESTING REVERSE ARRAYS ======================================
    
    cout << "Insertion Sort - Reversed Array: " << endl;	// -------- insertion sort reverse arrays
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *reverse_array = new int[size];
        // use j to assign items to array from index 0 to size
        // use k to fill in values in reverse order from size-1 to 0
        int j = 0;
        for (int k = size-1; k >= 0; k--) {
            reverse_array[j] = k;
            j++;
        }
        
        // capture the beginning time that the function started operating
        // send the array and the array's size to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        insertionSort(reverse_array, size);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        insertion_sort_reverse[i] = elapsed_time;
        cout << insertion_sort_reverse[i] << endl;
    }
    
    cout << "Merge Sort - Reversed Array: " << endl;       // --------------- merge sort reverse arrays
    
    // array to hold results of merge sort tests on reverse order arrays
    double merge_sort_reverse[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *reverse_array = new int[size];
        // use j to assign items to array from index 0 to size
        // use k to fill in values in reverse order from size-1 to 0
        int j = 0;
        for (int k = size-1; k >= 0; k--) {
            reverse_array[j] = k;
            j++;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the beginning index, and the ending index of the array
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        mergeSort(reverse_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        merge_sort_reverse[i] = elapsed_time;
        cout << merge_sort_reverse[i] << endl;
    }
    
    cout << "Quick Sort - Reversed Array: " << endl;       // --------------- quicksort reverse arrays
    
    // array to hold results of quick sort tests on reverse order arrays
    double quick_sort_reverse[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *reverse_array = new int[size];
        // use j to assign items to array from index 0 to size
        // use k to fill in values in reverse order from size-1 to 0
        int j = 0;
        for (int k = size-1; k >= 0; k--) {
            reverse_array[j] = k;
            j++;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the beginning index, and the ending index of the array
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        quickSort(reverse_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        quick_sort_reverse[i] = elapsed_time;
        cout << quick_sort_reverse[i] << endl;
    }
    
    cout << "Randomized Quick Sort - Reversed Array: " << endl;       // ------- quicksort reverse arrays
    
    // array to hold results of randomized quick sort tests on reverse order arrays
    double randomized_quick_sort_reverse[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *reverse_array = new int[size];
        // use j to assign items to array from index 0 to size
        // use k to fill in values in reverse order from size-1 to 0
        int j = 0;
        for (int k = size-1; k >= 0; k--) {
            reverse_array[j] = k;
            j++;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the beginning index, and the ending index of the array
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        randomizedQuickSort(reverse_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        randomized_quick_sort_reverse[i] = elapsed_time;
        cout << randomized_quick_sort_reverse[i] << endl;
    }
    
    // ======================== TESTING RANDOM ARRAYS ======================================
    
    cout << "Insertion Sort - Random Array: " << endl;			// -------- insertion sort random arrays
    
    // array to hold results of insertion sort on random order arrays
    double insertion_sort_random[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *random_array = new int[size];
        // assign a random positive number less than 1000 to each spot in the array
        for (int i = 0; i < size; i++) {
            random_array[i] = rand() % 1000;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's size
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        insertionSort(random_array, size);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        insertion_sort_random[i] = elapsed_time;
        cout << insertion_sort_random[i] << endl;
    }
    
    cout << "Merge Sort - Random Array: " << endl;       // ------------ merge sort random arrays
    
    // array to hold results of merge sort on random order arrays
    double merge_sort_random[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *random_array = new int[size];
        // assign a random positive number less than 1000 to each spot in the array
        for (int i = 0; i < size; i++) {
            random_array[i] = rand() % 1000;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's size
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        mergeSort(random_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        merge_sort_random[i] = elapsed_time;
        cout << merge_sort_random[i] << endl;
    }
    
    cout << "Quick Sort - Random Array: " << endl;       // ------------ quick sort random arrays
    
    // array to hold results of quick sort on random order arrays
    double quick_sort_random[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *random_array = new int[size];
        // assign a random positive number less than 1000 to each spot in the array
        for (int i = 0; i < size; i++) {
            random_array[i] = rand() % 1000;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's beginning index and ending index
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        quickSort(random_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        quick_sort_random[i] = elapsed_time;
        cout << quick_sort_random[i] << endl;
    }
    
    cout << "Randomized Quick Sort - Random Array: " << endl; // --- ramdon quick sort random arrays
    
    // array to hold results of randomized quick sort on random order arrays
    double randomized_quick_sort_random[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *random_array = new int[size];
        // assign a random positive number less than 1000 to each spot in the array
        for (int i = 0; i < size; i++) {
            random_array[i] = rand() % 1000;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's size
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        randomizedQuickSort(random_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        randomized_quick_sort_random[i] = elapsed_time;
        cout << randomized_quick_sort_random[i] << endl;
    }
    
    // ======================== TESTING ORDERED ARRAYS ======================================
    
    
    cout << "Insertion Sort - Ordered Array: " << endl;			// -------- insertion sort ordered arrays
    
    // array to hold results of insertion sort on ordered arrays
    double insertion_sort_ordered[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *ordered_array = new int[size];
        // fill array of values in increasing order from 0 to size-1
        for (int i = 0; i < size; i++) {
            ordered_array[i] = i;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's size
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        insertionSort(ordered_array, size);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        insertion_sort_ordered[i] = elapsed_time;
        cout << insertion_sort_ordered[i] << endl;
    }
    
    cout << "Merge Sort - Ordered Array: " << endl;			// -------- merge sort ordered arrays
    // array to hold results of merge sort on ordered arrays
    double merge_sort_ordered[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *ordered_array = new int[size];
        // fill array of values in increasing order from 0 to size-1
        for (int i = 0; i < size; i++) {
            ordered_array[i] = i;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's starting and ending index
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        mergeSort(ordered_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        merge_sort_ordered[i] = elapsed_time;
        cout << merge_sort_ordered[i] << endl;
    }
    
    cout << "Quick Sort - Ordered Array: " << endl;			// -------- quick sort ordered arrays
    
    // array to hold results of quick sort on ordered arrays
    double quick_sort_ordered[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *ordered_array = new int[size];
        // fill array of values in increasing order from 0 to size-1
        for (int i = 0; i < size; i++) {
            ordered_array[i] = i;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's starting and ending index
        // to the sorting function
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the
        // number of clock cycles that go by per second
        clock_t begin = clock();
        quickSort(ordered_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        quick_sort_ordered[i] = elapsed_time;
        cout << quick_sort_ordered[i] << endl;
    }
    
    cout << "Random Quick Sort - Ordered Array: " << endl;	// ----- random quick sort ordered arrays
    
    // array to hold results of random quick sort on ordered arrays
    double random_quick_sort_ordered[4];
    // loop through 4 times, reassigning the size variable each time to
    // create the correctly sized test arrays
    for (int i = 0; i < 4; i++) {
        int size = -1;
        
        if (i == 0) {
            size = 25000;
        } else if (i == 1) {
            size = 50000;
        } else if (i == 2) {
            size = 75000;
        } else {
            size = 100000;
        }
        
        // declare the array of correct size, depending on which iteration of the
        // for loop we are currently in
        int *ordered_array = new int[size];
        // fill array of values in increasing order from 0 to size-1
        for (int i = 0; i < size; i++) {
            ordered_array[i] = i;
        }
        
        // capture the beginning time that the function started operating
        // send the array, and the array's starting and ending index	
        // to the sorting function	
        // capture the end time that the function completed
        // capture elapsed time by subtracting end from begin and dividing by the 
        // number of clock cycles that go by per second
        clock_t begin = clock();
        randomizedQuickSort(ordered_array, 0, size-1);
        clock_t end = clock();
        double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
        
        // capture the timing results from each of the 4 iterations in an array
        // output the time it took for this iteration to complete to the terminal
        random_quick_sort_ordered[i] = elapsed_time;
        cout << random_quick_sort_ordered[i] << endl;
    }
}
