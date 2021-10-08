#include "grafo.hpp"
#include <climits>

using namespace std;

GRAFO::GRAFO(char nombrefichero[], int &errorapertura)
{
  unsigned i, j;
  int k;
  ElementoLista dummy;

  cout << "Introduzca el nombre del fichero: " << endl;
  cin >> nombrefichero;
  ifstream fich;
  fich.open(nombrefichero);
  if (!fich.is_open())
  {
    cout << "\nError en la apertura del fichero." << endl;
    errorapertura = 1;
  }
  else
  {
    cout << "\nEl fichero se ha cargado correctamente." << endl;
    errorapertura = 0;
    fich >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;
    LS.resize(n);
    LP.resize(n);
    for (int q = 0; q < m; q++)
    {

      //fich >> (unsigned &) i >> (unsigned &) j;
      //if (dirigido == 1){
      fich >> (unsigned &)i >> (unsigned &)j >> (int &)k;
      dummy.j = j - 1;
      dummy.c = k;
      LS[i - 1].push_back(dummy);
      dummy.j = i - 1;
      dummy.c = k;

      LP[j - 1].push_back(dummy);
      //else{
      if (dirigido == 0)
      {
        if (i == j)
        {
        }
        else
        {
          dummy.j = i - 1;
          LS[j - 1].push_back(dummy);
        }
      }
    }
    fich.close();
    ListaPredecesores();
  }
  if (dirigido != 0 && dirigido != 1)
  {
    cout << "ERROR EN EL ARCHIVO" << endl;
  }
}

void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{

  LS.clear();
  LP.clear();

  unsigned i, j;
  int k;
  ElementoLista dummy;

  cout << "Introduzca el nombre del fichero: " << endl;
  cin >> nombrefichero;
  ifstream fich;
  fich.open(nombrefichero);
  if (!fich.is_open())
  {
    cout << "\nError en la apertura del fichero." << endl;
    errorapertura = 1;
  }
  else
  {
    cout << "\nEl fichero se ha cargado correctamente." << endl;
    errorapertura = 0;
    fich >> (unsigned &)n >> (unsigned &)m >> (unsigned &)dirigido;
    LS.resize(n);
    LP.resize(n);
    for (int q = 0; q < m; q++)
    {

      //fich >> (unsigned &) i >> (unsigned &) j;
      //if (dirigido == 1){
      fich >> (unsigned &)i >> (unsigned &)j >> k;
      dummy.j = j - 1;
      dummy.c = k;
      LS[i - 1].push_back(dummy);
      dummy.j = i - 1;
      dummy.c = k;
      LP[j - 1].push_back(dummy);

      //else{
      if (dirigido == 0)
      {
        if (i == j)
        {
        }
        else
        {
          dummy.j = i - 1;
          LS[j - 1].push_back(dummy);
        }
      }
    }

    fich.close();
    ListaPredecesores();
  }
  if (dirigido != 0 && dirigido != 1)
  {
    cout << "ERROR EN EL ARCHIVO" << endl;
  }
}

void GRAFO::Info_Grafo()
{
  if (dirigido == 1)
  {
    cout << endl
         << "El grafo es dirigido." << endl;
  }
  else
  {
    cout << endl
         << "El grafo es NO dirigido." << endl;
  }
  cout << "Hay " << n << " nodos y " << m << " aristas" << endl;
}

void GRAFO::Mostrar_Listas(int l)
{
  if (l == 0)
  {
    cout << "Mostrando la lista de predecesores." << endl;
    for (int q = 0; q < n; q++)
    {
      cout << endl
           << "El nodo " << q + 1 << " tiene como predecesores a: ";
      for (int w = 0; w < LP[q].size(); w++)
      {
        cout << " " << (LP[q][w].j) + 1;
      }
    }
  }
  if (l == 1)
  {
    cout << "Mostrando la lista de sucesores." << endl;
    for (int q = 0; q < n; q++)
    {
      cout << endl
           << "El nodo " << q + 1 << " tiene como sucesores a: ";
      for (int w = 0; w < LS[q].size(); w++)
      {
        cout << " " << (LS[q][w].j) + 1;
      }
    }
  }
  if (l == 2)
  {
    cout << "Mostrando la lista de adyacentes." << endl;
    for (int q = 0; q < n; q++)
    {
      cout << endl
           << "El nodo " << q + 1 << " tiene como adyacentes a: ";
      for (int w = 0; w < LS[q].size(); w++)
      {
        cout << " " << (LS[q][w].j) + 1;
      }
    }
  }
  cout << endl;
}

void GRAFO::ListaPredecesores()
{
  /*int i, j, k;
ElementoLista dummy;
LP.resize(n);
fich >> (unsigned &) i >> (unsigned &) j >> (int &) k;
for (int q = 0; q < n; q++){
for (int w = 0; w < LS[q].size(); w++){
fich >> (unsigned &) i >> (unsigned &) j >> (int &) k;
dummy.j = q;
dummy.c = k;
LP[LS[q][w].j].push_back(dummy);
}
}
*/
}

GRAFO::~GRAFO()
{
  for (int q; q < n; q++)
  {
    LS[q].clear();
    LP[q].clear();
  }
  LS.clear();
  LP.clear();
}

void GRAFO::Compconex(void)
{
  vector<bool> visit;
  visit.resize(n);
  unsigned component = 0;

  cout << endl;
  cout << "Componente conexa " << component + 1 << ": ";
  dfs(component, visit);
  cout << endl;

  for (unsigned i = 1; i < visit.size(); i++)
  {
    if (visit[i] == false)
    {
      component++;
      cout << "Componente conexa " << component + 1 << ": ";
      dfs(i, visit);
      cout << endl;
    }
  }
  if (component == 0)
  {
    cout << "\nEl grafo es conexo.\n";
  }
  else
  {
    cout << "\nEl grafo NO es conexo.\n";
  }
}

