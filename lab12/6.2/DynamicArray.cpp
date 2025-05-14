#include "DynamicArray.h"

void DynamicArray::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    SpaceEntity** newData = new SpaceEntity*[capacity];
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i]->clone();
    }
    delete[] data;
    data = newData;
}

DynamicArray::DynamicArray(const DynamicArray& other) : 
    data(new SpaceEntity*[other.capacity]), 
    size(other.size), 
    capacity(other.capacity) 
{
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]->clone();
    }
}

DynamicArray::DynamicArray(DynamicArray&& other) : 
    data(other.data), 
    size(other.size), 
    capacity(other.capacity) 
{
    other.data = nullptr;
    other.size = other.capacity = 0;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }
        if (capacity < other.size) {
            delete[] data;
            capacity = other.size;
            data = new SpaceEntity*[capacity];
        }
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]->clone();
        }
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
    if (this != &other) {
        clear();
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = other.capacity = 0;
    }
    return *this;
}

DynamicArray::~DynamicArray() {
    clear();
}

void DynamicArray::add(const SpaceEntity* entity) {
    if (size >= capacity) resize();
    data[size++] = entity->clone();
}

void DynamicArray::remove(size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    delete data[index];
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

void DynamicArray::print() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->print(std::cout);
        std::cout << "\n";
    }
}

void DynamicArray::clear() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = capacity = 0;
}

void DynamicArray::save(const std::string& fileName) const {
    std::ofstream file(fileName);
    if (!file) throw std::runtime_error("Cannot open file for writing");
    
    file << size << "\n";
    for (size_t i = 0; i < size; ++i) {
        data[i]->serialize(file);
    }
}

void DynamicArray::load(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        throw std::runtime_error("Cannot open file for reading");
    }
    
    clear();
    
    size_t count;
    file >> count;
    file.ignore();
    
    for (size_t i = 0; i < count; ++i) {
        std::string type;
        if (!(file >> type)) {
            throw std::runtime_error("Failed to read entity type");
        }
        
        SpaceEntity* entity = nullptr;
        
        try {
            if (type == "Star") {
                std::string name;
                double temp, lum;
                if (!(file >> name >> temp >> lum)) {
                    throw std::runtime_error("Invalid Star data");
                }
                entity = new Star(name.c_str(), temp, lum);
            }
            else if (type == "Planet") {
                std::string name;
                double temp;
                bool solid, atmosphere;
                if (!(file >> name >> temp >> solid >> atmosphere)) {
                    throw std::runtime_error("Invalid Planet data");
                }
                entity = new Planet(name.c_str(), temp, solid, atmosphere);
            }
            else if (type == "Asteroid") {
                std::string name;
                Vector3 pos, vel;
                double diameter;
                if (!(file >> name >> pos.x >> pos.y >> pos.z 
                          >> vel.x >> vel.y >> vel.z >> diameter)) {
                    throw std::runtime_error("Invalid Asteroid data");
                }
                entity = new Asteroid(name.c_str(), pos, vel, diameter);
            }
            else if (type == "Spacecraft") {
                std::string name;
                Vector3 pos, vel;
                double maxSpeed;
                int ammo;
                bool hostile;
                if (!(file >> name >> pos.x >> pos.y >> pos.z 
                          >> vel.x >> vel.y >> vel.z >> maxSpeed >> ammo >> hostile)) {
                    throw std::runtime_error("Invalid Spacecraft data");
                }
                entity = new Spacecraft(name.c_str(), pos, vel, maxSpeed, ammo, hostile);
            }
            else if (type == "Missile") {
                Vector3 pos, vel;
                double power, fuelTime;
                if (!(file >> pos.x >> pos.y >> pos.z 
                          >> vel.x >> vel.y >> vel.z >> power >> fuelTime)) {
                    throw std::runtime_error("Invalid Missile data");
                }
                entity = new Missile(pos, vel, power, fuelTime);
            }
            else {
                throw std::runtime_error("Unknown entity type: " + type);
            }
            
            if (entity) {
                add(entity);
                delete entity; 
            }
        }
        catch (...) {
            delete entity;
            throw;
        }
    }
}