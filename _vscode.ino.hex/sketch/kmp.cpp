#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\kmp.cpp"
#include<bits/stdc++.h>
using namespace std;

int lps[1000005];
void computeLPSArray(string pat, int M, int* lps) // lps = longest prefix suffix, lps[i] = longest prefix suffix of pat[0..i], which is also a prefix of pat[0..M-1]
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            cout<<"Found pattern at index "<< i - j<<endl;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}


int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}