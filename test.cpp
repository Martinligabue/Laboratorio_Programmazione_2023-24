
#include <iostream>
#include <vector>
#include <unistd.h>



int main(int argc, char *argv[]){
    std::cout << "Hello, World!" << std::endl;
    Observer o;
    Subject s;
    // Create displays


    // Register displays as observers
    s.addObserver(&o);

    s.Carica();

    return 0;
}



class ObserverInterface {
public:
    virtual void update(int percentuale) = 0;
};


class Observer : public ObserverInterface {
public:
    void update(int percentuale) {
        std::cout << "percentuale " << percentuale
        << std::endl;
    }
};


class Subject {
private:
    int percentuale;
    //vector perchè è dinamico rispetto all'array classico
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyAll(int percentuale) {
        for (Observer* observer : observers) {
            observer->update(percentuale);
        }
    }


    void Carica() {
        for (int i = 0; i <100; i++){
            notifyAll(i);
            sleep(1);
        }
    }
};