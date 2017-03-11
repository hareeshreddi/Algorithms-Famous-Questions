#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,q,i,j;
    int arr[26];
    for(i=0;i<26;i++)
     {
      arr[i]=0;
      }
    scanf("%d",&n);
    scanf("%d",&q);
    char in[n+1];
    in[n]='\0';
    for(i=0;i<n;i++)
    {
      scanf(" %c",&in[i]);
    }

    for(i=0;i<q;i++)
    {
        int l;
        scanf("%d",&l);
        if(l==1)
        {
          char ch;
          scanf(" %c",&ch);
          if(arr[ch-'a']==0)
             arr[ch-'a']=1;
          else
             arr[ch-'a']=0;
        }
        else if(l==2)
        {
            int a1,a2,x,output=0;
            scanf("%d%d",&a1,&a2);
            char d[4];
            scanf(" %s",d);
            if(strlen(d)==2)
               x=1;
            else
               x=0;
             for(j=a1-1;j<=a2-1;j++)
             {
                if(arr[in[j]-'a']==x)
                  output++;
             }
             if(i!=q-1)
                printf("%d\n",output);
             else if(i==q-1)
                printf("%d",output);
        }
    }
    return 0;
}
/*
DESCRIPTION
Sid has N switches arranged linearly each of which is of one of the 26 types. The types are denoted by lowercase English letters. Each switch can be in either off state or on state. By default, all the switches are in off state.

Sid now wants to perform Q operations (or queries) on the switches. Operations can be of two types - 1 and 2. 
The type 1 operation - toggling the state (i.e. from off to on and vice-versa) of all the switches of a particular type.
The type 2 operation - querying about the total number of switches which are in a particular state.

Given the switch arrangement and the queries, can you help Sid to find out the answer for queries of type 2?

Input 
The first line contains 2 integers N and Q, the number of switches and the number of queries, respectively. 
The next line contains a string of lowercase English letters denoting the arrangement of N switches. 
The next Q lines contain a query either of the following forms: 
1 x: where x is a lowercase English letter specifying the type of the switch whose state is to be toggled, or, 
2 l r s: where [l,r] is the section of the given string for which you have to determine the number of switches which are in the state S. 
S is either "off" (quotes for clarity) or "on" (quotes for clarity).

Output 
For each query of type 2, print an integer denoting the number of switches, in the specified segment, which is in the specified state.

Constraints
1 <= N <= 105  
1 <= Q <= 105   
1 <= l,r <= N 
l <= r 

Sample Test Case

Input
10 5 
abcdabcdxy 
1 c 
2 3 5 off 
1 x 
1 c 
2 6 9 on

Output
2 
1