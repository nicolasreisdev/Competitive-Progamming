#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if( i < (k-i) && (k-i) <= n){ // i+k-i <= n
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}