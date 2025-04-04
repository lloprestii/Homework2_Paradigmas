#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "ej2.hpp"

using namespace std;

Estudiante::Estudiante(string nombre, int legajo) {
    nombreCompleto = nombre;
    this->legajo = legajo;
}

void Estudiante::agregarCurso(string curso, float nota) {
    cursos.push_back(make_pair(curso, nota));
    cout << "Curso agregado: " << curso << " con nota: " << nota << endl;
}

string Estudiante::getNombreCompleto() const {
    return nombreCompleto;
}

int Estudiante::getLegajo() const {
    return legajo;
}

float Estudiante::calcularPromedio() const {
    if (cursos.empty()) {
        return 0.0;
    }
    float suma = 0.0;
    for (unsigned int i = 0; i < cursos.size(); i++) {
        suma += cursos[i].second;
    }
    return suma / cursos.size();
}

float Estudiante::getPromedio() const {
    return calcularPromedio();
}

bool operator<(const Estudiante &e1, const Estudiante &e2) {
    return e1.getNombreCompleto() < e2.getNombreCompleto();
}

ostream& operator<<(ostream& os, const Estudiante &e) {
    os << "Nombre: " << e.getNombreCompleto() << ", Legajo: " << e.getLegajo();
    return os;
}

Curso::Curso(string nombre, const Curso &other) : nombreCurso(nombre), estudiantes(other.estudiantes), size(other.size), maxSize(other.maxSize) {}

Curso::Curso(string nombre, int maxSize) : nombreCurso(nombre), size(0), maxSize(maxSize) {}

void Curso::agregarEstudiante(Estudiante* estudiante) {
    if (!estaCompleto()) {
        estudiantes.push_back(estudiante);
        size++;
        cout << "Estudiante agregado: " << estudiante->getNombreCompleto() << endl;
        cout << "Tamaño actual del curso: " << size << endl;
    } else {
        cout << "El curso está completo." << endl;
    }
}

void Curso::eliminarEstudiante(int legajo) {
    for (int i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i]->getLegajo() == legajo) {
            delete estudiantes[i];
            estudiantes.erase(estudiantes.begin() + i);
            cout << "Estudiante con legajo " << legajo << " eliminado." << endl;
            size--;
            break;
        }
    }
}

