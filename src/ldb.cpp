#include <iostream>
#include <sstream>
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

    // Add 256 values to the database
    leveldb::WriteOptions writeOptions;
    for (unsigned int i = 0; i < 256; ++i)
    {
        stringstream keyStream;
        keyStream << "Key" << i;

        stringstream valueStream;
        valueStream << "Test data value: " << i;

        db->Put(writeOptions, keyStream.str(), valueStream.str());
    }

    // Iterate over each item in the database and print them
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());

    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        cout << it->key().ToString() << " : " << it->value().ToString() << endl;
    }

    if (false == it->status().ok())
    {
        cerr << "An error was found during the scan" << endl;
        cerr << it->status().ToString() << endl;
    }

    delete it;

    // Close the database
    delete db;

    return 0;
}
