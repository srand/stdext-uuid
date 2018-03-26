#include <stdext/uuid.h>
#include <random>
#include <cstring>
#include <mutex>

namespace stdext {

uuid::uuid(const uuid &id) {
  std::memcpy(_data, id._data, 16);
}

uuid::uuid() {
  static std::mutex m;
  static std::default_random_engine r(
    std::chrono::system_clock::now().time_since_epoch().count());

  std::unique_lock<std::mutex> lock(m);
  for (unsigned char &byte : _data) {
    byte = (char)r();
  }
  _data[12] = 4;
}

std::string uuid::str() const {
  char tmp[37];

  std::snprintf(tmp, sizeof(tmp), 
		"%2.2x%2.2x%2.2x%2.2x-%2.2x%2.2x-%2.2x%2.2x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x",
		_data[0],  _data[1],  _data[2],  _data[3],  
		_data[4],  _data[5],  _data[6],  _data[7],
		_data[8],  _data[9],  _data[10], _data[11], 
		_data[12], _data[13], _data[14], _data[15]);

  return tmp;
}

bool uuid::operator == (const uuid &id) const {
  return std::memcmp(_data, id._data, 16) == 0;
}

bool uuid::operator != (const uuid &id) const {
  return std::memcmp(_data, id._data, 16) != 0;
}

bool uuid::operator < (const uuid &id) const {
  return std::memcmp(_data, id._data, 16) < 0;
}

bool uuid::operator > (const uuid &id) const {
  return std::memcmp(_data, id._data, 16) > 0;
}

std::ostream &operator << (std::ostream &os, const uuid &id) {
  return os << id.str();
}

std::istream &operator >> (std::istream &is, uuid &id) {
  std::string str;
  if (is >> str) {
    unsigned int data[16];
    int n = std::sscanf(str.c_str(),
			"%2x%2x%2x%2x-%2x%2x-%2x%2x-%2x%2x-%2x%2x%2x%2x%2x%2x",
			&data[0],  &data[1],  &data[2],  &data[3],  
			&data[4],  &data[5],  &data[6],  &data[7],
			&data[8],  &data[9],  &data[10], &data[11],
			&data[12], &data[13], &data[14], &data[15]);
    if (n != 16) {
      is.setstate(is.failbit);
    } else {
      for (unsigned int i=0; i<16; i++)
	id._data[i] = (unsigned char)data[i];
    }
  }
  return is;
}

} // stdext
