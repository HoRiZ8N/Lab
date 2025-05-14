#pragma once

#include <iostream>
#include <cstring>
#include <cmath>

// SpaceEntity (абстрактный)
// ├── StaticEntity (абстрактный)
// │   ├── Star
// │   └── Planet
// └── MovingEntity (абстрактный)
//     ├── Asteroid
//     ├── Spacecraft
//     └── Missile

struct Vector3 {
    double x;
    double y;
    double z;
    Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

class SpaceEntity {
protected:
    char* name;
    static void copyString(const char* source, char*& destination) {
        if (source == nullptr) {
            destination = nullptr;
            return;
        }
        size_t length = strlen(source) + 1;
        destination = new char[length];
        strncpy(destination, source, length);
    }

public:
    SpaceEntity() : name(nullptr) {}
    SpaceEntity(const char* entityName) : name(nullptr) {
        if (entityName != nullptr) {
            copyString(entityName, name);
        }
    }
    SpaceEntity(const SpaceEntity& other) : name(nullptr) {
        copyString(other.name, name);
    }
    SpaceEntity& operator=(const SpaceEntity& other) {
        if (this != &other) {
            delete[] name;
            copyString(other.name, name);
        }
        return *this;
    }
    virtual ~SpaceEntity() {
        delete[] name;
    }

    const char* getName() const { return name; }
    void setName(const char* newName) {
        delete[] name;
        copyString(newName, name);
    }

    virtual void serialize(std::ostream& os) const = 0;
    virtual SpaceEntity* clone() const = 0;
    virtual void print(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const SpaceEntity& entity) {
        entity.print(os);
        return os;
    }
};

class StaticEntity : public SpaceEntity {
protected:
    double temperature;
    bool hasSolidSurface;

public:
    StaticEntity(const char* name, double temp, bool solid)
        : SpaceEntity(name), temperature(temp), hasSolidSurface(solid) {}

    double getTemperature() const { return temperature; }
    void setTemperature(double temp) { temperature = temp; }

    bool getHasSolidSurface() const { return hasSolidSurface; }
    void setSolidSurface(bool solid) { hasSolidSurface = solid; }
};

class Star : public StaticEntity {
protected:
    double luminosity;

public:
    Star(const char* name, double temp, double lum)
        : StaticEntity(name, temp, false), luminosity(lum) {}

    double getLuminosity() const { return luminosity; }
    void setLuminosity(double lum) { luminosity = lum; }

    Star* clone() const override { return new Star(*this); }

    void serialize(std::ostream& os) const override {
    os << "Star "
       << (name ? name : "") << " "
       << temperature << " "
       << luminosity << "\n";
    }
    void print(std::ostream& os) const override {
        os << "Star [" << (name ? name : "Unnamed") << "] "
           << "Temp: " << temperature << "K, "
           << "Luminosity: " << luminosity << "L";
    }
};

class Planet : public StaticEntity {
protected:
    bool atmospherePresent;

public:
    Planet(const char* name, double temp, bool solid, bool atmosphere)
        : StaticEntity(name, temp, solid), atmospherePresent(atmosphere) {}

    bool hasAtmosphere() const { return atmospherePresent; }
    void setAtmosphere(bool atm) { atmospherePresent = atm; }

    void serialize(std::ostream& os) const override {
        os << "Planet "
        << (name ? name : "") << " "
        << temperature << " "
        << hasSolidSurface << " "
        << atmospherePresent << "\n";
    }

    Planet* clone() const override { return new Planet(*this); }

    void print(std::ostream& os) const override {
        os << "Planet [" << (name ? name : "Unnamed") << "] "
           << "Temp: " << temperature << "K, "
           << (hasSolidSurface ? "Solid" : "Gas") << ", "
           << (atmospherePresent ? "Has atmosphere" : "No atmosphere");
    }
};

class MovingEntity : public SpaceEntity {
protected:
    Vector3 position;
    Vector3 velocity;

public:
    MovingEntity(const char* name, const Vector3& pos, const Vector3& vel)
        : SpaceEntity(name), position(pos), velocity(vel) {}

    Vector3 getPosition() const { return position; }
    void setPosition(const Vector3& pos) { position = pos; }

    Vector3 getVelocity() const { return velocity; }
    void setVelocity(const Vector3& vel) { velocity = vel; }

    virtual void Move(double time) = 0;
};

class Asteroid : public MovingEntity {
protected:
    double maxDiameter;

public:
    Asteroid(const char* name, const Vector3& pos,
             const Vector3& vel, double diameter)
        : MovingEntity(name, pos, vel), maxDiameter(diameter) {}

