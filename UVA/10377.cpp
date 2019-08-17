#include <bits/stdc++.h>
using namespace std;
string mapa[200],lixo;
char direcao,mov,linha[300];

int x,y,t; //POS INI
int rotacao,n,m;
bool blank=false;

bool possivel(int a,int b)
{
    if(mapa[a][b]=='*' || a<0 || a>=n || b<0 || b>=m) return false;
    return true;
}

void go()
{
    if(direcao=='N')
    {
        if(possivel(x-1,y))
            x--;
    }
    else if(direcao=='E')
    {
        if(possivel(x,y+1))
            y++;
    }
    else if(direcao=='S')
    {
        if(possivel(x+1,y))
            x++;
    }
    else if(direcao=='W')
    {
        if(possivel(x,y-1))
            y--;
    }

    return ;
}

void L()
{
    if(direcao=='N') direcao='W';
    else if(direcao=='E') direcao='N';
    else if(direcao=='S') direcao='E';
    else if(direcao=='W') direcao='S';
}
void R()
{
    if(direcao=='N') direcao='E';
    else if(direcao=='E') direcao='S';
    else if(direcao=='S') direcao='W';
    else if(direcao=='W') direcao='N';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        getline(cin,lixo);

        for(int i=0;i<n;++i)
        {
            cin.getline(linha,sizeof linha);
            mapa[i]=linha;
        }

        direcao='N';
        cin>>x>>y;
        x--; y--;

        while( (mov=cin.get()) != 'Q')
        {
            if(mov=='F') go();
            else if(mov=='R') R();
            else if(mov=='L') L();
        }

        if(blank) cout<<'\n';
        blank=true;
        cout<<x+1<<' '<<y+1<<' '<<direcao<<'\n';
    }

    return 0;
}
