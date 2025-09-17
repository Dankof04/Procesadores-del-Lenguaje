%x A B

%%

Aon		BEGIN(A);
Aoff		BEGIN(INITIAL);
Bon 		BEGIN(B);
Boff		BEGIN(INITIAL);

<A,B>[0-9]	{ 	if(YY_START==A)
				printf("A");
			else
				printf("B");
		}

<A>	printf("a");
<B>	printf("b");
.	printf("0");



Aoncc45AoffBoncc45Boff

Para inclusiva
aaAAbbBB


Para exclusiva

aaAAaaaaaaaaaAAaaaa


Aon		BEGIN(A);
<A>Aoff		BEGIN(INITIAL);
Bon 		BEGIN(B);
<B>Boff		BEGIN(INITIAL);

<A,B>[0-9]	{ 	if(YY_START==A)
				printf("A");
			else
				printf("B");
		}

<A>	printf("a");
<B>	printf("b");
.	printf("0");



