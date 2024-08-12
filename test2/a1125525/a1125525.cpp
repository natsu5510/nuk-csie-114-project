#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int x=2, t=1,ans=0;

        while(t<n)
        {

               if(x%2==0||x%3==0||x%5==0)
                {
                    ans=x;
                    x++;
                    t++;
                }
                else
                {
                    x++;
                }


        }
        cout << ans << endl;

    }

    return 0;
}
