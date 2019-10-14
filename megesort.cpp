#include<bits/stdc++.h>

using namespace std;

// Function to print the sorted array
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}

// Function to implement Merge Sort
void merge(int arr[],int lef,int m,int h)
{
    
    int n1=m-lef+1,n2=h-m;
    int L[n1],R[n2];

    //Dividing the array into two parts
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[i+lef]; // Copy the left part of the array into L[]
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=arr[m+1+i]; // Copy the Right part of the array into R[]
    }

    int k=lef;
    int l=0,r=0;
    while(l<n1 && r<n2)
    {
        // Take the smaller element when comparing the left and right parts
        if(L[l]<=R[r])
        {
            arr[k]=L[l];
            l++;
        }
        else
        {
            arr[k]=R[r];
            r++;
        }
        k++;
    }

    // Copy the leftover values of the LEFT part
    while(l<n1)
    {
        arr[k]=L[l];
        l++;
        k++;
    }

    // Copy the leftover values of the Right part
    while(r<n2)
    {
        arr[k]=R[r];
        r++;
        k++;
    }


}

void sort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        // Divide the array into two parts
        sort(arr,l,mid);
        sort(arr,mid+1,h);

        // Merge both parts to produce the sorted array
        merge(arr,l,mid,h);
    }
}

int main()
{
    cout << "Enter the size of the input data\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the numbers\n";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,0,n-1);
    print(arr,n);
}