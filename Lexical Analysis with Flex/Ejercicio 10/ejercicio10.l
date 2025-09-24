 int n_tabs=0;
%%
\t\t\t		unput(' '); yymore();
\t		n_tabs++; yymore()
.		yymore();
\n		{ if(n_tabs<3)
			ECHO;
			n_tabs=0;
		}
