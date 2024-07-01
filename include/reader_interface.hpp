#ifndef READER_INTERFACE_HPP_
#define READER_INTERFACE_HPP_
#include <memory>
#include <string>
#include <vector>

namespace Map {
namespace Reader {

template <class ReadingDataT>
using ReadingDataPtr = std::unique_ptr<std::vector<ReadingDataT>>;

template <class ReadingDataT>
class IReader;
template <class ReadingDataT>
using ReaderPtr = std::unique_ptr<IReader<ReadingDataT>>;

template <class ReadingDataT>
class IReader {
 public:
  IReader(){};
  IReader(const std::string &directory){};
  virtual ~IReader(){};

  virtual bool Read() = 0;

  virtual void SetReadingDataPtr(const std::vector<ReadingDataT> &in) = 0;

  virtual void SetDirectory(const std::string &directory) = 0;

  virtual std::vector<ReadingDataT> *GetReadingDataPtr() = 0;

  virtual std::string GetReadingDir() = 0;
};

template <class Derived, class ReadingDataT>
class StaticIReader : public IReader<ReadingDataT> {
 public:
  StaticIReader(){};

  StaticIReader(const std::string &directory) {
    this->SetDirectory(directory);
  };
  virtual ~StaticIReader(){};

  bool Read() override { return static_cast<Derived *>(this)->ReadImpl(); };

  void SetReadingDataPtr(const std::vector<ReadingDataT> &in) override {
    static_cast<Derived *>(this)->SetReadingDataPtrImpl(in);
  };

  void SetDirectory(const std::string &directory) override {
    return static_cast<Derived *>(this)->SetDirectoryImpl(directory);
  };

  std::vector<ReadingDataT> *GetReadingDataPtr() override {
    return static_cast<Derived *>(this)->GetReadingDataPtrImpl();
  };

  std::string GetReadingDir() override {
    return static_cast<Derived *>(this)->GetReadingDirImpl();
  };
};

}  // namespace Reader
}  // namespace Map

#endif  // end of READER_INTERFACE_HPP_