#include <stdio.h>
#include <math.h>

int ipBloco[4], maskBloco[4], redeBloco[4], firstBloco[4], lastBloco[4], broadBloco[4];
int cidr, subRedes, hosts, bits, bit = 7;

void printBinary(int value)
{
	for (int i = 7; i >= 0; i--)
	{
		int bitt = (value >> i) & 1; // Obtém o valor do bit na posição i
		printf("%d", bitt);
	}
}

void calcular()
{
	int i;
	bits = cidr;

	for (i = 0; i < 4; i++)
	{
		maskBloco[i] = 0;
		redeBloco[i] = 0;
		if (i < 3)
		{
			firstBloco[i] = 0;
			lastBloco[i] = 255;
		}
		else
		{
			firstBloco[i] = 1;
			lastBloco[i] = 254;
		}
		broadBloco[i] = 255;
	}

	if (cidr > 8)
	{

		maskBloco[0] = 255;
		subRedes = (int)pow(2, cidr - 8);
		redeBloco[0] = ipBloco[0];
		broadBloco[0] = ipBloco[0];
		firstBloco[0] = ipBloco[0];
		lastBloco[0] = ipBloco[0];
	}
	else
	{

		subRedes = (int)pow(2, cidr);

		while (redeBloco[0] <= ipBloco[0])
		{
			redeBloco[0] += (256 / (int)pow(2, cidr));
		}

		redeBloco[0] -= 256 / (int)pow(2, cidr);

		firstBloco[0] = redeBloco[0];

		broadBloco[0] = redeBloco[0] + ((256 / (int)pow(2, cidr)) - 1);

		lastBloco[0] = broadBloco[0];

		while (bits > 0)
		{
			maskBloco[0] += (int)pow(2, bit);
			bit--;
			bits--;
		}
	}

	if (cidr > 16)
	{
		maskBloco[1] = 255;
		subRedes = (int)pow(2, cidr - 16);
		redeBloco[1] = ipBloco[1];
		broadBloco[1] = ipBloco[1];
		firstBloco[1] = ipBloco[1];
		lastBloco[1] = ipBloco[1];
	}
	else if (cidr > 8)
	{

		subRedes = (int)pow(2, cidr - 8);

		while (redeBloco[1] <= ipBloco[1])
		{
			redeBloco[1] += (256 / (int)pow(2, cidr - 8));
		}

		redeBloco[1] -= 256 / (int)pow(2, cidr - 8);

		firstBloco[1] = redeBloco[1];

		broadBloco[1] = redeBloco[1] + ((256 / (int)pow(2, cidr - 8)) - 1);

		lastBloco[1] = broadBloco[1];

		while (bits > 8)
		{
			maskBloco[1] += (int)pow(2, bit);
			bit--;
			bits--;
		}
	}

	if (cidr > 24)
	{
		maskBloco[2] = 255;
		subRedes = (int)pow(2, cidr - 24);
		redeBloco[2] = ipBloco[2];
		broadBloco[2] = ipBloco[2];
		firstBloco[2] = ipBloco[2];
		lastBloco[2] = ipBloco[2];

		while (redeBloco[3] <= ipBloco[3])
		{
			redeBloco[3] += (256 / (int)pow(2, cidr - 24));
		}

		redeBloco[3] -= 256 / (int)pow(2, cidr - 24);

		firstBloco[3] = redeBloco[3] + 1;

		broadBloco[3] = redeBloco[3] + ((256 / (int)pow(2, cidr - 24)) - 1);

		lastBloco[3] = broadBloco[3] - 1;

		while (bits > 24)
		{
			maskBloco[3] += (int)pow(2, bit);
			bit--;
			bits--;
		}
	}
	else if (cidr > 16)
	{

		subRedes = (int)pow(2, cidr - 16);

		while (redeBloco[2] <= ipBloco[2])
		{
			redeBloco[2] += (256 / (int)pow(2, cidr - 16));
		}

		redeBloco[2] -= 256 / (int)pow(2, cidr - 16);

		firstBloco[2] = redeBloco[2];

		broadBloco[2] = redeBloco[2] + ((256 / (int)pow(2, cidr - 16)) - 1);

		lastBloco[2] = broadBloco[2];

		while (bits > 16)
		{
			maskBloco[2] += (int)pow(2, bit);
			bit--;
			bits--;
		}
	}

	printf("\n  IP: %i.%i.%i.%i/%i", ipBloco[0], ipBloco[1], ipBloco[2], ipBloco[3], cidr);

	printf("\n--------------------------------------------");

	if (ipBloco[0] >= 1 && ipBloco[0] <= 127)
	{
		printf("\nClasse: A");
	}
	else if (ipBloco[0] >= 128 && ipBloco[0] <= 191)
	{
		printf("\nClasse: B");
	}
	else if (ipBloco[0] >= 192 && ipBloco[0] <= 223)
	{
		printf("\nClasse: C");
	}
	else if (ipBloco[0] >= 124 && ipBloco[0] <= 254)
	{
		printf("\nClasse: D");
	}

	printf("\n--------------------------------------------");
	printf("\nMascara: %i.%i.%i.%i", maskBloco[0], maskBloco[1], maskBloco[2], maskBloco[3]);
	printf("\nMascara em binario: ");
	for (int i = 0; i < 4; i++)
	{
		if (i > 0)
		{
			printf(".");
		}
		printBinary(maskBloco[i]);
	}
	printf("\nCIDR: %i", cidr);
	printf("\n--------------------------------------------");

	printf("\nRede: %i.%i.%i.%i", redeBloco[0], redeBloco[1], redeBloco[2], redeBloco[3]);
	printf("\nRede em binario: ");
	for (int i = 0; i < 4; i++)
	{
		if (i > 0)
		{
			printf(".");
		}
		printBinary(redeBloco[i]);
	}

	printf("\n--------------------------------------------");

	printf("\nBroadcast: %i.%i.%i.%i", broadBloco[0], broadBloco[1], broadBloco[2], broadBloco[3]);
	printf("\nBroadcast em binario: ");
	for (int i = 0; i < 4; i++)
	{
		if (i > 0)
		{
			printf(".");
		}
		printBinary(broadBloco[i]);
	}

	printf("\n--------------------------------------------");

	// printf("\nPrimeiro: %i.%i.%i.%i", firstBloco[0], firstBloco[1], firstBloco[2], firstBloco[3]);

	// printf("\n--------------------------------------------");

	// printf("\nUltimo: %i.%i.%i.%i", lastBloco[0], lastBloco[1], lastBloco[2], lastBloco[3]);

	// printf("\n--------------------------------------------");

	printf("\nSub-Redes: %i", subRedes);

	printf("\n--------------------------------------------");

	hosts = (int)pow(2, 32 - cidr) - 2;
	printf("\nHosts: %i", hosts);
	printf("\n--------------------------------------------");
}

