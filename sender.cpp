#include "factory.hpp"

void Sender::sendProduct(){
    if (list_of_products.size() == 0){
        std::cout << "Brak produktów do wysłania";
    }
    Product product_to_send = list_of_products[0];
    std::vector<Product>:: iterator it = list_of_products.begin();
    list_of_products.erase(it);
    IReceiver chosen_receiver = receiver_preferences.drawReceiver;
    chosen_reciver.ReceiveProduct(product_to_send);
}

void Sender::setPreferences(Preferences pref){
    receiver_preferences = pref;
}

Preferences Sender::getPreferences(){
    return receiver_preferences;
}
