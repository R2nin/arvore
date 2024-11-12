#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Estrutura para representar um nó na árvore binária
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Classe para representar a árvore binária
class BinaryTree {
private:
    Node* root;

    // Método privado para inserir um novo valor na árvore
    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    // Método privado para exibir a árvore em um formato visualmente agradável
    void printTree(Node* root, string prefix = "", bool isLeft = true) {
        if (root == nullptr) return;

        cout << prefix;
        cout << (isLeft ? "|--" : "\\--" );
        cout << root->data << endl;

        printTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
        printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
    }

    // Método privado para procurar um valor na árvore
    bool searchNode(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    // Método privado para armazenar os valores da árvore em ordem em um vetor
    void storeInorder(Node* node, vector<int>& arr) {
        if (node == nullptr) return;

        storeInorder(node->left, arr);
        arr.push_back(node->data);
        storeInorder(node->right, arr);
    }

    // Método privado para balancear a árvore
    Node* arrayToBST(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        Node* node = new Node(arr[mid]);

        node->left = arrayToBST(arr, start, mid - 1);
        node->right = arrayToBST(arr, mid + 1, end);

        return node;
    }

public:
    // Construtor da classe
    BinaryTree() {
        root = nullptr;
    }

    // Método público para inserir um novo valor na árvore
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Método público para exibir a árvore
    void display() {
        cout << "\nArvore Binaria:\n";
        printTree(root, "", false);
    }

    // Método público para procurar um valor na árvore
    bool search(int value) {
        return searchNode(root, value);
    }

    // Método público para balancear a árvore
    void balance() {
        vector<int> arr;
        storeInorder(root, arr);
        root = arrayToBST(arr, 0, arr.size() - 1);
    }
};

// Função principal
int main() {
    BinaryTree tree;
    string input;

    cout << "Digite numeros para inserir na arvore (digite 'nao' para parar):\n";

    // Loop para inserir valores na árvore
    while (true) {
        cout << "Numero: ";
        cin >> input;

        if (input == "nao") break;

        try {
            int num = stoi(input);
            tree.insert(num);
        } catch (...) {
            cout << "Entrada invalida. Digite um numero ou 'nao'.\n";
        }
    }

    tree.display();

    int choice;
    // Loop para interagir com a árvore
    do {
        cout << "\nEscolha uma opcao:\n";
        cout << "1. Procurar valor\n";
        cout << "2. Inserir novo valor\n";
        cout << "3. Balancear arvore\n";
        cout << "4. Mostrar arvore\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int value;
                cout << "Digite o valor a procurar: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Valor encontrado na arvore!\n";
                else
                    cout << "Valor nao encontrado na arvore.\n";
                break;
            }
            case 2: {
                int value;
                cout << "Digite o valor a inserir: ";
                cin >> value;
                tree.insert(value);
                cout << "Valor inserido com sucesso!\n";
                tree.display();
                break;
            }
            case 3: {
                tree.balance();
                cout << "Arvore balanceada!\n";
                tree.display();
                break;
            }
            case 4: {
                tree.display();
                break;
            }
            case 0:
                cout << "Programa finalizado!\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (choice != 0);

    return 0;
}
