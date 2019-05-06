#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
using namespace std;
double scuter_vol = 0.2,scuter_mas=20.0,masina_vol=1.0,masina_mas=100,duba_vol=3.0,duba_mas=300;
int minute=0;
enum stare {stationar,in_mers};
enum tip {normal,special};

class obiect {
double vol;
double mas;
public:
    obiect(){ vol=0; mas=0;}
    obiect (double volum, double masa) { vol=volum; mas=masa; }
    double get_mas(){return mas;}
    double get_vol(){return vol;}

};
class vehicul{
    protected:
double eta;
stare stare_actuala;
double volum_admis;
double masa_admisa;
double x;
double y;
vector <obiect> portbagaj;
public:


    vehicul(){
    volum_admis=0;
    masa_admisa=0;
    x=0;
    y=0;
    stare_actuala=stationar;
    eta=0;
    }

    vehicul(double vol , double mass ,double coord1,double coord2 ){
    volum_admis=vol;
    masa_admisa=mass;
    x=coord1;
    y=coord2;
    stare_actuala=stationar;
    eta=0;
    }

    vehicul(const vehicul & v){
    stare_actuala=v.stare_actuala;
    volum_admis=v.volum_admis;
    masa_admisa=v.masa_admisa;
    x=v.x;
    y=v.y;
    eta=0;
    }

