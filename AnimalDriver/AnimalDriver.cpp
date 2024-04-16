#include "Animal.h"
#include "HelperTick.h"


int main() {
    setlocale(LC_ALL, "Russian");

    int kmDistance;

    cout << "Укажите кол-во км забега (km): "; //1
    cin >> kmDistance;


    vector<unique_ptr<Animal>> animals;

    animals.push_back(make_unique<Rabbit>("Заяц", 23));
    animals.push_back(make_unique<Turtle>("Черепаха", 5));

    std::cout << "Соревнование в беге между животными:" << std::endl;

    F2::Timer t(1000);
    t.start();
    bool isFinished = false;

    while (true)
    {
        t.get_tick();
        if (t.updated()) // If the tick value has changed
        {
            
            for (auto& animal : animals) {
                animal->setEvent(generateRandomEvent());
                animal->updateSpeed();
                animal->run();
                if (animal->getDistance() >= kmDistance ) {

                    std::cout << "Животное " << animal->getName() << " прибыло на финиш!" << std::endl;
                    std::cout << "Дистанция: " << animal->getDistance() << " м" << std::endl;
                    isFinished = true;
                }
            }

            // Отсортировать животных по скорости
            std::sort(animals.begin(), animals.end(), [](const unique_ptr<Animal>& a, const unique_ptr<Animal>& b) {
                return a->getSpeed() > b->getSpeed();
                });

            // Вывод текущего положения животных
            for (const auto& animal : animals) {
                std::cout << animal->getName() << ": " << animal->getSpeed() << " км/ч" << std::endl;
            }
            if (isFinished)
                break;
        }
        
    }
 
    std::cout << "Результат соревнования:" << std::endl;
    std::cout << "Победитель: " << animals.front()->getName() << std::endl;

    return 0;
}
