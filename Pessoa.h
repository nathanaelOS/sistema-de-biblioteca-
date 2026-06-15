#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa {
protected:
    string nome;
    string cpf;

public:
    Pessoa(string nome, string cpf);

    string getNome();
    void setNome(string nome);

    string getCpf();
    void setCpf(string cpf);
};

#endif
