template <typename T, typename U> 
struct Bucket {
  T key;
  U data;
  T deletedKey;
  bool full = false;
  Bucket() : key(), data(), full(false), deletedKey() {}
  Bucket(T key, U data) : key(key), data(data), full(true), deletedKey() {}
  Bucket(T key) : key(key), full(true), deletedKey() {}
  Bucket(U data) : data(data), full(true), deletedKey() {}
};