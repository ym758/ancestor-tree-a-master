#include "FamilyTree.hpp"
#include <iostream>
#include <string>
using namespace std;//
using namespace family;

Node::Node(){

}
Node::Node (std::string _name){
name=_name;
child=NULL;
Father=NULL;
Mother=NULL;
}
 Tree::Tree(){
     Node* temp= new Node();
     root=temp;
 }
Tree::~Tree(){
delete (root);
}
Tree::Tree (std::string n){
    Node* temp= new Node(n);
    root=temp;
    root->relation="I";
}
Tree& Tree::T(std::string root){
    return *this;
} 
 void addFat (Node* t, std::string child, std::string father, int count){
 }
 void addMot (Node* t, std::string child, std::string mother, int count){
 }


     Tree& Tree::addFather(std::string child,std::string father){
         //
         //
         Node*temp=root;
         //addFat (temp,child,father,1);
         Tree& t= *this;
         return t;
     }

     Tree& Tree::addMother(std::string child,std::string mother){
         //
         //
         Node*temp=root;
         //addMot (temp,child,mother,1);
         Tree& t= *this;
         return t;
     }
     std::string Tree::locationRelation(Node* t,std::string name){
         return name;
    }
std::string Tree::relation(std::string name){
    return name;
}
std::string Tree::locatinName(Node* t,std::string relation){
return relation;
}
std::string Tree::find(std::string relation){
    return relation;
}
void Tree::disp(Node* root, int n){

}

void Tree::display(){

}
void Tree::freeAll(Node* t){

}
void Tree::remove(std::string a){

}
void Tree::remove(Node* t,std::string name){

}

