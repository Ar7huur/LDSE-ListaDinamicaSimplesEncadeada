#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>    
#include <locale.h> 

#pragma region Módulos do exercício de LDSE

struct TpPont {
    char info;
    TpPont* prox;
};


//Função para passar elemento sem estar chumbado no int main
char FornecerElemento() {
    char elemento;
    printf("\nForneca um elemento para a funcao: ");
    fflush(stdin);
    elemento = toupper(_getche());
    return elemento;
}

TpPont* CriaCaixa(char Elemento) {
    TpPont* Caixa;
    Caixa = new TpPont;
    Caixa->info = Elemento;
    Caixa->prox = NULL;
    return Caixa;
}

//Módulo 1:
TpPont* InserirInit(TpPont * CB) {
    char Elemento;
    TpPont* nc;
    Elemento = FornecerElemento();
    nc = CriaCaixa(Elemento);
    nc->prox = CB;
    CB = nc;
    return CB;
}

//Módulo 2:
TpPont* InserirInit2(TpPont * CB) {
    char Elemento;
    TpPont* no;

    printf("\nDigite o Elemento:");
    fflush(stdin);
    Elemento = toupper(_getche());

    while (Elemento != 27) {

        no = CriaCaixa(Elemento);

        if (CB == NULL) {
            CB = no;
            return CB;
        }
        else {
            no->prox = CB;
            CB = no;
            return CB;
        }
    }
}


//Módulo 3:
TpPont* InserirOrdenado(TpPont * CB) {
    char Elemento;
    TpPont* ant, * atual, * no;
    Elemento = FornecerElemento();
    no = CriaCaixa(Elemento);

    if (CB == NULL)
        return CB = no;
    else {

        if (Elemento < CB->info) {
            no->prox = CB;
            CB = no;
        }
        else {

            ant = CB;
            atual = CB->prox;

            while (atual->prox != NULL && Elemento > atual->info) {
                ant = atual;
                atual = atual->prox;
            }

            if (atual->info > Elemento) {
                ant->prox = no;
                no->prox = atual;
            }

            if (atual->prox == NULL && atual->info < Elemento)
                atual->prox = no;
        }

    }
    return CB;
}


void ExibirElementoInitLDSE(TpPont * CB) {

    if (CB == NULL)
        printf("\nLista esta null, impossivel exibir algo.");
    else
        printf("\n%c", CB->info);
}


void ExibirElementoLastLDSE(TpPont * CB) {

    if (CB == NULL)
        printf("\nLista esta null, impossivel exibir algo.");
    else {

        while (CB->prox != NULL)
            CB = CB->prox;

        if (CB->prox == NULL)
            printf("\n%c", CB->info);
    }
}


TpPont* InserirAposElementoLast(TpPont * CB) {
    char Elemento;
    TpPont* no, * atual;

    Elemento = FornecerElemento();
    no = CriaCaixa(Elemento);

    if (CB == NULL) {
        no->prox = CB;
        CB = no;
        return CB;
    }
    else {

        atual = CB;

        while (atual->prox != NULL)
            atual = atual->prox;

        if (atual->prox == NULL)
            atual->prox = no;
    }
    return CB;
}

void ExibeListaToda(TpPont * CB) {

    if (CB == NULL)
        printf("\nLista NULL, nada para exibir");
    else
    {
        while (CB != NULL) {
            printf("%c\t", CB->info);
            CB = CB->prox;
        }
        Sleep(5000);
    }
}

void ExibeListaTodaRecursivo(TpPont * CB) {

    if (CB == NULL) {
        Sleep(5000);
        return;
    }

    else {
        if (CB != NULL)
            printf("%c\t", CB->info);
        return ExibeListaTodaRecursivo(CB->prox);
    }

}

