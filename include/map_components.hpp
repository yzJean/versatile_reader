#ifndef MAP_COMPONENTS_HPP_
#define MAP_COMPONENTS_HPP_
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

namespace Map {
namespace Components {

struct RoadData {
  uint16_t lane_count = 0u;
  double start_longitude = 0.0f;
  double start_latitude = 0.0f;
  double end_longitude = 0.0f;
  double end_latitude = 0.0f;
  size_t road_index = 0;

  // TODO: limited in the csv formatted in sclar
  // ref:
  // https://stackoverflow.com/questions/63322454/how-to-read-csv-data-to-pointers-of-struct-vector-in-c
  friend std::istream &operator>>(std::istream &is, RoadData &road_data) {
    char comma;
    return is >> road_data.lane_count >> comma >> road_data.start_longitude >>
           comma >> road_data.start_latitude >> comma >>
           road_data.end_longitude >> comma >> road_data.end_latitude;
  }

  // TODO: refactor
  RoadData operator=(const std::string &in) {
    std::stringstream linestream(in);
    std::string cell;
    std::vector<std::string> row;
    row.clear();
    while (std::getline(linestream, cell, ',')) {
      row.push_back(cell);
    }
    this->lane_count = row[0] != "None" ? std::stoul(row[0]) : 0u;
    this->start_longitude = std::stod(row[1]);
    this->start_latitude = std::stod(row[2]);
    this->end_longitude = std::stod(row[3]);
    this->end_latitude = std::stod(row[4]);
    this->road_index = 0;
    return *this;
  }

  RoadData() {
    lane_count = 0u;
    start_longitude = 0.0f;
    start_latitude = 0.0f;
    end_longitude = 0.0f;
    end_latitude = 0.0f;
    road_index = 0;
  }
  RoadData(const RoadData &in_road_data) {
    this->lane_count = in_road_data.lane_count;
    this->start_longitude = in_road_data.start_longitude;
    this->start_latitude = in_road_data.start_latitude;
    this->end_longitude = in_road_data.end_longitude;
    this->end_latitude = in_road_data.end_latitude;
    this->road_index = in_road_data.road_index;
  }

  RoadData operator=(const RoadData &in_road_data) {
    this->lane_count = in_road_data.lane_count;
    this->start_longitude = in_road_data.start_longitude;
    this->start_latitude = in_road_data.start_latitude;
    this->end_longitude = in_road_data.end_longitude;
    this->end_latitude = in_road_data.end_latitude;
    this->road_index = in_road_data.road_index;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const RoadData &road_data) {
    return os << road_data.road_index << "," << road_data.lane_count << ","
              << road_data.start_longitude << "," << road_data.start_latitude
              << "," << road_data.end_longitude << ","
              << road_data.end_latitude;
    //  << std::endl;
  }
};
}  // namespace Components
}  // namespace Map

#endif  // MAP_COMPONENTS_HPP_