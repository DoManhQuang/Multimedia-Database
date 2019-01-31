#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s; /// chuỗi kỹ tự S
string t; /// chuỗi kỹ tự t
int m; /// độ dài chuỗi s
int n; /// độ dài chuỗi t
int a[100][100];
void Input()
{
    cin>>s;
    cin>>t;
    m = s.length();
    n = t.length();
}
int Minimun(int a, int b, int c)
{
    int mi = a;
    if(mi > b)
        mi = b;
    else if(mi > c)
        mi = c;
    return mi;
}

/**
        0   1   2   3   4   5   6   7   m   j
    0   0   0   0   0   0   0   0   0
    1   0   0   0   0   0   0   0   0
    2   0   0   0   0   0   0   0   0
    3   0   0   0   0   0   0   0   0
    4   0   0   0   0   0   0   0   0
    5   0   0   0   0   0   0   0   0
    6   0   0   0   0   0   0   0   0
i
    n
*/
void Cre_table()
{
    for(int i=0;i<=m;i++)
    {
        a[i][0] = i;
    }
    for(int j=0;j<=n;j++)
    {
        a[0][j] = j;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j] = 0;
        }
    }
}
void Output_data()
{
    for(int i=0; i<=m; i++)
    {
        for(int j =0; j<=n; j++)
        {
            cout<<setw(7)<<a[i][j];
        }
        cout<<endl;
    }
}

int Levenshtein_Distance() /// function Matrix return a[m][n]
{
    for(int i=1; i<=m; i++)
    {
        for(int j =1; j<=n; j++)
        {
            int cost = 1;
            if(s[i-1] == t[j-1])
            {
                cost = 0;
            }
            int value_del = a[i-1][j] + 1; /// deletion
            int value_inst = a[i][j-1] + 1;/// insertion
            int value_sub = a[i-1][j-1] + cost; /// substitution
            a[i][j] = Minimun(value_del,value_inst,value_sub);
        }
    }
    return a[m][n];
}
void Levenshtein_table() /// function
{
    for(int i=1; i<=m; i++)
    {
        for(int j =1; j<=n; j++)
        {
            int cost = 1;
            if(s[i-1] == t[j-1])
            {
                cost = 0;
            }
            int value_del = a[i-1][j] + 1; /// deletion
            int value_inst = a[i][j-1] + 1;/// insertion
            int value_sub = a[i-1][j-1] + cost; /// substitution
            a[i][j] = Minimun(value_del,value_inst,value_sub);
        }
    }
}
int LevenshteinDistance(string s, int len_s, string t, int len_t) /// Function Recursive
{
  int cost;

  /* base case: empty strings */
  if (len_s == 0) return len_t;
  if (len_t == 0) return len_s;

  /* test if last characters of the strings match */
  if (s[len_s-1] == t[len_t-1])
      cost = 0;
  else
      cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char from both */
  return Minimun(LevenshteinDistance(s, len_s - 1, t, len_t    ) + 1,
                 LevenshteinDistance(s, len_s    , t, len_t - 1) + 1,
                 LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost);
}
int main()
{
    freopen("dataString.txt","r",stdin);
    freopen("Output_data.txt","w",stdout);
    cout << "\t\t Levenshtein by Manh Quang " << endl<<endl;
    Input();
    cout<<"Length ( "<<s<<" ) is : "<<m<<endl;
    cout<<"Length ( "<<t<<" ) is : "<<n<<endl<<endl;
    cout<<"New Table : "<<endl;
    Cre_table();
    Output_data();
    cout<<endl<<"Levenshtein Table Result :"<<endl;
    Levenshtein_table();
    Output_data();
    int distance = LevenshteinDistance(s,m,t,n);
    //int distance = Levenshtein_Distance();
    cout<<endl<<"Levenshtein Distance Result is : "<<distance<<endl;
    return 0;
}
