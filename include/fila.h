/**
 * @file	fila.h
 * @brief	Declaracao da classe fila e seus metodos
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	09/05/2017
 * @date	25/06/2017
 */
#ifndef FILA_H
#define FILA_H

#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
namespace edb1{
    template <typename T>
    class Fila{
    private:
    int maximo;
    int tamanho;
    T *fila;

    public:
    Fila(int tamanho);
    int push(T el);
    T pop();
};

template <typename T>
Fila<T>::Fila(int t){
    fila= new T[t];
    maximo=t;
    tamanho=0;
}

template <typename T>
int Fila<T>::push(T el){
    //Possível erro: Se a pilha estiver cheia não pode inserir elementos
    if(tamanho==maximo){
        cout<<"Pilha cheia, nao e possivel mais inserir"<<endl;
        return tamanho;
    }
    fila[tamanho]=el;
    return ++tamanho;
}

template <typename T>
T Fila<T>::pop(){
    //Possível erro: Se a pilha estiver vazia não pode imprimir elementos
    if(tamanho==0){
        cout<<"Pilha vazia, nao e possivel mais retirar"<<endl;
        return tamanho;
    }
    --tamanho;
    T retirado= fila[0];
    for(int ii=0; ii<tamanho; ii++){
        fila[ii]=fila[ii+1];
    }
    return retirado;
}
}

#endif