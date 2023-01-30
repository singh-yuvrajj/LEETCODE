#include<bits/stdc++.h>
using namespace std;
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> mapping;
        for(int i=0;i<26;i++) mapping.push_back(i+97);

        for(int i=0;i<s1.length();i++){
            int toReplace = max(mapping[s1[i]-'a'],mapping[s2[i]-'a']);
            int withReplace = min(mapping[s1[i]-'a'],mapping[s2[i]-'a']);
            mapping[toReplace-97] = withReplace;
            for(int j=0;j<26;j++){
                if(mapping[j] == toReplace) mapping[j] = withReplace;
            }
        }

        string ans="";
        for(auto i:baseStr) ans += char(mapping[i-'a']);
        return ans;
    }
int main()
{
    string s1="parker";
    string s2 = "morris";
    string basestr = "parser";
    cout<<smallestEquivalentString(s1,s2,basestr);
    return 0;
}