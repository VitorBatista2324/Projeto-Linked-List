#include <iostream>
#include <string>

using namespace std;

struct Comprador {

    string nome;
    int idade;
    string cidade;
    int ingresso;

};

struct Node {

    Comprador comprador;
    Node* anterior;
    Node* proximo;

};

int contador(Node* inicio) {

    int contador = 0;

    Node* atual = inicio;

    while(atual != NULL) {

        contador++;

        atual = atual->proximo;

    }

    return contador;

}

void cadastrar(Node** inicio) {

    Node* novo = new Node();

    cout << "nome: ";

    cin >> novo->comprador.nome;

    cout << "idade: ";

    cin >> novo->comprador.idade;

    cout << "cidade: ";

    cin >> novo->comprador.cidade;

    cout << "ingresso: ";

    cin >> novo->comprador.ingresso;

    novo->anterior = NULL;

    novo->proximo = NULL;

    if(*inicio == NULL) {

        *inicio = novo;

    }

    else {

        Node* atual = *inicio;

        while(atual->proximo != NULL) {

            atual = atual->proximo;

        }

        atual->proximo = novo;

        novo->anterior = atual;

    }

    cout << "Comprador cadastrado!" << endl;

}

void imprimir(Node* inicio) {

    if(inicio == NULL) {

        cout << "Nenhum comprador encontrado." << endl;

        return;

    }

    Node* atual = inicio;

    while(atual != NULL) {

        cout << endl;

        cout << "Nome: " << atual->comprador.nome << endl;

        cout << "Idade: " << atual->comprador.idade << endl;

        cout << "Cidade: " << atual->comprador.cidade << endl;

        cout << "Ingresso: " << atual->comprador.ingresso << endl;

        atual = atual->proximo;

    }

}

void buscar(Node* inicio) {

    string nome;

    cout << "Digite o nome do comprador: ";

    cin >> nome;

    Node* atual = inicio;

    while(atual != NULL) {

        if(atual->comprador.nome == nome) {

            cout << "Comprador encontrado!" << endl;

            cout << "Nome: " << atual->comprador.nome << endl;

            cout << "Idade: " << atual->comprador.idade << endl;

            cout << "Cidade: " << atual->comprador.cidade << endl;

            cout << "Ingresso: " << atual->comprador.ingresso << endl;

            return;

        }

        atual = atual->proximo;

    }

    cout << "Comprador nao encontrado!" << endl;

}

void remover(Node** inicio) {

    string nome;

    cout << "Digite o nome do comprador: ";

    cin >> nome;

    Node* atual = *inicio;

    if(atual != NULL && atual->comprador.nome == nome) {

        *inicio = atual->proximo;

        if(*inicio != NULL) {

            (*inicio)->anterior = NULL;

        }

        cout << "Comprador removido!" << endl;

        return;

    }

    while(atual != NULL && atual->proximo != NULL) {

        if(atual->proximo->comprador.nome == nome) {

            atual->proximo = atual->proximo->proximo;

            if(atual->proximo != NULL) {

                atual->proximo->anterior = atual;

            }

            cout << "Comprador removido!" << endl;

            return;

        }

        atual = atual->proximo;

    }

    cout << "Comprador nao encontrado!" << endl;

}

void mostrarInverso(Node* inicio) {

    if(inicio == NULL) {

        cout << "Nenhum comprador encontrado." << endl;

        return;

    }

    Node* atual = inicio;

    while(atual->proximo != NULL) {

        atual = atual->proximo;

    }

    while(atual != NULL) {

        cout << endl;

        cout << "Nome: " << atual->comprador.nome << endl;

        cout << "Idade: " << atual->comprador.idade << endl;

        cout << "Cidade: " << atual->comprador.cidade << endl;

        cout << "Ingresso: " << atual->comprador.ingresso << endl;

        atual = atual->anterior;

    }

}

int main() {

    Node* inicio = NULL;

    int opcao = 0;

    while(opcao != 6) {

        cout << endl;

        cout << "SHOWS" << endl;

        cout << "1 - Cadastrar comprador" << endl;

        cout << "2 - Consultar compradores" << endl;

        cout << "3 - Buscar comprador" << endl;

        cout << "4 - Remover comprador" << endl;

        cout << "5 - Consultar em ordem inversa" << endl;

        cout << "6 - Sair" << endl;

        cout << "Escolha: ";

        cin >> opcao;

        if(opcao == 1) {

            cadastrar(&inicio);

        }

        else if(opcao == 2) {

            imprimir(inicio);

        }

        else if(opcao == 3) {

            buscar(inicio);

        }

        else if(opcao == 4) {

            remover(&inicio);

        }

        else if(opcao == 5) {

            mostrarInverso(inicio);

        }

    }

    return 0;

}