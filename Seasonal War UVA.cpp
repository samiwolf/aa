#define FOR(i,n) for(int i=0; i<n; i++)
#define Scan(a) scanf("%d",&a)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define MM 210

#include<bits/stdc++.h>
using namespace std;

int ara[MM][MM];
int n,r,c;
int sx, sy, dx, dy;

bool isValid(int x, int y)
{
    return x>=0 && x<r && y>=0 && y<r;
}


int move_x[]= {-1,-1,-1,1,1,1,0,0};
int move_y[]= {-1,1,0,-1,1,0,-1,1};


void dfs(int x, int y)
{
    ara[x][y] = 0;

    for(int i=0; i<8; i++)
    {
        int xx = x+move_x[i];
        int yy = y+move_y[i];
        //  printf("%d,%d\n%d\n", xx, yy, isValid(xx,yy));
        if(ara[xx][yy]==1 && isValid(xx,yy))
        {
            ara[xx][yy] = 0;
            dfs(xx, yy);
        }
    }


}


int main()
{
    //freopen("in.txt","r",stdin);
    //  freopen("out.txt","w",stdout);
    int cnt = 0;
    while(Scan(n) != EOF)
    {
        SET(ara);
        cnt++;
        r = n;
        c = n;
        getchar();
        FOR(i,n)
        {
            FOR(j,n)
            {
                char ch;

                scanf("%c",&ch);
                if(ch=='1') ara[i][j] = 1;
                else if(ch=='0') ara[i][j] = 0;
            }
            getchar();
        }

        int cn = 0;
        FOR(i,n)
        {
            FOR(j,n)
        {
            if(ara[i][j]==1)
              {
                 dfs(i,j);
               cn++;
              }
        }

        }

      printf("Image number %d contains %d war eagles.\n",cnt, cn);





    }


}

/*FOR(i,r)
    {
        FOR(j,c)
        {
            printf("%d",ara[i][j]);
        }
        printf("\n");
    }*/
