# lab10
segmentation fault
parametros errados
container vazia

Na TAD Lista Ligada, ao criar um novo n�, podia ser que n�o houvesse espa�o para a
aloca��o, portanto, foi implementado um try/catch com bad_alloc;

No main:
Nas buscas, inser��es e ordena��es foi implementado um try/catch com
invalid_argument para que n�o fossem passados argumentos invalidos nas fun��es;