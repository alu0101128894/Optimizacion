#include "grafo.cpp"

using namespace std;

int main(void)
{
  char option;
  char nombrefichero[50];
  int errorapertura;

  cout << "\nPráctica 4 Grafos. José Javier Díaz González\n"
       << endl;

  GRAFO graph(nombrefichero, errorapertura);

  while ((graph.dirigido == 0 || graph.dirigido == 1) && errorapertura == 0)
  {
    if (graph.dirigido == 0)
    {
      while (option != 'q' && graph.dirigido == 0)
      {
        cout << "\nActividad I, Optimización: carga básica de un grafo." << endl;
        cout << "c. [c]argar grafo desde archivo." << endl;
        cout << "i. Mostrar [i]nformación básica del grafo." << endl;
        cout << "a. Mostrar la lista de [a]dyacencia del grafo." << endl;
        cout << "q. Finalizar el programa." << endl;
        cout << "Introduzca la letra de la acción a ejecutar: ";
        cin >> option;
        while (option != 'c' && option != 'i' && option != 'a' && option != 'q')
        {
          cout << endl
               << "Ha introducido una opción no correcta. Por favor introduzca una opción correcta: " << endl;
          cin >> option;
        }
        switch (option)
        {
        case 'c':
          graph.actualizar(nombrefichero, errorapertura);
          while (errorapertura == 1)
          {
            graph.actualizar(nombrefichero, errorapertura);
          }
          break;
        case 'i':
          graph.Info_Grafo();
          break;
        case 'a':
          graph.Mostrar_Listas(2);
          break;
        case 'q':
          cout << "\nGracias por utilizar este programa.\n"
               << endl;
          graph.dirigido = 2;
        }
      }
    }

    if (graph.dirigido == 1 && errorapertura == 0)
    {
      while (option != 'q' && graph.dirigido == 1)
      {
        cout << "\nActividad I, Optimización: carga básica de un grafo." << endl;
        cout << "c. [c]argar grafo desde archivo." << endl;
        cout << "i. Mostrar [i]nformación básica del grafo." << endl;
        cout << "s. Mostrar la lista de [s]ucesores del grafo." << endl;
        cout << "p. Mostrar la lista de [p]redecesores del grafo." << endl;
        cout << "q. Finalizar el programa." << endl;
        cout << "Introduzca la letra de la acción a ejecutar: ";
        cin >> option;
        while (option != 'c' && option != 'i' && option != 's' && option != 'p' && option != 'q')
        {
          cout << endl
               << "Ha introducido una opción no correcta. Por favor introduzca otra nuevamente: " << endl;
          cin >> option;
        }
        switch (option)
        {
        case 'c':
          graph.actualizar(nombrefichero, errorapertura);
          while (errorapertura == 1)
          {
            graph.actualizar(nombrefichero, errorapertura);
          }
          break;
        case 'i':
          graph.Info_Grafo();
          break;
        case 's':
          graph.Mostrar_Listas(1);
          break;
        case 'p':
          graph.Mostrar_Listas(0);
          break;
        case 'q':
          cout << "\nGracias por utilizar este programa.\n"
               << endl;
          graph.dirigido = 2;
        }
      }
    }
  }
}
