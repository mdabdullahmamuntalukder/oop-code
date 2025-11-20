#include<bits/stdc++.h>
using namespace std;
class ticket
{
protected:
    string ticketID,source ,destination;
    float distance;
public:
    void setTicketInfo()
    {
        cout<<"Enter Ticket ID: ";
        cin>>ticketID;
        cout<<"Enter Source: ";
        cin>>source;
        cout<<"Enter Destination: ";
        cin>>destination;
        cout<<"Enter Distance in km: ";
        cin>>distance;
    }
    void displayTicketInfo()
    {
        cout<<"Ticket Id: "<<ticketID<<endl;
        cout<<"Source: "<<source<<endl;
        cout<<"Destination: "<<destination<<endl;
        cout<<"Distance: "<<distance<<endl;
    }
    virtual float calculateFare()
    {
        return distance*1.0;
    }
};
class TrainTicket:private ticket
{
private:
    string coachType;
public:
    void setTrainTicket()
    {
        setTicketInfo();
        cout<<"Enter Coach Type: ";
        cin>>coachType;
    }
    float calculateFare()
    {
        float fare =distance*1.0;
        if(coachType=="AC")
        {
            fare+=200;
        }
        else if(coachType=="Sleeper")
        {
            fare+=100;
        }
       
        return fare;

    }
    void displayTrainTicket() {
        
        cout << " Train Ticket Details:\n ";
        displayTicketInfo();
        cout << "Coach Type: " << coachType << endl;
        cout << "Total Fare: " << calculateFare() << " tk" << endl;
    }
};
class FlightTicket:protected ticket
{
protected:
    string seatClass;
    float luggageWeight;
public:
    void setFlightTicket()
    {
        setTicketInfo();
        cout<<"Enter seat class: ";
        cin>>seatClass;
        cout<<"Enter Luggage Weight in kg: ";
        cin>>luggageWeight;
    }
    float calculateFare()
    {
        float fare=distance*25.0;
        if(seatClass=="Business")
        {
            fare+=20000;
        }
        if(luggageWeight>20)
        {
            float extra = luggageWeight - 20;
            fare += extra * 5000;
        }
        return fare;
    }
    void displayFlightTicket()
    {
        cout<<"Flight Ticket Details:\n";
        displayTicketInfo();
        
        cout<<"seat Class: "<<seatClass<<endl;
        cout<<"Luggage Weight: "<<luggageWeight<<endl;
        cout<<"Total Fare: "<<calculateFare()<<" tk"<<endl;
    }


};
int main()
{
    TrainTicket t1;
    FlightTicket t2;
    cout<<"Enter Train Ticket Information:\n";
    t1.setTrainTicket();
    t1.displayTrainTicket();
    cout<<"Enter Flight Ticket Information:\n";
    t2.setFlightTicket();
   t2.displayFlightTicket();
    return 0;
}