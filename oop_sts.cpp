#include <bits/stdc++.h>
using namespace std;
class planet{
    public:
      string name;
      double x,y,z;
      planet(string name,double x,double y,double z){
      this->name=name;
      this->x=x;
      this->y=y;
      this->z=z;}
      double get_x(){
      return x;
      }
      double get_y(){
      return y;
      }
      double get_z(){
      return z;
      }
      string get_name(){
      return name;
      }
      void get_coordinates(){
      cout<<x<<" "<<y<<" "<<z<<endl;
      }
      double distance(planet*other){
      return sqrt(pow(this->x-other->get_x(),2)+pow(this->y-other->get_y(),2)+pow(this->z-other->get_z(),2));
      }
};

class moon: public planet{
   public:
     string atmosphere;
     string water;
     string get_atmosphere();
     string get_water();
};
class traveller{
   protected:
     int id;
     int astronaut_id;
     int commander_id;
   public:
     static int given_id;
     string name;
     string traveller_id;
     vector<int> list_of_tickets;
     string get_name(){
     return name;
     }
     int get_id(){
     return id;
     }
     string get_trav_id(){
     return traveller_id;
     }
     void update_id(string id){
     this->traveller_id=id;
     }
     bool verify_id(string id){
     return (this->traveller_id==id);
     }
};

class astronaut:public traveller{
   public:
     int experience;
     astronaut(string name,int experience,string traveller_id){
     this->name=name;
     this->experience=experience;
     this->traveller_id=traveller_id;
     given_id++;
     }
     void push_astro();
     void set_id(){
     id=given_id;
     }
};
vector<astronaut*> list_of_astro;
void astronaut::push_astro(){
     list_of_astro.push_back(this);
}
class commander:public traveller{
   public:
     int experience;
     string license_id;
     void push_commander();
     commander(string name,int experience,string license_id){
     this->name=name;
     this->experience=experience;
     this->license_id=license_id;
     push_commander();
     }
     void set_id(){
     id=given_id;
     }
};
vector<commander*> list_of_commander;
void commander::push_commander(){
     list_of_commander.push_back(this);
}

class passenger:public traveller{
     int validity;
   public:
     passenger(string name,string traveller_id){
     this->name=name;
     this->validity=10;
     given_id++;
     this->traveller_id=traveller_id;
     }
     void set_id(){
     id=given_id;
     }
};
class ticket{
     int price;
   public:
     traveller*passenger;
     planet*source;
     planet*destination;
     int date;
     int month;
     int year;
     static int ticket_id;
     bool is_return_trip;
     void push_global(ticket* Ticket);
     ticket(planet* source,planet* destination,int date,int month,int year,bool is_return_trip,traveller*passenger){
     this->passenger=passenger;
     this->source=source;
     this->destination=destination;
     this->date=date;
     this->month=month;
     this->year=year;
     this->is_return_trip=is_return_trip;
     push_global(this);
     cout<<"your ticket has been booked"<<endl;
     ticket_id++;
     }
     void update(planet* source,planet* destination,int date,int month,int year,bool is_return_trip){
     this->source=source;
     this->destination=destination;
     this->date=date;
     this->month=month;
     this->year=year;
     this->is_return_trip=is_return_trip;
     cout<<"your trip has been updated"<<endl;
     }
     int cost(){
     tm travel_date={0,0,0,date,month-1,year-1900,0,0,0};
     time_t travel_time=mktime(&travel_date);
     int k=source->distance(destination);
     auto now=chrono::system_clock::to_time_t(chrono::system_clock::now());
     int days_until_travel=ceil(difftime(now,travel_time)/(60*60*24))+1;
     return k/days_until_travel;
     }
     void print_ticket(){
     cout<<"Passenger name:"<<this->passenger->name<<endl;
     cout<<"Ticket_id:"<<this->ticket_id<<endl;
     cout<<"Source_planet:"<<this->source->name<<endl;
     cout<<"Destination planet:"<<this->destination->name<<endl;
     cout<<"Date of travel:"<<this->date<<"-"<<this->month<<"-"<<year<<endl;
     cout<<"Return ticket:"<<this->is_return_trip<<endl;
     cout<<"Price"<<this->get_price();
     }
     void push(){
     (passenger->list_of_tickets).push_back(this->ticket_id);
     }
     void set_price(){
     price=cost();
     }
     void get_name(){
     cout<<passenger->get_name()<<endl;
     }
     void get_id(){
     cout<<passenger->get_id()<<endl;
     }
     int get_price(){
     return price;
     }
     ticket*find(int ticket_id);
     void delete_ticket(int ticket_id);
};
int ticket::ticket_id=0;
int traveller::given_id=0;
vector<ticket*>tickets;

