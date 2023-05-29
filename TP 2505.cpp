#include <iostream>
#include <cstdlib>
using namespace std;

struct No
{
    int dado;
    No *prox;
};

struct Fila
{
    No *ini;
    No *fim;
};

Fila *initFila()
{
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int isEmptyFila(Fila *f)
{
    return (f->ini == NULL);
}

int countFila(Fila *f)
{
    int qtde = 0;
    No *no;
    no = f->ini;
    while (no != NULL)
    {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void printFila(Fila *f)
{
    No *no;
    no = f->ini;
    cout << "-------------" << endl;
    while (no != NULL)
    {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "-------------" << endl;
}

int valorFila(Fila *f)
{
    No *no;
    no = f->ini;
    int valor = 0;

    if (no != NULL)
    {
        valor = no->dado;
    }

    return valor;
}

void enqueueFila(Fila *f, int v)
{
    No *no = new No;
    no->dado = v;
    no->prox = NULL;
    if (isEmptyFila(f))
    {
        f->ini = no;
    }
    else
    {
        f->fim->prox = no;
    }
    f->fim = no;
}

float dequeue(Fila *f)
{
    float ret;
    if (isEmptyFila(f))
    {
        ret = -1;
    }
    else
    {
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;
        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        free(no);
    }
    return ret;
}

void freeFila(Fila *f)
{
    No *no = f->ini;
    while (no != NULL)
    {
        No *temp = no->prox;
        free(no);
        no = temp;
    }
    free(f);
}

struct Lista
{
	int dado;
    Fila *senhaAtendidas;
	struct Lista *prox;
};

Lista* initLista()
{
	return NULL;
}

int isEmptyLista(Lista* lista)
{
	return (lista == NULL);
}

Lista* insertLista(Lista* lista, int i, Fila* senhaAtendida)
{
	Lista* novo = new Lista();
	novo->dado = i;
    novo->senhaAtendidas = senhaAtendida;
	novo->prox = lista;
	return novo;
}

void printLista(Lista* lista)
{
	Lista* aux = lista;
	
	while (aux != NULL)
	{
		cout << "Dado: " << aux->dado << endl;
		aux = aux->prox;
	}
}

Lista* findLista(Lista* lista, int i)
{
	Lista* aux = lista;
	
	while (aux != NULL && aux->dado != i)
	{
		aux = aux->prox;
	}
	return aux;
}

Lista* removeLista(Lista* lista, int i)
{
	Lista* ant = NULL;
	Lista* aux = lista;
	
	while (aux != NULL && aux->dado != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		return lista;
	}
	if (ant == NULL)
	{
		lista = aux->prox;	
	}
	else
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

int main()
{
    Fila *senhaGeradas;
    senhaGeradas = initFila();

    Fila *senhaAtendidas;
    senhaAtendidas = initFila();

    Lista *listaGuiche;
    listaGuiche = initLista(); 

    int escolhaMenu = 0;
    int idGuiche = 0;
    int idGuicheEscolhido = 0;

    do
    {
        cout << "0. SAIR" << endl;
        cout << "1. GERAR SENHA" << endl;
        cout << "2. ABRIR GUICHE" << endl;
        cout << "3. REALIZAR ATENDIMENTO" << endl;
        cout << "4. LISTAR SENHAS ATENDIDAS" << endl;

        cin >> escolhaMenu;

        switch (escolhaMenu)
        {
        case 0:
            isEmptyFila(senhaGeradas) ? escolhaMenu = 0 : escolhaMenu = -1;
            break;
        case 1:
            cout << "--- GERANDO SENHA ---" << endl
                 << endl;
            enqueueFila(senhaGeradas, rand());
            break;
        case 2:
            cout << "--- ABRIR GUICHE ---" << endl;
            listaGuiche = insertLista(listaGuiche, ++idGuiche, senhaAtendidas);
            break;
        case 3:
            cout << "--- ATENDIMENTO ---" << endl;
            cout << "Digite o id do guiche: " << endl;
            cin >> idGuicheEscolhido;
            
            if (findLista(listaGuiche, idGuicheEscolhido) != NULL)
            {
                cout << "Senha: " << valorFila(senhaGeradas) << endl;
                enqueueFila(senhaAtendidas, valorFila(senhaGeradas));
                dequeue(senhaGeradas);
            } 
            
            cout << "Quantidade de senha aguardando atendimento: " << countFila(senhaGeradas) << endl
                << endl;
            break;
        case 4:
            cout << "--- LISTAR SENHAS ATENDIDAS ---" << endl;

            cout << "Digite o id do guiche: " << endl;
            cin >> idGuicheEscolhido;

            if (findLista(listaGuiche, idGuicheEscolhido) != NULL)
            {
                cout << "Quantidade de senhas atendidas pelo guiche " << idGuicheEscolhido << ": " << countFila(listaGuiche->senhaAtendidas) << endl;
                cout << "Senhas atendidas " << endl;
                printFila(listaGuiche->senhaAtendidas);
            }

            break;
        default:
            cout << "Digite uma opção valida!";
            break;
        }
    } while (escolhaMenu != 0);

    cout << "Quantidade de senhas atendidas: " << countFila(senhaAtendidas) << endl;

    freeFila(senhaGeradas);
    freeFila(senhaAtendidas);
}