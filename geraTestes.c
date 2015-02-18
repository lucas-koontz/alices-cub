#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	FILE *out = fopen("entrada.txt", "w");
	if(!out)
		puts("Fudeo");
	int num, vet[17], k, l;
	char entrada[35], c;
	int q, r, j, i=0;
	for(k=0;k<65536; k++){
		num=k;
		i=0;
		while(num>0){
			r=num%2;
			vet[i] = r;
			i++;
			q = num/2;
			num=q;
		}
		q=0;
		l=0;
		r = (16-i);
		while(l<r){
			entrada[q++] = '0';
			entrada[q++] = ' ';
			l++;
		}
		for(j=i-1; j>=0; j--){

			sprintf(&c, "%d", vet[j]);
			entrada[q++] = c;
			entrada[q++] = ' ';
		}
		entrada[q]='\0';
		l=0;
		r=0;
		for(q=0; q<33; q+=2){
			if(entrada[q] == '0')
				l++;
			else if(entrada[q] == '1')
				r++;
		}
		if(l!=8 || r!=8)
			continue;
		fputs(entrada, out);
		fprintf(out, "\n");
		//printf("%d\t%s\n", k, entrada);
	}
	fclose(out);
	return 0;
}
