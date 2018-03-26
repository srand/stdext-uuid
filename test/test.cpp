#include <stdext/uuid.h>
#include <iostream>
#include <sstream>
#include <cassert>


int main()
{
  std::stringstream os;
  stdext::uuid od, id;
  
  os << od << std::endl;
  assert(os >> id);
  os << "8b8af70b--dc0c-7ea0-1977042003cd";
  assert(!(os >> id));
  assert(id == od);

  std::cout << od << std::endl;
  std::cout << id << std::endl;
  std::cout << (id == od) << std::endl;
  std::cout << (id != od) << std::endl;
  std::cout << (id < stdext::uuid()) << std::endl;
  std::cout << (id > stdext::uuid()) << std::endl;
  std::cout << stdext::uuid(id) << std::endl;
  
  return EXIT_SUCCESS;  
}
