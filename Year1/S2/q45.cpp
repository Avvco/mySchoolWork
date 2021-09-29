// source https://blog.itbiu.com/2009/10/25/200910252/
// not AC yet
#include <iostream>

using namespace std;

int main()
{
  int n,a[201][201]={0},line[201]={0},coulum[201]={0};
  int i,j,k,lin, cou,haveeven;

  while(cin>>n&&n)
  {
    k=haveeven=0;

    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
        cin>>a[i][j];
        if(a[i][j]==1)
        {
          line[i]++;
          coulum[j]++;
        }
      }

     for(i=1;i<=n;i++)
     {
       if(line[i]%2!=0)
       {
          haveeven=1;

          for(j=1;j<=n;j++)
            if(coulum[j]%2!=0)
            {
              if(a[i][j]==1)
              {
                line[i]--;
                coulum[j]--;
                a[i][j]=0;
              }
              else
              {
                a[i][j]=1;
                line[i]++;
                coulum[j]++;
              }

            haveeven=0;
            k++;
            lin=i;
            cou=j;
          }
      }

      if(haveeven==1||k>1)
        break;

      if(coulum[i]%2!=0)
      {
        haveeven=1;
        for(j=1;j<=n;j++)
          if(line[j]%2!=0)
          {
            if(a[j][i]==1)
            {
             line[j]--;
             coulum[i]--;
             a[j][i]=0;
            }
            else
            {
             a[j][i]=1;
             line[j]++;
             coulum[i]++;
            }

          haveeven=0;
          k++;
          lin=j;
          cou=i;
        }
      }


      if(haveeven==1||k>1)
        break;
    }

    if(k==0&&haveeven==0)
      cout<<"OK"<<endl;

    if(k==1&&haveeven==0)
      cout<<"Change bit ("<<lin<<","<<cou<<")"<<endl;

    if(k>1||haveeven==1)
      cout<<"Corrupt"<<endl;

    for(i=1;i<=n;i++)
      line[i]=coulum[i]=0;
  }

  return 0;
}
