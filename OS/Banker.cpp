#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, i, j, k;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

    int alloc[n][m], max[n][m], avail[m];
    cout << "Enter the allocation matrix:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter the max matrix:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the available resources:" << endl;
    for (i = 0; i < m; i++) {
        cin >> avail[i];
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                       
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            cout << "The given sequence is not safe" << endl;
            break;
        }
    }

    if (flag == 1) {
        cout << "Following is the SAFE Sequence:" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }
    
    cout << "Process" <<" | "<<"Allocation" <<" | "<<"Max" <<" | "<<"Available"<<" | "<<"Max Need"<<endl;
    cout << "--------------------------------------"<<endl;
      for (i = 0; i < n; i++)
    {
        cout<<"P"<<i<<"      | ";
        for (j=0; j<m; j++) {
            cout << alloc[i][j] << " ";
        }
        cout << "| ";

        for (j=0; j<m; j++) {
            cout << max[i][j] << " ";
        }
        cout << "| ";

        if (i == 0) {
            for (j=0; j<m; j++) {
                cout << avail[j] << " ";
            }
        }
        if (i == 0){
         cout << "| ";
         for (j=0; j<m; j++) {
            cout << need[i][j] << " ";
        }}
        else{
            cout << "       | ";
            for (j=0; j<m; j++) {
            cout << need[i][j] << " ";
        }
        }
        cout<<endl;
      }
    return (0);
}