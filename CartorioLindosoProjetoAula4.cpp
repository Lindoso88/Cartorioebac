#include <stdio.h>		//biblioteca de comunicação com o usuário
#include <stdlib.h>		//biblioteca de alocação de espaço em memória
#include <locale.h>		//biblioteca de alocação de texto por região
#include <string.h>		//biblioteca responsável por cuidar das strings (conjunto de variáveis)

int registro() //Função responsável por cadastrar o usuário no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a inforção do usuário
	scanf("%s",cpf); // "%s"scaneia string (refere-se ao armazenamento das strings)
	
	strcpy(arquivo,cpf);  //Responsável por copiar os valores das strings (aqui o nome do arquivo é cópia do nome do CPF)
	
	FILE *file;  // Cria o aquivo
	file = fopen(arquivo, "w");  //Cria o arquivo e "w" significa "write" escrever
	fprintf(file,cpf); 	// escreve no "file" (arquivo) o valor da variável (CPF)
	fclose(file);	//Fecha o arquivo
	
	
	file = fopen(arquivo,"a");	// abrir o arquivo, "a" é para atualizar a informação e não escrever uma nova("w")
	fprintf(file,","); // Virgula para separar
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");	  // Definindo a linguagem( caso o texto exibido contenha acentuação ou qualquer tipo de escrita p´ropria da linguagem ( aqui no caso o printf quando o arquivo não é localizado possui til)
	
	// inicio da definição das variaveis
	char cpf[40];
	char conteudo[200];
	 //fim  variaveis
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r"); // "read" o cpf
	 
	 if(file == NULL) // "== NULL" significa não existe
	 	{
	 			printf("Não foi possível abrir o arquivo, não localizado.\n");	
		}
		 
		 while(fgets(conteudo, 200, file) != NULL) // salvando 200 caracteres que estão dentro do arquivo (file) e pára quando o caractere for nulo (!= NULL)
	 	{
	 			printf("\nEssas são as informações do usuário: \n");	
	 			printf("%s", conteudo);
	 			printf("\n\n");
		}
		 fclose(file); // ****importate fechar o arquivo****
		 system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // deleta (remove) o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); //função de abrir e "r" (read) para ler 
	
	if(file == NULL);
	{
		fclose(file); 
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}

}

int main()
{	
	
		int opcao=0;	//Definindo as variáveis
		int laco=1;
		
		for(laco=1;laco=1;)
	
	{
		system("cls");

		setlocale(LC_ALL,"Portuguese");		// Definindo a linguagem

		printf("### Cartório da EBAC ###\n\n"); 	//Início do Menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");		//Fim do menu
	
		scanf("%d",&opcao);		//Armazenando a escolha do usuário "%d% scaneia a variável
	
		system("cls"); //Responsável por Limpar a tela (Clear Screen)
		
		switch(opcao)
		{
		case 1:		//Início da seleção
			registro(); //Chamada de funções
			break;
			
		case 2: 
			consulta();
			break;
			
		case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível.\n");
			system("pause");
			break;		//Fim da seleção
			
		}
		
	}
	
	printf("Esse software pertence à L1nd0$0");
	
}
