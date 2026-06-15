#ifndef LIVRO_H
#define LIVRO_H

#include <string>
using namespace std;

class Livro {
private:
    string isbn;
    string titulo;
    string autor;
    bool disponivel;

public:
    Livro(string isbn, string titulo, string autor);

    string getIsbn();
    void setIsbn(string isbn);

    string getTitulo();
    void setTitulo(string titulo);

    string getAutor();
    void setAutor(string autor);

    bool getDisponivel();
    void setDisponivel(bool disponivel);

    void emprestar();
    void devolver();
};

#endif