bool Curso::seEncuentraEstudiante(int legajo) const {
    for (unsigned int i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i]->getLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

void Curso::mostrarEstudiantes() const {
    for (unsigned int i = 0; i < estudiantes.size(); i++) {
        cout << *estudiantes[i] << endl;
    }
}

void Curso::mostrarPromedios() const {
    for (unsigned int i = 0; i < estudiantes.size(); i++) {
        cout << "Nombre: " << estudiantes[i]->getNombreCompleto() 
             << ", Promedio: " << estudiantes[i]->getPromedio() << endl;
    }
}

bool Curso::estaCompleto() const {
    return size >= maxSize;
}

void Curso::ordenarEstudiantes() {
    sort(estudiantes.begin(), estudiantes.end(), [](Estudiante* e1, Estudiante* e2) {
        return *e1 < *e2;
    });
}

void Curso::copiarEstudiantes(const Curso& otroCurso) {
    for (unsigned int i = 0; i < otroCurso.estudiantes.size(); i++) {
        agregarEstudiante(otroCurso.estudiantes[i]);
    }
}

void Curso::mostrarEstudiantesOrdenados() const {
    vector<Estudiante*> temp = estudiantes;
    sort(temp.begin(), temp.end(), [](Estudiante* e1, Estudiante* e2) {
        return *e1 < *e2;
    });
    for (unsigned int i = 0; i < temp.size(); i++) {
        cout << *temp[i] << endl;
    }
}

ostream& operator<<(ostream& os, const Curso& c) {
    vector<Estudiante*> temp = c.estudiantes;
    sort(temp.begin(), temp.end(), [](Estudiante* e1, Estudiante* e2) {
        return *e1 < *e2;
    });
    for (unsigned int i = 0; i < temp.size(); i++) {
        os << *temp[i] << endl;
    }
    return os;
}

int main(){
    vector<CursoRegistro> cursos;
    vector<Estudiante*> alumnos;
    int opcion;
    
    while(true) {
        cout << "----------------------------------------" << endl;
        cout << "            MENU PRINCIPAL" << endl;
        cout << "----------------------------------------" << endl;
        cout << "1. Administrar Cursos" << endl;
        cout << "2. Administrar Alumnos" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(1000, '\n');
        system("clear");
        
        if(opcion == 1) {
            int opCursos;
            while(true) {
                cout << "----------------------------------------" << endl;
                cout << "             MENU DE CURSOS" << endl;
                cout << "----------------------------------------" << endl;
                cout << "1. Crear curso" << endl;
                cout << "2. Listar cursos" << endl;
                cout << "3. Seleccionar curso para administrar" << endl;
                cout << "4. Regresar al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opCursos;
                cin.ignore(1000, '\n');
                system("clear");
                
                if(opCursos == 1) {
                    string nombreCurso;
                    int maxEstudiantes;
                    cout << "Ingrese el nombre del curso: ";
                    getline(cin, nombreCurso);
                    cout << "Ingrese el maximo de estudiantes: ";
                    cin >> maxEstudiantes;
                    cin.ignore(1000, '\n');
                    Curso* nuevoCurso = new Curso(nombreCurso, maxEstudiantes);
                    CursoRegistro reg;
                    reg.nombre = nombreCurso;
                    reg.curso = nuevoCurso;
                    cursos.push_back(reg);
                    cout << "Curso '" << nombreCurso << "' creado." << endl;
                }
                else if(opCursos == 2) {
                    if(cursos.size() == 0)
                        cout << "No hay cursos creados." << endl;
                    else {
                        cout << "Cursos:" << endl;
                        for(unsigned int i = 0; i < cursos.size(); i++){
                            cout << i+1 << ". " << cursos[i].nombre << endl;
                        }
                    }
                }
                else if(opCursos == 3) {
                    if(cursos.size() == 0) {
                        cout << "No hay cursos creados." << endl;
                    } else {
                        cout << "Seleccione el curso a administrar:" << endl;
                        for(unsigned int i = 0; i < cursos.size(); i++){
                            cout << i+1 << ". " << cursos[i].nombre << endl;
                        }
                        int idx;
                        cin >> idx;
                        cin.ignore(1000, '\n');
                        if(idx < 1 || idx > cursos.size()){
                            cout << "Opcion invalida." << endl;
                        } else {
                            Curso* cursoActual = cursos[idx-1].curso;
                            int opAdminCurso;
                            while(true) {
                                cout << "----------------------------------------" << endl;
                                cout << "   Administrando curso: " << cursos[idx-1].nombre << endl;
                                cout << "----------------------------------------" << endl;
                                cout << "1. Agregar estudiante al curso" << endl;
                                cout << "2. Eliminar estudiante del curso" << endl;
                                cout << "3. Mostrar estudiantes (orden original)" << endl;
                                cout << "4. Mostrar estudiantes ordenados" << endl;
                                cout << "5. Mostrar promedios" << endl;
                                cout << "6. Ordenar estudiantes internamente" << endl;
                                cout << "7. Regresar al menu de cursos" << endl;
                                cout << "Ingrese una opcion: ";
                                cin >> opAdminCurso;
                                cin.ignore(1000, '\n');
                                system("clear");
                                
                                if(opAdminCurso == 1) {
                                    if(alumnos.size() == 0) {
                                        cout << "No hay alumnos registrados globalmente." << endl;
                                    } else {
                                        cout << "Lista de alumnos disponibles:" << endl;
                                        for(unsigned int j = 0; j < alumnos.size(); j++){
                                            cout << j+1 << ". " << alumnos[j]->getNombreCompleto() 
                                                 << " (Legajo: " << alumnos[j]->getLegajo() << ")" << endl;
                                        }
                                        cout << "Ingrese el numero del alumno a agregar: ";
                                        int num;
                                        cin >> num;
                                        cin.ignore(1000, '\n');
                                        if(num < 1 || num > alumnos.size()){
                                            cout << "Opcion invalida." << endl;
                                        } else {
                                            cursoActual->agregarEstudiante(alumnos[num-1]);
                                        }
                                    }
                                }
                                else if(opAdminCurso == 2) {
                                    cout << "Ingrese el legajo del estudiante a eliminar del curso: ";
                                    int leg;
                                    cin >> leg;
                                    cin.ignore(1000, '\n');
                                    cursoActual->eliminarEstudiante(leg);
                                }
                                else if(opAdminCurso == 3) {
                                    cout << "Estudiantes (orden de ingreso):" << endl;
                                    cursoActual->mostrarEstudiantes();
                                }
                                else if(opAdminCurso == 4) {
                                    cout << "Estudiantes ordenados:" << endl;
                                    cout << *cursoActual;
                                }
                                else if(opAdminCurso == 5) {
                                    cout << "Promedios de los estudiantes:" << endl;
                                    cursoActual->mostrarPromedios();
                                }
                                else if(opAdminCurso == 6) {
                                    cursoActual->ordenarEstudiantes();
                                    cout << "Estudiantes ordenados internamente." << endl;
                                }
                                else if(opAdminCurso == 7) {
                                    break;
                                }
                                else {
                                    cout << "Opcion invalida." << endl;
                                }
                            }
                        }
                    }
                }
                else if(opCursos == 4) {
                    break;
                }
                else {
                    cout << "Opcion invalida." << endl;
                }
                cout << "\nPresione ENTER para continuar...";
                cin.get();
                system("clear");
            }
        }
        else if(opcion == 2) {
            int opAlumnos;
            while(true) {
                cout << "----------------------------------------" << endl;
                cout << "            MENU DE ALUMNOS" << endl;
                cout << "----------------------------------------" << endl;
                cout << "1. Crear alumno" << endl;
                cout << "2. Listar alumnos" << endl;
                cout << "3. Asignar curso y nota a un alumno" << endl;
                cout << "4. Eliminar alumno" << endl;
                cout << "5. Regresar al menu principal" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opAlumnos;
                cin.ignore(1000, '\n');
                system("clear");
                
                if(opAlumnos == 1) {
                    string nombreAlum;
                    int legajo;
                    cout << "Ingrese el nombre del alumno: ";
                    getline(cin, nombreAlum);
                    cout << "Ingrese el legajo del alumno: ";
                    cin >> legajo;
                    cin.ignore(1000, '\n');
                    Estudiante* nuevoAlum = new Estudiante(nombreAlum, legajo);
                    alumnos.push_back(nuevoAlum);
                    cout << "Alumno '" << nombreAlum << "' creado." << endl;
                }
                else if(opAlumnos == 2) {
                    if(alumnos.size() == 0)
                        cout << "No hay alumnos registrados." << endl;
                    else {
                        cout << "Alumnos registrados:" << endl;
                        for(unsigned int i = 0; i < alumnos.size(); i++){
                            cout << i+1 << ". " << alumnos[i]->getNombreCompleto() 
                                 << " (Legajo: " << alumnos[i]->getLegajo() << ")" << endl;
                        }
                    }
                }
                else if(opAlumnos == 3) {
                    if(alumnos.size() == 0) {
                        cout << "No hay alumnos registrados." << endl;
                    } else {
                        cout << "Seleccione el alumno por su numero:" << endl;
                        for(unsigned int i = 0; i < alumnos.size(); i++){
                            cout << i+1 << ". " << alumnos[i]->getNombreCompleto() 
                                 << " (Legajo: " << alumnos[i]->getLegajo() << ")" << endl;
                        }
                        int num;
                        cin >> num;
                        cin.ignore(1000, '\n');
                        if(num < 1 || num > alumnos.size()){
                            cout << "Opcion invalida." << endl;
                        } else {
                            string nomCurso;
                            float nota;
                            cout << "Ingrese el nombre del curso a asignar: ";
                            getline(cin, nomCurso);
                            cout << "Ingrese la nota para el curso: ";
                            cin >> nota;
                            cin.ignore(1000, '\n');
                            alumnos[num-1]->agregarCurso(nomCurso, nota);
                        }
                    }
                }
                else if(opAlumnos == 4) {
                    if(alumnos.size() == 0) {
                        cout << "No hay alumnos registrados." << endl;
                    } else {
                        cout << "Ingrese el legajo del alumno a eliminar: ";
                        int leg;
                        cin >> leg;
                        cin.ignore(1000, '\n');
                        bool encontrado = false;
                        for(unsigned int i = 0; i < alumnos.size(); i++){
                            if(alumnos[i]->getLegajo() == leg) {
                                delete alumnos[i];
                                alumnos.erase(alumnos.begin() + i);
                                cout << "Alumno con legajo " << leg << " eliminado." << endl;
                                encontrado = true;
                                break;
                            }
                        }
                        if(!encontrado)
                            cout << "No se encontro alumno con ese legajo." << endl;
                    }
                }
                else if(opAlumnos == 5) {
                    break;
                }
                else {
                    cout << "Opcion invalida." << endl;
                }
                cout << "\nPresione ENTER para continuar...";
                cin.get();
                system("clear");
            }
        }
        else if(opcion == 3) {
            cout << "Saliendo del programa..." << endl;
            break;
        }
        else {
            cout << "Opcion invalida." << endl;
        }
        cout << "\nPresione ENTER para continuar...";
        cin.get();
        system("clear");
    }
    
    for(unsigned int i = 0; i < cursos.size(); i++){
        delete cursos[i].curso;
    }
    for(unsigned int i = 0; i < alumnos.size(); i++){
        delete alumnos[i];
    }
    
    return 0;
}
