
#include <iostream>
#include <map>
#include<queue>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include<string>
using namespace std;

class no{
    public:
    int freq;
    char letra;
    no* dir;
    no* esq;
    no(int f, char c)
    {
        freq = f;
        letra =c;
        dir =NULL;
        esq = NULL;
    }
    no(){

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

    friend bool operator<(const no &ind1, const no &ind2);
    friend bool operator>(const no &ind1, const no &ind2);

};

bool operator<(const no &ind1, const no &ind2)
{
    return ind1.freq < ind2.freq;
}
bool operator>(const no &ind1, const no &ind2)
{
    return ind1.freq > ind2.freq;
}

void contaLetras(string frase, map<char,int>& tabela)
{
    int tam = frase.length();
    for(int i=0;i<tam;i++)
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

        if(v.empty()){
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
        for(int i=0;i<v.size();i++)
    {
        cout<<v[i].letra<<": "<<v[i].freq<<endl;
    }
    }

}
void mostra (no* a, int n) {
  if (a!= NULL) {
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
    string a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam ac luctus felis. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Nullam tempor ultrices lectus. Proin varius dolor nec congue rhoncus. In laoreet velit quis congue malesuada. Phasellus mattis venenatis commodo. Suspendisse potenti. Nulla nisi risus, varius vel lacinia vitae, ultricies at justo. Ut sed commodo tortor. Etiam a rhoncus elit. Maecenas et rutrum purus. Morbi a erat a erat placerat ullamcorper. Vestibulum quis turpis ut lacus aliquet molestie. Sed a est iaculis velit mattis dignissim. Mauris viverra nisi libero, eget blandit nisi condimentum in. Donec ut mi ullamcorper, elementum risus eu, pellentesque elit. In et orci at velit condimentum fermentum sit amet et nunc. Nam in finibus sem, nec eleifend erat. Nullam non tristique nunc. Praesent eget ipsum ex. Vestibulum efficitur massa et mi tincidunt tincidunt. Nam aliquet aliquam diam, at sagittis metus ornare non. Sed pharetra mi ac libero elementum, at facilisis nisi cursus. Cras metus quam, vulputate eu placerat vel, pharetra vitae mi. Nullam in efficitur lectus, eget vehicula quam. Sed sit amet efficitur purus. Sed non urna a tellus pretium elementum nec quis orci. Donec ultrices sem sit amet mi congue elementum. Proin aliquet dui ac erat dapibus, porttitor venenatis orci vulputate. Nulla in fermentum metus. Sed a mauris ullamcorper, sagittis libero ut, luctus mi. Donec nisi metus, hendrerit non porta id, imperdiet id quam. Phasellus egestas justo ac felis rhoncus posuere. Sed ornare purus et bibendum commodo. Fusce sagittis elementum neque vitae laoreet. Sed venenatis ullamcorper purus eget tempor.";
    vector<no> v, v2;
    map<char,int> tab;

    contaLetras(a, tab);

    for (const auto& x : tab){
        v.push_back(no(x.second, x.first));

    }
    sort(v.begin(), v.end());
    cout<<"\ntamanho: "<<v.size()<<endl;
    int tam = v.size();
    for(int i=0;i<tam;i++)
    {
        cout<<v[i].letra<<": "<<v[i].freq<<endl;
    }

    no* tree = montaArvore(v);
    mostra(tree, 0);
    tam = v.size();
    for(int i=0;i<tam;i++)
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
    for(int i=0;i<a.length();i++)
        total +=mapa[a[i]];

    cout<<"\n\n"<<total<<"\n\ntamanho: "<<total.length();
    cout<<"\ntamanho em bits antigo: "<<(4*sizeof(char)*a.length());
    cout<<"\nTaxa de compressao: "<<total.length()/(4.0*sizeof(char)*a.length());



    return 0;
}
