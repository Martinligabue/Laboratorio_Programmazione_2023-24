# Laboratorio_Programmazione_2023-24
 
# Observer Pattern with Qt in C++

Questo progetto illustra l'implementazione del pattern Observer utilizzando il framework Qt in C++. Nel contesto di questo esempio, il pattern Observer viene utilizzato per aggiornare una finestra Qt con una percentuale in base alle notifiche da un soggetto.

## Struttura del progetto

- `TextWindow.h` e `TextWindow.cpp`: Contengono la definizione e l'implementazione della classe `TextWindow`, che eredita da `QLabel` e rappresenta la finestra Qt per la visualizzazione del testo.
- `ObserverInterface.h` e `Observer.cpp`: Definiscono l'interfaccia e l'implementazione della classe `Observer`, che si occupa di aggiornare la finestra `TextWindow`.
- `Subject.h` e `Subject.cpp`: Contengono la definizione e l'implementazione della classe `Subject`, che emette notifiche agli osservatori.
- `main.cpp`: Contiene il punto di ingresso del programma, crea una finestra `TextWindow`, un osservatore `Observer`, e simula notifiche periodiche del soggetto.

## Build e Esecuzione

```bash
make
make run
```