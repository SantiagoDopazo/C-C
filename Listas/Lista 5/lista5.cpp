#include <iostream>
#include <stdio.h>
#include <cstring>

#define RUTA_ALUMNOS "archivoalumnos"
#define RUTA_MATERIAS "archivomaterias.dato"
using namespace std;


struct Materia
{
    char nombreMateria[50];
    char fechaAprobacion[11];
    int legajo;
    int nota;
    int libro;
    int folio;
};

struct NodoListaSEMateria
{
    Materia info;
    NodoListaSEMateria *sgte;
};

struct Alumno
{
    char nombre[50];
    char apellido[50];
    char dni[50];
    int legajo;
    int codcarrera;
};

struct NodoListaSEAlumno
{
    Alumno info;
    NodoListaSEAlumno *sgte;
    NodoListaSEMateria *listaMaterias;
};

void ListaAlumnoInsertarSiguiente (NodoListaSEAlumno *&lista, Alumno x)
{
    NodoListaSEAlumno *aux = new NodoListaSEAlumno();
    aux->info = x;

    if(lista != NULL)
    {
        aux->sgte = lista->sgte;
        lista->sgte = aux;
    }
    else
    {
        aux->sgte = NULL;
        lista = aux;
    }

    return;
}

void ListaMateriaInsertarSiguiente(NodoListaSEMateria *lista, Materia m)
{
    NodoListaSEMateria *aux = new NodoListaSEMateria();
    aux->info = m;

    if(lista != NULL)
    {
        aux->sgte = lista->sgte;
        lista->sgte = aux;
    }
    else
    {
        aux->sgte = NULL;
        lista = aux;
    }

    return;
}

void ListaAlumnoInsertarFinal(NodoListaSEAlumno *&lista, Alumno a)
{
    NodoListaSEAlumno *aux = NULL;
    aux = lista;
    while(aux != NULL && aux->sgte != NULL)
    {
        aux = aux->sgte;
    }
    if(aux != NULL)
    {
        ListaAlumnoInsertarSiguiente(aux, a);
    }
    else
    {
        ListaAlumnoInsertarSiguiente(lista, a);
    }
    return;
}

void CargarDatosPrueba(void)
{
    FILE *f;
    f = fopen(RUTA_ALUMNOS, "wb");
    Alumno x;
    if(f != NULL)
    {
        x.codcarrera = 10;
        x.legajo = 111111;
        strcpy(x.apellido, "DOPAZO");
        strcpy(x.nombre, "SANTIAGO");

        fwrite(&x, sizeof(Alumno), 1, f);

        x.codcarrera = 10;
        x.legajo = 222222;
        strcpy(x.apellido, "GARECA");
        strcpy(x.nombre, "MAGALI");

        fwrite(&x, sizeof(Alumno), 1, f);

        x.codcarrera = 10;
        x.legajo = 333333;
        strcpy(x.apellido, "TAURASI");
        strcpy(x.nombre, "NICOLAS");

        fwrite(&x, sizeof(Alumno), 1, f);

        fclose(f);
        cout << "Se cargo el archivo con exito" << endl;
   
    }
    else
    {
        cout << "Error: no se puede crear el archivo" << endl;
    }

    return;
}

void CargarMateriasPrueba(void)
{
    FILE *f;
    Materia x;

    f = fopen(RUTA_MATERIAS, "wb");

    if (f != NULL)
    {
        strcpy(x.nombreMateria, "Algoritmos y Estructura de Datos");
        strcpy(x.fechaAprobacion, "2022-11-28");
        x.libro = 10;
        x.folio = 114;
        x.nota = 8;
        x.legajo = 222222;
        fwrite(&x, sizeof(Materia), 1, f);

        strcpy(x.nombreMateria, "Arquitectura Computadoras");
        strcpy(x.fechaAprobacion, "2022-11-21");
        x.libro = 41;
        x.folio = 19;
        x.nota = 9; 
        x.legajo = 111111;
        fwrite(&x, sizeof(Materia), 1, f);

        strcpy(x.nombreMateria, "Matematica Discreta");
        strcpy(x.fechaAprobacion, "2022-11-30");
        x.libro = 21;
        x.folio = 711;
        x.nota = 7;
        x.legajo = 111111;
        fwrite(&x, sizeof(Materia), 1, f);

        cout << "Se cargo el archivo con exito" << endl;
    }
    else
    {
        cout << "Error: no se puede crear el archivo" << endl;
    }
    return;
}

