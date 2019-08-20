/*		
	1253 - Caesar Cipher
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;
int i,movimentos,repeticoes,aux;
char palavra[52];

int main()
{

    scanf("%d", &repeticoes);
    while(repeticoes--)
    {
        scanf("%s", palavra);
        scanf("%d", &movimentos);
        for (i = 0; i < 52; i++)
        {
            if (palavra[i] == '\0')
                break;

            if ((palavra[i] - movimentos) < 65)
                aux = (palavra[i] - movimentos) + 26;

            else
                aux = palavra[i] - movimentos;

        printf("%c", aux);
        }
        printf("\n");
    }
    return 0;
}
