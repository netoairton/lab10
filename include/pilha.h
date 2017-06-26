/**
 * @file	pilha.h
 * @brief	Declaracao da classe Pilha e seus metodos
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	09/05/2017
 * @date	14/05/2017
 */
 
#ifndef PILHA_H
#define PILHA_H

#include<iostream>
using std::cout;
using std::endl;
#include<string>
using std::string;
namespace edb1{
    template <typename T>
    class Pilha{
    private:
    int maximo;
    int tamanho;
    T *pilha;

    public:
    Pilha(int tamanho);
    int push(T el);
    T pop();
};

template <typename T>
Pilha<T>::Pilha(int t){
    pilha= new T[t];
    maximo=t;
    tamanho=0;
}

template <typename T>
int Pilha<T>::push(T el){
    //Possível erro: Se a pilha estiver cheia não pode inserir elementos
    if(tamanho==maximo){
        cout<<"Pilha cheia, nao e possivel mais inserir"<<endl;
        return -1;
    }
    pilha[tamanho]=el;
    return ++tamanho;
}

template <typename T>
T Pilha<T>::pop(){
    //Possível erro: Se a pilha estiver vazia não pode imprimir elementos
    if(tamanho==0){
        cout<<"Pilha vazia, nao e possivel mais retirar"<<endl;
        return -1;
    }
    --tamanho;
    return pilha[tamanho];
}
}

#endif