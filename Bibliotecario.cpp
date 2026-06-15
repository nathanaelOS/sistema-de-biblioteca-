#include "Bibliotecario.h"
#include <iostream>
using namespace std;

Bibliotecario::Bibliotecario(string nome, string cpf, int codigoFuncionario) : Pessoa(nome, cpf) {
    this->codigoFuncionario = codigoFuncionario;
}

int Bibliotecario::getCodigoFuncionario() {
    return codigoFuncionario;
}

void Bibliotecario::setCodigoFuncionario(int codigoFuncionario) {
    this->codigoFuncionario = codigoFuncionario;
}

void Bibliotecario::cadastrarLivro(vector<Livro> &livros, Livro livro) {
    livros.push_back(livro);
    cout << "Livro cadastrado com sucesso.\n";
}

void Bibliotecario::realizarEmprestimo(vector<Emprestimo> &emprestimos, Usuario *usuario, Livro *livro,
                                        string dataEmprestimo, string dataPrevistaDevolucao) {
    if (!livro->getDisponivel()) {
        cout << "Livro nao disponivel para emprestimo.\n";
        return;
    }
    livro->emprestar();
    Emprestimo novoEmprestimo(dataEmprestimo, dataPrevistaDevolucao, usuario, livro);
    emprestimos.push_back(novoEmprestimo);
    novoEmprestimo.registrar();
}