ticket*ticket::find(int ticket_id){
   vector<ticket*>::iterator ptr;
   for(ptr=tickets.begin();ptr!=tickets.end();ptr++){
    if((*ptr)->ticket_id==ticket_id)return *ptr;
   }return nullptr;
}
void ticket::delete_ticket(int ticket_id){
  vector<ticket*>::iterator ptr;
  *ptr=find(ticket_id);
  tickets.erase(ptr);
}
void ticket::push_global(ticket* Ticket){
  tickets.push_back(Ticket);
}
class space_travel{
   private:
      vector<traveller*> list_of_travellers;
      astronaut* astro;
      commander* commando;
   public:
      planet* source;
      planet* destination;
      int date;
      int month;
      int year;
      int id;
      void add_traveller(traveller* pass){
        list_of_travellers.push_back(pass);
      }
      space_travel(){
        cout<<"Space travel created";
      }
      void list_traveller(){
        vector<traveller*>::iterator ptr;
        for(ptr=list_of_travellers.begin();ptr!=list_of_travellers.end();ptr++){
         cout<<"Name:"<<(*ptr)->name<<"  "<<"id:"<<(*ptr)->traveller_id<<endl;
        }
      }
      void set_astro(string id){
        vector<astronaut*>::iterator ptr;
        for(ptr=list_of_astro.begin();ptr!=list_of_astro.end();ptr++){
         if(id==(*ptr)->traveller_id) astro=*ptr;
        }
        cout<<"Astronaut with id "<<id<<" has been assigned"<<endl;
      }
      void set_commando(string id){
        vector<commander*>::iterator ptr;
        for(ptr=list_of_commander.begin();ptr!=list_of_commander.end();ptr++){
         if(id==(*ptr)->traveller_id) commando=*ptr;
        }
        cout<<"Commander with id "<<id<<" has been assigned"<<endl;
      }
      void update_commando(string id){
        vector<commander*>::iterator ptr;
        for(ptr=list_of_commander.begin();ptr!=list_of_commander.end();ptr++){
         if(id==(*ptr)->traveller_id) commando=*ptr;
        }
        cout<<"Commander with id "<<id<<" has been assigned"<<endl;
      }
      void update_astro(string id){
        vector<astronaut*>::iterator ptr;
        for(ptr=list_of_astro.begin();ptr!=list_of_astro.end();ptr++){
         if(id==(*ptr)->traveller_id) astro=*ptr;
        }
        cout<<"Astronaut with id "<<id<<" has been assigned"<<endl;
      }
      int get_id(){
       return id;
      }
      void set_id(int id){
       this->id=id;
      }
};

int main(){
    planet* Earth=new planet("Earth",0,0,0);
    planet* Jupiter=new planet("Jupiter",100,200,300);
    planet* Pluto=new planet("Pluto",500,700,30);

    astronaut* Astro1=new astronaut("Astro1",5,"IA10");
    astronaut* Astro2=new astronaut("Astro2",10,"IA78");
    commander* Com1=new commander("Com1",10,"IC15");
    commander* Com2=new commander("Com2",15,"IC20");
    passenger* P1=new passenger("P1","IP01");
    passenger* P2=new passenger("P2","IP02");
    passenger* P3=new passenger("P3","IP03");
    passenger* P4=new passenger("P4","IP04");
    passenger* P5=new passenger("P5","IP05");
    passenger* P6=new passenger("P6","IP06");
    passenger* P7=new passenger("P7","IP07");
    passenger* P8=new passenger("P8","IP08");
    passenger* P9=new passenger("P9","IP09");
    passenger* P10=new passenger("P10","IP10");
    passenger* P11=new passenger("P11","IP11");

    ticket* A_ticket=new ticket(Earth,Jupiter,20,3,2023,0,Astro1);
    ticket* C_ticket=new ticket(Earth,Jupiter,20,3,2023,0,Com1);
    ticket* P_ticket1=new ticket(Earth,Jupiter,20,3,2023,0,P1);
    ticket* P_ticket2=new ticket(Earth,Jupiter,20,3,2023,0,P2);
    ticket* P_ticket3=new ticket(Earth,Jupiter,20,3,2023,0,P4);

    int i,j,k,temp=0;
    for(i=0;i<=tickets.size();i++){
        for(j=0;j<=tickets.size();j++){
            if(i==j)continue;
            for(k=0;k<=tickets.size();k++){
            if(j==k || i==k)continue;
            if((tickets[i]->source)->name==(tickets[j]->source)->name&&(tickets[i]->source)->name==(tickets[k]->source)->name&&(tickets[i]->destination)->name==(tickets[j]->destination)->name&&(tickets[i]->destination)->name==(tickets[k]->destination)->name&&tickets[i]->date==tickets[j]->date&&tickets[i]->date==tickets[k]->date&&tickets[i]->month==tickets[j]->month&&tickets[i]->month==tickets[k]->month&&tickets[i]->year==tickets[j]->year&&tickets[i]->year==tickets[k]->year){
            temp=1;break;
            }
            }
        if(temp==1)break;
       }
        if(temp==1)break;
    }
    if(temp){
        space_travel travel;
        travel.id=1;
        travel.source=tickets[i]->source;
        travel.destination=tickets[i]->destination;
        travel.date=tickets[i]->date;
        travel.add_traveller(tickets[i]->passenger);
        travel.add_traveller(tickets[j]->passenger);
        travel.add_traveller(tickets[k]->passenger);
        travel.set_astro("IA10");
        travel.set_commando("IC15");
        travel.list_traveller();
    }
    return 0;
}

