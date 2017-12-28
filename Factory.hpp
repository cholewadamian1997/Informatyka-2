#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <functional>

typedef int Time;
typedef int Duration;
typedef int ElementID;

typedef enum{WORKER = 0, STOREHOUSE = 1} ReceiverType;
typedef enum{LIFO = 0, FIFO = 1} QueueType;

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
    IReceiver* drawReceiver();
    std::pair<IReceiver*, double> view();
};

class Sender{

private:
    Preferences receiver_preferences;
    std::vector<Product> list_of_products;
public:
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
    void push(Product);
    bool isEmpty();
    int size();
    Product view();
};

class Queue : Storage{

private:
    QueueType queue_type;
    std::function<Product()> pop_function;

public:
    void push(Product);
    Product pop();
    bool isEmpty();
    int size();
    Product view();
    QueueType getQueueType();
};

class Storehouse : IReceiver{

private:
    ElementID id;
    Storage* storage;

public:
    Storehouse(ElementID);
    void receiveProduct(Product);
    virtual Product viewDepot();
    virtual ElementID getId();
};

class Ramp : public Sender{

private:
    ElementID id;
    Duration delivery_frequency;

public:
    Ramp(ElementID _id, Duration df, Preferences rp, std::vector<Product> lop) : id(_id), delivery_frequency(df), Sender(rp, lop) {}
    Ramp(const Ramp & ramp, Preferences rp, std::vector<Product> lop) : id(ramp.id), delivery_frequency(ramp.delivery_frequency), Sender(rp, lop)  {}
    ElementID getId() {return id;}
    Duration getDeliveryFrequency() {return delivery_frequency;}

};

class Worker : Sender, IReceiver {

private:
    ElementID id;
    Duration processing_time;
    Queue* queue;

public:
    Worker(ElementID, Duration, Queue*);
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

