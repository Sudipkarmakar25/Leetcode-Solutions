#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,string endWord,vector<string>&wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while (!q.empty())
        {
            pair<string,int> fnode=q.front();
            q.pop();
            string currString =fnode.first;
            int currCount=fnode.second;
            if(currString==endWord)
            {
                return currCount;
            }
        
        for (int i = 0; i < currString.size(); i++)
        {
            char originalCharacter=currString[i];
            for(char ch='a'; ch<='z';ch++)
            {
                currString[i]=ch;
                if(st.find(currString) !=st.end())
                {
                    q.push({currString,currCount+1});
                    st.erase(currString);
                }
            }
            currString[i]=originalCharacter;
        }
        }
        return 0;
    }
};