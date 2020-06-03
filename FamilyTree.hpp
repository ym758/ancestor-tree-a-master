#pragma once
#include <string>
#include <iostream>
using namespace std;//
namespace family{
class Tree{

public:
struct Node* root;//
    Tree();
    ~Tree();
    Tree(std::string root);
    Tree& T(std::string child);
    Tree& addFather(std::string child,std::string father);
    Tree& addMother(std::string child,std::string mother);
    std::string relation(std::string name);
    std::string find(std::string relation);
    //void remove(std::string a);
    void display();
    void remove(std::string name);
private:
void addFat (Node* t, std::string child, std::string father, int count);
void addMot (Node* t, std::string child, std::string mother, int count);
void disp(Node* t, int n);
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

