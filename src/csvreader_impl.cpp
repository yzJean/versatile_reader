#include "csvreader_impl.hpp"

#include <fstream>

namespace Map {
namespace Reader {

template <class ReadingDataT>
CsvReader<ReadingDataT>::CsvReader() : reader_type_("csv") {
  reading_data_ptr_ = std::make_unique<std::vector<ReadingDataT>>();
}

template <class ReadingDataT>
CsvReader<ReadingDataT>::CsvReader(const std::string &directory)
    : reader_type_("csv") {
  this->SetDirectory(directory);
  reading_data_ptr_ = std::make_unique<std::vector<ReadingDataT>>();
}

template <class ReadingDataT>
CsvReader<ReadingDataT>::~CsvReader() {}

template <class ReadingDataT>
bool CsvReader<ReadingDataT>::ReadImpl() {
  std::string file_directory = this->GetReadingDirImpl();
  std::cout << "Reading " << reader_type_ << " file: " << file_directory
            << std::endl;
  std::string ext = file_directory.substr(file_directory.find_last_of(".") + 1);
  if (ext != reader_type_) {
    std::cout << "Input path is invalid. It should be " << reader_type_
              << " file." << std::endl;
    return false;
  }

  std::ifstream file(file_directory);
  if (!file.is_open()) {
    std::cout << reader_type_ << " file is not opened." << std::endl;
    return false;
  }

  // start to read
  file.seekg(0, file.beg);
  if (std::string header{}; std::getline(file, header))
    std::cout << header << '\n';

  std::vector<ReadingDataT> csv_reading;
  csv_reading.clear();
  ReadingDataT tmp{};
  std::string frameInfo;  // per row
  while (std::getline(file, frameInfo, '\n')) {
    tmp = frameInfo;
    csv_reading.push_back(std::move(tmp));
  }
  // TODO: limited in the csv formatted in sclar
  // ref:
  // https://stackoverflow.com/questions/63322454/how-to-read-csv-data-to-pointers-of-struct-vector-in-c
  //    while (file >> tmp) {
  //        std::cout << tmp;
  //        csv_reading.push_back(std::move(tmp));
  //     }

  // DEBUG
  // for (auto &&row : csv_reading) std::cout << row;
  SetReadingDataPtrImpl(csv_reading);
  return !this->GetReadingDataPtrImpl()->empty();
}

template <class ReadingDataT>
void CsvReader<ReadingDataT>::SetReadingDataPtrImpl(
    const std::vector<ReadingDataT> &in) {
  *(reading_data_ptr_.get()) = in;
}

template <class ReadingDataT>
void CsvReader<ReadingDataT>::SetDirectoryImpl(const std::string &directory) {
  directory_ = directory;
}

template <class ReadingDataT>
std::vector<ReadingDataT> *CsvReader<ReadingDataT>::GetReadingDataPtrImpl() {
  return reading_data_ptr_.get();
}
template <class ReadingDataT>
std::string CsvReader<ReadingDataT>::GetReadingDirImpl() {
  return directory_;
}
template class CsvReader<RoadData>;
}  // namespace Reader
}  // namespace Map