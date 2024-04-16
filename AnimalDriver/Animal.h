#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

enum class RandomEvents // ������������� ������������ ������
{
    Sleep,      //0
    Base,       //1
    GoatTime    //2
};
void getEvent(RandomEvents event) {
    switch (event) {
    case(RandomEvents::Sleep):
        cout << "Animal is sleeping" << endl;
        break;
    case(RandomEvents::Base):
        cout << "Animal is good" << endl;
        break;
    case(RandomEvents::GoatTime):
        cout << "ITS TIME TO GOAT" << endl;
        break;
    default:
        cout << "doesn't exist" << endl;
        break;
    }
}
RandomEvents generateRandomEvent()
{

    // ��������� ���������� �����
    int randomValue = rand() % 3;

    // ����������� ���������������� �������� �� ������������
    return static_cast<RandomEvents>(randomValue);
}


class Animal {
public:
    Animal(string name, double baseSpeed) : strName(name), dBaseSpeed(baseSpeed) {}
    virtual ~Animal() = default;

    string getName() const {
        return strName;
    }
    virtual double getSpeed() const = 0 {};
    virtual void updateSpeed() {};
    virtual void setEvent(RandomEvents newEvent) { 
        event = newEvent;
        getEvent(event);
    }
    virtual void run() = 0;
    virtual int getDistance() const = 0;


protected:
    string strName;
    double dBaseSpeed;
    RandomEvents event;
    double distanceRun;
};

//����� �����
class Rabbit : public Animal {
public:
    Rabbit(string name, double speed) : Animal(name, speed) {}

    double getSpeed() const override {
        return dBaseSpeed;
    }
    virtual void updateSpeed() override {
        // ������������� ����������� ���������� ��� ��������� ��������� �����
        if (event != RandomEvents::Sleep) {
            dBaseSpeed += event == RandomEvents::Base ? dBaseSpeed : dBaseSpeed * (rand() % 10);
            return;
        }
        dBaseSpeed = 0;
           
    }
    void run() override {
        distanceRun += dBaseSpeed * (1000 / 3600);
    }
    int getDistance() const override {
        return distanceRun;
    }

};

//����� ��������
class Turtle : public Animal {
public:
    Turtle(string name, double speed) : Animal(name, speed) {}

    double getSpeed() const override {
        return dBaseSpeed;
    }
    virtual void updateSpeed() override {
        // ������������� ����������� ���������� ��� ��������� ��������� �����
        if (event != RandomEvents::Sleep) {
            dBaseSpeed = 0;
            return;
        }
        dBaseSpeed += event == RandomEvents::Base ? dBaseSpeed : dBaseSpeed * (rand() % 10);


        //dBaseSpeed += event != RandomEvents::Sleep ? dis(gen) : -dBaseSpeed;
    }
    void run() override {
        distanceRun += dBaseSpeed * (1000 / 3600);
    }
    int getDistance() const override {
        return distanceRun;
    }


};
