#ifndef BIBLIOTECARIO_H
#define BIBLIOTECARIO_H

#include "Pessoa.h"
#include "Livro.h"
#include "Usuario.h"
#include "Emprestimo.h"
#include <vector>
using namespace std;

class Bibliotecario : public Pessoa {
private:
    int codigoFuncionario;

public:
    Bibliotecario(string nome, string cpf, int codigoFuncionario);

    int getCodigoFuncionario();
    void setCodigoFuncionario(int codigoFuncionario);

    void cadastrarLivro(vector<Livro> &livros, Livro livro);
    void realizarEmprestimo(vector<Emprestimo> &emprestimos, Usuario *usuario, Livro *livro,
                             string dataEmprestimo, string dataPrevistaDevolucao);
};

#endif
