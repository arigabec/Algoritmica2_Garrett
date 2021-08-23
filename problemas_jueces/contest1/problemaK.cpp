//UNION FIND

#include <bits/stdc++.h> 
using namespace std;
int parent[105];
int rango[105];
int n;

void init() {
    for(int i = 0;  i <= n; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

float distance(pair <float, float> a, pair <float, float> b) {
    float x = a.first - b.first;
    float y = a.second - b.second;
    return sqrt(x * x + y * y);
}

bool compare(pair <float, pair <int, int>> a, pair <float, pair<int, int>> b) {
    return a.first < b.first;
}

int main() {
    int cases;
    float x,y;
    cin >> cases;
    while(cases--) {
        cin >> n;
        vector< pair <float, float>> points;
        float matrix[n][n];
        float visited[n], cost[n], prev[n];
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            points.push_back(make_pair(x,y));
        }
        init();
        vector<pair<float, pair<int, int>>> E;
        E.clear();
        vector<pair<float, pair<int, int>>> X;
        X.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                E.push_back(make_pair(distance(points[i], points[j]), make_pair(i, j)));
            }
        }
        sort(E.begin(), E.end(), compare);
 
        for (int i = 0; i < E.size(); i++) {
            if (find(E[i].second.first) != find(E[i].second.second)) {
                X.push_back(E[i]);
                unionRango(E[i].second.first, E[i].second.second);
            }
        }
        float total = 0;
        for (int i = 0; i < X.size(); i++){
            total += X[i].first;
        }
        printf("%.2f\n", total);
        if(cases > 0){
            cout << endl;
        }   
    }
    return 0;
}