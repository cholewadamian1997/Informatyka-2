#include "Factory.hpp"

// class: Preferences
std::map<IReceiver*, double > Preferences::getPreferences(){

    return preferences;
}

// nw czy o to chodzi ???
void Preferences::setPreferences(std::map<IReceiver* , double> preferences){

    double tmp;
    for (auto &it : preferences){
        std::cin >> tmp;
        it.second = tmp;
    }
}

void Preferences::addReceiver(IReceiver* receiver){

    preferences.insert (std::pair<IReceiver*, double>(receiver, (1/preferences.size())));

    for (auto &it : preferences)
        it.second=(1/preferences.size());
}

void Preferences::addReceiverWithPreferences(IReceiver* receiver, double probability){

    for (auto &it : preferences)
        it.second=(1-probability)*(it.second);

    preferences.insert (std::pair<IReceiver*, double>(receiver, probability));
}

void Preferences::removeReceiver(IReceiver* receiver){

    for (auto &it : preferences)
        it.second=(it.second)/(1-preferences[receiver]);

    preferences.erase(receiver);
}

void Preferences::view(){

    for (auto &it : preferences)
        std::cout << "ID: " << it.first << "  Probability: " << it.second << std::endl;
}

IReceiver* Preferences::drawReceiver(){

    std::ostringstream ss;
    std::string str;
    int digits_after_dot;
    int max_size = 0;

    for(auto &it : preferences){

        ss << it.second;
        str = ss.str();

        if (it.second > 1){
            std::cout << "EROR" << std::endl;
            digits_after_dot = -1;
        }
        if (it.second == 0)
            digits_after_dot = -1;
        if (it.second == 1)
            digits_after_dot = 0;
        else
            digits_after_dot = str.size()-2;

        if (digits_after_dot > max_size)
            max_size = digits_after_dot;
    }

    int range = pow(10,max_size);

    srand( time( NULL ) );
    double drawn_number = (std::rand() & range);
    drawn_number /= range;

    int x = 0;

    for (auto &it : preferences) {

        if (x <= drawn_number &&  drawn_number < x + it.second)
            return it.first;

        x += it.second;
    }
}
// class: Product
Product::Product(ElementID _id) {id = _id;}

Product::Product(const Product& product) {id = product.id;}

ElementID Product::getId() { return id;}

// class: Storage
void Storage::push(const Product& product){ products_deque.push_back(product); }

//true if the Storage size is 0, false otherwise.
bool Storage::isEmpty() { return products_deque.empty(); }

int Storage::storage_size() { return products_deque.size(); }

void Storage::view() {

    for (auto &it : products_deque)
        std::cout << it.getId() << std::endl;
}

// class: Queue
QueueType Queue::getQueueType() {return queue_type;}

void Queue::push(const Product& product) { products_deque.push_back(product); }

void Queue::pop(){

    if (queue_type == FIFO)
        products_deque.pop_back();

    else if (queue_type == LIFO)
        products_deque.pop_front();
}

bool Queue::isEmpty() {return products_deque.empty();}

int Queue::queueSize() {return products_deque.size();}

void Queue::view() {

    for (auto &it : products_deque)
        std::cout << it.getId() << std::endl;
}

// class: Sender
Sender::Sender(Preferences _receiver_preferences) {
    receiver_preferences = _receiver_preferences;
}

void Sender::sendProduct(){
    if (list_of_products.size() == 0){
        std::cout << "Brak produktów do wysłania";
    }
    Product product_to_send = list_of_products[0];
    std::vector<Product>:: iterator it = list_of_products.begin();
    list_of_products.erase(it);
    auto chosen_receiver = receiver_preferences.drawReceiver();
    //chosen_receiver.receiveProduct(product_to_send);
}

void Sender::setPreferences(Preferences pref){
    receiver_preferences = pref;
}

Preferences Sender::getPreferences(){
    return receiver_preferences;
}

// class StorageHouse
Storehouse::Storehouse(ElementID _id) {id = _id; }

void Storehouse::receiveProduct(Product product) {
    storage->push(product);
}

void Storehouse::viewDepot() {
    storage->view();
}

ElementID Storehouse::getId() {
    return id;
}

ReceiverType Storehouse::getReceiverType() {
    return STOREHOUSE;
}

// class Ramp
ElementID Ramp::getId() {
    return id;
}

Duration Ramp::getDeliveryFrequency() {
    return delivery_frequency;
}

//