TpPont* InserirEntreElementos(TpPont * CB) {

    char Elemento1, Elemento2, Elemento;
    TpPont* ant, * atual, * no;

    printf("\nElemento 1: ");
    Elemento1 = toupper(_getche());
    printf("\nElemento 2: ");
    Elemento2 = toupper(_getche());
    printf("\nElemento para inserir entre ambos: ");
    Elemento = FornecerElemento();
    no = CriaCaixa(Elemento);

    if (CB == NULL)
        printf("\nLista esta null, sem possibilidade de inserir entre elementos");
    else {
        ant = CB;
        atual = CB->prox;
        if (atual == NULL)
            printf("Lista so possui um unico elemento, forneca uma lista com mais elementos");
        else {

            while (ant->info != Elemento1 && atual->info != Elemento2 && atual != NULL) {
                ant = atual;
                atual = atual->prox;
            }
            if (ant->info == Elemento1 && atual->info == Elemento2) {
                ant->prox = no;
                no->prox = atual;
            }
            else
                printf("\nNao achou um dos elementos");
        }
    }
    return CB;
}


void ConsultarElemento(TpPont * CB) {

    char elemento;
    elemento = FornecerElemento();

    if (CB == NULL)
        printf("\nLista NULL, nada para consultar");
    else {

        if (CB->info == elemento)
            printf("Achou na primeira posicao, o elemento %c se encontra no inicio da lista\n");
        else {
            while (CB->info != elemento && CB != NULL)
                CB = CB->prox;

            if (CB == NULL)
                printf("\nNao achou o elemento desejado");
            else
                printf("O elemento %c esta correto e existe na lista");
        }
    }
}

TpPont* ExcluirElemento(TpPont * CB) {
    TpPont* ant, * atual;
    char Elemento;
    Elemento = FornecerElemento();
    if (CB == NULL)
        printf("\nLista NULL, nada para excluir");
    else {
        if (CB->info == Elemento) {
            atual = CB;
            CB = CB->prox;
            delete(atual);
        }
        else {
            ant = CB;
            atual = CB->prox;

            while (atual != NULL && atual->info != Elemento) {
                ant = atual;
                atual = atual->prox;
            }

            if (atual == NULL)
                printf("\nNao achou");
            else {
                ant->prox = atual->prox;
                delete(atual);
            }
        }
    }
    return CB;
}

TpPont* ExcluirElementoRecursivo(TpPont * CB) {

    TpPont* aux;
    char Elemento;
    Elemento = FornecerElemento();

    if (CB == NULL)
        return NULL;
    else {
        if (CB->info == Elemento) {
            aux = CB;
            CB = CB->prox;
            delete(aux);
            return CB;
        }
        else {
            CB->prox = ExcluirElementoRecursivo(CB->prox);
            return CB;
        }

    }
}

TpPont* ExcluirListaTodaIterativo(TpPont * CB) {
    TpPont* ant, * atual;
    ant = CB;
    if (CB == NULL)
        printf("\nLista esta null");
    else {
        while (ant != NULL) {
            atual = ant->prox;
            delete(ant);
            ant = atual;
        }
        CB = ant;
    }
    return CB;
}

TpPont* ExcluirListaTodaRecursivo(TpPont * CB) {
    if (CB == NULL)
        return NULL;
    else
        ExcluirListaTodaRecursivo(CB->prox);
    delete(CB);
    return NULL;
}
#pragma endregion


struct RegBin {

    char Nome[100], Curso[10], DataNascimento[15], Endereco[30], Cidade[30], Estado[20];
    RegBin* prox;
};

