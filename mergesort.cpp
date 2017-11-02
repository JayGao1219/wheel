void Merge(int arr[], int tmp[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int idt = left;
    while(i <= mid && j <= right){
        if (arr[i] <= arr[j]){
            tmp[idt++] = arr[i++];
        }
        else{
            tmp[idt++] = arr[j++];
        }
    }
    while(i <= mid){
        tmp[idt++] = arr[i++];
    }
    while(j <= right){
        tmp[idt++] = arr[j++];
    }
}
void MergePass(int arr[], int tmp[], int step){
    int i = 0;
    while (n - i >= 2 * step){
        Merge(arr, tmp, i, i+step-1, i+2*step-1);
        i = i + 2 * step;
    }
    if (n - i > step)
        Merge(arr, tmp, i, i+step-1, n-1);
    else
        for (int j = i; j < n; j++)
            tmp[j] = arr[j];
}
void mergesort(int arr[]){
    int step = 1;
    int* tmp = new int[n];
    while(step < n){
        MergePass(arr, tmp, step);
        step *= 2;
        MergePass(tmp, arr, step);
        step *= 2;
    }
    delete[] tmp;
}
