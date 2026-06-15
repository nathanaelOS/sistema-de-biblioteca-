#ifndef USUARIO_H
#define USUARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include <vector>
using namespace std;

class Usuario : public Pessoa {
private:
    int matricula;

public:
    Usuario(string nome, string cpf, int matricula);

    int getMatricula();
    void setMatricula(int matricula);

    void consultarLivros(vector<Livro> &livros);
};

#endif
