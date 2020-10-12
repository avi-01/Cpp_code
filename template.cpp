/*
    * @authr AVINISH KUMAR
    * @college BIT MESRA    
*/
    
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define maxn 100000000000017
#define endl "\n"
#define mk make_pair
#define pll pair<ll,ll>
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector< ppl >
#define ff first
#define ss second
#define pb push_back

#define Ns 1000007

// #define Ni 10007
// #define Ns 107

typedef long long ll;
typedef long double ld;
    
///###INPUT & OUTPUT DEFINE###///
    
char local ='O';
#define o1(a) if(local=='L'){cout<<#a<<" "<<a<<endl;}
#define o2(a,b) if(local=='L'){cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;}
#define o3(a,b,c) if(local=='L'){cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;}
#define o4(a,b,c,d) if(local=='L'){cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl;}
#define i1(a) cin>>a;
#define i2(a,b) cin>>a>>b;
#define i3(a,b,c) cin>>a>>b>>c;
#define i4(a,b,c,d) cin>>a>>b>>c>>d;

///###END INPUT & OUTPUT DEFINE###///
    
///###FOR DEFINE###///
    
#define forn(i,n) for(ll i = 0 ; i < n ; ++i )
#define forne(i,n) for(ll i = 1 ; i <= n ; ++i)
#define forr(i,n) for(ll i = n-1 ; i >=0 ; --i )
#define forab(i,a,b) for(ll i = a ; i <= b ; ++i)
#define for_range(i,a,b,c) for(ll i = a ; i <= b ; i += c)
    
    
///###END FOR DEFINE###///
    
//////////////////////////////////////TEMPLATE///////////////////////////////////
    
////////////////#####################INPUT###############///////////////////////
    
template <typename T>
void read(T &a){
    cin>>a;
}
    
template <typename T , typename T1>
void read(T &a,T1 &b){
    cin>>a>>b;
}
    
template <typename T ,typename T1 , typename T2>
void read(T &a,T1 &b,T2 &c){
    cin>>a>>b>>c;
}
    
template <typename T , typename T1>
void read(pair< T , T1 > &p){
    cin >>p.ff>>p.ss;
}   
    
template <typename T>
void read(T arr[] , ll n){
    for(ll i=0;i<n;i++){
        read(arr[i]);
    }
}
    
template <typename T>
void read(vector< T > &arr){
    for(ll i=0;i<arr.size();i++){
        read(arr[i]);
    }
}
    
    
////////////////#####################END INPUT###############//////////////////
    
    
////////////////#####################FUNCTION###############/////////////////////
    
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
    
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)        
        return binaryExponentiation(x*x,n/2);
    else                            
        return x*binaryExponentiation(x*x,(n-1)/2);
}
    
ll GCD(ll A, ll B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
    
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1; 
    y = x1;
    return gcd; 
}
    
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
    
//For M=prime no
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}

vector<ll> prime;

void sieve(ll N){
    bool isPrime[N+!1];

    for(ll i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i = 2; i * i <= N; ++i) {
            if(isPrime[i] == true) {   
                for(ll j = i * i; j <= N ;j += i)
                    isPrime[j] = false;
        }
    }

    for(ll i =2;i<=N;i++) {
        if(isPrime[i] == true) {
            prime.push_back(i);
        }
    }
}


ll minPrime[Ns];
void factorSieve(ll n){
    memset(minPrime,0,sizeof(minPrime));
    for (ll i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (ll j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}

ll factorize(ll n) {

    map<ll,ll> m;
    m.clear();
    while (n != 1) {
        m[minPrime[n]]++;
        n /= minPrime[n];
    }

    for(auto i:m) {
        if(i.second>1) {
            return 0;
        }
    }

    return 1;
    
}
    
void merge(ll A[ ] , ll start, ll mid, ll end) {
    ll p = start ,q = mid+1;
    
    ll Arr[end-start+1] , k=0;
    
    for(ll i = start ;i <= end ;i++) {
        if(p > mid)     
        Arr[ k++ ] = A[ q++] ;
    
    else if ( q > end) 
        Arr[ k++ ] = A[ p++ ];
    
    else if( A[ p ] < A[ q ])
        Arr[ k++ ] = A[ p++ ];
    
    else
        Arr[ k++ ] = A[ q++];
    }
    for (ll p=0 ; p< k ;p ++) {
        A[ start++ ] = Arr[ p ] ;                          
    }
}
    
void merge_sort (ll A[ ] , ll start , ll end ){
    if( start < end )
    {
        ll mid = (start + end ) / 2 ;          
        merge_sort (A, start , mid ) ;
        merge_sort (A,mid+1 , end ) ;         
    
        merge(A,start , mid , end );   
    }                    
}
    
ll binarySearch(ll a[],ll low,ll high,ll key){
    while(low<=high)
    {
        ll mid=(low+high)/2;
        if(a[mid]<key)
        {
            low=mid+1;
        }
        else if(a[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
    
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) { 
    if(a.first == b.first)
    {
        a.second > b.second;
    }
    return (a.first < b.first); 
}

void fib(ll n,ll m,ll a[]){
    if(n==0){
        a[0]=0;
        a[1]=1;
        return;
    }
    fib(n/2,m,a);
    ll c,d;
    c=(a[0]*(2*a[1]-a[0]+m))%m;
    d=(a[0]*a[0]+a[1]*a[1])%m;
    if(n%2==0){
        a[0]=c;
        a[1]=d;
    }
    else{
        a[0]=d;
        a[1]=c+d;
    }
}
    
struct comp {
bool operator()(pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}  
};

bool cmp (pair<ll,ll> a, pair<ll,ll> b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}  
    
    
////////////////#####################END FUNCTION###############/////////////////
    
    
    
////////////////////////////////////END TEMPLATE/////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


void solve () 
{


}


int main()  
{   
    
    #ifdef L
        local = 'L';
        time_t start, end;
        time(&start);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  
     

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);


    ll t;

    t = 1;

    // cin>>t;

    while(t--) {
        solve();
    }

    #ifdef L
        time(&end); 
        double time_taken = double(end - start); 
        cout<< endl<< endl << endl<<"Time taken by program is : " << fixed 
            << time_taken << setprecision(6); 
        cout << " sec " << endl;
    #endif 

}
