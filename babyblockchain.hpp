#ifndef _BABYBLOCKCHAIN_HPP
#define _BABYBLOCKCHAIN_HPP

#include <string>
#include <iostream>
#include <exception>

class Block {
public:
  std::string data;
  Block *prev;
  Block *next;
  int ID;
  int ID_prev;
  
  Block(); //Default constructor
  Block(std::string s);
  
  int verifyBlock();
  int calcID();
  
  friend std::ostream& operator<<(std::ostream &os, Block &b);
};


class Blockchain {
private:
  Block *chain; //pointer to the beginning of the chain
  Block *last; //pointer to last element of the chain
  unsigned count; //number of blocks

  /*Make it ilegal to copy queues by defining an empty 
    copy constructor*/
  Blockchain(const Blockchain &value) {
    chain = value.chain;
    last  = value.last;
    count = value.count;
  }

  Blockchain& operator=(const Blockchain &rhs) { return *this; }

public:
  /*
   * Constructor: blockchain
   * Usage: blockchain<ValueType> blockchain;
   * ------------------------------
   * Initializes a new empty blockchain.
   */
  Blockchain();

  /*
   * Destructor: ~blockchain
   * Usage: (usually implicit)
   * -------------------------
   * Frees any heap storage associated with this blockchain.
   */
  ~Blockchain();

  /*
   * Method: size
   * Usage: int n = blockchain.size();
   * ----------------------------
   * Returns the number of values in this blockchain.
   */
  unsigned size();

  /*
   * Method: empty
   * Usage: if (blockchain.isEmpty()) . . .
   * ---------------------------------
   * Returns true if this blockchain contains no elements.
   */
  bool empty();

  /*
   * Method: clear
   * Usage: blockchain.clear();
   * ---------------------
   * Removes all elements from this blockchain.
   */
  void clear();

  /*
   * Method: push
   * Usage: blockchain.push(value);
   * -------------------------
   * Pushes a block with the specified value onto this blockchain.
   */
  void push(std::string new_data);

  /*
   * Method: pop
   * Usage: ValueType top = blockchain.pop();
   * ------------------------------------
   * Removes the top block from this blockchain and returns the data
   * stored there. This method signals an error if called on an empty blockchain.
   */
  std::string pop();

  /*
   * Method: peek
   * Usage: ValueType top = blockchain.peek();
   * ------------------------------------
   * Returns the value of top element from this blockchain, without removing
   * it. This method signals an error if called on an empty blockchain.
   */
  std::string peek();

  /*
   * Method: peek_all
   * Usage:  blockchain.peek_all();
   * ------------------------------------
   * Prints all the values from this blockchain, without removing
   * it. This method signals an error if called on an empty blockchain.
   */
  void peek_all();

  /*
   * Method: verify
   * Usage: ValueType top = blockchain.peek_all();
x   * ------------------------------------
   * Returns the value of top element from this blockchain, without removing
   * it. This method signals an error if called on an empty blockchain.
   */
  void verify();


  //HACKS--------------------------------------------------
  void hack_changeData(std::string new_data, unsigned pos);

  void hack_insertBlock(std::string new_data, unsigned pos);
  
};

#endif
