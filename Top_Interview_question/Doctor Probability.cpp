#include<iostream>
using namespace std;

int main()
{
    int tastcase;
    cin>>tastcase;

    for(int i=1; i<=tastcase; i++)
    {
        double division[100][100] = {0};
        double table[100][100] = {0};
        int nodes,edge, time;

        cin >> nodes>>edge>>time;

        for (int i = 0; i < edge; i++)
        {
            int u,v;
            cin>>u>>v;
            cin >> division[u-1][v-1];
        }

        table[0][0] = 1;

        for (int i = 0; i < time/10; i++)
        {
            for (int j = 0; j < nodes ; j++)
            {
                if (table[i][j] > 0)
                {
                    for (int k = 0; k < nodes; k++)
                    {
                        table[i+1][k]  += table[i][j]*division[j][k];

                    }
                }
            }
        }
        double ans = 0;
        int finalNode;
        for (int i = 0; i < nodes; i++)
        {
            if (table[time/10][i] > ans)
            {
                ans = table[time/10][i];
                finalNode = i;
            }
        }

        cout << finalNode+1 <<" "<< ans << endl;
    }
    return 0;
}
