#include<bits/stdc++.h>
using namespace std;

#define sll(a,b) scanf("%lld %lld",&a,&b);
#define outl(a) printf("%lld\n",a)
typedef long long i64;


/*
 Observation 1: a/b, if we add resistor 1 in series, we get (a+b)/b
 Observation 2: a/b, if we add resistor 1 in parallel, we get a/(a+b)

 Observation 3: a/b, if min(a,b)=a, we have to reach a/b from a/(b-x*a), where x= b/a
 Observation 4: a/b, if min(a,b)=b, we have to reach a/b from (a-x*b)/b, where x= a/b

 Observation 5: a/1, we have to add a resistors in series
 Observation 6: 1/b, we have to add b resistors in parallel
*/

i64 call(i64 a, i64 b){
    if(a==1)  return b;
    if(b==1)  return a;

    i64 mini= min(a,b);
    i64 maxi= max(a,b);

    return maxi/mini+ call(maxi-(maxi/mini)*mini,mini);

}

main(){
    i64 a,b;
    sll(a,b);

    outl(call(a,b));

}