void exibir_resultado()
{
	if (cidr < 31)
	{
		if (ipBloco[0] > 255 || ipBloco[1] > 255 || ipBloco[2] > 255 || ipBloco[3] > 255)
		{
			printf("\nIP Invalido!Por favor, digite corretamente!!!");
		}
		else if ((ipBloco[1] == 255 && ipBloco[2] == 255 && ipBloco[3] == 255) || (ipBloco[2] == 255 && ipBloco[3] == 255) || (ipBloco[3] == 255))
		{
			printf("\nIP invalido! Por faor, digite corretamente!!!");
		}
		else if (ipBloco[0] == 127 && ipBloco[1] == 0)
		{
			printf("O IP digitado: reservado para Loopback!");
		}
		else if (((ipBloco[0] != 255 && ipBloco[1] == 0 && ipBloco[2] == 0 && ipBloco[3] == 0) || (ipBloco[0] != 255 && ipBloco[2] == 0 && ipBloco[3] == 0) || (ipBloco[0] != 255 && ipBloco[3] == 0)))
		{
			printf("\nIP e um endereco de rede ou Invalido!");
		}
		else if ((ipBloco[0] == 255 && ipBloco[1] == 255 && ipBloco[2] == 255 && ipBloco[3] == 0) || (ipBloco[0] == 255 && ipBloco[1] == 255 && ipBloco[2] == 0 && ipBloco[3] == 0) || (ipBloco[0] == 255 && ipBloco[1] == 0 && ipBloco[2] == 0 && ipBloco[3] == 0))
		{
			printf("\nIP Invalido! Por favor, digite corretamente!!!");
		}
		else
		{
			calcular();
		}
	}
	else
	{
		printf("\nTamanho de Mascara invalido!");
	}
}

int main()
{

	int choice;

	do
	{
		printf("Menu\n\n");
		printf("1. Calcular\n");
		printf("2. Sair\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nDigite o IP");
			printf("\nOcteto 1: ");
			scanf("%i", &ipBloco[0]);
			printf("Octeto 2: ");
			scanf("%i", &ipBloco[1]);
			printf("Octeto 3: ");
			scanf("%i", &ipBloco[2]);
			printf("Octeto 4: ");
			scanf("%i", &ipBloco[3]);
			printf("Tamanho da Mascara: ");
			scanf("%i", &cidr);
			exibir_resultado();

			printf("\n\nDeseja calcular um novo endereco? (1 - Sim, 2 - Nao): ");
			scanf("%d", &choice);
			if (choice == 1)
			{
				break;
			}
			else
			{
				printf("\nSaindo do programa.\n");
				exit(0);
			}
			break;

		case 2:
			printf("\nSaindo do programa.\n");
			exit(0);
			break;

		default:
			printf("\nEscolha invalida! Tente novamente.\n");
			break;
		}

	} while (choice != 2);

	return 0;
}
