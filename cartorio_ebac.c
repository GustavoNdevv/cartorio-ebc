#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // bilbioteca de alocações string

int cadastrar() // Int responsável por fazer o cadastro dos usuários
{
	//Iinicio da criação de variáveis
	char arquivo[40];
	char cpf[40];	
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // Abre o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvando o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o Arquivo
	fprintf(file,","); // colocando vírgula entre uma informação e outra
	fclose(file); // fechando arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //Analisando resposta do usuário
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo, o "a" é para atualizar o com a informação
	fprintf(file,nome); //Salvando o valor da variável
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo
	fprintf(file,","); //colcoando vírgula entre uma informação do usuário e outra
	fclose(file); //Fechando o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); //Coletando informações
	scanf("%s", sobrenome); //Analisando resposta do usuário
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e pedindo para atualizar com a resposta do usuário
	fprintf(file,sobrenome); //Salvando a informação do usuário
	fclose(file); //Fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo o arquivo e atualizando com a informação do usuário
	fprintf(file,","); //Colocando vírgula entre as informações
	fclose(file); //Fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações
	scanf("%s", cargo); //Analisando a resposta do usuário lembrando que o "%s" refere-se a string

	file = fopen(arquivo, "a"); //abrindo o arquivo e atualizando ele com a informação do usuário
	fprintf(file,cargo); //Salvando informação
	fclose(file); //Fechando o arquivo
	
	system("pause"); // Pausando o programa na página
}

int consultar() //Int responsável por realizar a consulta de usuários
{
	setlocale(LC_ALL,"Portuguese"); // selecionando a línguaguem
	
	char cpf[40]; // Criando a char para armazenar informações de CPF
	char conteudo[200]; // Criando a char conteudo
	
	printf("digite o CPF a ser consultado: "); //Coletando informações
	scanf("%s",cpf); //Analisando informações

	FILE *file; //Criando arquivo
	file = fopen(cpf,"r"); //Abrindo arquivo, o "r" para ele ler a informação
	
	if(file == NULL) //função que faz a consulta da resposta no arquivo
	{
		printf("Não foi possivel abrir o Arquivo, não localizado!.\n"); //mensagem de alerta
	}

	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];	//Criando arquivo cpf
	
	printf("Digite o CPF do usuário a ser deletado: "); //Colhendo informações
	scanf("%s",cpf); //Analisando informações
	
	remove(cpf);//deletando informações
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //Abrindo o arquivo e pedindo para ele ler o que está na pasta
	
	if(file == NULL)//Se o dado coletado for diferente do que tem na pasta, ele vai mostrar a frase de que não encontrou
	{
		printf("O usuário não se encontra no sistema!.\n"); //frase alerta
		system("pause");//pausando a tela
	}
	
	else //se caso o dado indicado bater com o banco de dados ele vai mostrar que conseguiu deletar com sucesso o usuário
	{
		printf("Usuário deletado com sucesso!.\n");//mensagem de resposta
		system("pause");//pausando a tela
	}
}

int main()
{
	int opcao=0; // definindo variáveis
	
	int x=1; // definindo valor para a variável "X"
	
	for (x=1;x=1;) // confirmando que o programa será executado até o usuário fechar
	{
	
		system("cls");
	
	
		setlocale(LC_ALL,"Portuguese"); // selecionando a línguaguem
	
		printf("### Cartório da EBAC ###\n\n"); // Início do Menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n"); // Cadastro
		printf("\t2 - Consultar nomes\n"); // Consulta
		printf("\t3 - Deletar nomes\n\n"); // Delete
		printf("opção: "); // Fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
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
			printf("esta opção não está disponível\n");
			system("pause"); // pausando o sistema na escolha do usuário
			break;
			
		}
	}
}
