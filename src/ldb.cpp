#include <iostream>
#include "leveldb/db.h"

using namespace std;

int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;

    leveldb::Status status = leveldb::DB::Open(options, "C:/Qt/Projects/temp/testdb", &db);

    if (false == status.ok())
    {
        cerr << "Unable to open/create test database 'C:/Qt/Projects/temp/testdb'" << endl;
        cerr << status.ToString() << endl;
        return -1;
    }
    cout << "OK" << endl;
    return 0;
}
