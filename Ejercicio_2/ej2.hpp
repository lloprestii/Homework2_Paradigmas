#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Estudiante {
private:
    string nombreCompleto;
    int legajo;
    vector<pair<string, float>> cursos;

public:
    // Constructor
    Estudiante(string nombre, int legajo);
    // Agregar curso y nota
    void agregarCurso(string curso, float nota);
    // Obtener nombre completo
    string getNombreCompleto() const;
    // Obtener legajo
    int getLegajo() const;
    // Calcular promedio de notas
    float calcularPromedio() const;
    // Obtener promedio
    float getPromedio() const;
    // Sobrecarga de operador para comparar estudiantes
    friend bool operator<(const Estudiante& e1, const Estudiante& e2);
    // Sobrecarga de operador para imprimir estudiante
    friend ostream& operator<<(ostream& os, const Estudiante& e);
};

class Curso {
private:
    string nombreCurso;
    vector<Estudiante*> estudiantes;
    int size;
    int maxSize;

public:
    // Constructor de copia
    Curso(string nombre, const Curso &other);
    // Constructor
    Curso(string nombre, int maxSize);
    // Agregar estudiante
    void agregarEstudiante(Estudiante* estudiante);
    // Eliminar estudiante
    void eliminarEstudiante(int legajo);
    // Buscar estudiante por legajo
    bool seEncuentraEstudiante(int legajo) const;
    // Mostrar estudiantes
    void mostrarEstudiantes() const;
    // Mostrar promedios
    void mostrarPromedios() const;
    // Verificar si el curso está completo
    bool estaCompleto() const;
    // Ordenar estudiantes
    void ordenarEstudiantes();
    // Copiar estudiantes de otro curso
    void copiarEstudiantes(const Curso& otroCurso);
    // Mostrar estudiantes ordenados
    void mostrarEstudiantesOrdenados() const;
    // Sobrecarga de operador para imprimir curso
    friend ostream& operator<<(ostream& os, const Curso& c);
};

struct CursoRegistro {
    string nombre;
    Curso* curso;
};

/*
La relacion entre curso y estudiante es de agregacion. Esto se debe a que un curso contiene estudiantes (almacenados como punteros en un vector) y los estudiantes pueden existir de forma independiente, pudiendo ser compartidos entre distintos cursos.
*/