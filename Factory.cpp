#include "Factory.hpp"

// class: Preferences
std::map<IReceiver*, double > Preferences::getPreferences(){

    return preferences;
}

// nw czy o to chodzi ???
void Preferences::setPreferences(std::map<IReceiver* , double> preferences){

    double tmp;
    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it){
        std::cin >> tmp;
        it->second = tmp;
    }
}

void Preferences::addReceiver(IReceiver* receiver){

    preferences.insert (std::pair<IReceiver*, double>(receiver, (1/preferences.size())));

    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it)
        it->second=(1/preferences.size());
}

void Preferences::addReceiverWithPreferences(IReceiver* receiver, double probability){

    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it)
        it->second=(1-probability)*(it->second);

    preferences.insert (std::pair<IReceiver*, double>(receiver, probability));
}

void Preferences::removeReceiver(IReceiver* receiver){

    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it)
        it->second=(it->second)/(1-preferences[receiver]);

    preferences.erase(receiver);
}

std::pair<IReceiver*, double> Preferences::view(){

    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it)
        std::cout << "ID: " << it->first << "  Probability: " << it->second << std::endl;
}

IReceiver* Preferences::drawReceiver(){

    std::ostringstream ss;
    std::string str;
    int digits_after_dot;
    int range = pow(10,digits_after_dot);

    for(auto it=std::begin(preferences); it!=std::end(preferences); ++it){

        ss << it->second;
        str = ss.str();

        if (it->second > 1){
            std::cout << "EROR" << std::endl;
            digits_after_dot = -1;
        }
        if (it->second == 0)
            digits_after_dot = -1;
        if (it->second == 1)
            digits_after_dot = 0;
        else
            digits_after_dot = str.size()-2;
    }

    srand( time( NULL ) );
    double drawn_number = (std::rand() & range);
    drawn_number /= range;

    int x = 0;

    for (auto it=std::begin(preferences); it!=std::end(preferences); ++it){

        if (x <= drawn_number < x + it->second)
            return it->first;

        x += it->second;
    }
}

// class: IStorage
