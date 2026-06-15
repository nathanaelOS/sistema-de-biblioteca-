#include "Livro.h"
#include <iostream>
using namespace std;

Livro::Livro(string isbn, string titulo, string autor) {
    this->isbn = isbn;
    this->titulo = titulo;
    this->autor = autor;
    this->disponivel = true;
}

string Livro::getIsbn() {
    return isbn;
}

void Livro::setIsbn(string isbn) {
    this->isbn = isbn;
}

string Livro::getTitulo() {
    return titulo;
}

void Livro::setTitulo(string titulo) {
    this->titulo = titulo;
}

string Livro::getAutor() {
    return autor;
}

void Livro::setAutor(string autor) {
    this->autor = autor;
}

bool Livro::getDisponivel() {
    return disponivel;
}

void Livro::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

void Livro::emprestar() {
    if (disponivel) {
        disponivel = false;
        cout << "Livro emprestado com sucesso.\n";
    } else {
        cout << "Livro nao disponivel para emprestimo.\n";
    }
}

void Livro::devolver() {
    disponivel = true;
    cout << "Livro devolvido com sucesso.\n";
}
