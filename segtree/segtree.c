#include <stdio.h>

#define MAX 123456

int a[MAX] = {3,8,4,6,7,5,2,2};
int st[4*MAX];

void build(int i, // node idx
            int l, int r // current l and r
            ) {
          
    if (l==r) { // leaf node
        st[i] = a[l];
    } else {
        
        int m = (l+r)/2;
        build(2*i, l, m); // left
        build(2*i+1, m+1, r); // right
        st[i] = st[2*i] + st[2*i+1];
        
    }
    
}

int query(int i, // node idx
            int l, int r, // current l and r
            int ql, int qr // query's l and r
            ) {

    if (ql <= l && qr >= r) // query between l and r
        return st[i];
        
    if (ql > r || qr < l) // query is out
        return 0;
        
    int m = (l+r)/2;
    return query(2*i, l, m, ql, qr) // left
        + query(2*i+1, m+1, r, ql, qr); // right

}

void update(int i, // node idx
            int l, int r, // current l and r
            int pos, // position to update
            int val // value to update
            ) {
                
    if (l==r) // leaf
        st[i] = val;
    else {
        
        int m = (l+r)/2;
        if (pos <= m)
            update(2*i, l, m, pos, val);
        else
            update(2*i+1, m+1, r, pos, val);
            
        st[i] = st[2*i] + st[2*i+1];
        
    }
}

int main() {
    
    int n = 8;
    
    build(1, 0, n-1);
    
    printf("%d\n", query(1, 0, n-1, 0, 7));
    printf("%d\n", query(1, 0, n-1, 0, 1));
    printf("%d\n", query(1, 0, n-1, 2, 5));
    printf("%d\n", query(1, 0, n-1, 5, 7));
    printf("%d\n", query(1, 0, n-1, 1, 7));
    
    update(1, 0, n-1, 4, 9);
    
    printf("%d\n", query(1, 0, n-1, 0, 7));
    printf("%d\n", query(1, 0, n-1, 0, 1));
    printf("%d\n", query(1, 0, n-1, 2, 5));
    printf("%d\n", query(1, 0, n-1, 5, 7));
    printf("%d\n", query(1, 0, n-1, 1, 7));
    
    
}
