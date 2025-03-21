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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

ll _tam_crivo;
bitset<100000010> bs; // 10^7 + extra bits, suficiente para maioria
vector<int> primos;  // lista de primos

void crivo(ll limite){                            // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset();
    bs.flip(); // todos valendo true
    bs.set(0, false);
    bs.set(1, false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++)
        if (bs.test((size_t)i))
        { // corta todos os multiplos de i comecando de i*i
            for (ll j = i * i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.push_back((int)i); // adiciona na lista de primos
        }
} 
bool eh_primo(ll N){ 
    if (N < _tam_crivo)
        return bs.test(N);
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true; 
}

void printPrimes(ll m, ll n){
    for (ll i = m; i <= n; i++)
        if (eh_primo(i))cout << i << endl;
}

int main(){
    crivo(100000000);
    int t; cin >> t;
    while(t!=0){
        ll m , n; cin >> m >> n;
        printPrimes(m, n);
        cout << endl;
        t--;
    }


    return 0;
}