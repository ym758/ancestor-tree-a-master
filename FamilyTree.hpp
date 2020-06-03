#pragma once
#include <string>
#include <iostream>
namespace family{
class Tree{

public:
struct Node* root;
    Node* T;
    Tree();
    ~Tree();
    Tree(std::string a);
    Tree& t(std::string a);
    Tree& addFather(std::string child,std::string father);
    Tree& addMother(std::string child,std::string mother);
    std::string relation(std::string name);
    std::string find(std::string nameorrelation);
    void remove(std::string a);
    void display();
    void remove(std::string name);
private:
void addFather (Node* t, std::string child, std::string father, int count);
void addMother (Node* t, std::string child, std::string mother, int count);
std::string locatinName(Node* t,std::string relation);
        std::string locationRelation(Node* t,std::string name);
   void remove(Node* t,std::string name);
        void freeAll(Node* t);
};


struct Node { 
    public:
    std::string name;
    struct Node* child;
    struct Node* Father;
    struct Node* Mother;
    std::string relation;
    public:
    Node (std::string name);
    Node();

};
}

