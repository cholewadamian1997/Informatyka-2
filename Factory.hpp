#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <queue>
#include <stack>

typedef int Time;
typedef int Duration;
typedef int ElementID;

typedef enum{WORKER, STOREHOUSE} ReceiverType;
typedef enum{LIFO, FIFO} QueueType;

class Product{

private:
    ElementID id;

public:
    Product(ElementID _id) {id = _id;}
    Product(const Product& product) {id = product.id;}
    ElementID getId();
};

class IReceiver{

public:
    virtual void ReceiveProduct(Product) = 0;
    virtual Product viewDepot() = 0;
    virtual ReceiverType getReceiverType() = 0;
    virtual ElementID getId() = 0;
};

class Preferences{

private:
    std::map<IReceiver*, double> preferences;

public:

    std::map<IReceiver*, double> getPreferences();
    void setPreferences(std::map<IReceiver*, double>);
    void addReceiver(IReceiver*);
    void addReceiverWithPreferences(IReceiver*, double);
    void removeReceiver(IReceiver*);
    std::pair<IReceiver*, double> view();
};

class Sender{

private:
    Preferences receiver_preferences;
public:
    Sender(ElementID);
    virtual void sendProduct();
    virtual void setPreferences(Preferences);
    virtual Preferences getPreferences();
};

class IStorage{

public:
    virtual void push(Product) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual Product view() = 0;
};

class IQueue : IStorage{

public:
    virtual void push(Product) = 0;
    virtual Product pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual Product view() = 0;
    virtual QueueType getQueueType() = 0;
};

class Storehouse : IReceiver{

private:
    ElementID id;
    IStorage* storage;

public:
    Storehouse(ElementID);
    void receiveProduct(Product);
    virtual Product viewDepot();
    virtual ElementID getId();
};

class Ramp : Sender{

private:
    ElementID id;
    Duration delivery_frequency;

public:
    Ramp(ElementID, Duration);
    ElementID getId();
    Duration getDeliveryFrequency();

};

class Worker : Sender, IReceiver {

private:
    ElementID id;
    Duration processing_time;
    IQueue* queue;

public:
    Worker(ElementID, Duration, IQueue*);
    virtual void ReceiveProduct(Product);
    virtual Product viewDepot();
    void doWork();
    virtual ElementID getId();
    Duration getProcessingTime();
    virtual ReceiverType getReceiverType();
};

class Factory {

private:
    std::vector<Storehouse> storehouses;
    std::vector<Worker> workers;
    std::vector<Ramp> ramps;\

public:
    Ramp getRamps();
    void addRamp(Ramp);
    void removeRamp(ElementID);

    Worker getWorkers();
    void addWroker(Worker);
    void removeWorker(ElementID);

    Storehouse& getStorehouses();  //zwaracam referencje bo inaczej error "invalid abstract return type
    void addStorehouse(Storehouse&);
    void removeStorehouse(ElementID);

    bool isConected();
};
#endif // FACTORY_HPP
