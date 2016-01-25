#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct bigint {
    int val[603];
    int n;
    int sign;
    bigint() {}
    bigint(int a){
        if(a == 0){
            sign = 0;
            val[0] = 0;
            n = 1;
            return;
        }
        sign = 1;
        if(a < 0) {
            sign = -1;
            a *= -1;
        }
        n = 0;
        while(a) {
            val[n] = a%10;
            a/=10;
            ++n;
        }
    }
    void product(const bigint &other) {
        if(sign == 0 || other.sign == 0){
            sign = 0;
            n = 1;
            val[0] = 0;
            return;
        }
        int tmp[604];
        sign *= other.sign;
        for(int i=0;i<604;++i) tmp[i] = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<other.n;++j){
                tmp[i+j] += val[i] * other.val[j];
            }
        }
        int k = 0;
        while(k < n+other.n-2 || tmp[k] != 0){
            tmp[k+1] += tmp[k]/10;
            tmp[k] %= 10;
            ++k;
        }
        n = k;
        for(int i=0;i<n;++i){
            val[i] = tmp[i];
        }
    }
    void bigger(const bigint& other) {
        if(sign < other.sign || (sign == 1 && other.sign == 1 && other.n > n) || (sign == -1 && other.sign == -1 && other.n < n) ) {
            for(int i=0;i<other.n; ++i){
                val[i] = other.val[i];
            }
            sign = other.sign;
            n = other.n;
        } else if(sign == 1 && other.sign == 1 && other.n == n) {
            bool iambigger = true;
            for(int i=n-1;i>=0;--i){
                if(val[i] < other.val[i]){
                    iambigger = false;
                    break;
                }
            }
            if( !iambigger) {
                for(int i=0;i<other.n; ++i){
                    val[i] = other.val[i];
                }
                sign = other.sign;
                n = other.n;
            }
        } else if(sign == -1 && other.sign == -1 && other.n == n) {
            bool iambigger = true;
            for(int i=n-1;i>=0;--i){
                if(val[i] > other.val[i]){
                    iambigger = false;
                    break;
                }
            }
            if( !iambigger) {
                for(int i=0;i<other.n; ++i){
                    val[i] = other.val[i];
                }
                sign = other.sign;
                n = other.n;
            }
        }
    }
    void print() {
        if(sign == -1) printf("-");
        for(int i=n-1;i>=0;--i){
            printf("%d", val[i]);
        }
        printf("\n");
    }
};


bigint P[103][103];

int main(){
    int v;
    while(cin >> v) {
        int N = 1;
        P[0][0] = bigint(v);
        bigint ans = P[0][0];
        while(cin >> v) {
            if(v == -999999) break;
            P[N][N] = bigint(v);
            ans.bigger(P[N][N]);
            ++N;
        }
        for(int k = 1; k < N; ++k){
            for(int i=0;i+k<N;++i){
                int j = i+k;
                P[i][j] = P[i][i];
                P[i][j].product(P[i+1][j]);
                //printf("%d %d ", i, j);
                //P[i][j].print();
                ans.bigger(P[i][j]);
            }
        }
        ans.print();
    }
    return 0;
}
