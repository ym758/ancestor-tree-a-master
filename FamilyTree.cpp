#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#define COUNT 10

using namespace family;

Node::Node(){//***//
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
 void Tree::addFat (Node* t, std::string child, std::string father, int count){
     if(t->name==child){
     if (t->Father)  throw  std::invalid_argument("have father");
     Node* temp = new Node (father);
     t->Father=temp;
     if (count==1) t->Father->relation="father";
     else if (count==2) t->Father->relation="grandfather";
     else {
         for(int i=0; i<count-2; i++){
         t->Father->relation+="great-";
     }
t->Father->relation+="grandfather";
     }
 }
 count++;//****//
 if (t->Father!=NULL) addFat(t->Father,child,father,count);///****///
 if (t->Mother!=NULL) addFat(t->Mother,child,father,count);///***///

 } 
 void Tree::addMot (Node* t, std::string child, std::string mother, int count){
if (t->name==child){
if (t->Mother)  throw  std::invalid_argument("have mother");
Node* temp = new Node(mother);
t->Mother=temp;
if (count==1) t->Mother->relation="mother";
else if (count==2) t->Mother->relation="grandmother";
else{
     for(int i=0; i<=count-2; i++){
    t->Mother->relation+="great-";
            }
t->Mother->relation+="grandmother";
}

}
count++;///***//
if(t->Father!=NULL) addMot(t->Father,child,mother,count);////***///
if(t->Mother!=NULL) addMot(t->Mother,child,mother,count);////***///
 }


     Tree& Tree::addFather(std::string child,std::string father){
         //
         if (relation(child)=="unrelated") throw  std::invalid_argument("unrelated");

         Node*temp=root;
         addFat (temp,child,father,1);
         Tree& t= *this;
         return t;
     }

     Tree& Tree::addMother(std::string child,std::string mother){
         //
         if (relation(child)=="unrelated") throw  std::invalid_argument("unrelated");
         Node*temp=root;
         addMot (temp,child,mother,1);
         Tree& t= *this;
         return t;
     }
     std::string Tree::locationRelation(Node* t,std::string name){
         if (t->name==name) return t->relation;
         else if (t->Father==NULL && t->Mother!=NULL) return locationRelation (t->Mother,name);
         else if (t->Father!=NULL && t->Mother==NULL) return locationRelation (t->Father,name);
         else if (t->Father!=NULL && t->Mother!=NULL) return locationRelation (t->Father,name) + locationRelation (t->Mother,name);
         return "";
    }
std::string Tree::relation(std::string name){
    std::string ans="";
    if (root->name==name) return root->relation;
    else {if (root->Father==NULL && root->Mother!=NULL) ans+=locationRelation (root->Mother,name);
    else  if (root->Father!=NULL && root->Mother==NULL) ans+=locationRelation (root->Father,name);
    else  if (root->Father!=NULL && root->Mother!=NULL) ans+=locationRelation (root->Father,name) + locationRelation (root->Mother,name);
    }
    if (ans=="") return "unrelated";
    return ans;    
}

std::string Tree::locatinName(Node* t,std::string relation){
    if (t->relation==relation) return t->name;

        if (t->Father==NULL && t->Mother!=NULL) return locatinName(t->Mother, relation);
        else if (t->Father!=NULL && t->Mother==NULL) return locatinName (t->Father,relation);
        else if (t->Father!=NULL && t->Mother!=NULL) {
            if(locatinName(t->Father,relation)!="") return locatinName (t->Father,relation);
            if(locatinName(t->Mother,relation)!="") return locatinName (t->Mother,relation);
    } 
return "";
}

std::string Tree::find(std::string relation){
    std::string ans="";
    if (root->relation==relation) return root->name;
    else {
      if (root->Father!=NULL) ans=locatinName(root->Father,relation);
     if (root->Mother!=NULL && ans=="") ans=locatinName(root->Mother,relation); 
    }
    if (ans=="") {
  throw  std::invalid_argument("eror");
    }
    
    return ans;    

}
void Tree::disp(Node* root, int n){
if (root==NULL) return;
n+=COUNT;
disp (root->Mother,n);
std::cout<<std::endl;
for(int i=COUNT;i<n;i++) 
{std::cout<<" ";}
std::cout<<root->name<<"\n";
disp(root->Father,n);
}

void Tree::display(){
    disp(root,0);

}
void Tree::freeALL(Node* t){
if (t->Father){
    freeALL(t->Father);
}
if(t->Mother){
    freeALL(t->Mother);
}
if (!t->Father && !t->Mother) delete (t);
}
void Tree::remove1(Node* t,std::string name){
if (t->Father){
    if (t->Father->name==name){
        freeALL(t->Father);
        t->Father=NULL;
    }
    else remove1 (t->Father,name);
}
if (t->Mother){
    if (t->Mother->name==name){
        freeALL (t->Mother);
        t->Mother=NULL;
    }
    else remove1 (t->Mother, name);
    }

}

void Tree::remove(std::string a){
if (relation(a)=="unrelated") throw invalid_argument ("eror");
if (root->name==a) throw invalid_argument ("eror");
if (root->Father){
if (root->Father->name==a){
    freeALL(root->Father);
    root->Father=NULL;
}
else remove1(root->Father, a);
}
if (root->Mother){
    if (root->Mother->name==a){
        freeALL (root->Mother);
        root->Mother=NULL;
    }
    else remove1(root->Mother,a);
}


}