    double getDiameter() const { return maxDiameter; }
    void setDiameter(double diameter) { maxDiameter = diameter; }

    void Move(double time) override {
        position.x += velocity.x * time;
        position.y += velocity.y * time;
        position.z += velocity.z * time;
    }

    Asteroid* clone() const override { return new Asteroid(*this); }

    void serialize(std::ostream& os) const override {
        os << "Asteroid "
        << (name ? name : "") << " "
        << position.x << " " << position.y << " " << position.z << " "
        << velocity.x << " " << velocity.y << " " << velocity.z << " "
        << maxDiameter << "\n";
    }

    void print(std::ostream& os) const override {
        os << "Asteroid [" << (name ? name : "Unnamed") << "] "
           << "Pos: (" << position.x << ", " << position.y << ", " << position.z << "), "
           << "Vel: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << "), "
           << "Size: " << maxDiameter << "m";
    }
};

class Spacecraft : public MovingEntity {\
protected:
    double maxSpeed;
    int ammoCount;
    bool hostile;

public:
    Spacecraft(const char* name, const Vector3& pos,
               const Vector3& vel, double maxV, int ammo, bool hostile)
        : MovingEntity(name, pos, vel), maxSpeed(maxV), ammoCount(ammo), hostile(hostile) {}

    double getMaxSpeed() const { return maxSpeed; }
    int getAmmoCount() const { return ammoCount; }
    bool isHostile() const { return hostile; }

    void setMaxSpeed(double speed) { maxSpeed = speed; }
    void setAmmoCount(int count) { ammoCount = count; }
    void setHostile(bool isHostile) { hostile = isHostile; }

    void Move(double time) override {
        double currentSpeed = sqrt(velocity.x*velocity.x + velocity.y*velocity.y + velocity.z*velocity.z);
        if (currentSpeed > maxSpeed) {
            double ratio = maxSpeed / currentSpeed;
            velocity.x *= ratio;
            velocity.y *= ratio;
            velocity.z *= ratio;
        }
        position.x += velocity.x * time;
        position.y += velocity.y * time;
        position.z += velocity.z * time;
    }

    void Shoot() {
        if (ammoCount > 0) ammoCount--;
    }

    void serialize(std::ostream& os) const override {
        os << "Spacecraft "
        << (name ? name : "") << " "
        << position.x << " " << position.y << " " << position.z << " "
        << velocity.x << " " << velocity.y << " " << velocity.z << " "
        << maxSpeed << " " << ammoCount << " " << hostile << "\n";
    }

    Spacecraft* clone() const override { return new Spacecraft(*this); }

    void print(std::ostream& os) const override {
        os << (hostile ? "Enemy" : "Friendly") << " Spacecraft [" << (name ? name : "Unnamed") << "] "
           << "Pos: (" << position.x << ", " << position.y << ", " << position.z << "), "
           << "Vel: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << "), "
           << "Max speed: " << maxSpeed << ", Ammo: " << ammoCount;
    }
};

class Missile : public MovingEntity {
protected:
    double explosionPower;
    double remainingFuelTime;

public:
    Missile(const Vector3& pos, const Vector3& vel, double power, double fuelTime)
        : MovingEntity(nullptr, pos, vel), explosionPower(power), remainingFuelTime(fuelTime) {}

    double getPower() const { return explosionPower; }
    double getRemainingFuelTime() const { return remainingFuelTime; }

    void setPower(double power) { explosionPower = power; }
    void setFuelTime(double time) { remainingFuelTime = time; }

    void Move(double time) override {
        if (remainingFuelTime <= 0) return;
        double moveTime = (time > remainingFuelTime) ? remainingFuelTime : time;
        position.x += velocity.x * moveTime;
        position.y += velocity.y * moveTime;
        position.z += velocity.z * moveTime;
        remainingFuelTime -= moveTime;
    }

    bool isActive() const { return remainingFuelTime > 0; }

    Missile* clone() const override { return new Missile(*this); }

    void serialize(std::ostream& os) const override {
        os << "Missile "
        << position.x << " " << position.y << " " << position.z << " "
        << velocity.x << " " << velocity.y << " " << velocity.z << " "
        << explosionPower << " " << remainingFuelTime << "\n";
    }

    void print(std::ostream& os) const override {
        os << "Missile - "
           << "Pos: (" << position.x << ", " << position.y << ", " << position.z << "), "
           << "Vel: (" << velocity.x << ", " << velocity.y << ", " << velocity.z << "), "
           << "Power: " << explosionPower << ", "
           << "Fuel left: " << remainingFuelTime << "s";
    }
};