#define N 1000000
int arr[N];
int tree[4*N];
void build(int node,int st,int en)
{
    if(st==en)
    {
        tree[node]=arr[st];
        return;
    }
    int lf=node*2,rt=lf+1,md=(st+en)/2;
    build(lf,st,md);
    build(rt,md+1,en);
    tree[node]=min(tree[lf],tree[rt]);
}
int query(int node,int st,int en,int i,int j)
{
    if(i>en || j<st) return INT_MAX;
    if(st>=i && en<=j) return tree[node];
    int lf=node*2,rt=lf+1,md=(st+en)/2;
    int x=query(lf,st,md,i,j);
    int y=query(rt,md+1,en,i,j);
    if(x<=y) return x;
    return y;
}
void update(int node,int st,int en,int i,int val)
{
    if(i>en || i<st) return;
    if(st==i && en==i)
    {
        tree[node]=val;
        return;
    }
    int lf=node*2,rt=lf+1,md=(st+en)/2;
    update(lf,st,md,i,val);
    update(rt,md+1,en,i,val);
    tree[node]=min(tree[lf],tree[rt]);
}
