# g++ -g -IC:/Qt/Tools/leveldb/include ldb.cpp -LC:/Qt/Tools/leveldb/lib -lleveldb  -o test
cmake_minimum_required(VERSION 2.6)
project(test)
include_directories("C:/Qt/Tools/leveldb/include")
link_directories("C:/Qt/Tools/leveldb/lib")
add_executable(${PROJECT_NAME} "src/ldb.cpp")
target_link_libraries(${PROJECT_NAME} leveldb)