void ExibirDadosArquivoBinario() {
    
    char nomeArq[100];
    printf("\nQual o nome do arquivo ?  ");

    printf("\nForneça o nome (pressione Enter para sair): ");
    fgets(nomeArq, sizeof(nomeArq), stdin);
    nomeArq[strcspn(nomeArq, "\n")] = '\0';

    FILE* Ptr = fopen(nomeArq, "rb");
    if (Ptr == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    RegBin dados;
    // Leia e exiba enquanto fread retornar 1 (indicando que uma estrutura foi lida com sucesso)
    while (fread(&dados, sizeof(RegBin), 1, Ptr) == 1) {
        printf("Nome: %s\n", dados.Nome);
        printf("Curso: %s\n", dados.Curso);
        printf("Data de Nascimento: %s\n", dados.DataNascimento);
        printf("Endereço: %s\n", dados.Endereco);
        printf("Cidade: %s\n", dados.Cidade);
        printf("Estado: %s\n", dados.Estado);
        printf("\n");
    }

    Sleep(5000);
    fclose(Ptr);
}



void PopularStructBinaria() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Ou "Portuguese"
    system("chcp 65001 > nul");

    FILE* Ptr = fopen("Dados.dat", "ab");
    RegBin dados;

    printf("\nForneça o nome (pressione Enter para sair): ");
    fgets(dados.Nome, sizeof(dados.Nome), stdin);
    dados.Nome[strcspn(dados.Nome, "\n")] = '\0';

    while (strcmp(dados.Nome, "") != 0) {
        printf("Forneça o curso: ");
        fgets(dados.Curso, sizeof(dados.Curso), stdin);
        dados.Curso[strcspn(dados.Curso, "\n")] = '\0';

        printf("Forneça a data de nascimento (dd/mm/aaaa): ");
        fgets(dados.DataNascimento, sizeof(dados.DataNascimento), stdin);
        dados.DataNascimento[strcspn(dados.DataNascimento, "\n")] = '\0';

        printf("Forneça o endereço: ");
        fgets(dados.Endereco, sizeof(dados.Endereco), stdin);
        dados.Endereco[strcspn(dados.Endereco, "\n")] = '\0';

        printf("Forneça a cidade: ");
        fgets(dados.Cidade, sizeof(dados.Cidade), stdin);
        dados.Cidade[strcspn(dados.Cidade, "\n")] = '\0';

        printf("Forneça o estado (sigla de 2 letras): ");
        fgets(dados.Estado, sizeof(dados.Estado), stdin);
        dados.Estado[strcspn(dados.Estado, "\n")] = '\0';

        fwrite(&dados, sizeof(RegBin), 1, Ptr);

        printf("\nForneça outro nome (pressione Enter para sair): ");
        fgets(dados.Nome, sizeof(dados.Nome), stdin);
        dados.Nome[strcspn(dados.Nome, "\n")] = '\0';
    }
    fclose(Ptr);
}

RegBin* InserindoDadosBinarioOrdenadoLDSE(RegBin* CB) {
    RegBin* ant, * atual, * nc;
    FILE* PtrArq = fopen("Dados.dat", "rb");
    RegBin dados;

    fread(&dados, sizeof(RegBin), 1, PtrArq);
    while (!feof(PtrArq)) {
        nc = new RegBin;
        if (CB == NULL) {
            strcpy(nc->Nome, dados.Nome);
            strcpy(nc->Estado, dados.Estado);
            strcpy(nc->Endereco, dados.Endereco);
            strcpy(nc->DataNascimento, dados.DataNascimento);
            strcpy(nc->Curso, dados.Curso);
            strcpy(nc->Cidade, dados.Cidade);
            nc->prox = NULL;
            nc->prox = CB;
            CB = nc;

            //fread(&dados, sizeof(RegBin), 1, PtrArq);
        }
        else {

            if (strcmp(dados.Nome, CB->Nome) < 0) {
                strcpy(nc->Nome, dados.Nome);
                strcpy(nc->Estado, dados.Estado);
                strcpy(nc->Endereco, dados.Endereco);
                strcpy(nc->DataNascimento, dados.DataNascimento);
                strcpy(nc->Curso, dados.Curso);
                strcpy(nc->Cidade, dados.Cidade);
                nc->prox = NULL;
                nc->prox = CB;
                CB = nc;

                fread(&dados, sizeof(RegBin), 1, PtrArq);
            }
            else {

                ant = CB;
                atual = CB->prox;

                while (atual != NULL && strcmp(dados.Nome, atual->Nome) > 0) {
                    ant = atual;
                    atual = atual->prox;
                }
                if (ant->prox == NULL && atual == NULL && strcmp(ant->Nome, dados.Nome) < 0) {
                    strcpy(nc->Nome, dados.Nome);
                    strcpy(nc->Estado, dados.Estado);
                    strcpy(nc->Endereco, dados.Endereco);
                    strcpy(nc->DataNascimento, dados.DataNascimento);
                    strcpy(nc->Curso, dados.Curso);
                    strcpy(nc->Cidade, dados.Cidade);
                    nc->prox = NULL;
                    ant->prox = nc;
                }

                else if (strcmp(atual->Nome, dados.Nome) > 0) {
                    strcpy(nc->Nome, dados.Nome);
                    strcpy(nc->Estado, dados.Estado);
                    strcpy(nc->Endereco, dados.Endereco);
                    strcpy(nc->DataNascimento, dados.DataNascimento);
                    strcpy(nc->Curso, dados.Curso);
                    strcpy(nc->Cidade, dados.Cidade);
                    nc->prox = NULL;
                    ant->prox = nc;
                    nc->prox = atual;

                }

                fread(&dados, sizeof(RegBin), 1, PtrArq);
            }
        }
    }

    return CB;
}

