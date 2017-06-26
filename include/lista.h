/**
 * @file	lista.h
 * @brief	Declaracao da classe Lista e seus metodos
 * @author	Airton Neto(netoairton@yahoo.com.br)
 * @since	12/05/2017
 * @date	25/06/2017
 */
#ifndef LISTA_H
#define LISTA_H

#include<iostream>
using std::cout;
using std::cerr;
using std::endl;
#include<string>
using std::string;
#include<new>
using std::bad_alloc;
namespace edb1{
template<typename T>
	class Lista {
    	private:
        	T dado;
        	Lista *ant;
        	Lista *prox;
    	public:
        	Lista();
        	~Lista();
        	int vazia();
        	void Inserir(T elemento);
        	void Exibe();
	};
	template<typename T>
    Lista<T>::Lista(){
        prox = NULL;
	    ant = NULL;
    }
    template<typename T>
    Lista<T>::~Lista(){
        if(prox){
            delete prox;
        }
    }
    template<typename T>
    int Lista<T>::vazia(){
		//Possivel erro: Lista Vazia
	    if(prox == NULL)
		    return 1;
	    else
	    	return 0;
    }
    template<typename T>
    void Lista<T>::Inserir(T elemento){
		try{
        	Lista *novo = new Lista();
		//Possivel erro: Sem memoria para criar outro nó
        if(!novo){
		    cout << "Sem memoria disponivel!"<<endl;
		    return;
	    }
        novo->dado = elemento;
        if(vazia()){
		    prox=novo;
		    novo->ant=NULL;
		    novo->prox=NULL;
	    }
        else{
		    Lista *tmp = prox;
		    if(tmp->ant==NULL && novo->dado < tmp->dado){
			    novo->ant=NULL;
			    novo->prox=tmp;
			    prox = novo;
			    tmp->ant=novo;
		    }
		    else{
			    while(tmp->prox){
				    if(novo->dado > tmp->prox->dado){
					    tmp = tmp->prox;
				    }
				    else{
					    break;
				    }
			    }
		
			    novo->ant = tmp;
			    if(tmp->prox){
				    novo->prox=tmp->prox;
			    }
			    else{
				    novo->prox=NULL;
			    }
			    tmp->prox = novo;
		    }
	    }
		} catch (bad_alloc &ex){
			cerr<<ex.what()<<"Sem memoria disponivel!"<<endl;
			return;
		}

    }
    template<typename T>
    void Lista<T>::Exibe(){
        if(vazia()){
            cout << "Lista vazia!"<<endl
			    				  <<endl;
            return;
        }

        Lista *tmp;
	    tmp = prox;
	
	    while( tmp != NULL){
		    cout << tmp->dado << "  ";
		    tmp = tmp->prox;
		
	    }
	    cout << endl;
    }
}




#endif