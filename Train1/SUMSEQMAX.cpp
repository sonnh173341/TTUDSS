#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
  int sumMax = a[0];
  int maxhere = a[0];
  for(int i=1; i<n; i++){
    int u = maxhere + a[i];
    int v = a[i];
    if(u < v){
      maxhere = v;
    }else{
      maxhere = u;
    }
    sumMax = (sumMax > maxhere) ? sumMax :maxhere;
  }
	cout<< sumMax;
  cout<<endl;
	return 0;
}
