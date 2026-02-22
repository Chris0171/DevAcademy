#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constantes para el programa
const int MAX_DOCS = 4;
const int MAX_CAJAS = 3;
const int MAX_PESO = 10;

const int MAX_PENDIENTES = 100;
// Estructuras
struct tDocumento
{
    string codigo;
    int peso;
};

struct tListaDocs
{
    tDocumento docs[MAX_DOCS];
    int cont = 0;
};

struct tCaja
{
    tListaDocs lista;
    int peso = 0;
};

struct tArchivo
{
    tCaja cajas[MAX_CAJAS];
};

// Prototipado de funciones
void iniciar_archivo_docs(tArchivo &archivo);
bool insertar_final(const tDocumento &doc, tListaDocs &lista);
bool colocar_documento_caja(const tDocumento &doc, tCaja &caja);
bool eliminar_documento_caja(const string &code, tCaja &caja);
int eliminar_documento_archivo(const string &code, tArchivo &arch);
int colocar_documento_archivo(const tDocumento &doc, tArchivo &arch);
void procesar_operaciones(ifstream &file, tArchivo &arch, tListaDocs &pendientes);
void procesar_docs_pendientes(tListaDocs &pendientes, tArchivo &arch);
void mostrar_documento(const tDocumento &doc);
void mostrar_lista_documentos(const tListaDocs &lista);
void mostrar_caja(const tCaja &caja, int num_caja);
void mostrar_archivo_docs(const tArchivo &archivo);

// Programa principal
int main()
{
    ifstream file("operaciones.txt");

    if(file){
        tArchivo archivo;
        tListaDocs pendientes;
        
        pendientes.cont = 0;

        iniciar_archivo_docs(archivo);

        procesar_operaciones(file, archivo, pendientes);

        cout << "\n** ESTADO ACTUAL DEL ARCHIVO DE DOCUMENTOS **" << endl;

        mostrar_archivo_docs(archivo);

        cout << "\n ** DOCUMENTOS PENDIENTES DE ARCHIVAR **" << endl;

        mostrar_lista_documentos(pendientes);

        cout << "\n";

        procesar_docs_pendientes(pendientes, archivo);

        cout << "\n ** ESTADO ACTUAL DEL ARCHIVO DE DOCUMENTOS **:" << endl;

        mostrar_archivo_docs(archivo);

        file.close();

    }else{
        cout << "ERROR AL ABRIR EL FICHERO" << endl;
    }
    return 0;
}

// Implementación de funciones
void iniciar_archivo_docs(tArchivo &archivo){
    for(int i = 0; i < MAX_CAJAS; i++){
        archivo.cajas[i].peso = 0;
        archivo.cajas[i].lista.cont = 0;
    }
}

bool insertar_final(const tDocumento &doc, tListaDocs &lista){
    bool insertado = false;
    // [0 1 2 3] cont -> 1 2 3 4
    if(lista.cont < MAX_DOCS){
        lista.docs[lista.cont] = doc;
        lista.cont++;
        insertado = true;
    }
    return insertado;
}

bool colocar_documento_caja(const tDocumento &doc, tCaja &caja){
    bool colocado = false;

    if(caja.lista.cont < MAX_DOCS){
        if(caja.peso + doc.peso <= MAX_PESO){
            bool insertado = insertar_final(doc, caja.lista);
            
            if(insertado == true){
                caja.peso += doc.peso;
                colocado = true;
            }
        }
    }

    return colocado;
}

void mostrar_documento(const tDocumento &doc)
{
    cout << doc.codigo << ": Peso: " << doc.peso << endl; 
}
void mostrar_lista_documentos(const tListaDocs &lista)
{
    for(int i = 0; i < lista.cont; i++){
        mostrar_documento(lista.docs[i]);
    }
}
void mostrar_caja(const tCaja &caja, int num_caja)
{
    cout << "Caja numero " << num_caja << " Espacio libre: "
    << (MAX_PESO - caja.peso) << endl;
    mostrar_lista_documentos(caja.lista);
}
void mostrar_archivo_docs(const tArchivo &archivo)
{
    for (int i = 0; i < MAX_CAJAS; i++){
        mostrar_caja(archivo.cajas[i], i + 1);
    }
}

