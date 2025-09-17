


%x COM

%%

"//".*			{count++;}

"/*"			BEGIN(COM);
<COM>.|\n		;
<COM>"*/"		{ BEGIN(INITIAL); count++; }	
