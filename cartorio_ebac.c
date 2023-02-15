#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // bilbioteca de aloca��es string

int cadastrar() // Int respons�vel por fazer o cadastro dos usu�rios
{
	//Iinicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];	
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvando o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o Arquivo
	fprintf(file,","); // colocando v�rgula entre uma informa��o e outra
	fclose(file); // fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); //Analisando resposta do usu�rio
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo, o "a" � para atualizar o com a informa��o
	fprintf(file,nome); //Salvando o valor da vari�vel
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo
	fprintf(file,","); //colcoando v�rgula entre uma informa��o do usu�rio e outra
	fclose(file); //Fechando o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); //Coletando informa��es
	scanf("%s", sobrenome); //Analisando resposta do usu�rio
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e pedindo para atualizar com a resposta do usu�rio
	fprintf(file,sobrenome); //Salvando a informa��o do usu�rio
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizando com a informa��o do usu�rio
	fprintf(file,","); //Colocando v�rgula entre as informa��es
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es
	scanf("%s", cargo); //Analisando a resposta do usu�rio lembrando que o "%s" refere-se a string

	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando ele com a informa��o do usu�rio
	fprintf(file,cargo); //Salvando informa��o
	fclose(file); //Fechando o arquivo
	
	system("pause"); // Pausando o programa na p�gina
}

int consultar() //Int respons�vel por realizar a consulta de usu�rios
{
	setlocale(LC_ALL,"Portuguese"); // selecionando a l�nguaguem
	
	char cpf[40]; // Criando a char para armazenar informa��es de CPF
	char conteudo[200]; // Criando a char conteudo
	
	printf("digite o CPF a ser consultado: "); //Coletando informa��es
	scanf("%s",cpf); //Analisando informa��es

	FILE *file; //Criando arquivo
	file = fopen(cpf,"r"); //Abrindo arquivo, o "r" para ele ler a informa��o
	
	if(file == NULL) //fun��o que faz a consulta da resposta no arquivo
	{
		printf("N�o foi possivel abrir o Arquivo, n�o localizado!.\n"); //mensagem de alerta
	}

	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];	//Criando arquivo cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Colhendo informa��es
	scanf("%s",cpf); //Analisando informa��es
	
	remove(cpf);//deletando informa��es
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //Abrindo o arquivo e pedindo para ele ler o que est� na pasta
	
	if(file == NULL)//Se o dado coletado for diferente do que tem na pasta, ele vai mostrar a frase de que n�o encontrou
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //frase alerta
		system("pause");//pausando a tela
	}
	
	else //se caso o dado indicado bater com o banco de dados ele vai mostrar que conseguiu deletar com sucesso o usu�rio
	{
		printf("Usu�rio deletado com sucesso!.\n");//mensagem de resposta
		system("pause");//pausando a tela
	}
}

int main()
{
	int opcao=0; // definindo vari�veis
	
	int x=1; // definindo valor para a vari�vel "X"
	
	for (x=1;x=1;) // confirmando que o programa ser� executado at� o usu�rio fechar
	{
	
		system("cls");
	
	
		setlocale(LC_ALL,"Portuguese"); // selecionando a l�nguaguem
	
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do Menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n"); // Cadastro
		printf("\t2 - Consultar nomes\n"); // Consulta
		printf("\t3 - Deletar nomes\n\n"); // Delete
		printf("op��o: "); // Fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao)
		{
			case 1:
			cadastrar();
			break;
			
			case 2:	
			consultar();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("esta op��o n�o est� dispon�vel\n");
			system("pause"); // pausando o sistema na escolha do usu�rio
			break;
			
		}
	}
}