    void move_to(double coord1,double coord2)
    {
      x=coord1;
    y=coord2;
    }
    double get_x(){return x;}
    double get_y() {return y;}
    void load (obiect  h ){ portbagaj.push_back(h);}
    void set_eta (double timp) {eta=timp;stare_actuala=in_mers;}
        double get_eta () {return eta;}
};
class scuter : public vehicul {
int viteza;
tip tip_transport;
public:
    scuter(double vol , double mass ,double coord1,double coord2,tip tip_trans ):vehicul(vol,mass,coord1,coord2){tip_transport=tip_trans; viteza=20;}
    scuter(const scuter & s1 ) : vehicul (s1.volum_admis,s1.masa_admisa,s1.x,s1.y) {tip_transport=s1.tip_transport ; viteza = 20; }
    scuter() : vehicul() { viteza = 0 ; tip_transport=normal;}
};
class masina : public vehicul {
int viteza;
tip tip_transport;
public:
    masina(double vol , double mass ,double coord1,double coord2,tip tip_trans ):vehicul(vol,mass,coord1,coord2){tip_transport=tip_trans; viteza=10;}
    masina(const masina & s1 ) : vehicul (s1.volum_admis,s1.masa_admisa,s1.x,s1.y) {tip_transport=s1.tip_transport ; viteza = 10; }
    masina() : vehicul() { viteza = 0 ; tip_transport=normal;}
};
class duba : public vehicul {
int viteza;
tip tip_transport;
public:
    duba(double vol , double mass ,double coord1,double coord2,tip tip_trans ):vehicul(vol,mass,coord1,coord2){tip_transport=tip_trans; viteza=5;}
    duba(const duba & s1 ) : vehicul (s1.volum_admis,s1.masa_admisa,s1.x,s1.y) {tip_transport=s1.tip_transport ; viteza = 5; }
    duba() : vehicul() { viteza = 0 ; tip_transport=normal;}
};
int main()
{   srand(time(NULL));
        int x,y,i;
   cout<<"Situatie ora 00:00 "<<endl;
   int scutere=rand()%100,masini=rand()%60,dube=rand()%30,dube_frig=rand()%15;
    cout<<"Scutere:"<<scutere<<endl;
    cout<<"Masini:"<<masini<<endl;
    cout<<"Dube:"<<dube<<endl;
    cout<<"Dube frigorifice:"<<dube_frig<<endl;
    scuter s[scutere];
    masina m[masini];
    duba  d[dube];
    duba  d_f[dube_frig];


    for (i=0;i<scutere;i++){
        x=rand()%40;
        y=rand()%40;
        s[i]=scuter(scuter_vol,scuter_mas,x,y,normal);
        cout<<"scuterul "<<i+1<<" la poz  "<< x << " "<< y<<endl;
    }
    for (i=0;i<masini;i++){
        x=rand()%40;
        y=rand()%40;
        m[i]=masina(masina_vol,masina_mas,x,y,normal);
        cout<<"masina "<<i+1<<" la poz  "<< x << " "<< y<<endl;
    }
    for (i=0;i<dube;i++){
        x=rand()%40;
        y=rand()%40;
        d[i]=duba(duba_vol,duba_mas,x,y,normal);
        cout<<"duba "<<i+1<<" la poz  "<< x << " "<< y<<endl;
    }
    for (i=0;i<dube_frig;i++){
        x=rand()%40;
        y=rand()%40;
        d_f[i]=duba(duba_vol,duba_mas,x,y,special);
        cout<<"duba frigorifica "<<i+1<<" la poz  "<< x << " "<< y<<endl;
    }
int count=0;
double r,v;
    while (minute<=1440){
            bool e_speciala=false;
     x=(int)minute/60 ;
     y=minute%60;
     cout<<x << " "<< y<<endl;
    minute++;
    int rnd=rand()%14;
    if (rnd<2)
    {rnd=rand();
            if (rand()%400>370)
        e_speciala=true;
        if(rnd%205<=100)
        { r = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/0.2);
         v = static_cast <double> (rand()) / static_cast <double> (RAND_MAX/20);
        bool sa_livrat=false;
        double x_pick_up = rand()%40,y_pick_up = rand()%40;
        double x_drop_off = rand ()%40 , y_drop_off= rand()%40;
        double client_time =  minute+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1439-minute));
        cout<<"Obiect volum : "<< r << " masa "<< v <<" poz "<< x_pick_up<< " "<< y_pick_up<<"timpul clientului"<< " timpul clientului " << (int)client_time/60 << " : "<<((int)(client_time))%60  <<endl;
        for (i=0 ; i<scutere ; i++){
            double s_x=s[i].get_x();
            double s_y=s[i].get_y();
            double total_dist = sqrt((s_x-x_pick_up)*(s_x-x_pick_up)  +  (s_y-y_pick_up)*(s_y-y_pick_up))+sqrt((x_pick_up-x_drop_off)*(x_pick_up-x_drop_off) + (y_pick_up+y_drop_off)*(y_pick_up+y_drop_off));
            double total_time = (total_dist/20)*60;
            if (total_time<client_time-minute)
            {   if(s[i].get_eta()<=minute){
                s[i].load(obiect(r,v));
                s[i].set_eta(client_time);
                s[i].move_to(x_drop_off,y_drop_off);
                cout<<"Scuterul "<<i+1<<" a plecat la "<<x_pick_up<< " "<< y_pick_up <<" si ajunge la "<<x_drop_off<< " "<<y_drop_off<<" la ora "<<(int)(total_time+minute)/60<<" : "<<((int)(total_time+minute))%60<<endl ;
                sa_livrat=true;
                break;
                }
            }

        }

        if(!sa_livrat)
        cout<<"ne pare rau nu putem onora aceasta livrare"<<endl;

        }
        if(100<=rnd%205 && rnd%205<=160){
          r = 0.2+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/0.8);
         v=static_cast <double> (rand()) / static_cast <double> (RAND_MAX/100);
        bool sa_livrat=false;
         double x_pick_up = rand()%40,y_pick_up = rand()%40;
        double x_drop_off = rand ()%40 , y_drop_off= rand()%40;
        double client_time =  minute+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1440-minute));
        cout<<"Obiect volum : "<< r << " masa "<< v <<" poz "<< x_pick_up<< " "<< y_pick_up<<"timpul clientului"<< " timpul clientului " << (int)client_time/60 << " : "<<((int)(client_time))%60  <<endl;
           for (i=0;i<masini;i++){
            double m_x=s[i].get_x();
            double m_y=s[i].get_y();
            double total_dist =  abs(m_x-x_pick_up)+abs(m_y-y_pick_up) +abs(x_pick_up-x_drop_off) + abs(y_pick_up-y_drop_off) ;
            double total_time = (total_dist/10)*60;

                if (total_time<client_time-minute)
            {   if(m[i].get_eta()<=minute){
                m[i].load(obiect(r,v));
                m[i].set_eta(client_time);
                m[i].move_to(x_drop_off,y_drop_off);

                cout<<"Masina "<<i+1<<" a plecat la "<<x_pick_up<< " "<< y_pick_up <<" si ajunge la "<<x_drop_off<< " "<<y_drop_off<<" la ora "<<(int)(total_time+minute)/60<<" : "<<((int)(total_time+minute))%60<<endl ;
                sa_livrat=true;
                break;
                }
            }


           }
             if(!sa_livrat)
        cout<<"ne pare rau nu putem onora aceasta livrare"<<endl;
        }
