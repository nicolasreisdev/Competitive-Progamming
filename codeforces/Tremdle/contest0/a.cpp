#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    fastio;

    int a, b;
    cin >> a >> b;
    int ansOne = min(a, b);
    a -= ansOne;
    b -= ansOne;
    int ansTwo = a / 2 + b / 2;
    cout << ansOne << " " << ansTwo << endl;

    return 0;
}