#include "ej1.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Time::Time(){
    hora = 0;
    minuto = 0;
    segundo = 0;
    periodo = "a.m.";
}

Time::Time(int h){
    hora = h;
    minuto = 0;
    segundo = 0;
    periodo = "a.m.";
}

Time::Time(int h, int m){
    hora = h;
    minuto = m;
    segundo = 0;
    periodo = "a.m.";
}

Time::Time(int h, int m, int s){
    hora = h;
    minuto = m;
    segundo = s;
    periodo = "a.m.";
}

Time::Time(int h, int m, int s, string p){
    hora = h;
    minuto = m;
    segundo = s;
    periodo = p;
}

void Time::mostrarHora12() const {
    cout << setfill('0')
         << setw(2) << hora << "h, "
         << setw(2) << minuto << "m, "
         << setw(2) << segundo << "s "
         << periodo << endl;
}

void Time::mostrarHora24() const {
    int hora24 = (periodo == "p.m." && hora != 12) ? hora + 12 : hora;
    hora24 = (periodo == "a.m." && hora == 12) ? 0 : hora24;
    cout << setfill('0')
         << setw(2) << hora24 << "h, "
         << setw(2) << minuto << "m, "
         << setw(2) << segundo << "s" << endl;
}

void Time::setHora(int h){
    if (h >= 0 && h <= 12){
        hora = h;
    } else {
        cout << "Hora no valida" << endl;
    }
}

void Time::setMinuto(int m){
    if (m >= 0 && m <= 59){
        minuto = m;
    } else {
        cout << "Minutos no validos" << endl;
    }
}

void Time::setSegundo(int s){
    if (s >= 0 && s <= 59){
        segundo = s;
    } else {
        cout << "Segundos no validos" << endl;
    }
}

void Time::setPeriodo(string p){
    if (p == "a.m." || p == "p.m."){
        periodo = p;
    } else {
        cout << "Periodo no valido" << endl;
    }
}


