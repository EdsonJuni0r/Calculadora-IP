#include <stdio.h>
#include <math.h>

int ipBloco[4], maskBloco[4], redeBloco[4], firstBloco[4], lastBloco[4], broadBloco[4];
int cidr, subRedes, hosts, bits, bit = 7;

void calcular(){
	int i;
	bits = cidr;

	for(i = 0; i < 4; i++){
		maskBloco[i] = 0;
		redeBloco[i] = 0;
		if(i < 3){
			firstBloco[i] = 0;
			lastBloco[i] = 255;
		}else{
			firstBloco[i] = 1;
			lastBloco[i] = 254;
		}
		broadBloco[i] = 255;
	}

	if(cidr > 8){

		maskBloco[0] = 255;
		subRedes = (int) pow(2, cidr - 8);
		redeBloco[0] = ipBloco[0];
		broadBloco[0] = ipBloco[0];
		firstBloco[0] = ipBloco[0];
		lastBloco[0] = ipBloco[0];
	}else{

		subRedes = (int) pow(2, cidr);

		while(redeBloco[0] <= ipBloco[0]){
				redeBloco[0] += (256 / (int) pow(2, cidr));

			}

			redeBloco[0] -= 256 / (int) pow(2, cidr);

			firstBloco[0] = redeBloco[0];

			broadBloco[0] = redeBloco[0] + ((256 / (int) pow(2, cidr)) - 1);

			lastBloco[0] = broadBloco[0];


			while(bits > 0){
				maskBloco[0] += (int) pow(2, bit);
				bit--;
				bits--;
			}

	}

	if(cidr > 16){
			maskBloco[1] = 255;
			subRedes = (int) pow(2, cidr - 16);
			redeBloco[1] = ipBloco[1];
			broadBloco[1] = ipBloco[1];
			firstBloco[1] = ipBloco[1];
			lastBloco[1] = ipBloco[1];
		}else if(cidr > 8){

			subRedes = (int) pow(2, cidr - 8);

			while(redeBloco[1] <= ipBloco[1]){
				redeBloco[1] += (256 / (int) pow(2, cidr - 8));

			}

			redeBloco[1] -= 256 / (int) pow(2, cidr - 8);

			firstBloco[1] = redeBloco[1];

			broadBloco[1] = redeBloco[1] + ((256 / (int) pow(2, cidr - 8)) - 1);

			lastBloco[1] = broadBloco[1];


			while(bits > 8){
				maskBloco[1] += (int) pow(2, bit);
				bit--;
				bits--;
			}

		}

		if(cidr > 24){
			maskBloco[2] = 255;
			subRedes = (int) pow(2, cidr - 24);
			redeBloco[2] = ipBloco[2];
			broadBloco[2] = ipBloco[2];
			firstBloco[2] = ipBloco[2];
			lastBloco[2] = ipBloco[2];

			while(redeBloco[3] <= ipBloco[3]){
				redeBloco[3] += (256 / (int) pow(2, cidr - 24));

			}

			redeBloco[3] -= 256 / (int) pow(2, cidr - 24);

			firstBloco[3] = redeBloco[3] + 1;

			broadBloco[3] = redeBloco[3] + ((256 / (int) pow(2, cidr - 24)) - 1);

			lastBloco[3] = broadBloco[3] - 1;


			while(bits > 24){
				maskBloco[3] += (int) pow(2, bit);
				bit--;
				bits--;
			}

		}else if(cidr > 16){

			subRedes = (int) pow(2, cidr - 16);

			while(redeBloco[2] <= ipBloco[2]){
				redeBloco[2] += (256 / (int) pow(2, cidr - 16));

			}

			redeBloco[2] -= 256 / (int) pow(2, cidr - 16);

			firstBloco[2] = redeBloco[2];

			broadBloco[2] = redeBloco[2] + ((256 / (int) pow(2, cidr - 16)) - 1);

			lastBloco[2] = broadBloco[2];


			while(bits > 16){
				maskBloco[2] += (int) pow(2,bit);
				bit--;
				bits--;
			}

		}

		printf("\nIp: %i.%i.%i.%i/%i", ipBloco[0], ipBloco[1], ipBloco[2], ipBloco[3], cidr);
		printf("\nMascara: %i.%i.%i.%i", maskBloco[0], maskBloco[1], maskBloco[2], maskBloco[3]);
		printf("\nSub-Redes: %i", subRedes);
		printf("\nRede: %i.%i.%i.%i", redeBloco[0], redeBloco[1], redeBloco[2], redeBloco[3]);
		printf("\nBroadcast: %i.%i.%i.%i", broadBloco[0], broadBloco[1], broadBloco[2], broadBloco[3]);
		printf("\nPrimeiro: %i.%i.%i.%i", firstBloco[0], firstBloco[1], firstBloco[2], firstBloco[3]);
		printf("\nUltimo: %i.%i.%i.%i", lastBloco[0], lastBloco[1], lastBloco[2], lastBloco[3]);
		hosts = (int) pow(2, 32 - cidr) - 2;
		printf("\nHosts: %i", hosts);

}

void exibir_resultado(){
	if(cidr < 31){
        else if(ipBloco[0] > 255 &&  ipBloco[1] > 255 &&  ipBloco[2] > 255 && ipBloco[3] > 255){

        }
        else if(ipBloco[0] == 127){
            printf("O IP digitado é reservado para Loopback!");
        }
        else if(((ipBloco[0] != 255 && ipBloco[1] == 0 && ipBloco[2] == 0 && ipBloco[3] == 0) || (ipBloco[0] != 255 && ipBloco[2] == 0 && ipBloco[3] == 0) || (ipBloco[0] != 255 && ipBloco[3] == 0))){
            printf("\nIP e um endereço de rede ou Invalido!");
        }
        else if ((ipBloco[0] == 255 && ipBloco[1] == 255 && ipBloco[2] == 255 && ipBloco[3] == 0) || (ipBloco[0] == 255 && ipBloco[1] == 255 && ipBloco[2] == 0 && ipBloco[3] == 0)
        || (ipBloco[0] == 255 && ipBloco[1] == 0 && ipBloco[2] == 0 && ipBloco[3] == 0)) {
            printf("\nIP Invalido!");
        }
        else{
            calcular();
        }
    }else{
        printf("\nTamanho de Mascara invalido!");
    }
}

int main(){


	printf("Digite o ip");

	printf("\nBloco 1: ");
	scanf("%i", &ipBloco[0]);

	printf("Bloco 2: ");
	scanf("%i", &ipBloco[1]);

	printf("Bloco 3: ");
	scanf("%i", &ipBloco[2]);

	printf("Bloco 4: ");
	scanf("%i", &ipBloco[3]);

	printf("Tamanho da Mascara: ");
	scanf("%i", &cidr);

    exibir_resultado();

	return 0;
}
