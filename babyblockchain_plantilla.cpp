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
  } else if (ID != calcID()) {
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

Blockchain::Blockchain(const Blockchain &value) {
  chain = value.chain;
  last  = value.last;
  count = value.count;
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
  if (empty())
    throw std::runtime_error("[WARN] :: Empty Blockchain");
  int size_b = count;
  for (int i = 0; i < size_b; i++) {
    Block *temp = last;
    last = last->prev;
    count--;
    delete temp;
  }
}

void Blockchain::push(std::string new_data) {
  if (new_data.empty() || new_data.size() < 2)
    throw std::runtime_error("[ERROR] :: push: can't push data empty or min two character");
  Block *b = new Block(new_data);
  if (count == 0) {
    chain = b;
    last  = b;
    b->prev = b;
    count++;
  } else {
      b->prev = last;
      last->next = nullptr;
      if(last->next == nullptr) {
        last->next = b;
      }
      b->ID_prev = last->calcID();
      last = b;
      count++;
      if (b->verifyBlock())
        throw std::runtime_error("[ERROR] :: Invalid Id prev not match!");
  }
}

/*
* Method: pop
* Usage: ValueType top = blockchain.pop();
* ------------------------------------
* Removes the top block from this blockchain and returns the data
* stored there. This method signals an error if called on an empty blockchain.
*/
std::string Blockchain::pop(){
    Block *temp = chain;
    delete chain;
    chain = temp->next;
    if(count == 1) last = nullptr;
    count--;
    return " \nData: ", temp->data, "\n";
}

std::string Blockchain::peek(){
  if (empty())
    throw std::runtime_error("[WARN] :: Empty Blockchain");
  return "\nID: "+ last->ID, "\nID_Prev: ", last->ID_prev, " \nData: ", last->data;
}

void Blockchain::peek_all(){
  if (empty())
    throw std::runtime_error("[WARN] :: Empty Blockchain");
  Block *temp = last;
  Block *temp_prev;
  for (unsigned i = 0; i < count; i++) {
    std::cout << "\nBloque [" << count-i << "]:" << "\nID: " << temp->ID
      << "\nID_Prev: " << temp->ID_prev << " \nData: " << temp->data
      << "\nNext_Block: " << temp->next << "\nPrev_Block: " << temp->prev << std::endl;
    temp_prev = temp->prev;
    temp = temp_prev;
  }
}

void Blockchain::verify(){
  if (empty())
    throw std::runtime_error("[WARN] :: Empty Blockchain");
  Block *temp = last;
  Block *temp_prev;
  int cnt = 0;
  for (unsigned i = 1; i < count; i++) {
    temp_prev = temp->prev;
    int new_prev_Id = temp_prev->calcID();
    if (new_prev_Id != temp->ID_prev) {
      count ++;
      std::cout << "[INFO] :: BlockChain position [" << count-i << "] with error" << std::endl;
    }
    temp = temp_prev;
  }
  if(count == 0)
      std::cout << "[INFO] :: BlockChain data is Okay!" << std::endl;
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
