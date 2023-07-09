//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_DATASTORE_H
#define CPP_REDIS_LIKE_DATASTORE_H


#include <string>
#include <map>

class DataStore {
private:
    DataStore();

    std::map<std::string, std::string> data;

public:
    static DataStore &GetInstance();

    DataStore(DataStore &other) = delete;

    void operator=(const DataStore &) = delete;

    bool setValue(const std::string &key, std::string value);

    std::string getValue(const std::string &key);
};


#endif //CPP_REDIS_LIKE_DATASTORE_H
