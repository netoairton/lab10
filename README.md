# lab10
segmentation fault
parametros errados
container vazia

Na TAD Lista Ligada, ao criar um novo nó, podia ser que não houvesse espaço para a
alocação, portanto, foi implementado um try/catch com bad_alloc;

No main:
Nas buscas, inserções e ordenações foi implementado um try/catch com
invalid_argument para que não fossem passados argumentos invalidos nas funções;