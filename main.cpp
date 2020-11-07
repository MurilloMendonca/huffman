#include <iostream>
#include <map>
#include<queue>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include<string>
using namespace std;

class no
{
public:
    int freq;
    char letra;
    no* dir;
    no* esq;


    no()
    {
        dir = NULL;
        esq = NULL;
    }

    no(int f, char c)
    {
        freq = f;
        letra =c;
        dir =NULL;
        esq = NULL;
    }
    no(no* no1, no* no2)
    {
        esq = no1;
        dir = no2;
        freq = no1->freq + no2->freq;
        letra = '@';
    }
    no(int f, char c, no* d, no* e)
    {
        freq = f;
        letra =c;
        dir =d;
        esq = e;
    }

    friend bool operator<(const no &ind1, const no &ind2)
    {
        return ind1.freq < ind2.freq;
    }
    friend bool operator>(const no &ind1, const no &ind2)
    {
        return ind1.freq > ind2.freq;
    }


};


void contaLetras(string frase, map<char,int>& tabela)
{
    int tam = frase.length();
    for(int i=0; i<tam; i++)
    {

        if(tabela.find((char)frase[i]) == tabela.end())
        {
            tabela.insert(pair<char,int>((char)frase[i],0));
        }
        tabela[(char)frase[i]]++;
    }
}
no* montaArvore(vector<no>& v)
{
    while(true)
    {
        cout<<"\nrodei\ntam do v:"<<v.size()<<endl;
        no* no1 = new no(v.front().freq, v.front().letra, v.front().dir, v.front().esq);
        v.erase(v.begin());
        no* no2 = new no(v.front().freq, v.front().letra, v.front().dir, v.front().esq);
        v.erase(v.begin());

        no* pai = new no(no1, no2);

        if(v.empty())
        {
            cout<<"sai\n";
            return pai;
        }

        int pos =0;
        vector<no>::iterator it = v.begin();
        while(pai->freq>v[pos].freq)
        {
            pos++;
        }
        if(pos>=v.size())
            v.push_back(*pai);
        else
            v.insert(it+pos, *pai);
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i].letra<<": "<<v[i].freq<<endl;
        }
    }

}
void mostra (no* a, int n)
{
    if (a!= NULL)
    {
        int i;
        mostra (a->dir, n+1);
        for (i = 0; i < n; i++) cout << "    ";
        cout << a->freq << endl;
        mostra (a->esq, n+1);
    }
}
bool ehFolha(no* a)
{
    return(a->dir==NULL && a->esq==NULL);
}
void cod(no* raiz, map<char, string>& m, string c)
{
    if(ehFolha(raiz))
    {
        m.insert({raiz->letra, c});
        return;
    }

    cod(raiz->esq, m, c+"0");
    cod(raiz->dir, m, c+"1");

}
int main()
{
    //string a = "Mais uma vez as forças e os interesses contra o povo coordenaram-se e novamente se desencadeiam sobre mim. Não me acusam, insultam; não me combatem, caluniam, e não me dão o direito de defesa. Precisam sufocar a minha voz e impedir a minha ação, para que eu não continue a defender, como sempre defendi, o povo e principalmente os humildes. Sigo o destino que me é imposto. Depois de decênios de domínio e espoliação dos grupos econômicos e financeiros internacionais, fiz-me chefe de uma revolução e venci. Iniciei o trabalho de libertação e instaurei o regime de liberdade social. Tive de renunciar. Voltei ao governo nos braços do povo. A campanha subterrânea dos grupos internacionais aliou-se à dos grupos nacionais revoltados contra o regime de garantia do trabalho. A lei de lucros extraordinários foi detida no Congresso. Contra a justiça da revisão do salário mínimo se desencadearam os ódios. Quis criar liberdade nacional na potencialização das nossas riquezas através da Petrobrás e, mal começa esta a funcionar, a onda de agitação se avoluma. A Eletrobrás foi obstaculada até o desespero. Não querem que o trabalhador seja livre. Não querem que o povo seja independente. Assumi o Governo dentro da espiral inflacionária que destruía os valores do trabalho. Os lucros das empresas estrangeiras alcançavam até 500% ao ano. Nas declarações de valores do que importávamos existiam fraudes constatadas de mais de 100 milhões de dólares por ano. Veio a crise do café, valorizou-se o nosso principal produto. Tentamos defender seu preço e a resposta foi uma violenta pressão sobre a nossa economia, a ponto de sermos obrigados a ceder. Tenho lutado mês a mês, dia a dia, hora a hora, resistindo a uma pressão constante, incessante, tudo suportando em silêncio, tudo esquecendo, renunciando a mim mesmo, para defender o povo, que agora se queda desamparado. Nada mais vos posso dar, a não ser meu sangue. Se as aves de rapina querem o sangue de alguém, querem continuar sugando o povo brasileiro, eu ofereço em holocausto a minha vida. Escolho este meio de estar sempre convosco. Quando vos humilharem, sentireis minha alma sofrendo ao vosso lado. Quando a fome bater à vossa porta, sentireis em vosso peito a energia para a luta por vós e vossos filhos. Quando vos vilipendiarem, sentireis no pensamento a força para a reação. Meu sacrifício vos manterá unidos e meu nome será a vossa bandeira de luta. Cada gota de meu sangue será uma chama imortal na vossa consciência e manterá a vibração sagrada para a resistência. Ao ódio respondo com o perdão. E aos que pensam que me derrotaram respondo com a minha vitória. Era escravo do povo e hoje me liberto para a vida eterna. Mas esse povo de quem fui escravo não mais será escravo de ninguém. Meu sacrifício ficará para sempre em sua alma e meu sangue será o preço do seu resgate. Lutei contra a espoliação do Brasil. Lutei contra a espoliação do povo. Tenho lutado de peito aberto. O ódio, as infâmias, a calúnia não abateram meu ânimo. Eu vos dei a minha vida. Agora vos ofereço a minha morte. Nada receio. Serenamente dou o primeiro passo no caminho da eternidade e saio da vida para entrar na História.";
    string a = "al al al al al ala";
    vector<no> v, v2;
    map<char,int> tab;

    contaLetras(a, tab);

    for (const auto& x : tab)
    {
        v.push_back(no(x.second, x.first));

    }
    sort(v.begin(), v.end());
    cout<<"\ntamanho: "<<v.size()<<endl;
    int tam = v.size();
    for(int i=0; i<tam; i++)
    {
        cout<<v[i].letra<<": "<<v[i].freq<<endl;
    }

    no* tree = montaArvore(v);
    mostra(tree, 0);
    tam = v.size();
    for(int i=0; i<tam; i++)
    {
        cout<<v[i].letra<<": "<<v[i].freq<<endl;
    }


    map<char, string> mapa;
    string str="";
    cod(tree, mapa, str );

    for (const auto& x : mapa)
        cout<<x.first<<": "<<x.second<<endl;

    cout<<"\n\n\n";

    string total="";
    for(int i=0; i<a.length(); i++)
        total +=mapa[a[i]];

    float tamanhoOriginal = (8*sizeof(char)*a.length());
    float tamanhoComprimido= total.length();

    cout<<"\n\nVersão Comprimida (codeword): \n\n"<<total<<endl;
    cout<<"\n\nTamanho em bits comprimida: "<<tamanhoComprimido;
    cout<<"\nTamanho em bits original: "<<tamanhoOriginal;
    cout<<"\nTaxa de compressao: "<<(tamanhoComprimido/tamanhoOriginal)*100<<"% do tamanho original";



    return 0;
}
