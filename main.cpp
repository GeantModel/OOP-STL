#include <iostream>
#include "vector"
#include "random"
#include "time.h"
#include "Point.h"
#include "algorithm"
#include "map"

using namespace std;
int main() {
    srand(time(0));
    int n=50;
    vector<Point> coord;
    for(int i=0; i<n; i++){
        Point Ai(rand()%100-rand()%100,rand()%100-rand()%100,rand()%100-rand()%100);
        coord.push_back(Ai);
        cout<<"("<<Ai.getX()<<", "<<Ai.getY()<<", "<<Ai.getZ()<<")"<<endl;
    }
    double k=0;
    for(int i=0; i<n; i++){
        if (coord[i].getRast()<coord[k].getRast())
            k=i;
    }
    cout << endl;
    cout<<"Minimal'naya k centru tochka "<<"("<<coord[k].getX()<<", "<<coord[k].getY()<<", "<<coord[k].getZ()<<")"<<endl;
    vector<Point> A;
    Point A1(-100,-100,-100);
    Point A2(-100,100,-100);
    Point A3(100,100,-100);
    Point A4(100,-100,-100);
    Point A5(100,-100,100);
    Point A6(-100,-100,100);
    Point A7(-100,100,100);
    Point A8(100,100,100);
    A.push_back(A1);A.push_back(A2);A.push_back(A3);A.push_back(A4);
    A.push_back(A5);A.push_back(A6);A.push_back(A7);A.push_back(A8);
    cout << endl;
    for (int i=0; i<8; i++){
        k=0;
        for (int j=0; j<n; j++){
            if (Point::getRast2(coord[j],A[i])<Point::getRast2(coord[k],A[i]))
                k=j;
        }
        cout<<"Minimal'naya k "<<"("<<A[i].getX()<<", "<<A[i].getY()<<", "<<A[i].getZ()<<")  "<<"("<<coord[k].getX()<<", "<<coord[k].getY()<<", "<<coord[k].getZ()<<")"<<endl;
    }
    sort(coord.begin(),coord.end());
    map<int, Point> M;
    for (int i=0; i<n; i++) {
        M.emplace((i+1),coord[i]);
    }
    cout << endl;
    for (auto& x: M) {
        cout << x.first <<" "<<"(" << x.second.getX()<<" "<<x.second.getY()<<" "<<x.second.getZ()<<")"<<endl;
    }

}