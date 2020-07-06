#include <iostream>

using namespace std;

int num_p_func1 = 0, num_p_func2 = 0;
float x1, x2, val_p_func1[30], val_p_func2[30], vendas1 = 0, vendas2 = 0;

bool vendeu_p_x(float x, int & num_p_func, float val_p_func[30]);
bool vendeu_2p(float val_p_func[30], int & num_p_func);
int maior_lucro(float val_p_func1[30], float val_p_func2[30], int & num_p_func1, int & num_p_func2, float & vendas1, float & vendas2);
bool vend1_mais_caro_vend2(float val_p_func1[30], int & num_p_func1, int & num_p_func2, float val_p_func2[30]);

int main() {
  cin >> num_p_func1;
  for (int e = 0; e < num_p_func1; e++) {
    cin >> val_p_func1[e];
  }
  cin >> num_p_func2;
  for (int e = 0; e < num_p_func2; e++) {
    cin >> val_p_func2[e];
  }
  cin >> x1;
  cin >> x2;

  cout << "Vendas 1." << endl;
  cout << "[ ";
  for (int e = 0; e < num_p_func1; e++) {
    if (e != num_p_func1 - 1) {
      cout << val_p_func1[e] << " , ";
    } else {
      cout << val_p_func1[e];
    }

  }
  cout << " ]" << endl;


  cout << "Vendas 2." << endl;
  cout << "[ ";
  for (int e = 0; e < num_p_func2; e++) {
    if (e != num_p_func2 - 1) {
      cout << val_p_func2[e] << " , ";
    } else {
      cout << val_p_func2[e];
    }

  }
  cout << " ]" << endl;


  if (vendeu_p_x(x1, num_p_func1, val_p_func1)) {
    cout << "Sim, funcionário 1 vendeu um produto cujo valor foi " << x1 << endl;
  } else {
    cout << "Não, funcionário 1 não vendeu um produto cujo valor foi " << x1 << endl;
  }


  if (vendeu_p_x(x2, num_p_func2, val_p_func2)) {
    cout << "Sim, funcionário 2 vendeu um produto cujo valor foi " << x2 << endl;
  } else {
    cout << "Não, funcionário 2 não vendeu um produto cujo valor foi " << x2 << endl;
  }


  if (vendeu_2p(val_p_func1, num_p_func1)) {
    cout << "Sim, funcionário 1 vendeu dois produtos com o mesmo valor" << endl;
  } else {
    cout << "Não, funcionário 1 não vendeu dois produtos com o mesmo valor" << endl;
  }


  if (vendeu_2p(val_p_func2, num_p_func2)) {
    cout << "Sim, funcionário 2 vendeu dois produtos com o mesmo valor" << endl;
  } else {
    cout << "Não, funcionário 2 não vendeu dois produtos com o mesmo valor" << endl;
  }


  switch (maior_lucro(val_p_func1, val_p_func2, num_p_func1, num_p_func2, vendas1, vendas2)) {
  case 1:
    cout << "O melhor vendedor foi 1" << endl;
    break;
  case 2:
    cout << "O melhor vendedor foi 2" << endl;
    break;
  case 0:
    cout << "Empate" << endl;
    break;
  }


  if (vend1_mais_caro_vend2(val_p_func1, num_p_func1, num_p_func2, val_p_func2)) {
    cout << "Sim, todos os produtos vendidos por 1 foram mais caros que os produtos vendidos por 2" << endl;
  } else {
    cout << "Não, os produtos vendidos por 1 não foram todos mais caros que os produtos vendidos por 2" << endl;
  }


  if (vend1_mais_caro_vend2(val_p_func2, num_p_func2, num_p_func1, val_p_func1)) {
    cout << "Sim, todos os produtos vendidos por 2 foram mais caros que os produtos vendidos por 1" << endl;
  } else {
    cout << "Não, os produtos vendidos por 2 não foram todos mais caros que os produtos vendidos por 1" << endl;
  }

  return 0;
}


bool vendeu_p_x(float x, int & num_p_func, float val_p_func[30]) {
  for (int e = 0; e < num_p_func; e++) {
    if (val_p_func[e] == x) {
      return true;
    }
  }
  return false;
}


bool vendeu_2p(float val_p_func[30], int & num_p_func) {
  for (int e = 0; e < num_p_func; e++) {
    if (e > 0) {
      for (int i = 0; i < e; i++) {
        if (val_p_func[e] == val_p_func[i]) {
          return true;
        }
      }
    }
  }
  return false;
}


int maior_lucro(float val_p_func1[30], float val_p_func2[30], int & num_p_func1, int & num_p_func2, float & vendas1, float & vendas2) {
  for (int e = 0; e < num_p_func1; e++) {
    vendas1 += val_p_func1[e];
  }
  for (int e = 0; e < num_p_func2; e++) {
    vendas2 += val_p_func2[e];
  }
  if (vendas1 > vendas2) {
    return 1;
  } else {
    if (vendas1 == vendas2) {
      return 0;
    } else {
      return 2;
    }
  }
}


bool vend1_mais_caro_vend2(float val_p_func1[30], int & num_p_func1, int & num_p_func2, float val_p_func2[30]) {
  for (int e = 0; e < num_p_func1; e++) {
    for (int i = 0; i < num_p_func2; i++) {
      if (val_p_func1[e] < val_p_func2[i]) {
        return false;
      }
    }
  }
  return true;
}
