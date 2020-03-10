/*g++ -o "nome que vai ficar o execultavel" "nome do arquivo"

./"nome do execultavel"

Crie uma agenda em C++, capaz de apresentar e executar o seguinte menu de opção:

- cadastrar;

-Listar;

-Sair

Dados a serem cadastrados no arquivo: nome, telefone, email, endereço e código (utilize uma struct)
O programa deverá ser capaz de criar uma arquivo (caso não existe) e adicionar dados (você deverá utilizar wt, rt e a;

Poste apenas o cpp



#include <iostream>
int main() {

FILE *arquivo;

fopen("teste.txt","wt");//wt = gravação

	if (arquivo==NULL)
	{
		printf("não foi possível abrir o arquivo");
		exit(0);
	}
		fclose(arquivo);
		system("pause");
		return 0;
	}*/
	
#include <iostream>
#include <string.h>
#include <locale.h>

struct agenda{
	char nome[50];
	char telefone[12];
	char email[50];
	char endereco[100];
	int codigo=0;
	
};

void salvaTxt(agenda txt){
	FILE *arquivo;
	arquivo=fopen("Agenda.txt","a"); //a = adicionar
	
	if(arquivo==NULL)
	{
	printf("não foi possível abrir o arquivo");
	exit(0);
	}
	else{
	
		fprintf(arquivo,"Nome: ");
		fputs(txt.nome,arquivo);
		
		fprintf(arquivo,"Telefone: ");
		fputs(txt.telefone,arquivo);
		
		fprintf(arquivo,"email: ");
		fputs(txt.email,arquivo);
		
		fprintf(arquivo,"Endereço: ");
		fputs(txt.nome,arquivo);
		
		fprintf(arquivo,"Código: ");
		fputc(txt.codigo,arquivo);
	}
	
	fclose(arquivo);
	system("pause");
}

void cadastrar(agenda agenda){


	int posicao;
	system("cls");
		printf("\nNome: "); 
		getchar();
		fgets(agenda.nome,50,stdin);
		printf("\nTelefone: "); 
		getchar();
		fgets(agenda.telefone,12,stdin);
		printf("\nEmail: "); 
		getchar();
		fgets(agenda.email,50,stdin);
		printf("\nEndereço: "); 
		getchar();
		fgets(agenda.endereco,100,stdin);			
		agenda.codigo++;
			
}

void listar(){
	FILE *arquivo;
	arquivo=fopen("Agenda.txt", "rt"); //abre o arquivo
	if (arquivo==NULL) {
		printf("Não foi possível abrir o arquivo.\n");
		system("pause");
		exit(1);
	}
	
		//fclose(arquivo); //fecha o arquivo
}

int main(){
	
	int menu;
	agenda cadastro;
	
	setlocale(LC_ALL, "Portuguese"); 
	
	do{
		system("cls");
		printf("Escolha dentre a opções:\n1-Cadastrar\n2-Listar\n0-SAIR\n\n");
		
		scanf("%d",&menu);
		switch(menu){
	 		case 1:
	 			cadastrar(cadastro);
	 			salvaTxt(cadastro);
	 		break;
	 		case 2:
	 			listar();
	 		break;
	 		
	 		default:
	 			printf("Digite um número válido");
		}
	}while(menu!=0);
	
	return 0;
}
