#define NOT_IN_STACK 0
#define IN_STACK 1
bool dfs(int v, bool adj[][MAXN], int label[MAXN], int instack_count, int n){
        if(instack_count == n)
            return true;
        for(int i=0; i<n; i++)
            if(adj[v][i] && label[i] == NOT_IN_STACK){
                label[i]=IN_STACK;
                if(dfs(i, adj, label, instack_count+1, n))
                    return true;
                label[i]=NOT_IN_STACK;
            }
        return false;
}
bool check_using_dfs(bool adj[][MAXN], int n){
        int label[MAXN];
        for(int i=0; i<n; i++)
            label[i]=NOT_IN_STACK;
        for(int i=0; i<n; i++){
            label[i]=IN_STACK;
            if(dfs(i, adj, label, 1, n))
                return true;
            label[i]=NOT_IN_STACK;
        }
        return false;
}
