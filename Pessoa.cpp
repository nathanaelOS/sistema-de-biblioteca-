#include "Pessoa.h"

Pessoa::Pessoa(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getCpf() {
    return cpf;
}

void Pessoa::setCpf(string cpf) {
    this->cpf = cpf;
}
