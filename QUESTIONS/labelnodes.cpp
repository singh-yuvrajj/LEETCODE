#include<bits/stdc++.h>
using namespace std;

// ###with STring --

// class Solution {
//     public:
    
//     string solve(vector<bool>& visited,vector<int>& ans,string labels, unordered_map<int,vector<int>>& mp,int index){

//         vector<int> temp = mp[index];
//         visited[index] = true;
//         string mapping="";
//         for(auto i:temp){
            
//             if(visited[i]) continue;

//             mapping+=labels[i]+solve(visited,ans,labels,mp,i);
            
//         }
//         for(auto j:mapping) if(j==labels[index]) ans[index]++;

//         return mapping;
//     }
// public:
//     vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
//         vector<bool> visited(n,false);
//         unordered_map<int,vector<int>> mp;
//         for(int i=0;i<edges.size();i++){
//             mp[edges[i][0]].push_back(edges[i][1]);
//             mp[edges[i][1]].push_back(edges[i][0]);
//         }
//         for(auto i:mp){
//             cout<<i.first<<" - ";
//             for(auto j: i.second) cout<<j<<" ";
//             cout<<endl;
//         }
//         vector<int> ans(n,1);
//         string s = solve(visited,ans,labels,mp,0);
//         return ans;
//     }
// };


// ####WIth array

class Solution {
    public:
    
    vector<int> solve(vector<bool>& visited,vector<int>& ans,string& labels, unordered_map<int,vector<int>>& mp,int index){
        vector<int> temp = mp[index];
        visited[index] = true;
        vector<int> mapping(26,0);
        for(auto i:temp){
            
            if(visited[i]) continue;

            vector<int> temp =solve(visited,ans,labels,mp,i);

            for(int j=0;j<26;j++) mapping[j]+=temp[j];

            mapping[int(labels[i])-97]++;    
        }
        ans[index]+=mapping[int(labels[index])-97];

        return mapping;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(n,1);
        vector<int> temp = solve(visited,ans,labels,mp,0);
        return ans;
    }
};
int main()
{
    Solution *ob;
    vector<vector<int>> ans{{0,1},{1,2},{0,3}};
    string labels = "bbbb";
    vector<int> temp = ob->countSubTrees(labels.length(),ans,labels);
    for(auto i: temp) cout<<i;
    return 0;
}