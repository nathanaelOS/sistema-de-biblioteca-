#include <iostream>
#include <vector>
#include "Livro.h"
#include "Usuario.h"
#include "Bibliotecario.h"
#include "Emprestimo.h"
using namespace std;

int main() {
    vector<Livro> livros;
    vector<Usuario> usuarios;
    vector<Emprestimo> emprestimos;

    // Bibliotecario fixo do sistema
    Bibliotecario bibliotecario("Admin", "00000000000", 1);

    int opcao;

    do {
        cout << "\n===== SISTEMA DE BIBLIOTECA =====\n";
        cout << "1. Cadastrar Livro\n";
        cout << "2. Cadastrar Usuario\n";
        cout << "3. Consultar Livros\n";
        cout << "4. Realizar Emprestimo\n";
        cout << "5. Realizar Devolucao\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string isbn, titulo, autor;
                cout << "\n--- Cadastrar Livro ---\n";
                cout << "ISBN: ";
                cin >> isbn;
                cout << "Titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);

                Livro novoLivro(isbn, titulo, autor);
                bibliotecario.cadastrarLivro(livros, novoLivro);
                break;
            }
            case 2: {
                string nome, cpf;
                int matricula;
                cout << "\n--- Cadastrar Usuario ---\n";
                cout << "Nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "CPF: ";
                cin >> cpf;
                cout << "Matricula: ";
                cin >> matricula;

                Usuario novoUsuario(nome, cpf, matricula);
                usuarios.push_back(novoUsuario);
                cout << "Usuario cadastrado com sucesso.\n";
                break;
            }
            case 3: {
                if (usuarios.empty()) {
                    cout << "\nNenhum usuario cadastrado. Cadastre um usuario primeiro.\n";
                    break;
                }
                usuarios[0].consultarLivros(livros);
                break;
            }
            case 4: {
                if (usuarios.empty() || livros.empty()) {
                    cout << "\nE necessario ter usuarios e livros cadastrados.\n";
                    break;
                }
                int idxUsuario, idxLivro;
                string dataEmprestimo, dataPrevistaDevolucao;

                cout << "\n--- Usuarios ---\n";
                for (size_t i = 0; i < usuarios.size(); i++) {
                    cout << i << " - " << usuarios[i].getNome() << endl;
                }
                cout << "Escolha o indice do usuario: ";
                cin >> idxUsuario;

                cout << "\n--- Livros ---\n";
                for (size_t i = 0; i < livros.size(); i++) {
                    cout << i << " - " << livros[i].getTitulo()
                         << " (" << (livros[i].getDisponivel() ? "Disponivel" : "Indisponivel") << ")" << endl;
                }
                cout << "Escolha o indice do livro: ";
                cin >> idxLivro;

                if (idxUsuario < 0 || idxUsuario >= (int)usuarios.size() ||
                    idxLivro < 0 || idxLivro >= (int)livros.size()) {
                    cout << "Indice invalido.\n";
                    break;
                }

                cout << "Data do Emprestimo (dd/mm/aaaa): ";
                cin >> dataEmprestimo;
                cout << "Data Prevista de Devolucao (dd/mm/aaaa): ";
                cin >> dataPrevistaDevolucao;

                bibliotecario.realizarEmprestimo(emprestimos, &usuarios[idxUsuario], &livros[idxLivro],
                                                  dataEmprestimo, dataPrevistaDevolucao);
                break;
            }
            case 5: {
                if (livros.empty()) {
                    cout << "\nNenhum livro cadastrado.\n";
                    break;
                }
                int idxLivro;
                cout << "\n--- Livros ---\n";
                for (size_t i = 0; i < livros.size(); i++) {
                    cout << i << " - " << livros[i].getTitulo()
                         << " (" << (livros[i].getDisponivel() ? "Disponivel" : "Indisponivel") << ")" << endl;
                }
                cout << "Escolha o indice do livro para devolver: ";
                cin >> idxLivro;

                if (idxLivro < 0 || idxLivro >= (int)livros.size()) {
                    cout << "Indice invalido.\n";
                    break;
                }
                livros[idxLivro].devolver();
                break;
            }
            case 0:
                cout << "\nSaindo do sistema...\n";
                break;
            default:
                cout << "\nOpcao invalida.\n";
        }

    } while (opcao != 0);

    return 0;
}
