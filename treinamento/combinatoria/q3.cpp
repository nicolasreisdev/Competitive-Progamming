#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0;

int main()
{
    int x, cont = 0; cin >> x;

    for(int i = x-1; i > 1;i--){
        cont += i;
    }
    cout << cont << endl;

    return 0;
}