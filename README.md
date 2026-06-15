# Sistema de Biblioteca em C++

Esse projeto é a implementação da atividade de Programação Orientada a Objetos

A ideia geral é simular o funcionamento básico de uma biblioteca: cadastrar livros, cadastrar usuários, fazer empréstimos e devoluções, tudo pelo terminal.

## Como o código está organizado

Cada classe do diagrama virou um par de arquivos `.h` (header, onde fica a "assinatura" da classe) e `.cpp.

### Pessoa (Pessoa.h / Pessoa.cpp)

É a classe mãe do sistema. possue nome e cpf, com seus getters e setters.

### Usuario (Usuario.h / Usuario.cpp)

Herda de `Pessoa` e adiciona a `matricula`. Além disso tem o método `consultarLivros()`, que mostra na tela todos os livros cadastrados, indicando se estão disponíveis ou não.

### Bibliotecario (Bibliotecario.h / Bibliotecario.cpp)

Também herda de `Pessoa`, mas representa quem trabalha na biblioteca. Tem o `codigoFuncionario` e dois métodos importantes:

- `cadastrarLivro()`: adiciona um novo livro na lista de livros do sistema.
- `realizarEmprestimo()`: faz a "ponte" entre um usuário e um livro, criando um empréstimo (e marcando o livro como indisponível).

### Livro (Livro.h / Livro.cpp)

Representa cada livro da biblioteca: `isbn`, `titulo`, `autor` e um booleano `disponivel` que indica se ele está livre para empréstimo.

- `emprestar()`: muda `disponivel` para `false` (se já não tiver sido emprestado).
- `devolver()`: muda `disponivel` de volta para `true`.

### Emprestimo (Emprestimo.h / Emprestimo.cpp)

É a classe que liga um `Usuario` a um `Livro`. Guarda a data do empréstimo e a data prevista de devolução, e usa **ponteiros** (`Usuario*` e `Livro*`) pra não precisar duplicar os dados — ela só "aponta" para o usuário e o livro que já existem na memória.

- `registrar()`: imprime na tela um resuminho do empréstimo (quem pegou, qual livro, e as datas).

### main.cpp

Aqui estão os  `vector`s que guardam os livros, usuários e empréstimos cadastrados, além do menu interativo que fica em loop até o usuário escolher a opção de saída (0):

1. Cadastrar Livro
2. Cadastrar Usuário
3. Consultar Livros
4. Realizar Empréstimo
5. Realizar Devolução
0. Sair

Cada opção do menu chama os métodos das classes que a gente criou — é basicamente o `main.cpp` "orquestrando" tudo.

## Como os conceitos de POO aparecem aqui

- **Encapsulamento**: todos os atributos são `private`/`protected`, só acessíveis via getters e setters.
- **Herança**: `Usuario` e `Bibliotecario` herdam de `Pessoa`.
- **Associação/Composição**: `Emprestimo` se relaciona com `Usuario` e `Livro` através de ponteiros.
- **Vetores**: livros, usuários e empréstimos ficam guardados em `std::vector`.

## Como compilar e rodar

g++ -o biblioteca.exe main.cpp Pessoa.cpp Usuario.cpp Bibliotecario.cpp Livro.cpp Emprestimo.cpp
 
.\biblioteca.exe
```

## Dica de uso

Pra testar o empréstimo, primeiro cadastre pelo menos um livro (opção 1) e um usuário (opção 2). Só depois disso a opção 4 (Realizar Empréstimo) vai funcionar, porque ela precisa de pelo menos um livro e um usuário já existentes na lista.