RegBin* InserindoDadosBinarioOrdenadoLDSESemArq(RegBin* CB, RegBin* no) {
    RegBin* ant, * atual, * nc;
    nc = new RegBin;

    if (CB == NULL) {
        strcpy(nc->Nome, no->Nome);
        strcpy(nc->Estado, no->Estado);
        strcpy(nc->Endereco, no->Endereco);
        strcpy(nc->DataNascimento, no->DataNascimento);
        strcpy(nc->Curso, no->Curso);
        strcpy(nc->Cidade, no->Cidade);
        nc->prox = NULL;
        CB = nc;  
    }
    else {
        if (strcmp(no->Nome, CB->Nome) < 0) {
            strcpy(nc->Nome, no->Nome);
            strcpy(nc->Estado, no->Estado);
            strcpy(nc->Endereco, no->Endereco);
            strcpy(nc->DataNascimento, no->DataNascimento);
            strcpy(nc->Curso, no->Curso);
            strcpy(nc->Cidade, no->Cidade);
            nc->prox = NULL;
            nc->prox = CB;
            CB = nc;
        }
        else {
            ant = CB;
            atual = CB->prox;

            while (atual != NULL && strcmp(no->Nome, atual->Nome) > 0) {
                ant = atual;
                atual = atual->prox;
            }
            if (ant->prox == NULL && atual == NULL && strcmp(ant->Nome, no->Nome) < 0) {
                strcpy(nc->Nome, no->Nome);
                strcpy(nc->Estado, no->Estado);
                strcpy(nc->Endereco, no->Endereco);
                strcpy(nc->DataNascimento, no->DataNascimento);
                strcpy(nc->Curso, no->Curso);
                strcpy(nc->Cidade, no->Cidade);
                nc->prox = NULL;
                ant->prox = nc;
            }
            else if (atual != NULL && strcmp(atual->Nome, no->Nome) > 0) {
                strcpy(nc->Nome, no->Nome);
                strcpy(nc->Estado, no->Estado);
                strcpy(nc->Endereco, no->Endereco);
                strcpy(nc->DataNascimento, no->DataNascimento);
                strcpy(nc->Curso, no->Curso);
                strcpy(nc->Cidade, no->Cidade);
                nc->prox = NULL;
                ant->prox = nc;
                nc->prox = atual;
            }
        }
    }

    return CB;
}


RegBin* InserirDadosBinarioLDSE(RegBin* CB) {
    FILE* PtrArq = fopen("Dados.dat", "rb");
    RegBin* nc;
    RegBin dados;
    nc = new RegBin;
    fread(&dados, sizeof(RegBin), 1, PtrArq);
    while (!feof(PtrArq)) {
        strcpy(nc->Nome, dados.Nome);
        strcpy(nc->Estado, dados.Estado);
        strcpy(nc->Endereco, dados.Endereco);
        strcpy(nc->DataNascimento, dados.DataNascimento);
        strcpy(nc->Curso, dados.Curso);
        strcpy(nc->Cidade, dados.Cidade);
        nc->prox = NULL;
        CB = InserindoDadosBinarioOrdenadoLDSESemArq(CB,nc);
        fread(&dados, sizeof(RegBin), 1, PtrArq);
    }
    
    return CB;
    fclose(PtrArq);
}





