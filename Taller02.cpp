#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string lectura(){
  ifstream archivo;
  string texto;
  
  archivo.open("example1.txt",ios::in); //Abrir el archivo en modo lectura

  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }

  while(!archivo.eof()){
    getline(archivo,texto);
    cout<<texto<<endl;
  }
  cout<<endl;
  archivo.close();
  return texto;
}

//Esta función busca listar todos los autores que se encuentran en el archivo de texto de JaveMusic
void listarAutores(string nombreArchivo){ //Definición de la función, con el nombre del archivo como parámetro
  string linea,autor; //Se define un string (linea) para guardar cada linea del archivo, y otro (autor) para guardar el nombre del autor
  set<string> autores; //Se define un set de tipo string para guardar los autores. No se usa un vector, por lo que se quiere que la información esté ordenada y que no esté repetida

  ifstream archivo(nombreArchivo);//Apertura del archivo
  if (archivo.is_open()) {
    // Se lee la primera linea del archivo para descartarla
    getline(archivo, linea);

    // Leer las demás lineas del archivo para almacenar los autores
    while (getline(archivo, linea)){ //Se lee cada linea del archivo y se guarda en el string (linea)
    unsigned int pos1 = linea.find('|'); //Se busca la posicion del primer '|' en la linea actual del archivo
    unsigned int pos2 = linea.find('|', pos1 + 1); //Se busca la posición del segundo '|' en la linea actual del archivo
    string autor = linea.substr(pos1 + 1, pos2 - pos1 - 1);  //Se obtiene el autor que se encuentra entre la primera y la segunda posicion del '|'
    autores.insert(autor);//Se agrega el autor obtenido al set de autores
    }

    archivo.close();//Cierre del archivo

    //Impresión de autores
    cout << "Autores presentes en el archivo:" << endl;
    set<string>:: iterator it; //Creación de iterador para recorrer el set de autores
    for (it = autores.begin(); it != autores.end(); ++it) {
    cout << *it << endl;
    }
  }
  
  else {
    cout << "Error al abrir el archivo" << endl;
  } 
}

//Esta función lista las canciones por autor
void listarCancionesAutor(string autorBuscado, string nombreArchivo){ //Definición de la función, con el autor a buscar y el nombre del archivo como parámetros
  ifstream archivo(nombreArchivo); //Apertura del archivo
  if (archivo.is_open()){
    vector<string> canciones; //Se crea un vector de tipo string para guardar las canciones del autor
    string linea; //
    getline(archivo, linea); //Se lee la primera linea del archivo para descartarla
    while (getline(archivo, linea)) {
    unsigned int pos1 = linea.find('|');
    unsigned int pos2 = linea.find('|', pos1 + 1);
    string autor = linea.substr(pos1 + 1, pos2 - pos1 - 1);//Se obtiene el autor, que está entre el primer y el segundo '|'
    string cancion = linea.substr(0, pos1); //Se obtiene el nombre de la canción que empieza desde el primer caracter de la linea del archivo, y que va hasta la posición del primer '|'
    archivo.close();

    if (autor == autorBuscado) {
      canciones.push_back(cancion);//Si el autor separado es igual al autor buscado, se agrega al final del vector (canciones)
      }
    }
    sort(canciones.begin(), canciones.end());//Ordenamiento de las canciones
    
    cout << "Canciones de " << autorBuscado << ":" << endl;
    vector<string>:: iterator it; //Recorrer el vector de canciones e imprimir el contenido
    for (it = canciones.begin(); it != canciones.end(); ++it) {
      cout << *it << endl;
    }
  }

  else{
    cout << "Error al abrir el archivo" << endl;
  }
}

