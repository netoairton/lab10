/**
 * @file	main.cpp
 * @brief	Implementação do main para testes
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	20/05/2017
 * @date	25/06/2017
 * @sa      biblio.h
 * @sa      lista.h
 * @sa      pilha.h
 * @sa      fila.h
 */
#include<iostream>
using std::cout;
using std::cerr;
using std::endl;
#include<cstdlib>
#include<ctime>
#include<string>
using std::string;
#include<stdexcept>
using std::invalid_argument;
#include "include/biblio.h"
#include "include/lista.h"
#include "include/pilha.h"
#include "include/fila.h"

using namespace edb1;
/** @brief Funcao principal */
int main(){
    try{
    ///Teste Busca///
    int *vetor= new int[100];
    for(int i = 0; i < 50; i++){
        vetor[i] = i + 1;
    }
    cout<<"Resultado das buscas:"<<endl;
    buscaSeqIt(vetor, 50, 30);
    cout<< buscaSeqRe(vetor, 50, 15)<<" ";
    cout<<buscaBiRe(vetor, 50, 10)<<" ";
    cout<<buscaBiIt(vetor, 50, 31)<<" ";
    cout<<buscaTerRe(vetor, 0, 50, 7)<<endl;
    buscaTerIt(vetor, 0, 50, 50);
    cout<<endl;
    delete [] vetor;
    } catch (invalid_argument &ex){
        cerr<<ex.what()<<"Argumento Invalido!"<<endl;
    } catch(bad_alloc &ex){
		cerr<<ex.what()<<"Sem memoria disponivel!"<<endl;
		return 0;
	}

    ///Teste lista///
    Lista<int> lista;
    try{
    lista.Inserir(33);
    lista.Inserir(99);
    lista.Inserir(15);
    } catch (invalid_argument &ex){
        cerr<<ex.what()<<"Argumento Invalido!"<<endl;
    }
    cout<<"Impressao dos itens da lista:"<<endl;
    lista.Exibe();

    ///Teste Pilha///
    Pilha<int> pilha(10);
    try{
    pilha.push(55);
    pilha.push(40);
    pilha.push(9);
    } catch (invalid_argument &ex){
        cerr<<ex.what()<<"Argumento Invalido!"<<endl;
    }
    cout<<"Impressao dos itens da pilha:"<<endl;
    cout<<pilha.pop()<<endl;
    cout<<pilha.pop()<<endl;
    cout<<pilha.pop()<<endl;

    ///Teste Fila///
    Fila<float> fila1(5);
    try{
    fila1.push(55);
    fila1.push(40);
    fila1.push(9);
    } catch (invalid_argument &ex){
        cerr<<ex.what()<<"Argumento Invalido!"<<endl;
    }
    cout<<"Impressao dos itens da fila:"<<endl;
    cout<<fila1.pop()<<endl;
    cout<<fila1.pop()<<endl;
    cout<<fila1.pop()<<endl;

    ///Teste Ordenação///
    srand(time(NULL));
    try{
    int *VET= new int[15];
    ///Insertion///
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    InsertionSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;
    ///Selection
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<endl
        <<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    SelectionSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;
    ///Bubble
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<endl
        <<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    BubbleSort(VET, 15);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    cout<<endl;

    //Quick
    cout<<endl;
    for(int i=0; i<15; i++){
        VET[i]= rand()%150;
    }
    cout<<"Vetor antes: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    QuickSort(VET, 0, 14);
    cout<<endl
        <<"Vetor apos ordenacao: "<<endl;
    for(int i=0; i<15; i++){
        cout<<VET[i]<<" ";
    }
    delete [] VET;
    } catch (invalid_argument &ex){
        cerr<<ex.what()<<"Argumento Invalido!"<<endl;
    } catch(bad_alloc &ex){
		cerr<<ex.what()<<"Sem memoria disponivel!"<<endl;
		return 0;
	}

    return 0;
}