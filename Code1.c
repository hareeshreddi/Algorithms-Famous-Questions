#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long power(int x,int y)
{
  int i;
  long long res=(long long)1;
  for(i=0;i<y;i++)
  {  res=res*(long long)x;
  }
  return res;
}
int main()
{
    int t,k,b,i,j,kk;
    long long out=0;
    int ar[26];
    char *ch=(char*)malloc(sizeof(char)*100000000);
    for(i=0;i<26;i++)
    {
      ar[i]=i+1;
    }
    scanf("%d",&t);
    
    for(i=0;i<t;i++)
    {
    int counter=0;
    //printf("aaa\n");
    scanf("%d %d",&k,&b);
    int arr[k];
    for(j=0;j<k;j++)
      {
       scanf("%d ",&arr[j]);
      }
    scanf("%[^\n]s",ch);
    ch[strlen(ch)]='\0';
    //printf("string::%s",ch);
    for (kk=0;strlen(ch)>=kk;kk++)
      {
        //printf("bbbb\n");
        if(kk==(strlen(ch)))
         {
         printf("%lld",out);
         out=(long long)0;
         break;
         }
        else if (ch[kk]==' ')
        {
        //printf("%d os the counter\n",counter);
           if(out>(long long)0)
              printf("%lld+",out);
           else
              printf("+");
        out=(long long)0;
        counter=0;
        }
        else
        {
          //printf("counter::%d",counter);
          out=out+(long long)(ar[ch[kk]-'a']*power(b,arr[counter]));
          counter=counter+1;
        }
      }
    if(i!=t-1)
     printf("\n");
    }
    
    return 0;
}
/*
DESCRIPTION
Ash has finally got the third clue (of Berland treasure) and she needs to inform her master. So, Ash decided to encode her message. To encode the message she converted all the space to ‘+’ and words to a hash value. 
To compute the hash value of a word she used her magical wand and generated K magical numbers. So, the hash value of words is the sum of a product of ith character (represented in numbers) of a word with B power of the ith  magical number. 
Each character can be represented by a number (a is 1, b is 2, … z is 26). 
Let’s see an example to encode her message, 
message: i did it 
3 Magical Numbers: 0 1 1 
B = 10 
encoded message: 
       i = (9*100) = 9 
     did = (4*100+ 9*101+ 4*101) = 134 
         it = (9*100+ 20*101) = 209
send message is: 9+134+209 

As Ash’s message can be very long so she asks you to encode her messages via her magical wand. (also don’t assume that everything her wand can do)

Input 
The first line contains T (1 <= T <= 100), the number of messages Ash wants to encode.
The first line of each T contains K (K >= |X|) and B (2 <= B <= 10). Here,
K is the number of digits in the magic number.
|X| is the number of words in the message.
B is the power.
The second line of each T contains K numbers P1, P2 ....... Pk(0 <= Pi<= 10).
The last line of each T contains message of Ash (message consists of only lower case alphabets and spaces).|X| <= 10.

Output 
For each T print the encoded message

Sample Test Case

Input
1
3 10
0 1 1
i did it

Output
9+134+209
