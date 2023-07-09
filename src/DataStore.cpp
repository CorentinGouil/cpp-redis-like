//
// Created by gouil on 09/07/2023.
//

#include "DataStore.h"

#include <utility>

DataStore::DataStore() = default;

DataStore &DataStore::GetInstance() {
    static DataStore inst;
    return inst;
}

bool DataStore::setValue(const std::string &key, std::string value) {
    data[key] = std::move(value);
    return true;
}
