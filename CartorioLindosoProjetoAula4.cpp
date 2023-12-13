#include <stdio.h>		//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>		//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>		//biblioteca de aloca��o de texto por regi�o
#include <string.h>		//biblioteca respons�vel por cuidar das strings (conjunto de vari�veis)

int registro() //Fun��o respons�vel por cadastrar o usu�rio no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando a infor��o do usu�rio
	scanf("%s",cpf); // "%s"scaneia string (refere-se ao armazenamento das strings)
	
	strcpy(arquivo,cpf);  //Respons�vel por copiar os valores das strings (aqui o nome do arquivo � c�pia do nome do CPF)
	
	FILE *file;  // Cria o aquivo
	file = fopen(arquivo, "w");  //Cria o arquivo e "w" significa "write" escrever
	fprintf(file,cpf); 	// escreve no "file" (arquivo) o valor da vari�vel (CPF)
	fclose(file);	//Fecha o arquivo
	
	
	file = fopen(arquivo,"a");	// abrir o arquivo, "a" � para atualizar a informa��o e n�o escrever uma nova("w")
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
	setlocale(LC_ALL,"Portuguese");	  // Definindo a linguagem( caso o texto exibido contenha acentua��o ou qualquer tipo de escrita p�ropria da linguagem ( aqui no caso o printf quando o arquivo n�o � localizado possui til)
	
	// inicio da defini��o das variaveis
	char cpf[40];
	char conteudo[200];
	 //fim  variaveis
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r"); // "read" o cpf
	 
	 if(file == NULL) // "== NULL" significa n�o existe
	 	{
	 			printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n");	
		}
		 
		 while(fgets(conteudo, 200, file) != NULL) // salvando 200 caracteres que est�o dentro do arquivo (file) e p�ra quando o caractere for nulo (!= NULL)
	 	{
	 			printf("\nEssas s�o as informa��es do usu�rio: \n");	
	 			printf("%s", conteudo);
	 			printf("\n\n");
		}
		 fclose(file); // ****importate fechar o arquivo****
		 system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); // deleta (remove) o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); //fun��o de abrir e "r" (read) para ler 
	
	if(file == NULL);
	{
		fclose(file); 
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}

}

int main()
{	
	
		int opcao=0;	//Definindo as vari�veis
		int laco=1;
		
		for(laco=1;laco=1;)
	
	{
		system("cls");

		setlocale(LC_ALL,"Portuguese");		// Definindo a linguagem

		printf("### Cart�rio da EBAC ###\n\n"); 	//In�cio do Menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");		//Fim do menu
	
		scanf("%d",&opcao);		//Armazenando a escolha do usu�rio "%d% scaneia a vari�vel
	
		system("cls"); //Respons�vel por Limpar a tela (Clear Screen)
		
		switch(opcao)
		{
		case 1:		//In�cio da sele��o
			registro(); //Chamada de fun��es
			break;
			
		case 2: 
			consulta();
			break;
			
		case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel.\n");
			system("pause");
			break;		//Fim da sele��o
			
		}
		
	}
	
	printf("Esse software pertence � L1nd0$0");
	
}
