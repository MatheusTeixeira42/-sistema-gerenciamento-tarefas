#include <stdio.h>
#include <string.h>

#define Quantidade 100
#define Tamanho 50

    void CadastrarTarefa(char tarefas[][4][50], int *QuantidadeTarefas);
    void ListarTarefas(char tarefas[][4][50], int QuantidadeTarefas);
    void EditarTarefa(char tarefas[][4][50], int indice);
    void ExcluirTarefa(char tarefas[][4][50], int *QuantidadeTarefas, int indice);
    void SalvarTarefasEmArquivo(char tarefas[][4][50], int QuantidadeTarefas);

int main()
{
    int Tipo=0;
    int QuantidadeTarefas=0;
    char Tarefas[Quantidade][4][Tamanho];
    int indice;
    
    do{
    
        printf("=== Sistema de Gerenciamento de Tarefas ===\n");
        printf("1. Cadastrar Tarefas\n");
        printf("2. Listar Tarefas\n");
        printf("3. Editar Tarefas\n");
        printf("4. Excluir Tarefas\n");
        printf("5. Salvar Tarefas em Arquivos\n");
        printf("6. Sair\n");
        printf("Escolha uma opção:");
        scanf("%d",&Tipo);
        getchar();
        printf("\n");
        
            switch (Tipo){
                case 1:
                    CadastrarTarefa(Tarefas, &QuantidadeTarefas);
                    QuantidadeTarefas=QuantidadeTarefas+1;
            break;
                
            case 2:
                ListarTarefas(Tarefas, QuantidadeTarefas);
            break;
            
            case 3:
                printf("Digite o numero da tarefa que deseja editar:");
                scanf("%d", &indice);
                getchar();
                
                    if (indice <= QuantidadeTarefas && indice > 0) {
                         EditarTarefa(Tarefas, indice-1);
                    }
                    else {
                        printf("Tarefa indisponível\n");
                    }
                break;
                
            case 4:
                printf("Digite o número da tarefa que deseja excluir: ");
                scanf("%d", &indice);
                getchar();
                ExcluirTarefa(Tarefas, &QuantidadeTarefas, indice-1);
                break;
            
            case 5:
                SalvarTarefasEmArquivo(Tarefas,QuantidadeTarefas);
                break;
            case 6:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                
        }
        
        printf("\n");
        
        
    }while(Tipo!=6);
    
    
    return 0;
}

        void CadastrarTarefa(char tarefas[][4][50], int *quantidade){
        
            printf("Cadastro de Tarefas\n");
            
            printf("Descrição: ");
                fgets(tarefas[*quantidade][0],Tamanho, stdin);
                 
            printf("Prioridade (Alta/Média/Baixa): ");
                fgets(tarefas[*quantidade][1],Tamanho, stdin);
            
            printf("Status (Pendente/Concluído):");
                fgets(tarefas[*quantidade][2],Tamanho, stdin);
                
           
                
            printf("\nTarefa cadastrada com sucesso!\n\n");
            
            
        }
        
        void ListarTarefas(char tarefas[][4][50], int QuantidadeTarefas){
            
            printf("Lista de tarefas\n\n");
            
            int contador=0;
            
                for(contador=0;contador<QuantidadeTarefas;contador=contador+1){
                    printf("Tarefa %d\n",contador+1);
                    printf("Descrição:%s",tarefas[contador][0]);
                    printf("Prioridade:%s",tarefas[contador][1]);
                    printf("Status:%s",tarefas[contador][2]);
                    printf("\n");
                }
        }
        
        void EditarTarefa(char tarefas[][4][50], int indice){
            
            printf("Edição de Tarefas\n");
            
            printf("Descrição:");
                fgets(tarefas[indice][0],Tamanho, stdin);
                 
            printf("Prioridade (Alta/Média/Baixa):");
                fgets(tarefas[indice][1],Tamanho, stdin);
            
            printf("Status (Pendente/Concluído):");
                fgets(tarefas[indice][2],Tamanho, stdin);
                
            printf("\n");
                
            printf("Tarefa editada com sucesso com sucesso!\n\n");
            
        }
        
        void ExcluirTarefa(char tarefas[][4][50], int *quantidade, int indice) {
                
                if (indice<0 || indice>=*quantidade) {
                    printf("Índice inválido!\n");
                return;
                }

                for (int i=indice; i<*quantidade-1;i=i+1) {
                    for (int j=0;j<4;j++) {
                        strcpy(tarefas[i][j], tarefas[i+1][j]);
                     }
                }

                    (*quantidade)--;

                    printf("Tarefa excluída com sucesso!\n");
        }
        
        
       void SalvarTarefasEmArquivo(char tarefas[][4][50], int quantidade) {
            FILE *arquivo = fopen("tarefas.txt", "w");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo para escrita.\n");
                return;
                }

                for (int i = 0; i<quantidade; i=i+1) {
                    fprintf(arquivo, "Tarefa %d: %s - Prioridade: %s - Status: %s",i+1, tarefas[i][0], tarefas[i][1], tarefas[i][2]); 
                    
                }

                fclose(arquivo);

    printf("Tarefas salvas com sucesso em 'tarefas.txt'.");
} 
        

    