if(160<=rnd%205 && rnd%205<=205){
          r = 1.0+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/2.0);
         v=static_cast <double> (rand()) / static_cast <double> (RAND_MAX/300);
        bool sa_livrat=false;
        double x_pick_up = rand()%40,y_pick_up = rand()%40;
        double x_drop_off = rand ()%40 , y_drop_off= rand()%40;
        double client_time =  minute+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1440-minute));
        cout<<"Obiect volum : "<< r << " masa "<< v <<" poz "<< x_pick_up<< " "<< y_pick_up<<"timpul clientului"<< " timpul clientului " << (int)client_time/60 << " : "<<((int)(client_time))%60  <<endl;
         for (i=0;i<dube;i++){
            double d_x=s[i].get_x();
            double d_y=s[i].get_y();
            double total_dist =  abs(d_x-x_pick_up)+abs(d_y-y_pick_up) +abs(x_pick_up-x_drop_off) + abs(y_pick_up-y_drop_off) ;
            double total_time = (total_dist/5)*60;
                if (total_time<client_time-minute)
            {   if(d[i].get_eta()<=minute){
                d[i].load(obiect(r,v));
                d[i].set_eta(client_time);
                d[i].move_to(x_drop_off,y_drop_off);

                cout<<"Duba "<<i+1<<" a plecat la "<<x_pick_up<< " "<< y_pick_up <<" si ajunge la "<<x_drop_off<< " "<<y_drop_off<<" la ora "<<(int)(total_time+minute)/60<<" : "<<((int)(total_time+minute))%60<<endl ;
                sa_livrat=true;
                break;
                }
            }


         }
             if(!sa_livrat)
        cout<<"ne pare rau nu putem onora aceasta livrare"<<endl;

        }

   if(e_speciala){
          r = 1.0+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/2.0);
         v=static_cast <double> (rand()) / static_cast <double> (RAND_MAX/300);
        bool sa_livrat=false;
        double x_pick_up = rand()%40,y_pick_up = rand()%40;
        double x_drop_off = rand ()%40 , y_drop_off= rand()%40;
        double client_time =  minute+static_cast <double> (rand()) / static_cast <double> (RAND_MAX/(1440-minute));

        cout<<"Obiect volum : "<< r << " masa "<< v <<" poz "<< x_pick_up<< " "<< y_pick_up<<"timpul clientului"<< " timpul clientului " << (int)client_time/60 << " : "<<((int)(client_time))%60  <<endl;
         for (i=0;i<dube_frig;i++){
            double d_x=s[i].get_x();
            double d_y=s[i].get_y();
            double total_dist =  abs(d_x-x_pick_up)+abs(d_y-y_pick_up) +abs(x_pick_up-x_drop_off) + abs(y_pick_up-y_drop_off) ;
            double total_time = (total_dist/5)*60;
                if (total_time<client_time-minute)
            {   if(d_f[i].get_eta()<=minute){
                d_f[i].load(obiect(r,v));
                d_f[i].set_eta(client_time);
                d_f[i].move_to(x_drop_off,y_drop_off);
                cout<<"Duba Frigorifica "<<i+1<<" a plecat la "<<x_pick_up<< " "<< y_pick_up <<" si ajunge la "<<x_drop_off<< " "<<y_drop_off<<" la ora "<<(int)(total_time+minute)/60<<" : "<<((int)(total_time+minute))%60 <<endl;

                sa_livrat=true;
                break;
                }
            }


         }
             if(!sa_livrat)
        cout<<"ne pare rau nu putem onora aceasta livrare"<<endl;

        }

cin.get();
    }
       if (x==23 and y==59)
       break;

    }


    return 0;
}
