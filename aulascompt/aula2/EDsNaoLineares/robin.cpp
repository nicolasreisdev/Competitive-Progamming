#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cctype>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

#define f(i,n) for(int i=0;i<n;i++)
#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define all(v) (v).begin(), (v).end()
const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;
const int modulo = 1000000007;

// cmp(x,y) == 1 , x>y
// cmp(x,y) == 0, x=y
// comp(x,y) ==-1, x<y
inline int cmp(double x, double y=0 , double tol = EPS) { 
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------

//BIT data structure ... source: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
//BIT data structure ... source: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
//ATTTTTTTT:!!!!!!!!!!!!!!!!!! idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//BIT data structure ... source: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
//ATTTTTTTT:!!!!!!!!!!!!!!!!!! idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//BIT data structure ... source: http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
//ATTTTTTTT:!!!!!!!!!!!!!!!!!! idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
//ATENTION idx>0!!!
class BIT {
public:

		
	//Superior limit for the values that will be added to the BIT
	BIT(int maxVal) {
		maxVal++;
		tree.resize(maxVal+1,0);
		//for(int i=0;i<tree.size();i++) tree[i]=0;
		this->MaxVal = maxVal;
		for(int i=0;i<8*sizeof(MaxVal);i++) {
			if (maxVal &(1<<i)) {
				bitMask = 1<<i;			
			}
		}
	}


	//Read the sum of the frequency elements in the bins smaller or equal than the bin with id idx.
	//sum(i) = a[0] + a[1] + a[2] + ....+ a[i]
	//Example: if we add: (2,1) (1,1) (3,1)  ( (idx,frequency) ) to a BIT...
	//                    read(2) = 2 ( only 2 and 1 are <= 2)  ... read(1) = 1 ... read(10) = 3
	int read(int idx){
		int sum = 0;
		while (idx > 0){
			sum += tree[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	//increment the occurrency of the element in bin idx by val... update(i,v) --> bin[idx] += val
	void update(int idx ,int val){
		while (idx <= MaxVal){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}

private:
	vector<int> tree;
	int MaxVal;
	int bitMask;
		
	/*
	int readSingle(int idx){
		int sum = tree[idx]; // sum will be decreased
		if (idx > 0){ // special case
			int z = idx - (idx & -idx); // make z first
			idx--; // idx is no important any more, so instead y, you can use idx
			while (idx != z){ // at some iteration idx (y) will become z
				sum -= tree[idx]; 
		// substruct tree frequency which is between y and "the same path"
				idx -= (idx & -idx);
			}
		}
		return sum;
	}

	void scale(int c){
		for (int i = 1 ; i <= MaxVal ; i++)
			update(-(c - 1) * readSingle(i) / c , i);
	}

	// if in tree exists more than one index with a same
	// cumulative frequency, this procedure will return 
	// some of them (we do not know which one)

	// bitMask - initialy, it is the greatest bit of MaxVal
	// bitMask store interval which should be searched
	int find(int cumFre){
		int idx = 0; // this var is result of function
		
		while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
			int tIdx = idx + bitMask; // we make midpoint of interval
			if (cumFre == tree[tIdx]) // if it is equal, we just return idx
				return tIdx;
			else if (cumFre > tree[tIdx]){ 
				// if tree frequency "can fit" into cumFre,
				// then include it
				idx = tIdx; // update index 
				cumFre -= tree[tIdx]; // set frequency for next loop 
			}
			bitMask >>= 1; // half current interval
		}
		if (cumFre != 0) // maybe given cumulative frequency doesn't exist
			return -1;
		else
			return idx;
	}



	// if in tree exists more than one index with a same
	// cumulative frequency, this procedure will return 
	// the greatest one
	int findG(int cumFre){
		int idx = 0;
		
		while ((bitMask != 0) && (idx < MaxVal)){
			int tIdx = idx + bitMask;
			if (cumFre >= tree[tIdx]){ 
				// if current cumulative frequency is equal to cumFre, 
				// we are still looking for higher index (if exists)
				idx = tIdx;
				cumFre -= tree[tIdx];
			}
			bitMask >>= 1;
		}
		if (cumFre != 0)
			return -1;
		else
			return idx;
	}*/

		
};

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------


/*
scanf("%d",&(nt));
scanf("%d %d",&(n),&(m));
scanf("%d",&(m[i][j]); 
sum%=1000000007;
 */

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

int caso = 1;
void solve() {
    int n, q;
    cin >> n >> q;
    BIT bit = BIT(n);
    cout << "Case " << caso++  << ":\n";

    for(int i=0;i<n;i++) {
    	int valor ;
    	cin >> valor;
    	bit.update(i+1,valor);
    }

    //posicoes validas: [1,n]
    for(int i=0;i<q;i++) {
        int op;
        cin >> op;
        if(op==1) {
            int balde;
            cin >> balde;
            balde++; //conta a partir do 1
            int totalBalde = bit.read(balde) - bit.read(balde-1); //ok: balde for <=0 --> retorna 0
            bit.update(balde,-totalBalde);
            cout << totalBalde << "\n";
        } else if(op==2) {
            int balde, valor;
            cin >> balde >> valor;
            balde++; //conta a partir do 1
            bit.update(balde,valor);
        } else {
            int balde, balde2;
            cin >> balde >> balde2;
            balde++; //conta a partir do 1
            balde2++;
            cout << bit.read(balde2) - bit.read(balde-1) << "\n";
        }
    }
}

int main() {
    int nt = 0;
    cin >> nt;
    for(int i=0;i<nt;i++)
        solve();	

	
	
	return 0;   
}