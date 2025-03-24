BÀI 1
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,s1;
    getline(cin,s);
    for (int i=s.length()-1;i>=0;--i)
    {
        s1+=s[i];
    }
    cout<<s1<<endl;
}
BÀI 2
#include <bits/stdc++.h>
using namespace std;

class point{
    public:
        double x,y;
        void import(){
            cin >> x >> y;
        }
        void print(){
            cout<<x<<" "<<y<<endl;
        }
};
class Line{
    public:
    double a,b;
    Line(point P1, point P2){
        a= (P1.y-P2.y)/(P1.x-P2.x);
        b= (P1.y*(P1.x-P2.x)-P1.x*(P1.y-P2.y))/(P1.x-P2.x);
    }
    void print(){
        cout<<"y="<<a<<"x+"<<b<<endl;
    }
};
    void toaDoDiem(Line L1,Line L2){
        if(L1.a==L2.a&&L1.b==L2.b) {
            cout<<"Many"<<endl;
        } 
        else if(L1.a==L2.a&&L1.b!=L2.b){
            cout<<"No"<<endl;
        }
        else {
            double xi,yi;
            xi=(L2.b-L1.b)/(L1.a-L2.a);
            yi=xi*L1.a+L1.b;
            cout<<xi<<" "<<yi<<endl;
        }
}
int main(){
    point A, B, C, D;
    A.import();
    B.import();
    C.import();
    D.import();
    Line AB (A, B);
    Line CD (C, D);
    AB.print();
    CD.print();
    toaDoDiem(AB,CD);
    return 0;
}
BÀI 3 
#include <iostream>
using namespace std;
int timUocchung(int a, int b){
    if(b==0){
        return a;
    }return timUocchung(b,a%b);
};
int main(){
    int a,b,u;
    cin>>a>>b;
    u=timUocchung(a,b);
    cout<<u<<endl;
    return 0;
} 
BÀI 4
#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
};

void sorted(int &a,int &b){
    if(a>b){
        swap(a,b);
    }
};
int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            sorted(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
BÀI 5
#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
};

void sorted(int &a, int &b){
    if(a>b)
        swap(a,b);
};

int main(){
    int n=5;
    int a[1000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            sorted(a[j],a[j+1]);
        }
    }
    int sum;
    sum=a[0]+a[n-1];
    cout<<sum<<endl;
    return 0;
}