void listarAlbumes(string nombreArchivo){
  string linea; //Se define un string (linea) para guardar cada linea del archivo, y otro (autor) para guardar el nombre del autor
  vector<string> albumes; //Se define un set de tipo string para guardar los albumes. No se usa un vector, por lo que se quiere que la información no esté repetida
  ifstream archivo(nombreArchivo);//Apertura del archivo
  int anioAux=0;
  if (archivo.is_open()) {
    // Se lee la primera linea del archivo para descartarla
    getline(archivo, linea);

    while (getline(archivo, linea)){ //Se lee cada linea del archivo y se guarda en el string (linea)
    unsigned int pos1 = linea.find('|'); //Se busca la posicion del primer '|' en la linea actual del archivo
    unsigned int pos2 = linea.find('|', pos1 + 1); //Se busca la posicion del segundo '|' en la linea actual del archivo
    unsigned int pos3 = linea.find('|', pos2 + 1); //Se busca la posicion del tercer '|' en la linea actual del archivo
    unsigned int pos4 = linea.find('|', pos3 + 1); //Se busca la posicion del cuarto '|' en la linea actual del archivo
    unsigned int pos5 = linea.find(' ', pos4 + 1);//Se busca la posición del quinto '|' en la linea actual del archivo
    string album = linea.substr(pos3+1,pos4-pos3-1);
    int anio = stoi(linea.substr(pos4+1,pos5-pos4-1));
    albumes.push_back(album);
    }
      
    archivo.close();//Cierre del archivo

    //Impresión de autores
    cout << "Albumes presentes en el archivo:" << endl;
    vector<string>:: iterator it; //Creación de iterador para recorrer el set de autores
    for (it = albumes.begin(); it != albumes.end(); ++it) {
    cout << *it << endl;
    }
  }

  else {
    cout << "Error al abrir el archivo" << endl;
  } 
    
}

void listarCancionesAlbum (string albumBuscado, string nombreArchivo){
  string linea,album; //Se define un string (linea) para guardar cada linea del archivo, y otro (autor) para guardar el nombre del autor
  ifstream archivo(nombreArchivo); //Apertura del archivo
  if (archivo.is_open()){
    set<string> canciones; //Se crea un vector de tipo string para guardar las canciones del autor
    string linea; //
    getline(archivo, linea); //Se lee la primera linea del archivo para descartarla
    while (getline(archivo, linea)) {
    unsigned int pos1 = linea.find('|');
    unsigned int pos2 = linea.find('|', pos1 + 1);
    unsigned int pos3 = linea.find('|', pos2 + 1); //Se busca la posicion del tercer '|' en la linea actual del archivo
    unsigned int pos4 = linea.find('|', pos3 + 1); //Se busca la posicion del cuarto '|' en la linea actual del archivo
    string album = linea.substr(pos3+1,pos4-pos3-1);
    string cancion = linea.substr(0, pos1); //Se obtiene el nombre de la canción que empieza desde el primer caracter de la linea del archivo, y que va hasta la posición del primer '|'
    archivo.close();
    
    
      if (album == albumBuscado) {
      canciones.insert(cancion);//Si el album separado es igual al album buscado, se agrega al final del vector (canciones)
      }
    }
  

    //Impresión de autores
    cout << "Canciones presentes en el album "<<albumBuscado<<endl;
    set<string>:: iterator it; //Creación de iterador para recorrer el set de autores
    for (it = canciones.begin(); it != canciones.end(); ++it) {
    cout << *it << endl;
    }
  }
  
  else {
    cout << "Error al abrir el archivo" << endl;
  } 
      
    
      
  
}


int main (){

  int op;
  string nombreArchivo, autorBuscado,albumBuscado;
  lectura();

  cout<<"Bienvenido a JaveMusic"<<endl<<endl;
  cout<<"Ingrese el nombre del archivo a emplear"<<endl;
  cin>>nombreArchivo;
  
  do{
    cout<<endl;
    cout<<"1. Listar todos los autores presentes, ordenados alfabéticamente. "<<endl;
    cout<<"2. Listar todas las canciones de un autor ordenadas alfabéticamente."<<endl;
    cout<<"3. Listar todos los álbumes presentes, ordenados cronológicamente."<<endl;
    cout<<"4. Listar todas las canciones que componen un album, ordenadas alfabéticamente por el nombre de la canción."<<endl;
    cout<<"5. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por el nombre de la canción."<<endl;
    cout<<"0. Salir"<<endl;
    cin>>op;

    switch(op){
      case 1:
        listarAutores(nombreArchivo);
      break;

      case 2:
        cout<<"Ingrese el nombre del autor que desea buscar"<<endl;
        cin>>autorBuscado;
        cout<<endl;
        listarCancionesAutor(autorBuscado,nombreArchivo);
      break;

      case 3:
        listarAlbumes(nombreArchivo);
      break;

      case 4:
        cout<<"Ingrese el nombre del album que desea buscar"<<endl;
        cin>>albumBuscado;
        listarCancionesAlbum (albumBuscado, nombreArchivo);
      break;

      case 5:
      break;

      default:
      break;
    }
    
  }while(op!=0);
  return 0;
}


