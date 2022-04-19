 #include<iostream>
 #include<stdio.h>
 using namespace std;

// here we are adding up the nabour element of the element of an array.
/* like 1 2 3         4+2     1+5+3    2+6     output   6     9    8  
        4 5 6   ==>  1+5+7   2+4+7+6  3+5+9     ===>    13    19   17  
        7 7 9         4+7     7+5+9    6+7              11    21   13    */
 
 int main()
 {
     int n,m;
     cin>>n>>m;
     int a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
             cin>>a[i][j];
        }
    }

    int c[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            c[i][j] = 0;           
        }
    }
    cout<<"\n\n";
    
    //code

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( i==0 && j==0)
            {
                c[i][j] = a[i][j+1] + a[i+1][j];
            }
            else if(i>=1 && j==0)
            {
                if( i<=n-2)
                {
                    c[i][j] = a[i-1][j] + a[i][j+1] + a[i+1][j];
                }
                else
                {
                    c[i][j] = a[i-1][j] + a[i][j+1];
                }
            }
            else if(i==0 && j>=1)
            {
                if(j<=m-2)
                {
                    c[i][j] = a[i][j-1] + a[i+1][j] + a[i][j+1];
                }
                else
                {
                    c[i][j] =  a[i][j-1] + a[i+1][j];
                }
            }
            else if(i>=1 && j>=1 && i<=n-2 && j<=m-2)
            {
                c[i][j] = a[i][j-1] + a[i+1][j] + a[i][j+1] + a[i-1][j];
            }
            else if(i==n-1)
            {
                if(j>=1 && j<=m-2)
                {
                    c[i][j] = a[i][j-1] + a[i][j+1] + a[i-1][j];
                }
                else
                {
                    c[i][j] = a[i][j-1] + a[i-1][j];
                }
            }
            else if(j==n-1)
            {
                if(i>=1 && i<=n-2)
                {
                    c[i][j] = a[i-1][j] + a[i][j-1] + a[i+1][j];
                }
            }
            else
            {
                cout<<"Something u have missed"<<endl<<endl;
                break;
            }
        }
    }

//output
     for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<c[i][j]<<" ";           
        }
        cout<<endl;
    }

     return 0;
 }
