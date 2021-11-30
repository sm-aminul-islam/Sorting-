#include<bits/stdc++.h>
using namespace std;
int n, arr[100000];
void Bubblesort_asd(int arr[100000],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void Bubblesort_dsnd(int arr[100000],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
int partition1(int arr[],int first,int right)
{
    int pivot=arr[right];
    int i=first-1;
    for(int j=first; j<right;j++)
    {
        if(arr[j]< pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[right]);
    return i;
}
void quicksort_asnd(int arr[],int first,int right)
{
    if(first < right)
    {
        int q=partition1(arr,first,right);
        quicksort_asnd(arr,first,q-1);
        quicksort_asnd(arr,q+1,right);
    }
}

int partition2(int arr[],int first,int right)
{
    int pivot=arr[right];
    int i=first-1;
    for(int j=first; j <right;j++)
    {
        if(arr[j] > pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[right]);
    return i;
}
void quicksort_dsnd(int arr[],int first,int right)
{
    if(first < right)
    {
        int q=partition2(arr,first,right);
        quicksort_dsnd(arr,first,q-1);
        quicksort_dsnd(arr,q+1,right);
    }
}


void Merge_asnd(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,temp[high+1],k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j]) temp[k++]=arr[i++];
        else temp[k++] =arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
    temp[k++]=arr[j++];
    for(k=0,i=low;i<=high;k++,i++) arr[i]=temp[k];

}
void Mergesort_asnd(int arr[],int low,int high)
{
    if(low >= high) return;
    int mid=(low+high)/2;
    Mergesort_asnd(arr,low,mid);
    Mergesort_asnd(arr,mid+1,high);
    Merge_asnd(arr,low,mid,high);

}
void Merge_dsnd(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,temp[high+1],k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j]) temp[k++]=arr[i++];
        else temp[k++] =arr[j++];
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
    temp[k++]=arr[j++];
    for(k=0,i=low;i<=high;k++,i++) arr[i]=temp[k];

}
void Mergesort_dsnd(int arr[],int low,int high)
{
    if(low >= high) return;
    int mid=(low+high)/2;
    Mergesort_dsnd(arr,low,mid);
    Mergesort_dsnd(arr,mid+1,high);
    Merge_dsnd(arr,low,mid,high);

}



void printArray(){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}
int main()
{
    freopen("input1.txt","r",stdin);
    freopen("sample.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Bubblesort_asd(arr,n);
   printArray();
   fclose(stdout);
    return 0;
}
