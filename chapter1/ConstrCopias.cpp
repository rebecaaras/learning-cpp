#include <iostream>
#include <cstring>

struct Node {
    char *nome;
    int idade;
    Node (char *n = "", int a = 0){
        nome = new char[strlen(n) + 1];
        strcpy(nome, n);
        idade = a;
    }
    
    Node(const Node& n){//construtor de cópias
        nome = new char[strlen(n.nome)+1];
        strcpy(nome, n.nome);
        idade = n.idade;
    }
    
	//Sobrescreve operação de atribuição
    Node& operator=(const Node& n){
        if (this != &n){//sem atribuição para si próprio;
            if (nome != 0)
            delete [] nome;
            nome = new char[strlen(n.nome) + 1];
            strcpy(nome, n.nome);
            idade = n.idade;        
        }
        return *this;
    };
};

int main(){
	Node node1("Roger", 20);
	Node node2(node1);
	strcpy(node2.nome, "Wendy");
	node2.idade = 30;
	
	//node2 = node1; // a operação de atribuição precisa ser sobrescrita pelo usuário senão gera um resultado inesperado
	
	std::cout<< "Node 1: "<< node1.nome << ", "<<node1.idade << std::endl;
	std::cout<< "Node 2: "<< node2.nome << ", "<<node2.idade << std::endl;
	
	return 0;
}