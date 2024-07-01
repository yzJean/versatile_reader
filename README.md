# Versatile File Reader
Mainly for csv file at this moment.

## Build
```
$ cd /csv_reader
$ mkdir build && cd build
$ cmake -DCsvReaderTestOn=ON ..
$ make -j32
```

## Run
```
$ cd /csv_reader/build
$ ./csvreader_test
```

## Results
```
====== Csv Reader Test Suit: Start ======
Reading csv file: ../test/test_file.csv
lane_count,start_longitude,start_latitude,end_longitude,end_latitude
[Passed] 
  Expect: 1 is equal to Actual: 1
Reading size: 71
Reading size: 71
====== Csv Reader Test Suit: End ======
```