void ExibeListaTodaRecursivoBinario(RegBin* CB) {
    if (CB == NULL) {
        printf("\nLista NULL");
        Sleep(5000);
        return;
    }
    else {
        
        printf("Nome: %s\n", CB->Nome);
        printf("Curso: %s\n", CB->Curso);
        printf("Data de Nascimento: %s\n", CB->DataNascimento);
        printf("Endereco: %s\n", CB->Endereco);
        printf("Cidade: %s\n", CB->Cidade);
        printf("Estado: %s\n", CB->Estado);
        printf("\n");

        
        ExibeListaTodaRecursivoBinario(CB->prox);
    }
}


void ConsultarNomeBinario(RegBin* CB) {
    RegBin dados;
    printf("\nNome para consultar: ");
    fgets(dados.Nome, sizeof(dados.Nome), stdin);
    dados.Nome[strcspn(dados.Nome, "\n")] = '\0';

    if (CB == NULL)
        printf("\nLista NULL, nada para consultar");
    else {

        while (strcmp(CB->Nome, dados.Nome) != 0 && CB->prox!=NULL)
            CB = CB->prox;

        if (strcmp(CB->Nome, dados.Nome) == 0) {
            printf("Nome: %s\n", CB->Nome);
            printf("Curso: %s\n", CB->Curso);
            printf("Data de Nascimento: %s\n", CB->DataNascimento);
            printf("Endereco: %s\n", CB->Endereco);
            printf("Cidade: %s\n", CB->Cidade);
            printf("Estado: %s\n", CB->Estado);
        }
        else
            printf("\nNao achou o nome na LDSE");

    }
    Sleep(5000);
}


RegBin* InserirOrdenadoArquivoTexto(RegBin* CB) {
    FILE* PtrArq = fopen("Arq.txt", "w");

    while (CB != NULL) {
        fprintf(PtrArq, "%-20s %-10s %-15s %-30s %-30s %-20s\n", CB->Nome, CB->Curso, CB->DataNascimento, CB->Endereco, CB->Cidade, CB->Estado);
        fprintf(PtrArq, "\n");
        CB = CB->prox;
    }
    printf("\nInseridos!\n");
    Sleep(5000);
    fclose(PtrArq);

    return CB;
}

RegBin* InserirDadosOrdenadosEmUmBinario(RegBin* CB) {
    FILE* PtrArq = fopen("DadosOrdenados.dat", "ab");
    RegBin dados;
    while (CB != NULL) {
        fwrite(CB, sizeof(RegBin), 1, PtrArq);
        CB = CB->prox;
    }
    printf("\nInseridos!\n");
    Sleep(5000);
    fclose(PtrArq);
    return CB;

}


RegBin* ExcluirLDSEBinariaRecursiva(RegBin* CB) {
    if (CB == NULL)
        return NULL;
    else
        ExcluirLDSEBinariaRecursiva(CB->prox);
    delete(CB);
    return NULL;
}


RegBin* ExcluirLDESEBinariaIterativa(RegBin* CB) {

    RegBin* ant, * atual;
    ant = CB;
    if (CB == NULL)
        printf("\nLista NULL");
    else {

        while (ant != NULL) {
            atual = ant->prox;
            delete(ant);
            ant = atual;
        }
        CB = ant;
    }
    return CB;
}

RegBin* ExcluirUmNomeDaLDSE(RegBin* CB) {

    RegBin* ant, * atual,dados;
    
    printf("\nNome para excluir: ");
    fgets(dados.Nome, sizeof(dados.Nome), stdin);
    dados.Nome[strcspn(dados.Nome, "\n")] = '\0';

    if (CB == NULL)
        printf("\nLista NULL");
    else {

        if (strcmp(CB->Nome, dados.Nome) == 0) {
            ant = CB;
            CB = CB->prox;
            delete(ant);
            return CB;
        }
        else {
            CB->prox = ExcluirUmNomeDaLDSE(CB->prox);
            return CB;
        }

    }
}


