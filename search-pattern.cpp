class Solution {
  public:
    vector<int>buildlps(string &pat){
        int m=pat.size();
        vector<int>lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len != 0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(string &pat, string &txt) {
        // code here
      int n=pat.length();
      int m=txt.length();
      
      vector<int>lps=buildlps(pat);
      vector<int>result;
      int i=0;
      int j=0;
      while(i<m){
          if(pat[j]==txt[i]){
              i++;
              j++;
          }

          if(j==n){
              result.push_back(i-j);
              j=lps[j-1];
          }
          else if(i<m && pat[j] != txt[i]){
              if(j != 0){
                  j=lps[j-1];
              }
              else{
                  i++;
              }
          }
      }
      return result;
    }
};\
