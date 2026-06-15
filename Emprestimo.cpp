#include "Emprestimo.h"
#include <iostream>
using namespace std;

Emprestimo::Emprestimo(string dataEmprestimo, string dataPrevistaDevolucao, Usuario *usuario, Livro *livro) {
    this->dataEmprestimo = dataEmprestimo;
    this->dataPrevistaDevolucao = dataPrevistaDevolucao;
    this->usuario = usuario;
    this->livro = livro;
}

string Emprestimo::getDataEmprestimo() {
    return dataEmprestimo;
}

void Emprestimo::setDataEmprestimo(string dataEmprestimo) {
    this->dataEmprestimo = dataEmprestimo;
}

string Emprestimo::getDataPrevistaDevolucao() {
    return dataPrevistaDevolucao;
}

void Emprestimo::setDataPrevistaDevolucao(string dataPrevistaDevolucao) {
    this->dataPrevistaDevolucao = dataPrevistaDevolucao;
}

Usuario* Emprestimo::getUsuario() {
    return usuario;
}

Livro* Emprestimo::getLivro() {
    return livro;
}

void Emprestimo::registrar() {
    cout << "\n--- Emprestimo Registrado ---\n";
    cout << "Usuario: " << usuario->getNome() << endl;
    cout << "Livro: " << livro->getTitulo() << endl;
    cout << "Data do Emprestimo: " << dataEmprestimo << endl;
    cout << "Data Prevista de Devolucao: " << dataPrevistaDevolucao << endl;
}
