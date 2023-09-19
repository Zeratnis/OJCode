#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
struct point {
    float l,r;
};
bool cmp(point p1,point p2){
    if(p1.r!=p2.r){
        return p1.r<p2.r;
    }
    else {
        return p1.l>p2.l;
    }
}
int main(){
    int n,r;
    int flg,kase=0;
    float x,y;
    while(scanf("%d%d",&n,&r)&&n&&r){
        flg=0;++kase;
        point points[n];
        for(int i=0;i<n;i++){
            int x0,y0;
            scanf("%d%d",&x0,&y0);
            if(flg)
                continue;
            if(y0<0||y0>r){
                printf("Case %d: -1\n",kase);
                flg=1;
                continue;
            }
            x=x0;y=y0;
            points[i].l=x-sqrt(r*r-y*y);
            points[i].r=x+sqrt(r*r-y*y);
        }
        if(flg)
            continue;
        sort(points,points+n,cmp);
        // for(int i=0;i<n;i++){
        //     printf("%f %f\n",points[i].l,points[i].r);
        // }
        int ans=1;
        float tmp=points[0].r;
        for(int i=1;i<n;i++){
            if(points[i].l>tmp){
                ans++;
                tmp=points[i].r;
            }
        }
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}