#include <iostream>
#include <string>

using namespace std;

struct Animal {

    string nome;
    string alimentacao;
    string pais;
    int idade;

};

struct Node {

    Animal animal;
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

    if(contador(*inicio) >= 5) {
        cout << "cheio!" << endl;
        return;
    }

    Node* novo = new Node();

    cout << "Nome: ";
    cin >> novo->animal.nome;

    cout << "Alimentacao: ";
    cin >> novo->animal.alimentacao;

    cout << "pais: ";
    cin >> novo->animal.pais;

    cout << "idade: ";
    cin >> novo->animal.idade;

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
    }

    cout << "Animal Registrado!" << endl;
}

void imprimir(Node* inicio) {

    if(inicio == NULL) {
        cout << "Nenhum animal encontrado no banco." << endl;
        return;
    }

    Node* atual = inicio;

    while(atual != NULL) {

        cout << endl;
        cout << "Nome: " << atual->animal.nome << endl;
        cout << "Alimentaca: " << atual->animal.alimentacao << endl;
        cout << "Pais: " << atual->animal.pais << endl;
        cout << "Idade: " << atual->animal.idade << endl;

        atual = atual->proximo;
    }
}

void buscar(Node* inicio) {

    string nome;

    cout << "Digite o nome do bicho: ";
    cin >> nome;

    Node* atual = inicio;

    while(atual != NULL) {

        if(atual->animal.nome == nome) {

            cout << "Animal encontrado!" << endl;
            cout << "Nome: " << atual->animal.nome << endl;
            cout << "Alimentacao: " << atual->animal.alimentacao << endl;
            cout << "Pais: " << atual->animal.pais << endl;
            cout << "Idade: " << atual->animal.idade << endl;

            return;
        }

        atual = atual->proximo;
    }

    cout << "Animal nao encontrado!" << endl;
}

void remover(Node** inicio) {

    string nome;

    cout << "Digite o nome do bicho: ";
    cin >> nome;

    Node* atual = *inicio;

    if(atual != NULL && atual->animal.nome == nome) {
        *inicio = atual->proximo;
        cout << "Animal removido!" << endl;
        return;
    }

    while(atual != NULL && atual->proximo != NULL) {

        if(atual->proximo->animal.nome == nome) {

            atual->proximo = atual->proximo->proximo;

            cout << "Animal removido!" << endl;
            return;
        }

        atual = atual->proximo;
    }

    cout << "Animal nao encontrado!" << endl;
}

int main() {

    Node* aquaticos = NULL;
    Node* terrestres = NULL;
    Node* voadores = NULL;

    int opcao = 0;

    while(opcao != 5) {

        cout << endl;
        cout << "ZOOLOGICO" << endl;
        cout << "1 - Aquatico" << endl;
        cout << "2 - Terrestre" << endl;
        cout << "3 - Voador" << endl;
        cout << "4 - Consultar todos" << endl;
        cout << "5 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        if(opcao == 1) {

            int opcaoAquatico = 0;

            while(opcaoAquatico != 5) {

                cout << endl;
                cout << "AQUATICOS" << endl;
                cout << "1 - Cadastrar" << endl;
                cout << "2 - Consulta" << endl;
                cout << "3 - Buscar" << endl;
                cout << "4 - Remover" << endl;
                cout << "5 - Sair" << endl;
                cout << "Escolha: ";
                cin >> opcaoAquatico;

                if(opcaoAquatico == 1) {
                    cadastrar(&aquaticos);
                }
                else if(opcaoAquatico == 2) {
                    imprimir(aquaticos);
                }
                else if(opcaoAquatico == 3) {
                    buscar(aquaticos);
                }
                else if(opcaoAquatico == 4) {
                    remover(&aquaticos);
                }
            }
        }

        else if(opcao == 2) {

            int opcaoTerrestre = 0;

            while(opcaoTerrestre != 5) {

                cout << endl;
                cout << "TERRESTRES" << endl;
                cout << "1 - Cadastrar" << endl;
                cout << "2 - Consultar" << endl;
                cout << "3 - Buscar" << endl;
                cout << "4 - Remover" << endl;
                cout << "5 - Sair" << endl;
                cout << "Escolha: ";
                cin >> opcaoTerrestre;

                if(opcaoTerrestre == 1) {
                    cadastrar(&terrestres);
                }
                else if(opcaoTerrestre == 2) {
                    imprimir(terrestres);
                }
                else if(opcaoTerrestre == 3) {
                    buscar(terrestres);
                }
                else if(opcaoTerrestre == 4) {
                    remover(&terrestres);
                }
            }
        }

        else if(opcao == 3) {

            int opcaoVoador = 0;

            while(opcaoVoador != 5) {

                cout << endl;
                cout << "VOADORES" << endl;
                cout << "1 - Cadastrar" << endl;
                cout << "2 - Consultar" << endl;
                cout << "3 - Buscar" << endl;
                cout << "4 - Remover" << endl;
                cout << "5 - Sair" << endl;
                cout << "Escolha: ";
                cin >> opcaoVoador;

                if(opcaoVoador == 1) {
                    cadastrar(&voadores);
                }
                else if(opcaoVoador == 2) {
                    imprimir(voadores);
                }
                else if(opcaoVoador == 3) {
                    buscar(voadores);
                }
                else if(opcaoVoador == 4) {
                    remover(&voadores);
                }
            }
        }

        else if(opcao == 4) {

            cout << endl;
            cout << "AQUATICOS" << endl;
            imprimir(aquaticos);

            cout << endl;
            cout << "TERRESTRES" << endl;
            imprimir(terrestres);

            cout << endl;
            cout << "VOADORES" << endl;
            imprimir(voadores);
        }
    }

    return 0;
}