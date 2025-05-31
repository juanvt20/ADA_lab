/*Alumnos:
-Samuel Alexander Imán Quispe
- Juan Victor Tejeda Cruz
*/

#include <iostream>
using namespace std;

struct nodo {
	int nombre, peso;
	nodo(int n = 0, int p = 0) {
		nombre = n;
		peso = p;
	}
	void print() {
		cout << "contendeor " << nombre << " peso: " << peso<<endl;
	}
};


int partition(nodo vec[], int low, int high) {

    int pivot = vec[high].peso;

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (vec[j].peso <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void quickSort(nodo vec[], int low, int high) {

    if (low < high) {

        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int max_cont(nodo v[], int k, int tam) {
	int sum = 0;
	int i = 0;int cont = 0;
	for (int i = 0; i < tam; i++) {
		if (sum + v[i].peso < k) {
			sum += v[i].peso;
			cout << "contenedor de " << v[i].peso << endl;
			cont++;
		}
	}
	return cont;
}

int max_carga(nodo v[], int k, int tam) {
	int sum = 0;
	int i = tam-1;
	for (; i > 0; i--) {
		if (sum + v[i].peso <= k) {
			sum += v[i].peso;
		}
	}
	return sum;
}

int main() {
	int peso_buque;
	cout << "peso buque: ";
	cin >> peso_buque;
	int tam;
	cout << "Numero de contenedores: ";
	cin >> tam;
	nodo *f=new nodo [tam];
	for (int i = 0; i < tam; i++) {
		f[i].nombre = i + 1;
		cout << "peso para contenedor " << f[i].nombre << " ";
		cin >> f[i].peso;
	}

	quickSort(f,0,tam-1);

	for (int i = 0; i < tam; i++) {
		f[i].print();
		cout << endl;
	}

	 cout << "numero de contenedores maximo: " << max_cont(f, peso_buque, tam) << endl;
	 cout << "maximo de carga: " << max_carga(f, peso_buque, tam);

	return 0;
}
