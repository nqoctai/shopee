#define maxn 1000
#define maxf 1000000000
#include <iostream>
#include <fstream>
using namespace std;

int a[maxn][maxn],n,m,s,e;
int f[maxn],trace[maxn],checkt2[maxn];

/* void  readf(){
  fstream inp("input.txt");
  inp>>n>>m;
  inp>>s>>e;
  for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++) a[i][j]=-1;
  for(int i=1;i<=m;i++){
    int u,v;
    inp>>u>>v;
    inp>>a[u][v];
    a[v][u]=a[u][v];
  }
  inp.close();
} */

void input()
{
    cout << "Nhap so dinh (n): ";
    cin >> n;
    cout << "Nhap so canh (m): ";
    cin >> m;
    cout << "Nhap dinh xuat phat (s): ";
    cin >> s;
    cout << "Nhap dinh dich (e): ";
    cin >> e;

    // Khởi tạo ma trận a với giá trị mặc định là -1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = -1;
        }
    }

    // Nhập thông tin về các cạnh
    for (int i = 1; i <= m; i++) {
        int u, v, weight;
        cout << "Nhap dinh u va dinh v cua canh thu " << i << ": ";
        cin >> u >> v;
        cout << "Nhap trong so cua canh thu " << i << ": ";
        cin >> weight;
        a[u][v] = weight;
        a[v][u] = weight; // Đồ thị vô hướng, gán cả hai chiều.
    }

}

void dijkstra(){
  for(int i=1;i<=n;i++){
    f[i]=maxf;
    checkt2[i]=true;
    trace[i]=0;
  }
  f[s]=0;
  trace[s]=0;
  int v=s,fmin;
  while(v!=e){
    //tim v
    fmin=maxf;
    for(int i=1;i<=n;i++)
    if(checkt2[i] && fmin>f[i]){
      fmin=f[i];
      v=i;
    }
    if(fmin==maxf) break;
    //xoa v khoi T2
    checkt2[v]=false;
    //toi uu cac dinh trong T2
    for(int i=1;i<=n;i++)
    if(a[v][i]>0 && f[i]>f[v]+a[v][i]){
      f[i]=f[v]+a[v][i];
      trace[i]=v;
    }
  }
}
void output(){
  if(f[e]==maxf) cout<<"NO PATH";
  else{
    cout<<f[e]<<"\n";
    int path[maxn],d=0;
    d++;
    path[d]=e;
    while(trace[e]!=0){
        e=trace[e];
        d++;
        path[d]=e;
    }
    for(int i=d;i>0;i--)
    cout<<path[i]<<" ";

  }
  
  

}

int main(){
  // readf();
    input();
  dijkstra();
  output();
}