#include "babyblockchain.hpp"

//Block-----------------------------------------------

Block::Block() {
  ID = -1;
  ID_prev = -1;
  next = nullptr;
  prev = nullptr;
}

Block::Block(std::string s) {
  data = s;
  ID = calcID();
  ID_prev = -1;
  next = nullptr;
  prev = nullptr;
}

int Block::verifyBlock() {
  if (prev->ID != ID_prev) {
    return 1;
  }else if (ID != calcID()) {
    return 2;
  }
  return 0;
}

int Block::calcID() {
  return data.at(0) * data.at(1);
}

std::ostream& operator<<(std::ostream &os, Block &b) {
  os << "ID: "<<std::to_string(b.ID)<<" Data: "<<b.data;
  return os;
}


//Blockchain-------------------------------------------
Blockchain::Blockchain(){
  chain = nullptr;
  last  = nullptr;
  count = 0;
}

Blockchain::~Blockchain(){
    while(!empty())
      pop();
}

unsigned Blockchain::size(){
  return count;
}

bool Blockchain::empty(){
  return (chain == nullptr) && (last == nullptr);
}

void Blockchain::clear(){

}

void Blockchain::push(std::string new_data) {
  Block *b = new Block;
  if(b->ID_prev != b->)
}

std::string Blockchain::pop(){
    Block *b = chain;
    chain = chain->next;
    delete b;
    if(count == 1)
      last = nullptr;
    count--;
}

std::string Blockchain::peek(){

}

void Blockchain::peek_all(){

}

void Blockchain::verify(){

}

//***HACKS*********************************************
void Blockchain::hack_changeData(std::string new_data, unsigned pos) {
  unsigned n = 0;
  Block *temp = chain;
  while(n < pos){
    if(temp != nullptr){
      temp = temp->next;
	n++;
      }else
      break;
  }
  if(n == pos){
    temp->data = new_data;
  }else
    std::cout << pos << "is beyond bounds.\n";
}

void Blockchain::hack_insertBlock(std::string new_data, unsigned pos) {
  unsigned n = 0;
  Block *temp = chain;
  while(n < pos){
    if(temp != nullptr){
      temp = temp->next;
      n++;
    }else
      break;
  }
  if(n == pos){
    Block *newb = new Block(new_data);
    Block *nx = temp->next;
    temp->next = newb;
    newb->prev = temp;
    if(nx != nullptr){
      nx->prev = newb;
    }
    newb->next = nx;
  }else
    std::cout << pos << "is beyond bounds.\n";
}
