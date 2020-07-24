#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Produto{
   int codigo;
   string nome;
   double preco;
   int estoque;
};

struct Data{
  int dia;
  int mes;
  int ano;
};

struct Cliente{
   string nome;
   string endereco;
   string email;
   long int cpf;
   Data data_nascimento;
};

struct Loja{
  string nome;
  string endereco;
  int telefone;
  Cliente clientes[1000];
  Produto produtos[50];
};
void aniversariantes_do_mes(Loja loja,int quant,int mes);
void prod_esto_inf10(Loja loja,int quant);
void exibir_cliente(Loja loja,int pos);
void info_prod(Loja loja,int pos);

int main(){
    int num_clientes,n_mes,num_produtos,pos_cliente,pos_produto;
    Loja loja;
    
    cin >> num_clientes;
    cin >> num_produtos;
    
    cin.ignore();
    getline(cin,loja.nome);
    getline(cin,loja.endereco);
    cin >> loja.telefone;
    
    for(int e = 0;e < num_clientes;e++){
        cin.ignore();
        getline(cin,loja.clientes[e].nome);
        getline(cin,loja.clientes[e].endereco);
        getline(cin,loja.clientes[e].email);
        cin >> loja.clientes[e].cpf;
        cin >> loja.clientes[e].data_nascimento.dia;
        cin >> loja.clientes[e].data_nascimento.mes;
        cin >> loja.clientes[e].data_nascimento.ano;
    }
    
    for(int e = 0;e < num_produtos;e++){
       cin >> loja.produtos[e].codigo;
       cin.ignore();
       getline(cin,loja.produtos[e].nome);
       cin >> loja.produtos[e].preco;
       cin >> loja.produtos[e].estoque;
       cin.ignore();
    }

    cin >> n_mes;
    cin >> pos_cliente;
    cin >> pos_produto;

    cout << "Loja: " << loja.nome << endl;
    cout << "Endereço: " << loja.endereco << endl;
    cout << "Telefone: " << loja.telefone << endl;

    aniversariantes_do_mes(loja,num_clientes,n_mes);
    prod_esto_inf10(loja, num_produtos);
    exibir_cliente(loja, pos_cliente);
    info_prod(loja,pos_produto);
    return 0;
}

void aniversariantes_do_mes(Loja loja,int quant,int mes){
    string meses[12] = {"janeiro","fevereiro","março","abril","maio","junho","julho","agosto","setembro","outubro","novembro","dezembro"};
    cout << "Aniversariantes de " << meses[mes-1] << ":" << endl;
    for(int e = 0;e < quant;e++){
        if(loja.clientes[e].data_nascimento.mes == mes){
            cout << loja.clientes[e].nome << endl;
        }
    }
}

void prod_esto_inf10(Loja loja,int quant){
  cout << "Produtos com estoque inferior a 10:" << endl;
  for(int e = 0;e < quant;e++){
    if(loja.produtos[e].estoque < 10){
      cout << loja.produtos[e].nome << endl;
    }
  }
}

void exibir_cliente(Loja loja,int pos){
  cout << "Cliente na posição " << pos << ":" << endl;
  cout << "Nome: " << loja.clientes[pos].nome << endl;
  cout << "Endereço: " << loja.clientes[pos].endereco << endl;
  cout << "Email: " << loja.clientes[pos].email << endl;
  cout << "CPF: " << loja.clientes[pos].cpf << endl;
  cout << "Data de nascimento: " << loja.clientes[pos].data_nascimento.dia << "/" << loja.clientes[pos].data_nascimento.mes << "/" << loja.clientes[pos].data_nascimento.ano << endl; 
}

void info_prod(Loja loja,int pos){
   cout << "Produto na posição: " << pos << endl;
   cout << "Código: " << loja.produtos[pos].codigo << endl;
   cout << "Nome: " << loja.produtos[pos].nome << endl;
   cout << "Preço: " << fixed << setprecision(2)<< loja.produtos[pos].preco << endl;
   cout << "Estoque: " << loja.produtos[pos].estoque << endl;
}
