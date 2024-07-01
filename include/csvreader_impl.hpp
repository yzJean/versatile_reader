#ifndef CSVREADER_IMPL_HPP_
#define CSVREADER_IMPL_HPP_
#include <memory>
#include <vector>

#include "map_components.hpp"
#include "reader_interface.hpp"

using namespace Map::Components;
namespace Map {
namespace Reader {

template <class ReadingDataT>
class CsvReader : public StaticIReader<CsvReader<ReadingDataT>, ReadingDataT> {
 public:
  CsvReader();
  CsvReader(const std::string &directory);
  ~CsvReader();
  bool ReadImpl();
  void SetReadingDataPtrImpl(const std::vector<ReadingDataT> &in);
  void SetDirectoryImpl(const std::string &directory);
  std::vector<ReadingDataT> *GetReadingDataPtrImpl();
  std::string GetReadingDirImpl();

 private:
  std::string reader_type_ = "csv";
  std::string directory_;
  ReadingDataPtr<ReadingDataT> reading_data_ptr_;
};

// Explicit instantiation types
extern template class CsvReader<RoadData>;

}  // namespace Reader
}  // namespace Map

#endif  // end of CSVREADER_IMPL_HPP_