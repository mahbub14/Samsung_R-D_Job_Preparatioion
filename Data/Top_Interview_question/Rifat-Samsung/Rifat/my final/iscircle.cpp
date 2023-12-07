#include<bits/stdc++.h>
using namespace std;
#define mx 1000
vector<int> node[1000];
vector<bool> vis(mx,false);
vector<bool> restack(mx,false);

bool iscircle(int parent){
    if(vis[parent] == false){
        vis[parent] = true;
        restack[parent] = true;
        for(int i=0;i<node[parent].size();i++){
            if(!vis[node[parent][i]] && iscircle(node[parent][i]))
                return true;
            else if(restack[node[parent][i]] == true)
                return true;
        }
    }

    restack[parent] = false;
    return false;
}


int main(){
    int n,e;
    cin>>n>>e;

    int x,y;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        node[x].push_back(y);
    }

    for(int i=0;i<n;i++){
        if(iscircle(i)){
            cout<<"circle found"<<endl;
            return 0;
        }
    }

    cout<<"no circle found"<<endl;



}
