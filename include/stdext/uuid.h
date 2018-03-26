#ifndef __STDEXT_UUID__
#define __STDEXT_UUID__

#include <string>
#include <iostream>

namespace stdext
{

  class uuid
  {
    friend std::istream &operator >> (std::istream &is, uuid &id);
    unsigned char _data[16];
	
  public:
    uuid();
    uuid(const uuid &);

    std::string str() const;

    bool operator == (const uuid &id) const;
    bool operator != (const uuid &id) const;
    bool operator < (const uuid &id) const;
    bool operator > (const uuid &id) const;
  };

  std::ostream &operator << (std::ostream &os, const uuid &id);
  std::istream &operator >> (std::istream &is, uuid &id);

} // stdext

#endif // __STDEXT_UUID__