void BorrarListaAlumnos(NodoListaSEAlumno *&lista)
{
    NodoListaSEAlumno *anterior;
    NodoListaSEAlumno *paux;

    while(lista != NULL)
    {
        anterior = NULL;
        paux = lista;
        while(paux && paux->sgte)
        {
            anterior = paux;
            paux = paux->sgte;
        }
        if(paux != NULL)
        {
            delete paux;
            if(anterior != NULL)
            {
                anterior->sgte = NULL;
            }
            else
            {
                lista = NULL;
            }
        }
    }

    return;
}

NodoListaSEAlumno *BuscarLegajo(NodoListaSEAlumno *lista, int legajo)
{
    while(lista != NULL && lista->info.legajo != legajo)
    {
        lista = lista->sgte;
    }

    return lista;
}

void ListaAlumnoListar(NodoListaSEAlumno *lista)
{
    while(lista != NULL)
    {
        cout << "DATOS DEL ALUMNO " << endl;
        cout << "Apellido y Nombre: " << lista->info.apellido << ", " << lista->info.nombre << endl;
        cout << "DNI: " << lista->info.dni << endl;
        cout << "Legajo: " << lista->info.legajo << endl;
        cout << "Carrera: " << lista->info.codcarrera << endl;

        lista = lista->sgte;
    }

    return;
}

void MostrarAlumno(Alumno a)
{
    cout << "DATOS DEL ALUMNO " << endl;
    cout << "Apellido y Nombre: " << a.apellido << ", " << a.nombre << endl;
    cout << "DNI: " << a.dni << endl;
    cout << "Legajo: " << a.legajo << endl;
    cout << "Carrera: " << a.codcarrera << endl;
    return;    
}

void MostrarMaterias (NodoListaSEMateria *lista)
{
    while(lista != NULL)
    {
        cout << "DATOS DEL ALUMNO " << endl;
        cout << "Materia: " << lista->info.nombreMateria << endl;
        cout << "Aprobada: " << lista->info.fechaAprobacion << endl;
        cout << "Libro: " << lista->info.libro << endl;
        cout << "folio: " << lista->info.folio << endl;
        cout << "Nota: " << lista->info.nota << endl;

        lista = lista->sgte;
    }
    return;
}

int mostrarmenu()
{
    int opcion = 0;

    cout << "Ingrese una opcion: " << endl;
    cout << "0 -Subir archivos de prueba" << endl;
    cout << "1 - Buscar alumno por legajo" << endl;
    cout << "2 - Listar materias aprobadas del alumno" << endl;
    cout << "3 - Listar el promedio de un alumno" << endl;
    cout << "4 - Agregar alumno" << endl;
    cout << "5 - Agregar materia" << endl;
    cout << "6 - Listar todos los alumnos" << endl;
    cout << "7 - Salir" << endl;

    cin >> opcion;

    return opcion;
}

