#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string nome, string cpf, int matricula) : Pessoa(nome, cpf) {
    this->matricula = matricula;
}

int Usuario::getMatricula() {
    return matricula;
}

void Usuario::setMatricula(int matricula) {
    this->matricula = matricula;
}

void Usuario::consultarLivros(vector<Livro> &livros) {
    cout << "\n--- Lista de Livros ---\n";
    if (livros.empty()) {
        cout << "Nenhum livro cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < livros.size(); i++) {
        cout << "ISBN: " << livros[i].getIsbn()
             << " | Titulo: " << livros[i].getTitulo()
             << " | Autor: " << livros[i].getAutor()
             << " | Disponivel: " << (livros[i].getDisponivel() ? "Sim" : "Nao")
             << endl;
    }
}
