//helper function 
int bs(int* arr, int n, int tar,int st,int end)
{
    if(st <= end)
    {
        int mid = (st + end)/ 2 ;    

        if(arr[mid]==tar) 
            {return mid ;}

        else if(arr[mid]<=tar) 
        {
            return bs(arr,n,tar,mid+1,end) ; 
        }

        else
        {
            return bs(arr,n,tar,st,mid-1) ;
        }

    }
    return -1 ;
}

int search(int* arr, int n, int tar) {

    return bs(arr,n,tar,0,n-1) ; 
}