#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

    int n; cin >> n;
    map<string, int> m;
    for(int i = 0; i < n;i++){
        string x; cin >> x;
        m[x]++;
    }

    for(auto ans: m){
        if(ans.second > n/2){
            cout << ans.first << endl;
            return 0;
        }
    }
    cout << "vixe" << endl;


    return 0;
}