int main(){
    system("clear");
    int opcion;
    int hora;
    int minuto;
    int segundo;
    string periodo;
    Time reloj;

    while(true){
        cout << "Seleccione una opcion:" << endl;
        cout << "0. Salir" << endl;
        cout << "1. Inicializa el reloj en 00h, 00m, 00s a.m." << endl;
        cout << "2. Inicializa el reloj en hh, 00m, 00s a.m." << endl;
        cout << "3. Inicializa el reloj en hh, mm, 00s a.m." << endl;
        cout << "4. Inicializa el reloj en hh, mm, ss a.m." << endl;
        cout << "5. Inicializa el reloj en hh, mm, ss p.m./a.m." << endl;
        cout << "6. Editar Reloj" << endl;
        cout << "7. Mostrar la hora" << endl;
        cout << "Introduzca su opcion: ";
        cin >> opcion;

        switch(opcion){
            case 0:
                system("clear");
                cout << "Saliendo..." << endl;
                return 0;
            case 1:
                reloj = Time();
                system("clear");
                cout << "Reloj configurado correctamente!" << endl;
                break;
            case 2:
                system("clear");
                while (true) {
                    cout << "Introduzca la hora: ";
                    cin >> hora;
                    if (hora < 0 || hora > 12){
                        system("clear");
                        cout << "Hora no valida. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                reloj.setHora(hora);
                system("clear");
                cout << "Reloj configurado correctamente!" << endl;
                break;
            case 3:
                system("clear");
                while (true) {
                    cout << "Introduzca la hora: ";
                    cin >> hora;
                    if (hora < 0 || hora > 12){
                        system("clear");
                        cout << "Hora no valida. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca los minutos: ";
                    cin >> minuto;
                    if (minuto < 0 || minuto > 59){
                        system("clear");
                        cout << "Minutos no validos. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                reloj.setHora(hora);
                reloj.setMinuto(minuto);
                system("clear");
                cout << "Reloj configurado correctamente!" << endl;
                break;
            case 4:
                system("clear");
                while (true) {
                    cout << "Introduzca la hora: ";
                    cin >> hora;
                    if (hora < 0 || hora > 12){
                        system("clear");
                        cout << "Hora no valida. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca los minutos: ";
                    cin >> minuto;
                    if (minuto < 0 || minuto > 59){
                        system("clear");
                        cout << "Minutos no validos. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca los segundos: ";
                    cin >> segundo;
                    if (segundo < 0 || segundo > 59){
                        system("clear");
                        cout << "Segundos no validos. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                reloj.setHora(hora);
                reloj.setMinuto(minuto);
                reloj.setSegundo(segundo);
                system("clear");
                cout << "Reloj configurado correctamente!" << endl;
                break;
            case 5:
                system("clear");
                while (true) {
                    cout << "Introduzca la hora: ";
                    cin >> hora;
                    if (hora < 0 || hora > 12){
                        system("clear");
                        cout << "Hora no valida. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca los minutos: ";
                    cin >> minuto;
                    if (minuto < 0 || minuto > 59){
                        system("clear");
                        cout << "Minutos no validos. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca los segundos: ";
                    cin >> segundo;
                    if (segundo < 0 || segundo > 59){
                        system("clear");
                        cout << "Segundos no validos. Intente de nuevo." << endl;
                    } else {
                        break;
                    }
                }
                while (true) {
                    cout << "Introduzca el periodo: " << endl;
                    cout << "0) a.m." << endl;
                    cout << "1) p.m." << endl;
                    cin >> periodo;
                    if (periodo == "0" || periodo == "1") {
                        break;
                    } else {
                        system("clear");
                        cout << "Periodo no valido. Intente de nuevo." << endl;
                    }
                }
                if (periodo == "0") {
                    periodo = "a.m.";
                } else {
                    periodo = "p.m.";
                }
                reloj.setHora(hora);
                reloj.setMinuto(minuto);
                reloj.setSegundo(segundo);
                reloj.setPeriodo(periodo);
                system("clear");
                cout << "Reloj configurado correctamente!" << endl;
                break;
            case 6:
                system("clear");
                while (true) {
                    cout << "Seleccione la parte del reloj que desea editar:" << endl;
                    cout << "1. Hora" << endl;
                    cout << "2. Minuto" << endl;
                    cout << "3. Segundo" << endl;
                    cout << "4. Periodo" << endl;
                    cout << "5. Salir" << endl;
                    cout << "Introduzca su opcion: ";
                    cin >> opcion;
                    system("clear");
                    if (opcion == 5){
                        break;
                    }
                    switch(opcion){
                        case 1:
                            while (true) {
                                cout << "Introduzca la hora: ";
                                cin >> hora;
                                if (hora < 0 || hora > 12){
                                    system("clear");
                                    cout << "Hora no valida. Intente de nuevo." << endl;
                                } else {
                                    break;
                                }
                            }
                            reloj.setHora(hora);
                            system("clear");
                            cout << "Hora editada correctamente!" << endl;
                            break;
                        case 2:
                            while (true) {
                                cout << "Introduzca los minutos: ";
                                cin >> minuto;
                                if (minuto < 0 || minuto > 59){
                                    system("clear");
                                    cout << "Minutos no validos. Intente de nuevo." << endl;
                                } else {
                                    break;
                                }
                            }
                            reloj.setMinuto(minuto);
                            system("clear");
                            cout << "Minutos editados correctamente!" << endl;
                            break;
                        case 3:
                            while (true) {
                                cout << "Introduzca los segundos: ";
                                cin >> segundo;
                                if (segundo < 0 || segundo > 59){
                                    system("clear");
                                    cout << "Segundos no validos. Intente de nuevo." << endl;
                                } else {
                                    break;
                                }
                            }
                            reloj.setSegundo(segundo);
                            system("clear");
                            cout << "Segundos editados correctamente!" << endl;
                            break;
                        case 4:
                            while (true) {
                                cout << "Introduzca el periodo: " << endl;
                                cout << "0) a.m." << endl;
                                cout << "1) p.m." << endl;
                                cin >> periodo;
                                if (periodo == "0" || periodo == "1") {
                                    break;
                                } else {
                                    system("clear");
                                    cout << "Periodo no valido. Intente de nuevo." << endl;
                                }
                            }
                            if (periodo == "0") {
                                periodo = "a.m.";
                            } else {
                                periodo = "p.m.";
                            }
                            reloj.setPeriodo(periodo);
                            system("clear");
                            cout << "Periodo editado correctamente!" << endl;
                            break;
                        default:
                            system("clear");
                            cout << "Opcion no valida" << endl;
                            break;
                    }
                }
                break;                
            case 7:
                system("clear");
                while (true){
                    cout << "Seleccione el formato de hora:" << endl;
                    cout << "1. Formato 12 horas" << endl;
                    cout << "2. Formato 24 horas" << endl;
                    cout << "Introduzca su opcion: ";
                    cin >> opcion;
                    system("clear");
                    if (opcion == 1){
                        cout << "Hora en formato 12 horas: ";
                        reloj.mostrarHora12();
                        break;
                    } else if (opcion == 2){
                        cout << "Hora en formato 24 horas: ";
                        reloj.mostrarHora24();
                        break;
                    } else {
                        system("clear");
                        cout << "Opcion no valida" << endl;
                    }
                }
                break;
            default:
                system("clear");
                cout << "Opcion no valida" << endl;
                break;
        }
    }
    return 0;
}
