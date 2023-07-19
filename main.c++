#include <iostream>
#include <vector>

using namespace std;

class Livro{
public:
  string titulo;
  string autor;
  bool disponivel;

  Livro(const string& titulo, const string& autor) : titulo(titulo),  autor(autor), disponivel(true) {}
};

class SistemaBiblioteca{
private:
  vector<Livro> livros;

public:
  void adicionarlivro(const string& titulo, const string& autor){
    Livro novoLivro(titulo, autor);
    livros.push_back(novoLivro);
  }

  void removerlivro(const string& titulo){
    for (auto it = livros.begin(); it != livros.end(); it++){
      if (it->titulo == titulo){
        livros.erase(it);
        break;
      }
    }
  }

  void emprestarlivro(const string& titulo){
    for (auto& livro : livros){
      if (livro.titulo == titulo && livro.disponivel){
        livro.disponivel = false;
        cout << "Livro " << livro.titulo << " emprestado com sucesso." << endl;
        return;
      }
    }
    cout << "Livro não disponível." << endl;
  }

  void devolverlivro(const string& titulo){
    for (auto& livro : livros){
      if (livro.titulo == titulo && !livro.disponivel){
        livro.disponivel = true;
        cout << "Livro " << livro.titulo << " devolvido com sucesso." << endl;
        return;
      }
    }
    cout << "Livro inválido ou já devolvido." << endl;
  }

  void exibirlivros(){
    cout << "    Livros disponíveis    " << endl;
    for (const auto& livro : livros){
      if (livro.disponivel){
        cout << "Título: " << livro.titulo << "  Autor: " << livro.autor << endl;
      }
    }
  }

  void pesquisarlivroportitulo(const string& titulo){
    cout << "Resultado da pesquisa por título" << endl;
    for (const auto& livro : livros){
      if (livro.titulo == titulo){
        cout << "Título: " << livro.titulo << " Autor: " << livro.autor << endl;
      }
    }
  }

  void pesquisaporautor(const string& autor){
    cout << "Resultado da pesquisa por autor" << endl;
    for (const auto& livro : livros){
      if (livro.autor == autor){
        cout << "Autor: " << livro.autor << " Livro: " << livro.titulo << endl;
      }
    }
  }
};

int main() {
  SistemaBiblioteca biblioteca;

  int opcao;
  string titulo, autor;

  do {
    cout << "\n*** Sistema de Biblioteca ***" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Adicionar livro" << endl;
    cout << "2. Remover livro" << endl;
    cout << "3. Emprestar livro" << endl;
    cout << "4. Devolver livro" << endl;
    cout << "5. Exibir livros disponíveis" << endl;
    cout << "6. Pesquisar livro por título" << endl;
    cout << "7. Pesquisar livro por autor" << endl;
    cout << "0. Sair" << endl;
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao){
      case 1: {
        cout << "Digite o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Digite o autor do livro: ";
        getline(cin, autor);
        biblioteca.adicionarlivro(titulo, autor);
        cout << "Livro adicionado com sucesso." << endl;
        break;
      }
      case 2: {
        cout << "Digite o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        biblioteca.removerlivro(titulo);
        cout << "Livro removido com sucesso." << endl;
        break;
      }
      case 3: {
        cout << "Digite o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        biblioteca.emprestarlivro(titulo);
        break;
      }
      case 4: {
        cout << "Digite o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        biblioteca.devolverlivro(titulo);
        break;
      }
      case 5:
        biblioteca.exibirlivros();
        break;
      case 6: {
        cout << "Digite o título do livro: ";
        cin.ignore();
        getline(cin, titulo);
        biblioteca.pesquisarlivroportitulo(titulo);
        break;
      }
      case 7: {
        cout << "Digite o nome do autor: ";
        cin.ignore();
        getline(cin, autor);
        biblioteca.pesquisaporautor(autor);
        break;
      }
      case 0:
        cout << "Saindo do programa." << endl;
        break;
      default:
        cout << "Opção inválida. Tente novamente." << endl;
    }
  } while (opcao != 0);

  return 0;
}