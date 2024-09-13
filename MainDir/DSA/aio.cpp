#include <iostream>
int sort_swap(int &a,int &b);
int quick_sort(int a[], int l, int r);
int selection_sort_algorithm(int size_of_array,int unsorted_arr[]);
int insertion_sort_algorithm(int size_of_array,int unsorted_arr[]);
int bubble_sort_algorithm(int size_of_array,int unsorted_arr[]);
int quicksort_sort_algorithm(int size_of_array,int unsorted_arr[],int lower_bound,int upper_bound);
void sort_output(int size_of_array,int unsorted_arr[]);
int mergesort_sort_algorithm(int unsorted_arr[],int size_of_array);
void merge(int left_arr[],int right_arr[],int unsorted_array[],int size_of_array);
int partition(int unsorted_arr[],int low,int high,int size_of_array);
//global variable
int counter_q=0;
int main() {
    int size_of_array,input_choice;
    std::cout << "Hello, World!" << std::endl;
    std::cout<<"Program for sorting"<<std::endl;
    int unsorted_arr[10];
    std::cout<<"enter the number of elements to be inserted"<<std::endl;
    std::cin>>size_of_array;
    for(int i=0;i<size_of_array;i++) {
        std::cout<<"enter array element number - "<<i<<" -> "<<std::endl;
        std::cin>>unsorted_arr[i];
    }
    //array output
    std::cout<<"array you entered is - ";
    for(int i=0;i<size_of_array;i++) {
        std::cout << unsorted_arr[i] << " ";
    }
    std::cout<<"Choose an option to sort"<<std::endl;
    std::cout<<"1)Selection Sort"<<std::endl;
    std::cout<<"2)Insertion Sort"<<std::endl;
    std::cout<<"3)Bubble Sort"<<std::endl;
    std::cout<<"4)QuickSort"<<std::endl;
    std::cout<<"5)MergeSort"<<std::endl;
    std::cin>>input_choice;
    switch (input_choice) {
        case 1:
            std::cout<<"SelectionSort Selected"<<std::endl;
            selection_sort_algorithm(size_of_array,unsorted_arr);
            break;
        case 2:
            std::cout<<"InsertionSort Selected"<<std::endl;
            insertion_sort_algorithm(size_of_array,unsorted_arr);
            break;
        case 3:
            std::cout<<"BubbleSort Selected"<<std::endl;
            bubble_sort_algorithm(size_of_array,unsorted_arr);
            break;
        case 4:
            std::cout<<"QuickSort Selected"<<std::endl;
            quicksort_sort_algorithm(size_of_array,unsorted_arr,0,size_of_array-1);
            break;
        case 5:
            std::cout<<"MergeSort Selected"<<std::endl;
            mergesort_sort_algorithm(unsorted_arr,size_of_array);
        //array output for merge sort
            sort_output(size_of_array,unsorted_arr);

            break;
        default:
            std::cout<<"invalid input"<<std::endl;
            break;
    }


    return 0;
}
int sort_swap(int &a, int &b) {

    int temp_var = a;
    a=b;
    b=temp_var;
    return 0;
}
int selection_sort_algorithm(int size_of_array,int unsorted_arr[]) {
    //selection sort
    for(int i=0;i<size_of_array;i++) {
        for(int j=i+1;j<size_of_array;j++) {
            if(unsorted_arr[i] > unsorted_arr[j]) {
                sort_swap(unsorted_arr[i],unsorted_arr[j]);
            }
        }
    }
    std::cout<<"sorting complete"<<std::endl;
    //sorted output
    for(int i=0;i<size_of_array;i++) {
        std::cout << unsorted_arr[i] << " ";
    }
    std::cout<<std::endl;
    return 0;
}
int insertion_sort_algorithm(int size_of_array,int unsorted_arr[]) {
    //insertion sort

    /*we start from index number 1(basically 2 element of the array)
     because we assume the first element is already sorted
    */
    //we initialize an extra variable current which will store the current element the pointer is on
    for(int i=1;i<size_of_array;i++) {
        int current = unsorted_arr[i];
        /*
        Start comparing this element 'current' with the elements on its left
        (the sorted part of the array) 'j'. Move all elements that are
        greater than the current element to the right by one position.
        */
        int j=i-1;
        //j>=0 is to avoid array out of bounds error
        while(j>=0 && unsorted_arr[j] > current) {
            unsorted_arr[j+1] = unsorted_arr[j];
            j--;
        }
        unsorted_arr[j+1] = current;
    }
    //output
    for(int i=0;i<size_of_array;i++) {
        std::cout << unsorted_arr[i] << " ";
    }
    return 0;
}
int bubble_sort_algorithm(int size_of_array, int unsorted_arr[]) {
    for (int i = 0; i < size_of_array - 1; i++) {
        //size of array-1 tells the loop not to iterate already sorted element
        for (int j = 0; j < size_of_array - 1 - i; j++) {
            //'size of array' - '1' - 'i'  is num of comparisons(decreasing i from size means lesser comparisons)
            if (unsorted_arr[j] > unsorted_arr[j + 1]) {
                std::swap(unsorted_arr[j], unsorted_arr[j + 1]);
            }
        }
    }

    // Output
    for (int i = 0; i < size_of_array; i++) {
        std::cout << unsorted_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


int quicksort_sort_algorithm(int size_of_array, int unsorted_arr[],int lower_bound,int upper_bound) {
    if (lower_bound < upper_bound) {
        int location = partition(unsorted_arr,lower_bound,upper_bound,size_of_array);
        quicksort_sort_algorithm(size_of_array,unsorted_arr,lower_bound,location-1);
        quicksort_sort_algorithm(size_of_array,unsorted_arr,location+1,upper_bound);
        counter_q++;
    }
    if(counter_q==2) {
        sort_output(size_of_array,unsorted_arr);
    }



    return 0;
}
int partition(int unsorted_arr[], int low, int high,int size_of_array) {
    int pivot = unsorted_arr[low];
    int start = low;
    int end = high;
    while(start<end) {
        while(unsorted_arr[start] <= pivot) {
            start++;
        }
        while(unsorted_arr[end] > pivot) {
            end --;
        }
        if(start<end) {
            sort_swap(unsorted_arr[start],unsorted_arr[end]);
        }
    }
    sort_swap(unsorted_arr[low],unsorted_arr[end]);
    //array output
    return end;
}


int mergesort_sort_algorithm(int unsorted_arr[], int size_of_array) {
    if (size_of_array < 2) {
        return 0; // Base case: single element is already sorted
    }

    int middle = size_of_array / 2;

    // Create left and right sub arrays
    int left_array[middle];
    int right_array[size_of_array - middle];

    // Copy values into left_array and right_array
    for (int i = 0; i < middle; i++) {
        left_array[i] = unsorted_arr[i];
    }
    for (int i = middle; i < size_of_array; i++) {
        right_array[i - middle] = unsorted_arr[i];
    }

    // Recursively sort both halves
    mergesort_sort_algorithm(left_array, middle);
    mergesort_sort_algorithm(right_array, size_of_array - middle);

    // Merge the sorted halves
    merge(left_array, right_array, unsorted_arr, size_of_array);

    return 0;
}

void merge(int left_arr[], int right_arr[], int unsorted_array[], int size_of_array) {
    int left_size = size_of_array / 2;
    int right_size = size_of_array - left_size;

    // Indices
    int i = 0, l = 0, r = 0;

    // Merge process
    while (l < left_size && r < right_size) {
        if (left_arr[l] <= right_arr[r]) {
            unsorted_array[i++] = left_arr[l++];
        } else {
            unsorted_array[i++] = right_arr[r++];
        }
    }

    // Copy any remaining elements from the left array
    while (l < left_size) {
        unsorted_array[i++] = left_arr[l++];
    }

    // Copy any remaining elements from the right array
    while (r < right_size) {
        unsorted_array[i++] = right_arr[r++];
    }
}


void sort_output(int size_of_array, int unsorted_arr[]) {
    for(int i=0;i<size_of_array;i++) {
        std::cout <<unsorted_arr[i] << " ";
    }
}


