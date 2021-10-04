#include "babyblockchain.cpp"

int main() {
  Blockchain chain;
  int nblocks = 4;
  std::string temp;

  //Insertar 4 bloques en la cadena
  for (int i = 0; i < nblocks; i++) {
    do{
      std::cout << "Escriba el dato del bloque " << i << ": ";
      std::getline(std::cin, temp);
      chain.push(temp);
      //chain.pop();
    } while(int(temp.size()) < nblocks-1);
  }

  //Mostrar todos los elementos de la cadena
  std::cout << "\n";
  std::cout << "Los elementos de la cadena son: \n";
  chain.peek_all();
  
  //Verificar el estado de la cadena
  std::cout << "\n";
  std::cout << "Verificando la cadena...\n";
  chain.verify();

  
  //Se altera el dato del penultimo nodo de la cadena**************************************
  chain.hack_changeData("This is an attack!", 2);
  
  // Se muestran todos los datos de la cadena
  std::cout << "\n";
  std::cout << "Los elementos de la cadena son: \n";
  chain.peek_all();

  //Se verifica la integridad de la cadena, y se debe identificar un problema
  std::cout << "\n";
  std::cout << "Verificando la cadena...\n";
  chain.verify();

  //Se inserta un bloque en la cadena*****************************************************
  chain.hack_insertBlock("This is an attack!", 2);
  
  // Se muestran todos los datos de la cadena
  std::cout << "\n";
  std::cout << "Los elementos de la cadena son: \n";
  chain.peek_all();

  //Se verifica la integridad de la cadena, y se debe identificar un problema
  std::cout << "\n";
  std::cout << "Verificando la cadena...\n";
  chain.verify();

  
  return 0;
}
