# 快排

分治法，取一个数，然后根据这个数分开前后大小两段，再对这两段排序


```
quicksort(a,l,r)
if(l<r)
int i=l,j=r
int temp=a[i];a[0]
while(i<j>){
    while(i<j&&temp<a[j]){
        j--;
    }
    if(i<j>)
    a[i++]=a[j];
    
    while(i<j&&temp>a[i]){
        i++;
    }
    if(i<j)
    a[j--]=a[i];
    
}
a[i]=temp;
quicksort(a,l,i-1);
quciksort(a,i+1,r);

sort(a){
    quicksort(a,0,n-1)
}

```

