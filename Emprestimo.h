#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <string>
#include "Usuario.h"
#include "Livro.h"
using namespace std;

class Emprestimo {
private:
    string dataEmprestimo;
    string dataPrevistaDevolucao;
    Usuario *usuario;
    Livro *livro;

public:
    Emprestimo(string dataEmprestimo, string dataPrevistaDevolucao, Usuario *usuario, Livro *livro);

    string getDataEmprestimo();
    void setDataEmprestimo(string dataEmprestimo);

    string getDataPrevistaDevolucao();
    void setDataPrevistaDevolucao(string dataPrevistaDevolucao);

    Usuario* getUsuario();
    Livro* getLivro();

    void registrar();
};

#endif
