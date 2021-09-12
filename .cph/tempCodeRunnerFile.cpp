 
void printduplicates(string s){
    unordered_map<char,int> m;
    for(int i =0;i<s.length();i++){
        m[s[i]]++;
    }
    for(auto it:m){
        if(it.second>1)cout<<it.first<<endl;
    }
}

int main()
{
printduplicates("ankushraiisaverygoodboy");
 return 0;
}