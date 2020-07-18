#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y, id;
    Point(int x=0, int y= 0, int id = 0){}
};

const double INF = 1e18;

bool cmpX(Point u, Point v){
    if(u.x!= v.x) return u.x < v.x;
    else return u.y < v.y;
}

bool cmpY(Point u, Point v){
    if(u.y!= v.y) return u.y < v.y;
    else return u.x < v.x;
}

void split(vector<Point> &A, Point pivot, vector<Point> &P, vector<Point> &Q){
    for(int i = 0; i< A.size(); i++){
        if(cmpX(A[i], pivot)) P.push_back(A[i]);
        else Q.push_back(A[i]);
    }
}

void getBorder(vector<Point> &A, Point pivot, double delta, vector<Point> &border){
    for(int i= 0; i< A.size(); i++){
        if(abs(A[i].x - pivot.x ) <= delta) border.push_back(A[i]);
    }
}
double getDist(Point u, Point v){
    int xx = u.x- v.x;
    int yy = u.y - v.y;
    return sqrt(1ll * xx*xx + 1ll*yy*yy);
}

double ans = INF;
int id1, id2; 

double solve(vector<Point> &X, vector<Point> &Y){
    if(X.size() == 1) return INF;
    int pivot = X.size()/2;
    vector<Point> Px, Py, Qx, Qy;

    //chia thanh 4 tap
    split(X, X[pivot], Px, Qx);
    split(Y, X[pivot], Py, Qy);

    double deltaP = solve(Px, Py);
    double deltaQ = solve(Qx, Qy);
    double delta = min(deltaP, deltaQ);

    vector<Point> borderP, borderQ;
    getBorder(Py, X[pivot], delta, borderP);
    getBorder(Qy, X[pivot], delta, borderQ);

    int posU = 0;
    double res = delta;
    for(int i= 0; i < borderP.size(); i++){
        Point p = borderP[i];
        while (posU < borderQ.size() && borderQ[posU].y < p.y) posU++;
        for(int it = -4; it <= 3; it++){
            if(posU+it >= 0 && posU + it< borderQ.size()){
                double dist = getDist(p, borderQ[posU + it]);
                res = min(res, dist);
                if(ans > dist){
                    ans = dist;
                    id1 = p.id;
                    id2 = borderQ[posU + it].id;
                }
            } 
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<Point> a(n);
    for(int i= 0; i<n; i++){
        cin>> a[i].x>> a[i].y;
        a[i].id = i;
    }

    vector<Point> X = a;
    vector<Point> Y = a;
    sort(X.begin(), X.end(), cmpX);
    sort(Y.begin(), Y.end(), cmpY);

    solve(X, Y);
    if(id1 > id2) swap(id1, id2);
    cout<<id1<<" "<< id2<< " "<<fixed<<setprecision(6)<< ans<<endl;
    return 0;
}