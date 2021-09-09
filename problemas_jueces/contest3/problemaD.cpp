#include <bits/stdc++.h>
using namespace std; 

struct Point{
    double x, y;
    Point(){} 
    Point(double a,double b) {
        x = a;
        y = b;
    }
};

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y-b.y); 
}

double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A);
}

bool pointInConvex(const vector<Point> &polign, const Point &P) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints; i++) {
        double areaPoints = area(P, polign[i], polign[(i+1)%nroPoints]);
        if(areaPoints > 0) {
           areasPositive++;
        } else if(areaPoints < 0) {
           areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}

int main(){
    vector<Point> poligono;
    int points, points2;
    while(cin >> points && points){
        for (int i = 0; i < points; i++){
            int n, m;
            cin >> n >> m;
            poligono.push_back(Point(n,m));
        }
        int x, y;
        cin >> x >> y;
        if(pointInConvex(poligono, Point(x,y))){
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
    return 0;
}