/*Alumnos: 
Imán Quispe, Samuel Alexander
Tejeda Cruz, Juan Victor
*/
#include <iostream>
#include <vector>
using namespace std;

struct nodo {
int b, t, i;
nodo(int _b, int _t, int _i) {
b = _b;
t = _t;
i = _i;
}
};

int main() {
vector<nodo> vn;


int n_tareas, beneficio, tiempo;
int indice = 1;
cin >> n_tareas;

while (n_tareas > 0) {
cin >> beneficio >> tiempo;
nodo n(beneficio, tiempo, indice);
if (vn.empty()) {
vn.push_back(n);
}
else {
for (int i = 0;i < vn.size();i++) {
if (vn[i].t == n.t) {
if (vn[i].b < n.b) {
vn[i] = n;
}
else {
break;
}

}
else if (vn[i].t != n.t) {
if (i + 1 == vn.size()) {
vn.push_back(n);
break;
}
}
}
}
n_tareas--;
indice++;
}
int b_total = 0;
for (int j = 0;j < vn.size();j++) {
b_total += vn[j].b;
cout << vn[j].i << " ";
}
cout << endl;
cout << b_total;



return 0;
}
