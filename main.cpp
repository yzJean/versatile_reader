#include "csvreader_impl.hpp"

using namespace Map;
using namespace Map::Reader;
using namespace Map::Components;

template <typename T>
bool ExpectTo(T expect, T actual) {
  if (expect != actual) {
    std::cout << "[Failed] \n  Expect: " << expect
              << " is not equal to Actual: " << actual << std::endl;
  } else {
    std::cout << "[Passed] \n  Expect: " << expect
              << " is equal to Actual: " << actual << std::endl;
  }
  return expect == actual;
}

int main() {
  std::string map_dir = "../test/test_file.csv";
  {
    std::cout << "\n====== Csv Reader Test Suit: Start ======" << std::endl;
    ReaderPtr<RoadData> reader_ptr =
        std::make_unique<CsvReader<RoadData>>(map_dir);
    bool b_is_read_succeeded = reader_ptr->Read();
    ExpectTo(true, b_is_read_succeeded);
    if (b_is_read_succeeded) {
      std::cout << "Reading size: " << reader_ptr->GetReadingDataPtr()->size()
                << std::endl;
    }
    std::cout << "====== Csv Reader Test Suit: End ======" << std::endl;
  }  // end of Csv Reader Test Suit
  return 0;
}