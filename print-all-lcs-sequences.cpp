My Solution: View on GitHub
class Solution {
  public:
    int lcslen = 0;

// dp matrix to store result of sub calls for lcs
int dp[100][100];
vector<string> answer;
// A memoization based function that returns LCS of
// str1[i..len1-1] and str2[j..len2-1]
int lcs(string str1, string str2, int len1, int len2,
                                      int i, int j)
{
    int &ret = dp[i][j];

    // base condition
    if (i==len1 || j==len2)
        return ret = 0;

    // if lcs has been computed
    if (ret != -1)
        return ret;

    ret = 0;

    // if characters are same return previous + 1 else
    // max of two sequences after removing i'th and j'th
    // char one by one
    if (str1[i] == str2[j])
        ret = 1 + lcs(str1, str2, len1, len2, i+1, j+1);
    else
        ret = max(lcs(str1, str2, len1, len2, i+1, j),
                  lcs(str1, str2, len1, len2, i, j+1));
    return ret;
}

    void printAll(string str1, string str2, int len1, int len2,
              string& data, int indx1, int indx2, int currlcs)
{
    // if currlcs is equal to lcslen then print it
    if (currlcs == lcslen)
    {
       answer.push_back(data);
        
        return;
    }

    // if we are done with all the characters of both string
    if (indx1==len1 || indx2==len2)
        return;

    // here we have to print all sub-sequences lexicographically,
    // that's why we start from 'a'to'z' if this character is
    // present in both of them then append it in data[] and same
    // remaining part
    for (char ch='a'; ch<='z'; ch++)
    {
        // done is a flag to tell that we have printed all the
        // subsequences corresponding to current character
        bool done = false;

        for (int i=indx1; i<len1; i++)
        {
            // if character ch is present in str1 then check if
            // it is present in str2
            if (ch==str1[i])
            {
              for (int j=indx2; j<len2; j++)
              {
                // if ch is present in both of them and
                // remaining length is equal to remaining
                // lcs length then add ch in sub-sequence
                if (ch==str2[j] &&
                  dp[i][j] == lcslen-currlcs)
                {
                  data+=ch;
                  printAll(str1, str2, len1, len2, data, i+1, j+1, currlcs+1);
                  data.pop_back();
                  done = true;
                  break;
                }
              }
            }

            // If we found LCS beginning with current character. 
            if (done)
                break;
        }
    }
}
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        int len1 = s1.size(), len2 = s2.size();
         memset(dp, -1, sizeof(dp));
        lcslen = lcs(s1, s2, len1, len2, 0, 0);
        string ans="";
        printAll(s1,s2,len1,len2,ans,0,0,0);
        sort(answer.begin(), answer.end());
answer.erase(unique(answer.begin(), answer.end()), answer.end());
        return answer;
    }
};
