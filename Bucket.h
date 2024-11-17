template <typename T, typename U> 
struct Bucket {
  T key;
  U data;
  bool full = false;
  Bucket() : key(), data(), full(false) {}
  Bucket(T key, U data) : key(key), data(data), full(true) {}
  Bucket(T key) : key(key), full(true) {}
  Bucket(U data) : data(data), full(true) {}
};