bool eliminar_documento_caja(const string &code, tCaja &caja){
    bool eliminado = false;
    
    // Buscamos el documento a eliminar
    int pos = -1; // Inicialmente no lo hemos encontrado
    for (int i = 0; i < caja.lista.cont; i++){
        if(caja.lista.docs[i].codigo == code){
            pos = i;
            i = caja.lista.cont;
        }
    }

    // Si lo encontramos, lo eliminamos
    if(pos != -1){
        // Restamos el peso del documento a la caja
        caja.peso -= caja.lista.docs[pos].peso;
        // [001, , 003, 004]
        // [001, 003, 004, ["", 0]] 
        // Movemos los documentos restantes una posición hacia atrás
        for(int i = pos; i < caja.lista.cont - 1; i++){
            caja.lista.docs[i] = caja.lista.docs[i + 1];
        }
        // caja.lista.docs[caja.lista.cont -1].codigo = "";
        // caja.lista.docs[caja.lista.cont -1].peso = 0;
        caja.lista.cont--;
        
        eliminado = true;
    }

    return eliminado;
}

int eliminar_documento_archivo(const string &code, tArchivo &arch){
    int pos = -1; // Inicialmente no lo hemos encontrado
    
    // Buscamos el documento a eliminar
    for (int i = 0; i < MAX_CAJAS; i++){
       bool eliminado =  eliminar_documento_caja(code, arch.cajas[i]);
       if(eliminado == true){
            pos = i;
            i = MAX_CAJAS;
       }
    }

    return pos;
}

int colocar_documento_archivo(const tDocumento &doc, tArchivo &arch){
    int pos = -1; // Inicialmente no lo hemos colocado
    
    for(int i = 0; i < MAX_CAJAS; i++){
        bool colocado = colocar_documento_caja(doc, arch.cajas[i]);
        if(colocado == true){
            pos = i;
            i = MAX_CAJAS;
        }
    }
    return pos;
}

void procesar_operaciones(ifstream &file, tArchivo &arch, tListaDocs &pendientes){
    int num_operaciones;
    file >> num_operaciones;

    cout << "** PROCESAMIENTO DE OPERACIONES **" << endl;
    for(int i = 0; i < num_operaciones; i++){
        string op;
        file >> op;

        if(op == "ADD"){
            int caja;
            tDocumento doc;

            file >> caja >> doc.codigo >> doc.peso;
            
            int idx = caja - 1;

            if(idx >= 0 && idx < MAX_CAJAS){

                if(colocar_documento_caja(doc, arch.cajas[idx])){
                    cout << "DOCUMENTO " << doc.codigo
                    << "( " << doc.peso << "kg) ALMACENADO EN LA CAJA "
                    << caja << ". EL PESO DE LA CAJA ES: " 
                    << arch.cajas[idx].peso << endl; 
                }else{
                    if(pendientes.cont < MAX_PENDIENTES){
                        pendientes.docs[pendientes.cont] = doc;
                        pendientes.cont++;
                    }
                    // EL DOCUMENTO H2 (5 kg) NO SE HA PODIDO ALMACENAR EN LA CAJA 2. DEJAMOS EL DOCUMENTO PENDIENTE
                    cout << "EL DOCUMENTO " << doc.codigo 
                    << "( " << doc.peso << "kg) NO SE HA PODIDO ALMACENAR EN LA CAJA "
                    << caja << ". DEJAMOS EL DOCUMENTO PENDIENTE" << endl;

                }
            }
        }else if(op == "RM"){
            string code;
            file >> code;

            int idx = eliminar_documento_archivo(code, arch);

            if (idx == -1){
                cout << "EL DOCUMENTO " << code << " NO EXISTE EN EL ARCHIVO" << endl;
            }else{
                cout << "DOCUMENTO " << code << "ELIMINADO DE LA CAJA "
                << idx + 1 << ". EL PESO DE LA CAJA ES: " << arch.cajas[idx].peso
                << endl;
            }
        }
        else {
            string resto;
            getline(file, resto);

            cout << "LA OPERACION " << op 
            << " NO ESTA SOPORTADA POR LA APLICACION" << endl;
        }
    }
}

void procesar_docs_pendientes(tListaDocs &pendientes, tArchivo &arch){
    cout << "** PROCESAMIENTO DE OPERACIONES PENDIENTES **" << endl;

    for (int i = 0; i < pendientes.cont; i++){
        tDocumento doc = pendientes.docs[i];
        int idx = colocar_documento_archivo(doc, arch);
        if(idx == -1){
            cout << "EL DOCUMENTO " << doc.codigo 
            << " NO SE HA PODIDO ALMACENAR" << endl;
        }else{
            cout << "DOCUMENTO " << doc.codigo 
            << "( " << doc.peso << "kg) ALMACENADO EN LA CAJA "
            << idx + 1 << ". EL PESO DE LA CAJA ES: " << arch.cajas[idx].peso 
            << endl;
        }
        
    }
    pendientes.cont = 0;
}

