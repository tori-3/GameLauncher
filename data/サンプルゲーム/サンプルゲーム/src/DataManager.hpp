#pragma once

//ƒVƒ“ƒOƒ‹ƒgƒ“
class DataManager {
private:
    DataManager() = default;
    ~DataManager() = default;

public:
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;
    DataManager(DataManager&&) = delete;
    DataManager& operator=(DataManager&&) = delete;

    static DataManager& getInstance()
    {
        static DataManager instance;
        return instance;
    };

    int score = 0;
};