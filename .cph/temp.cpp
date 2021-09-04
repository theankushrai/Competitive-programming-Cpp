void rightrotate(int a[],int i,int j){
        int temp=a[j];
        for(int k=j;k>i;k--){
            a[k]=a[k-1];
        }
        a[i]=temp;
    }
    void arranged(int a[],int n)
    {
        
        int i;//i is the index in which first inconsistency is to be found
        for(int i =0;i<n;i++){
            if(i%2==0&&a[i]<0){
                for(int j=i+1;j<n;j++){
                    if(a[j]>=0)rightrotate(a,i,j);
                }
            }
            else if(i%2==1&&a[i]>=0){
                for(int j =i+1;j<n;j++){
                    if(a[j]<0)rightrotate(a,i,j);
                }
            }
        }
    }

int main()
{
    int a[]={-1, 2, -3, 4, -5, 6};
    arranged(a,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
    
 return 0;
}