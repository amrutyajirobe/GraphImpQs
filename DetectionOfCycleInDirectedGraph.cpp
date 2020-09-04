#include<iostream>
#include<vector>
#include<utility>
using namespace std;


bool is_cyclic_util(vector<int>&adj[],vector<bool>&visited[],int curr){
        if(visited[curr]=true)  return true;

        visited[curr]=true;
        bool FLAG=false;

        for(int i=0;i<adj[curr].size();++i){
            FLAG=is_cyclic_util(adj,visited,adj[i][j]);;
            return true;
        }
        return false;
}

bool is_cyclic(int v,vector<int>&adj[]){

    vector<bool>visited(v,false);
    bool FLAG=false;            //keeps a track whether true value was returned or not

    for(int i=0;i<v;i++){
        visited[i]=false;

        for(j=0;j<adj[i].size();++j){
            
            FLAG=is_cyclic_util(adj,visited,adj[i][j]);
            if(FLAG)  return true;

        }
        visited[i]=false;

    }

    return false;
}


int main(){
    int t;
    cin>>t;

    

    while(t--)
    {
        int v,e;
        cin>>v>>e;
        vector<int>adj[v];

        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
    }

    cout<<is_cyclic(v,adj)<<endl;


}
