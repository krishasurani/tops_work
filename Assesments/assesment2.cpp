#include<iostream>
#include<cmath> 

using namespace std;

class Event {
private:
    string eventName;
    string firstName;
    string lastName;
    int numberOfGuests;
    int numberOfMinutes;
    int numberOfServers;

    const double CostPerHour = 18.50;
    const double CostPerMinute = 0.40;
    const double CostOfDinner = 20.70;

public:
    Event() {
        eventName = "";
        firstName = "";
        lastName = "";
        numberOfGuests = 0;
        numberOfMinutes = 0;
        numberOfServers = 0;
    }

    void inputEventDetails() {
        cout << "Enter event name: ";
        cin >> eventName;
        cout << "Enter your first name: ";
        cin >> firstName;
        cout << "Enter your last name: ";
        cin >> lastName;
        cout << "Enter number of guests: ";
        cin >> numberOfGuests;
        cout << "Enter duration of event in minutes: ";
        cin >> numberOfMinutes;
    }

    void calculateServers() {
        numberOfServers = ceil(numberOfGuests / 20.0);
    }

    double calculateServerCost() {
        double cost1 = (numberOfMinutes / 60.0) * CostPerHour;
        double cost2 = (numberOfMinutes % 60) * CostPerMinute;
        return cost1 + cost2;
    }

    double calculateFoodCost() {
        return numberOfGuests * CostOfDinner;
    }

    double calculateAverageCost() {
        return calculateFoodCost() / numberOfGuests;
    }

    double calculateTotalCost() {
        return calculateFoodCost() + (calculateServerCost() * numberOfServers);
    }

    double calculateDepositAmount() {
        return calculateTotalCost() * 0.25;
    }

    void displayCostEstimation() {
        cout << "\nEvent Details:" << endl;
        cout << "Event Name: " << eventName << endl;
        cout << "Organizer: " << firstName << " " << lastName << endl;
        cout << "Number of Guests: " << numberOfGuests << endl;
        cout << "Duration of Event (minutes): " << numberOfMinutes << endl;
        cout << "Number of Servers Required: " << numberOfServers << endl;
        cout << "Total Food Cost: Rs" << calculateFoodCost() << endl;
        cout << "Average Cost Per Person: Rs" << calculateAverageCost() << endl;
        cout << "Total Cost: Rs" << calculateTotalCost() << endl;
        cout << "Deposit Amount (25%): Rs" << calculateDepositAmount() << endl;
    }
};

int main() {
    Event event;
    event.inputEventDetails();
    event.calculateServers();
    event.displayCostEstimation();

    return 0;
}
