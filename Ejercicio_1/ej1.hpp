#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
    public:
        int hora;
        int minuto;
        int segundo;
        string periodo;
        
        Time();
        Time(int h);
        Time(int h, int m);
        Time(int h, int m, int s);
        Time(int h, int m, int s, string p);
        
        void mostrarHora12() const;
        void mostrarHora24() const;
        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);
        void setPeriodo(string p);
    };


