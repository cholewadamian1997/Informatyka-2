#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <functional>

typedef int Time;
typedef int Duration;
typedef int ElementID;

typedef enum{WORKER , STOREHOUSE} ReceiverType;
typedef enum{LIFO, FIFO} QueueType;

class Product{

private:
    ElementID id;

public:
    Product(ElementID);
    Product(const Product&);
    ElementID getId();
};

class IReceiver{

public:
    virtual void ReceiveProduct(const Product) = 0;
    virtual void viewDepot() = 0;
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
    IReceiver* drawReceiver();
    void view();
};

class Sender{

private:
    Preferences receiver_preferences;
    std::vector<Product> list_of_products;
public:
    Sender(Preferences);
    Sender(Preferences _receiver_preferences, std::vector<Product> _list_of_products) : receiver_preferences(_receiver_preferences), list_of_products(_list_of_products) {}
    Sender(const Sender & sender) : receiver_preferences(sender.receiver_preferences), list_of_products(sender.list_of_products) {}
    void sendProduct();
    void setPreferences(Preferences);
    Preferences getPreferences();
    ~Sender() {}
};

class Storage{

private:
    std::deque<Product> products_deque;
public:
    virtual void push(const Product&);
    bool isEmpty();
    int storage_size();
    void view();
};

class Queue : Storage{

private:
    std::deque<Product> products_deque;
    QueueType queue_type;
    std::function<Product()> pop_function;

public:
    void push(const Product&);
    void pop();
    bool isEmpty();
    int queueSize();
    void view();
    QueueType getQueueType();
};

class Storehouse : IReceiver{

private:
    ElementID id;
    Storage* storage;

public:
    Storehouse(ElementID);
    void receiveProduct(const Product);
    void viewDepot();
    ElementID getId();
    ReceiverType getReceiverType();
};

class Ramp : Sender{

private:
    ElementID id;
    Duration delivery_frequency;

public:
    Ramp(Preferences _receiver_preferences, ElementID _id, Duration _delivery_frequency)
        : Sender(_receiver_preferences), id(_id), delivery_frequency(_delivery_frequency) {}
    ElementID getId();
    Duration getDeliveryFrequency();

};

class Worker : Sender, IReceiver {

private:
    ElementID id;
    Duration processing_time;
    Queue* queue;

public:
    Worker(ElementID, Duration, Queue*);
    void ReceiveProduct(const Product);
    void viewDepot();
    void doWork();
    virtual ElementID getId();
    Duration getProcessingTime();
    ReceiverType getReceiverType();
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