char Menu(void)
{

    system("cls");
    printf("### MENU PARA OS Exercicios de Pilha padrao e caso 1 e 2 ###\n");
    printf("**** MENU DE OPCOES ****");
    printf("\n[A] Inserir no inicio - Codigo simples ");
    printf("\n[B] Inserir no inicio - Codigo mais complexo");
    printf("\n[C] Inserir de forma ordenada [A-Z]");
    printf("\n[D] Exibir elemento do inicio da lista");
    printf("\n[E] Exibir elemento do final da lista");
    printf("\n[F] Inserir no final da lista");
    printf("\n[G] Exibe toda Lista - Iterativa");
    printf("\n[H] Exibe toda Lista - Recursivo");
    printf("\n[I] Inserir entre dois elementos");
    printf("\n[J] Consultar elemento");
    printf("\n[K] Excluir um determinado elemento - Iterativo");
    printf("\n[L] Excluir toda a lista - Iterativo");
    printf("\n[M] Excluir toda a lista - Recursivo");
    printf("\n[N] Excluir um determinado elemento - Recursivo");
    printf("\n---LENDO DADOS DE UM BINARIO---");
    printf("\n[O] Popular arquivo binario");
    printf("\n[P] Inserir os dados do arquivo binario na LDSE");
    printf("\n[Q] Inserir os dados do arquivo binario ordenados na LDSE");
    printf("\n[R] Exibir dados binario");
    printf("\n[S] Exibir os dados passados para a LDSE");
    printf("\n[T] Consultar determinado dado da LDSE");
    printf("\n[U] Inserir os dados da LDSE para um TXT - Ja ordenados");
    printf("\n[V] Inserir os dados da LDSE para um BINARIO - Ja ordenado");
    printf("\n[W] Excluir um dado da LDSE - Recursivo");
    printf("\n[X] Excluir toda LDSE - Iterativa");
    printf("\n[Y] Excluir toda LDSE - Recursiva");
    printf("\n---LENDO DADOS DE UM TXT---");
    printf("\n[Z] ");


    printf("\n[ESC] Sair do Programa");
    printf("\nOpcao: ");

    _getch();
    return toupper(_getch());



}

int main() {
    char opcao;
    TpPont* Lista = NULL;
    RegBin* List = NULL;
    do
    {
        opcao = Menu();
        system("cls");
        switch (opcao)
        {

        case 'A':
            Lista=InserirInit(Lista);
            break;
        case 'B':
            Lista = InserirInit2(Lista);
            break;
        case 'C':
            Lista = InserirOrdenado(Lista);
            break;
        case 'D':
            ExibirElementoInitLDSE(Lista);
            break;
        case 'E':
            ExibirElementoLastLDSE(Lista);
            break;
        case 'F':
            Lista = InserirAposElementoLast(Lista);
            break;
        case 'G':
            ExibeListaToda(Lista);
            break;
        case 'H':
            ExibeListaTodaRecursivo(Lista);
            break;
        case 'I':
            Lista = InserirEntreElementos(Lista);
            break;
        case 'J':
            ConsultarElemento(Lista);
            break;
        case 'K':
            Lista = ExcluirElemento(Lista);
            break;

        case 'L':
            Lista = ExcluirListaTodaIterativo(Lista);
            break;

        case 'M':
            Lista = ExcluirListaTodaRecursivo(Lista);
            break;
        case 'N':
            Lista = ExcluirElementoRecursivo(Lista);
            break;
        case 'O':
            PopularStructBinaria();
            break;
        case 'P':
            List = InserirDadosBinarioLDSE(List);
            break;
        case 'Q':
            List = InserindoDadosBinarioOrdenadoLDSE(List);
            break;
        case 'R':
            ExibirDadosArquivoBinario();
            break;
        case 'S':
            ExibeListaTodaRecursivoBinario(List);
            break;
        case 'T':
            ConsultarNomeBinario(List);
            break;
        case 'U':
            InserirOrdenadoArquivoTexto(List);
            break;
        case 'V':
            InserirDadosOrdenadosEmUmBinario(List);
            break;
        case 'W':
            List = ExcluirUmNomeDaLDSE(List);
            break;
        case 'X':
            List = ExcluirLDESEBinariaIterativa(List);
            break;
        case 'Y':
            List = ExcluirLDSEBinariaRecursiva(List);
            break;
        case 'Z':
            break;
        }

    } while (opcao != 27);
    return 0;
}