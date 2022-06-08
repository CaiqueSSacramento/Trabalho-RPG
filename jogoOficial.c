#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct ficha
{
	char nome[50];
	int str;
	int con;
	int agi;
	int dex;
	int pv;	
} FICHA;

typedef struct monstro
{
	int str;
	int con;
	int agi;
	int dex;
	int pv;	
} MONSTRO;

typedef struct defesa
{
	int doMonstro;
	int doJogador;
} DEFESA;

void main()
{
	int ivo = 0;
	while(ivo == 0)
{//while que determina o Funcionamento do jogo
	
	
	//O COMECO DO JOGO
	int escolha = 0;
	int controladorAtributo;
	int pontos = 15;
	
	FICHA jogador;
	MONSTRO monstro;
	DEFESA defesa;
	int opcao = 5;
	int dado;
	int dano = 0;
	int cura = 0;
	int vidaQualquer = 5;
	int moeda = 5;
	int escolhadaarma = 2;
	int arma = 3;
	int bonusSTR = jogador.str*1.5;
	int ato = 3;
	int roundDefesa = 0;
	int roundDefesam = 0;
	int vidaInicial1 = jogador.pv;
	int vidaInicial1m = monstro.pv;
	int trocaArma = 0;

	printf("Bem-Vindo a The Legends of Sura!\n\n");
	printf("\n\nIntroducao: voce pode escolher 3 caminhos. \n1 - Iniciar o jogo; \n2 - Ler a historia do jogo; \n3 - Encerrar jogo: ");
	printf("\n\nSua escolha: ");
	scanf("%d", &escolha);
	
	
	
	
		switch(escolha)
	{
		case 1: 
		{
			
			
			{/*Criacao de personagem*/
			
			printf("Digite seu nome: ");
			scanf("%s", &jogador.nome);			
			printf("\n\nVoce escolheu iniciar o jogo. Voce tem 15 pontos de atributo para distribuir entre 4 atributos:\n\n");
			printf("Forca eh o atributo que AUMENTA seu DANO com ARMAS PESADAS!\n\n");
			printf("Quantos pontos voce deseja inserir em FORCA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.str = controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.str = 0;
			}
			
			printf("\n\nConstituicao eh o atributo que AUMENTA sua VIDA em 1 ponto e sua DEFESA em 1,5!\n\n");
			printf("Quantos pontos voce deseja inserir em CONSTITUICAO: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.con = controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.con = 0;
			}
			
			printf("\n\nAgilidade eh o atributo que AUMENTA sua VELOCIDADE e determina quem ATACA PRIMEIRO!\n\n");
			printf("Quantos pontos voce deseja inserir em AGILIDADE: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.agi = controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.agi = 0;
			}	
					
			printf("\n\nDestreza eh o atributo que AUMENTA seu dano com ARMAS LEVES\n\n");
			printf("Quantos pontos voce deseja inserir em DESTREZA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.dex = controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.dex = 0;
			}
			srand(time(NULL));
			printf("\n\nJogue 3 dados de 6 lados para definir sua vida: ");
			printf("\n\nJogar o primeiro: ");
			system("pause");
			int dado = rand()%5+1;
			printf("%d", dado);
			jogador.pv = dado;
			
			printf("\n\nJogar o Segundo: ");
			system("pause");
			dado = rand()%5+1;
			printf("%d", dado);
			jogador.pv += dado;
			
			printf("\n\nJogar o terceiro: ");
			system("pause");
			dado = rand()%5+1;
			printf("%d", dado);
			jogador.pv += dado;
			jogador.pv = jogador.pv + jogador.con;
			int escolhaDeArma = 1;
			
			
			printf("\nEscolha entre: \nArma Leve: 1 \nArma Pesada: 2\nSua Escolha: ");
			scanf("%d", &escolhaDeArma);
			printf("\n\nAlem de sua arma, voce tambem recebeu uma ARMADURA");

			defesa.doJogador = 3+(jogador.con*1.5);
			printf("\n\nFicha de %s", jogador.nome);
			printf("\nNome: %s \nPontos de Vida: %d \nDefesa: %d \nFor: %d \nCon: %d\n", jogador.nome, jogador.pv, defesa.doJogador, jogador.str, jogador.con);
			printf("agi: %d \nDes: %d\n", jogador.agi, jogador.dex);
}// bloco de criacao de personagem
			{//criacao de monstro
				
				int contadorMonstro = 15;
				int dadoMonstro = 0;
					monstro.str = rand()%15;
					contadorMonstro = contadorMonstro - monstro.str;
		
					if(contadorMonstro > 0)
					{
					
						monstro.agi = rand()%contadorMonstro;
						contadorMonstro -= monstro.agi;
					}
					if(contadorMonstro > 0)
					{
						monstro.con = rand()%contadorMonstro;
						contadorMonstro -= monstro.con;
					}
					if(contadorMonstro > 0)
					{
						monstro.dex = rand()%contadorMonstro;
						contadorMonstro -= monstro.dex;
					}
					if(contadorMonstro > 0)
					{
						monstro.con += contadorMonstro;
						contadorMonstro = 0;
					}
				dadoMonstro = rand()%5+1;
				dadoMonstro += rand()%5+1;
				dadoMonstro += rand()%5+1;
				defesa.doMonstro = 2+(monstro.con)*1.5;
				monstro.pv = dadoMonstro + monstro.con;
					printf("\nFicha do Monstro: \n\n");
					printf("\nPontos de Vida: %d \nDef: %d \nFor: %d \nCon: %d\n", monstro.pv, defesa.doMonstro, monstro.str, monstro.con);	
					printf("agi: %d \nDes: %d\n", monstro.agi, monstro.dex);

}// bloco de criacao de monstro

	while(opcao != 3)
{	
{//PRIMEIRO COMBATE
		
	while(vidaQualquer > 0)
	{
		
		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}
		if(jogador.pv <= 0)
		{
			break;
		}
		
		if(jogador.agi >= monstro.agi)
		{
			moeda = 1;
		}
		
		if(moeda == 1)
		{
		printf("VEZ DO JOGADOR: Escolha entre \nATACAR - 1 \nDEFENDER - 2 \nPOCAO - 3 \nSua Resposta: ");
		scanf("%d", &ato);
		}
		
switch(ato)
{//VEZ DO JOGADOR
			
			case 1:
			{	
				if(moeda == 1)
				{
				
				
				if(escolhadaarma == 1)
				{				
				printf("\n\nJogue 2 dados de 6 lados e 1 de 4 lados para definir seu dano: ");
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nPrimeiro - %d", dado);
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nSegundo - %d", dado);
				printf("\n\nJogar o dado de 4 lados: ");
				system("pause");
				dado = rand()%3+1;
				printf("\t\nTerceiro - %d\n", dado);
				dano += dado;
				dano += arma;
				dano += jogador.dex;
				if(roundDefesam == 1)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro DUPLICADA)\n\n", dano, arma, defesa.doMonstro*2);
				}	
				else if(roundDefesam == 0)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro)\n\n", dano, arma, defesa.doMonstro);
				}
				}
				if(escolhadaarma == 2)
				{				
				printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
				printf("\n\nJogar o dado de 12 lados: ");
				system("pause");
				dado = rand()%11+1;
				printf("\t\nNumero do dado - %d", dado);
				if(roundDefesam == 1)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (2*defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus  %d dano da arma) - %d DEFESA do monstro DUPLICADA)\n\n", dano, dado, jogador.str*1.5, arma, defesa.doMonstro*2);
				}
				
				else if(roundDefesam == 0)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus %d dano da arma) - %d DEFESA do monstro)\n\n", dano, dado, bonusSTR, arma, defesa.doMonstro);
				}
				}	
				monstro.pv -= dano;
			}//verificacao para saber se o jogador atacara
			}
			if(monstro.pv <= 0)
			{
				printf("\nParabens!! Voce derrotou o Monstro!");
				opcao = 3;
				break;
			}
			moeda = 0;
			
			case 2:
			{	if(moeda == 1)
				{
				
				printf("\nSuas defesas foram DUPLICADAS por 1 round!");
				roundDefesa = 1;
				}
				
			}
			
			case 3:
			{
				if(moeda == 1)
				{
				
				printf("\nVoce usou uma pocao, sua cura sera calculada pela soma de 3 dados de 6 lados!");
				
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nJogar o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((jogador.pv + cura) >= vidaInicial1)
				{
					printf("\nSua vida atual eh %d\n\n", vidaInicial1);
				}
				else
				{
					printf("\nSua vida atual eh %d\n\n", jogador.pv+cura);
				}
				}
			}
}//vez do jogador

		if(monstro.pv <= 0)
		{
			
		
			break;
		}
		
		ato = rand()%2+1;
		printf("\nVez De KalDur!");
		switch(ato)
		{
			
			case 1:
			{	
				printf("\nAs defesas de KalDur foram DUPLICADAS por 1 round!\n\n");
				roundDefesam = 1;
				break;					
			}//ataque monstro
			break;
			case 2:
			{

			printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
			system("pause");
			dado = rand()%11+1;
			printf("\t\nNumero do dado - %d", dado);
			dano = (dado)+(monstro.str);
			printf("\n%d de dano do KalDur em voce\n\n", dano);
			jogador.pv -= dano;
			printf("\n\n\n\nVida atual do jogador: %d \nVida atual do KalDur: %d\n\n", jogador.pv, monstro.pv);
			}//defesa monstro
			break;
			
			case 3:
			{
				printf("\nO KalDur usou uma pocao");
				
				printf("\n\nVer o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nVer o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nVer o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((monstro.pv + cura) >= vidaInicial1m)
				{
					printf("\nA vida atual do KalDur eh %d\n\n", vidaInicial1m);
				}
				else
				{
					printf("\nnA vida atual do KalDur eh %d\n\n", monstro.pv+cura);
				}	
			}//pocao monstro
			break;
		}//Round Monstro	
		moeda = 1;				
}// 1 combate --- PRIMEIRO WHILE

		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}
}//PRIMEIRO COMBATE	
{//PRIMEIRA RECOMPENSA
{//atributos novos
	printf("\n\nParabens! Voce passou de nivel. Sua recompensa serao +5 pontos de atributos para voce distribuir! E uma nova arma dentre 3 armas!\n\n");
	
	pontos = 5;
	printf("Quantos pontos voce deseja inserir em FORCA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.str += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
	
			else
			{
				jogador.str = jogador.str;
			}
	
			printf("Quantos pontos voce deseja inserir em CONSTITUICAO: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.con += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.con = jogador.con;
			}
	
	

			printf("Quantos pontos voce deseja inserir em AGILIDADE: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.agi += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.agi = jogador.agi;
			}	
					

			printf("Quantos pontos voce deseja inserir em DESTREZA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.dex += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.dex = jogador.dex;
			}
	
			jogador.pv = vidaInicial1 + jogador.con;
			printf("\n\nFicha de %s", jogador.nome);
			printf("\nNome: %s \nPontos de Vida: %d \nDefesa: %d \nFor: %d \nCon: %d\n", jogador.nome, jogador.pv, defesa.doJogador, jogador.str, jogador.con);
			printf("agi: %d \nDes: %d\n", jogador.agi, jogador.dex);
}
{//nova arma

	printf("1 - Infinity Edge: \nDano: 5 e +2 de STR\n\n");
	printf("2 - Butterfly: \nDano: 4 e +3 de AGI\n\n");
	printf("3 - Elden Bow: \nDano: 5 e +2 de Dex\n\n"); 
	printf("Digite sua resposta: ");
	scanf("%d", &trocaArma);
	
	if(trocaArma == 1)
	{
		arma = 5;
		jogador.str += 2;
	}
	if(trocaArma == 2)
	{
		arma = 4;
		jogador.agi += 3;
	}

	if(trocaArma == 3)
	{
		arma = 5;
		jogador.dex += 2;
	}

}//nova arma
}//PRIMEIRA RECOMPENSA
{//SEGUNDO COMBATE
	{//criacao de monstro2
				monstro.pv = 10 + rand()%12;
				int contadorMonstro = 20;
				int dadoMonstro = 0;
					monstro.str = rand()%20;
					contadorMonstro = contadorMonstro - monstro.str;
		
					if(contadorMonstro > 0)
					{
					
						monstro.agi = rand()%contadorMonstro;
						contadorMonstro -= monstro.agi;
					}
					if(contadorMonstro > 0)
					{
						monstro.con = rand()%contadorMonstro;
						contadorMonstro -= monstro.con;
					}
					if(contadorMonstro > 0)
					{
						monstro.dex = rand()%contadorMonstro;
						contadorMonstro -= monstro.dex;
					}
					if(contadorMonstro > 0)
					{
						monstro.con += contadorMonstro;
						contadorMonstro = 0;
					}
				dadoMonstro = rand()%5+1;
				dadoMonstro += rand()%5+1;
				dadoMonstro += rand()%5+1;
				defesa.doMonstro = 4+(monstro.con)*1.5;
				monstro.pv = dadoMonstro + monstro.con;
					printf("\nFicha do Monstro: \n\n");
					printf("\nPontos de Vida: %d \nDef: %d \nFor: %d \nCon: %d\n", monstro.pv, defesa.doMonstro, monstro.str, monstro.con);	
					printf("agi: %d \nDes: %d\n", monstro.agi, monstro.dex);

	}// CRIACAO DE MONSTRO2
	{//SEGUNDO COMBATE
		
	while(vidaQualquer > 0)
	{
		
		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}
		if(jogador.pv <= 0)
		{
			break;
		}
		
		if(jogador.agi >= monstro.agi)
		{
			moeda = 1;
		}
		
		if(moeda == 1)
		{
		printf("VEZ DO JOGADOR: Escolha entre \nATACAR - 1 \nDEFENDER - 2 \nPOCAO - 3 \nSua Resposta: ");
		scanf("%d", &ato);
		}
		
switch(ato)
{//VEZ DO JOGADOR
			
			case 1:
			{	
				if(moeda == 1)
				{
				
				
				if(escolhadaarma == 1)
				{				
				printf("\n\nJogue 2 dados de 6 lados e 1 de 4 lados para definir seu dano: ");
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nPrimeiro - %d", dado);
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nSegundo - %d", dado);
				printf("\n\nJogar o dado de 4 lados: ");
				system("pause");
				dado = rand()%3+1;
				printf("\t\nTerceiro - %d\n", dado);
				dano += dado;
				
				dano += arma;
				dano += jogador.dex;
				if(roundDefesam == 1)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro DUPLICADA)\n\n", dano, arma, defesa.doMonstro*2);
				}	
				else if(roundDefesam == 0)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro)\n\n", dano, arma, defesa.doMonstro);
				}	
				}
				if(escolhadaarma == 2)
				{				
				printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
				printf("\n\nJogar o dado de 12 lados: ");
				system("pause");
				dado = rand()%11+1;
				printf("\t\nNumero do dado - %d", dado);
				if(roundDefesam == 1)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (2*defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus  %d dano da arma) - %d DEFESA do KalRenz DUPLICADA)\n\n", dano, dado, jogador.str*1.5, arma, defesa.doMonstro*2);
				}
				
				else if(roundDefesam == 0)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus %d dano da arma) - %d DEFESA do KalRenz)\n\n", dano, dado, bonusSTR, arma, defesa.doMonstro);
				}
				}	
				monstro.pv -= dano;
			}//verificacao para saber se o jogador atacara
			}
			if(monstro.pv <= 0)
			{
				printf("\nParabens!! Voce derrotou o KalRenz!");
				opcao = 3;
				break;
			}
			moeda = 0;
			
			case 2:
			{	if(moeda == 1)
				{
				
				printf("\nSuas defesas foram DUPLICADAS por 1 round!");
				roundDefesa = 1;
				}
				
			}
			
			case 3:
			{
				if(moeda == 1)
				{
				
				printf("\nVoce usou uma pocao, sua cura sera calculada pela soma de 3 dados de 6 lados!");
				
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nJogar o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((jogador.pv + cura) >= vidaInicial1)
				{
					printf("\nSua vida atual eh %d\n\n", vidaInicial1);
				}
				else
				{
					printf("\nSua vida atual eh %d\n\n", jogador.pv+cura);
				}
				}
			}
}//vez do jogador

		if(monstro.pv <= 0)
		{
			
		
			break;
		}
		
		ato = rand()%2+1;
		printf("\nVez Do KalRenz!");
		switch(ato)
		{
			
			case 1:
			{	
				printf("\nAs defesas do KalRenz foram DUPLICADAS por 1 round!\n\n");
				roundDefesam = 1;
				break;					
			}//ataque monstro
			break;
			case 2:
			{

			printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
			system("pause");
			dado = rand()%11+1;
			printf("\t\nNumero do dado - %d", dado);
			dano = (dado)+(monstro.str);
			printf("\n%d de dano do KalRenz em voce\n\n", dano);
			jogador.pv -= dano;
			printf("\n\n\n\nVida atual do jogador: %d \nVida atual do KalRenz: %d\n\n", jogador.pv, monstro.pv);
			}//defesa monstro
			break;
			
			case 3:
			{
				printf("\nO KalRenz usou uma pocao");
				
				printf("\n\nVer o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nVer o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nVer o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((monstro.pv + cura) >= vidaInicial1m)
				{
					printf("\nA vida atual do KalRenz eh %d\n\n", vidaInicial1m);
				}
				else
				{
					printf("\nnA vida atual do KalRenz eh %d\n\n", monstro.pv+cura);
				}	
			}//pocao monstro
			break;
		}//Round Monstro	
		moeda = 1;				
}// 1 combate --- PRIMEIRO WHILE

		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}
}//SEGUNDO COMBATE
	{//SEGUNDA PREMIACAO
{//atributos novos
	printf("\n\nParabens! Voce passou de 2 niveis. Sua recompensa serao +10 pontos de atributos para voce distribuir! E uma nova armadura dentre 3!\n\n");
	
	pontos = 10;
	printf("Quantos pontos voce deseja inserir em FORCA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.str += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
	
			else
			{
				jogador.str = jogador.str;
			}
	
			printf("Quantos pontos voce deseja inserir em CONSTITUICAO: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.con += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.con = jogador.con;
			}
	
	

			printf("Quantos pontos voce deseja inserir em AGILIDADE: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.agi += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.agi = jogador.agi;
			}	
					

			printf("Quantos pontos voce deseja inserir em DESTREZA: ");
			scanf("%d", &controladorAtributo);
			if(pontos-controladorAtributo >= 0)
			{
				jogador.dex += controladorAtributo;
				pontos = pontos - controladorAtributo;
			}
			else
			{
				jogador.dex = jogador.dex;
			}
	
			jogador.pv = vidaInicial1 + jogador.con;
			printf("\n\nFicha de %s", jogador.nome);
			printf("\nNome: %s \nPontos de Vida: %d \nDefesa: %d \nFor: %d \nCon: %d\n", jogador.nome, jogador.pv, defesa.doJogador, jogador.str, jogador.con);
			printf("agi: %d \nDes: %d\n", jogador.agi, jogador.dex);
}	
{//nova armadura

	printf("1 - Void: \nDEFESA: 5 e +1 de STR\n\n");
	printf("2 - Fenix: \nDEFESA: 4 e +2 de AGI\n\n");
	printf("3 - Sparta: \nDEFESA: 5 e +1 de Dex\n\n"); 
	printf("Digite sua resposta: ");
	scanf("%d", &trocaArma);
	
	if(trocaArma == 1)
	{
		defesa.doJogador = 5;
		jogador.str += 1;
	}
	if(trocaArma == 2)
	{
		defesa.doJogador = 4;
		jogador.agi += 2;
	}

	if(trocaArma == 3)
	{
		defesa.doJogador = 5;
		jogador.dex += 1;
	}

}//nova armadura
}//SEGUNDA PREMIACAO


}//SEGUNDO COMBATE
{//TERCEIRO COMBATE
	while(vidaQualquer > 0)
	{
		
		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}
		if(jogador.pv <= 0)
		{
			break;
		}
		
		if(jogador.agi >= monstro.agi)
		{
			moeda = 1;
		}
		
		if(moeda == 1)
		{
		printf("VEZ DO JOGADOR: Escolha entre \nATACAR - 1 \nDEFENDER - 2 \nPOCAO - 3 \nSua Resposta: ");
		scanf("%d", &ato);
		}
		
switch(ato)
{//VEZ DO JOGADOR
			
			case 1:
			{	
				if(moeda == 1)
				{
				
				
				if(escolhadaarma == 1)
				{				
				printf("\n\nJogue 2 dados de 6 lados e 1 de 4 lados para definir seu dano: ");
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nPrimeiro - %d", dado);
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				dano += dado;
				printf("\t\nSegundo - %d", dado);
				printf("\n\nJogar o dado de 4 lados: ");
				system("pause");
				dado = rand()%3+1;
				printf("\t\nTerceiro - %d\n", dado);
				dano += dado;
				dano += arma;
				dano += jogador.dex;
				if(roundDefesam == 1)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro DUPLICADA)\n\n", dano, arma, defesa.doMonstro*2);
				}	
				else if(roundDefesam == 0)
				{
				
				printf("\nVoce causou %d de dano ((dados +%d dano da arma + dex do usuario) - %d DEFESA do monstro)\n\n", dano, arma, defesa.doMonstro);
				}
				}
				if(escolhadaarma == 2)
				{				
				printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
				printf("\n\nJogar o dado de 12 lados: ");
				system("pause");
				dado = rand()%11+1;
				printf("\t\nNumero do dado - %d", dado);
				if(roundDefesam == 1)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (2*defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus  %d dano da arma) - %d DEFESA do Arus DUPLICADA)\n\n", dano, dado, jogador.str*1.5, arma, defesa.doMonstro*2);
				}
				
				else if(roundDefesam == 0)
				{
				dano = (((dado)+(jogador.str)*1.5)+3) - (defesa.doMonstro);
				printf("\nVoce causou %d de dano ((%d dados + %.0f STR com bonus %d dano da arma) - %d DEFESA do Arus)\n\n", dano, dado, bonusSTR, arma, defesa.doMonstro);
				}
				}	
				monstro.pv -= dano;
			}//verificacao para saber se o jogador atacara
			}
			if(monstro.pv <= 0)
			{
				printf("\nParabens!! Voce Venceu o jogo!");
				opcao = 3;
				break;
			}
			moeda = 0;
			
			case 2:
			{	if(moeda == 1)
				{
				
				printf("\nSuas defesas foram DUPLICADAS por 1 round!");
				roundDefesa = 1;
				}
				
			}
			
			case 3:
			{
				if(moeda == 1)
				{
				
				printf("\nVoce usou uma pocao, sua cura sera calculada pela soma de 3 dados de 6 lados!");
				
				printf("\n\nJogar o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nJogar o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nJogar o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((jogador.pv + cura) >= vidaInicial1)
				{
					printf("\nSua vida atual eh %d\n\n", vidaInicial1);
				}
				else
				{
					printf("\nSua vida atual eh %d\n\n", jogador.pv+cura);
				}
				}
			}
}//vez do jogador

		if(monstro.pv <= 0)
		{
			
		
			break;
		}
		
		ato = rand()%2+1;
		printf("\nVez Do ARUS!");
		switch(ato)
		{
			
			case 1:
			{	
				printf("\nAs defesas do Arus foram DUPLICADAS por 1 round!\n\n");
				roundDefesam = 1;
				break;					
			}//ataque monstro
			break;
			case 2:
			{

			printf("\n\nJogue 1 dado de 12 lados para definir seu dano: ");
			system("pause");
			dado = rand()%11+1;
			printf("\t\nNumero do dado - %d", dado);
			dano = (dado)+(monstro.str);
			printf("\n%d de dano do Arus em voce\n\n", dano);
			jogador.pv -= dano;
			printf("\n\n\n\nVida atual do jogador: %d \nVida atual do Arus: %d\n\n", jogador.pv, monstro.pv);
			}//defesa monstro
			break;
			
			case 3:
			{
				printf("\nO Arus usou uma pocao");
				
				printf("\n\nVer o PRIMEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nPrimeiro - %d", dado);
				
				printf("\n\nVer o SEGUNDO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				cura += dado;
				printf("\t\nSegundo - %d", dado);
				
				printf("\n\nVer o TERCEIRO dado de 6 lados: ");
				system("pause");
				dado = rand()%5+1;
				printf("\t\nTerceiro - %d\n", dado);
				
				cura += dado;
				
				if((monstro.pv + cura) >= vidaInicial1m)
				{
					printf("\nA vida atual do Arus eh %d\n\n", vidaInicial1m);
				}
				else
				{
					printf("\nnA vida atual do Arus eh %d\n\n", monstro.pv+cura);
				}	
			}//pocao monstro
			break;
		}//Round Monstro	
		moeda = 1;				
}// 1 combate --- PRIMEIRO WHILE

		if(jogador.pv <= 0)
		{
			printf("\nSua jornada chegou ao fim!\n");
			break;
		}


}//TERCEIRO COMBATE
}//WHILE DO CASE 1
}// CASE 1 - O jogador escolheu seguir jogando	
		case 2:
		{
			printf("The Legend of Sura. \nEm um universo onde a magia e a realidade dividem o mesmo lado da moeda, uma criança nascida em Trix Town em meio ao vazio e ruinas da Guerra Runica dos Dragoes. Uma guerra travada entre dragoes e humanos iniciada pelo lider dos dragoes, Arus, como vingança de anos de tortura das maos dos magos runicos.");
			printf("\n\nA criança cresceu em meio a guerra, vendo sua cidade natal sendo destruida por conta do exercito de Arus, jurou vinganca contra aquele que matou todos aqueles que amava ");
			printf("\n\nEm seu leito de morte, sua mae fez seu ultimo pedido para seu filho cacula, que sobreviveu aos ataques furiosos dos dragoes, sua mae pediu para que seu ultimo filho seguisse a aventura que somente um heroi de verdade da cidade poderia enfrentar, recuperar o tesouro roubado do reino e consagrar o ultimo pedido de sua mae, o tesouro de Sura.");
			printf("\n\nApenas os mais antigos oradores da cidade ja entraram em sintonia com a Sura, mas ainda sim, eh rodeada de mitos sobre a importancia dela para os dragoes, o seu real poder e ate mesmo o que seria este tal tesouro.");
			printf("\n\nCriada atraves do forte ligamento das crencas de dragoes e humanos, a Sura oferece um poder inimaginavel para o seu portador, sendo ele humano, dragao, elfo ou qualquer outra criatura magica.");
			printf("\n\nPara recuperar este tesouro das posses do rei dos dragoes, o verdadeiro heroi precisara passar por grandes aventuras, enfrentando os mais sujos inimigos nesta jornada que ira se iniciar\n\n");
		break;
		}
		case 3:
		{
			printf("\n\nNao volte nunca mais!");
			ivo = 1;
			break;
		}
}// SWITCH	
}// WHILE do jogo
}//main