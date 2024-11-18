#include <iostream>
using namespace std;

int binarysearch(int arr[],int n, int key){
    int startingp = 0;
    int endingp = n;
    while (startingp<=endingp)
    {
        int mid = (startingp+endingp)/2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid]>key)  
        {
            endingp = mid-1;
        }
        else startingp = mid+1;  
    }
    return -1;
    
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarysearch(arr,n,key);
    
}