void CargarArchivos(NodoListaSEAlumno *&lista)
{
    FILE *f;
    Materia m;
    Alumno a;
    NodoListaSEAlumno *aux = NULL;

    f = fopen(RUTA_ALUMNOS, "rb");
    fread(&a, sizeof(Alumno), 1, f);

    while(feof(f) == 0)
    {
        ListaAlumnoInsertarSiguiente(lista, a);
        fread(&a, sizeof(Alumno), 1, f);
    }
    fclose(f);

    f = fopen(RUTA_MATERIAS, "rb");
    fread(&m, sizeof(Materia), 1, f);

    while(feof(f) == 0)
    {
        aux = BuscarLegajo(lista, m.legajo);

        if(aux != NULL)
        {
            ListaMateriaInsertarSiguiente(aux->listaMaterias, m);
        }
        fread (&m , sizeof(Materia), 1, f);
    }
    fclose(f);
    return;
}

int main ()
{
    NodoListaSEAlumno *lAlumnos = NULL;
    NodoListaSEAlumno *auxa = NULL;
    NodoListaSEMateria *auxm = NULL;
    int opcion = 0, legajo = 0, sum = 0, i = 0;
    char c;

    do
    {
        opcion = mostrarmenu();
        switch(opcion)
        {
            case 0:
                CargarDatosPrueba();
                CargarMateriasPrueba();
                CargarArchivos(lAlumnos);
                cout << "Se cargaron correctamente" <<endl;
            break;

            case 1:
                cout << "Inserte legajo" << endl;
                cin >> legajo;
                auxa = BuscarLegajo(lAlumnos, legajo);
                if(auxa != NULL)
                {
                    MostrarAlumno(auxa->info);
                }
                else
                {
                    cout << "No se encontro el alumno buscado" << endl;
                }
            break;

            case 2:
                cout << "Inserte legajo" << endl;
                cin >> legajo;
                auxa = BuscarLegajo(lAlumnos, legajo);
                if(auxa != NULL)
                {
                    MostrarAlumno (auxa->info);
                    MostrarMaterias (auxa->listaMaterias);
                }
                else
                {
                    cout << "No se encontro el alumno buscado" << endl;
                }
            break;

            case 3:
                cout << "Inserte legajo" << endl;
                cin >> legajo;
                auxa = BuscarLegajo(lAlumnos, legajo);
                if(auxa != NULL)
                {
                    auxm = auxa->listaMaterias;
                    while(auxm != NULL)
                    {
                        sum += auxm->info.nota;
                        i ++;
                        auxm = auxm->sgte;
                    }
                    if(i > 0)
                    {
                        cout << "El promedio es: " << sum/i << endl;

                    }
                    else
                    {
                        cout << "El alumno no tiene matieras cargadas" << endl;
                    }
                }
                else
                {
                    cout << "No se encontro el alumno buscado" << endl;
                }
            break;

            case 4:
                Alumno nuevoAlumno;
                cout << "Ingrese los datos del alumno" << endl;
                cout << "Legajo: ";
                cin >> nuevoAlumno.legajo;
                if(BuscarLegajo(lAlumnos, nuevoAlumno.legajo))
                {
                    cout << "ERROR: Ya existe alumno con ese legajo" << endl;
                }
                else
                {
                    cout << "DNI:";
                    cin >> nuevoAlumno.dni;
                    while((c=getchar() != '\n') && c != EOF);//fflush pero para la entrada de buffer
                    cout << "Apellidos del alumno:";
                    fgets(nuevoAlumno.apellido, 50, stdin);
                    while((c=getchar() != '\n') && c != EOF);//fflush pero para la entrada de buffer
                    cout << "Nombre del alumno:";
                    fgets(nuevoAlumno.nombre, 50, stdin);
                    cout << "Codigo de carrera: ";
                    cin >> nuevoAlumno.codcarrera;
                    ListaAlumnoInsertarFinal(lAlumnos, nuevoAlumno);
                    cout << "\nEl alumno se cargo con exito" << endl;
                }
            break;

            case 5:
            break;
            case 6:
                auxa =lAlumnos;

                while(auxa != NULL)
                {
                    MostrarAlumno(auxa->info);
                    auxa = auxa->sgte;
                }
            break;
            case 7:
            break;
            default:
            break;
        }

    }while(opcion != -1);
    return 0;
}