void GRAFO::dfs(unsigned i, vector<bool> &visit)
{
  visit[i] = true;
  cout << i + 1 << ", ";
  for (unsigned j = 0; j < LS[i].size(); ++j)
  {
    if (visit[LS[i][j].j] == false)
    {
      dfs(LS[i][j].j, visit);
    }
  }
}

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)
{
  if (i != s)
  {
    MostrarCamino(s, pred[i], pred);
    cout << pred[i] + 1 << " -> ";
  }
}

void GRAFO::Dijkstra()
{

  vector<bool> PermanentementeEtiquetado;
  vector<int> d;
  vector<unsigned> pred;
  unsigned i = 0, j, k = 0;
  unsigned s, candidato, min;
  int maxint = INT_MAX;
  unsigned UERROR = INT_MAX;

  //Inicialmente no hay ningun nodo etiquetado
  PermanentementeEtiquetado.resize(n, false);
  //Inicialmente todas las etiquetas distancias son infinito
  d.resize(n, maxint);
  //Inicialmente el pred es null
  pred.resize(n, UERROR);

  //Solicitamos al usuario nodo origen
  cout << "\nIntroduzca el nodo de partida. De 1 a " << n << ": ";
  cin >> s;

  //La etiqueta distancia del nodo origen es 0, y es su propio pred
  d[--s] = 0;
  pred[s] = s;

  do
  {

    min = maxint;
    //Buscamos un nodo candidato a ser permanentemente etiquetado y etiqueta minima no finita.
    for (i = 0; i < n; i++)
    {
      if ((PermanentementeEtiquetado[i] == false) && (d[i] < min))
      {
        candidato = i;
        min = d[i];
      }
    }
    if (candidato != UERROR)
    {
      //Si existe ese candidato, lo etiqueto permanente y usamos los arcos de la lista para buscar atajos
      PermanentementeEtiquetado[candidato] = true;
      for (unsigned k = 0; k < LS[candidato].size(); k++)
      {
        if (PermanentementeEtiquetado[LS[candidato][k].j] == false)
        {
          if ((d[LS[candidato][k].j]) > (d[candidato] + LS[candidato][k].c))
          {
            d[LS[candidato][k].j] = (d[candidato] + LS[candidato][k].c);
            pred[LS[candidato][k].j] = candidato;
          }
        }
      }
    }
  } while (min < maxint);
  cout << endl;
  for (unsigned i = 0; i < n; i++)
  {
    if (i != s)
    {
      if (PermanentementeEtiquetado[i] == true)
      {
        cout << "El camino desde " << s + 1 << " al nodo " << i + 1 << " es: ";
        MostrarCamino(s, i, pred);
        cout << i + 1 << " de longitud " << d[i] << endl;
      }
      else
        cout << "ERROR. No hay camino desde: " << s + 1 << " al nodo " << i + 1 << endl;
    }
  }
}

void GRAFO::Bellman()
{
  vector<int> d;
  vector<unsigned> pred;
  unsigned s;
  unsigned t;
  unsigned numeromejoras = 0;
  vector<int> mod;
  bool mejora;
  int maxint = INT_MAX;
  unsigned UERROR = INT_MAX;

  //Inicialmente todas las etiquetas distancias son infinito
  d.resize(n, maxint);
  //Inicialmente el pred es null
  pred.resize(n, UERROR);

  cout << "\nIntroduzca el nodo de partida. De 1 a " << n << ": ";
  cin >> (unsigned &)s;

  // cout<<"\nIntroduzca el destino: ";
  //  cin >> (unsigned &) t;

  d[--s] = 0;
  pred[s] = s;

  do
  {
    mejora = false;
    //recorremos todos los arcos y para cada (i,j) buscamos si d[j] > d[i]+cij y actualizamos d y pred
    //si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos terminado; contabilizamos
    //los ciclos en los que ha habido mejoras
    for (unsigned i = 0; i < n; i++)
    {
      for (unsigned k = 0; k < LS[i].size(); k++)
      {
        if (d[i] != maxint)
        {
          int nd = d[i] + LS[i][k].c;
          if (nd < d[LS[i][k].j])
          {
            d[LS[i][k].j] = nd;
            pred[LS[i][k].j] = i;
            mejora = true;
          }
        }
      }
      if (mejora == false)
      {
        mod.push_back(i);
      }
    }
    numeromejoras++;
    //para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos realizado n+1 veces la
    //relajacion con mejora; si mejora es falso, pues tenemos solucion
  } while ((numeromejoras < n) && (mejora == true));

  if (mejora == true)
  {
    cout << "ERROR. Se ha detectado un ciclo de coste negativo." << endl;
    for (int j = 0; j < n; j++)
    {
      cout << "nodo: " << mod[j + 1] << endl;
    }
  }
  else
  {
    cout << endl;
    for (unsigned i = 0; i < n; i++)
    {
      if (i != s)
      {
        if (pred[i] != UERROR)
        {
          cout << "El camino de " << s + 1 << " a " << i + 1 << " es: ";
          MostrarCamino(s, i, pred);
          cout << i + 1 << " de longitud " << d[i] << endl;
        }
        else
        {
          cout << "ERROR. No hay camino desde: " << s + 1 << " al nodo " << i + 1 << endl;
        }
      }
    }
  }
}
