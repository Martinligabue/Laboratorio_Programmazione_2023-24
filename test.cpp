#include <iostream>
#include <vector>
#include <unistd.h>
#include <QApplication>
#include <QProgressBar>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Creazione della barra di caricamento
    QProgressBar progressBar;
    progressBar.setRange(0, 100); // Imposta la gamma da 0 a 100
    progressBar.show();

    // Creazione di un timer per simulare il progresso del caricamento
    QTimer timer;
    int progressValue = 0;

    // Collega il segnale timeout del timer alla lambda function per aggiornare la barra di caricamento
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        progressValue += 10;
        progressBar.setValue(progressValue);

        if (progressValue >= 100) {
            // Il caricamento è completo, arresta il timer
            timer.stop();
        }
    });

    // Imposta l'intervallo del timer a 500 millisecondi (0,5 secondi)
    timer.start(500);

    return app.exec();
}


/*/ Dichiarazioni delle classi Observer e Subject
class Observer;
class Subject;

class ObserverInterface {
public:
    virtual void update(int percentuale) = 0;
};

class Observer : public ObserverInterface {
public:
    void update(int percentuale) {
        std::cout << "percentuale " << percentuale << std::endl;
    }
};

class Subject {
private:
    int percentuale;
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
        for (int i = 0; i < 100; i++) {
            notifyAll(i);
            sleep(1);
        }
    }
};

int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Observer o;
    Subject s;
    
    // Create displays

    // Register displays as observers
    s.addObserver(&o);

    s.Carica();

    return 0;
}
*/