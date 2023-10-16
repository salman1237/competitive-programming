class dsu
{
    vector<int>par,rank;
    public:
        dsu(int node)
        {
            rank.resize(node+1,0);
            par.resize(node+1);
            for(int i=0; i<=node; i++) par[i]=i;
        }
        int find(int node)
        {
            if(node==par[node]) return node;
            return par[node]=find(par[node]);
        }
        void Union(int u,int v)
        {
            int x=find(u);
            int y=find(v);
            if(rank[x]<rank[x]) par[x]=y;
            else if(rank[y]<rank[x]) par[y]=x;
            else
            {
                par[x]=y;
                rank[y]++;
            }
        }
};
