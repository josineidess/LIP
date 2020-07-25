#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

struct Pessoa{
   string cpf;
   string nome;
   string sobrenome;
   string endereco;
   string telefone;
};

int main()
{
    int quant;

    cin >> quant;
    cin.ignore();
    Pessoa pessoas[quant];

    for(int e = 0;e < quant;e++){
       getline(cin,pessoas[e].cpf);
       getline(cin,pessoas[e].nome);
       getline(cin,pessoas[e].sobrenome);
       getline(cin,pessoas[e].endereco);
       getline(cin,pessoas[e].telefone);
    }
    remove("pessoas.csv");
    
    ofstream arquivoE;
    arquivoE.open("pessoas.csv",ios::app);
    for(int e = 0;e < quant;e++){
      arquivoE << pessoas[e].cpf;
      arquivoE << ";";
      arquivoE << pessoas[e].nome;
      arquivoE << ";";
      arquivoE << pessoas[e].sobrenome;
      arquivoE << ";";
      arquivoE << pessoas[e].endereco;
      arquivoE << ";";
      arquivoE << pessoas[e].telefone;
      arquivoE << "\n";
    }
    arquivoE.close();

    fstream arquivoS;
    string linha;
    arquivoS.open("pessoas.csv");
    if(arquivoS.is_open()){
      while(getline(arquivoS,linha)){
        cout << linha << endl;
      }
      arquivoS.close();
    }else{
       cout << "Não foi possível abrir arquivo" << endl;
    }

    return 0;
}
