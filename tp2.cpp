#include <iostream>
#include<string>
#include<vector>

using namespace std;

class article
{
    private:
    int code;
    string designation;
    int qte_stock;
public:
article(){};
    article(int code,string designation,int qte_stock)
    {
        this->code=code;
        this->qte_stock=qte_stock;
        this->designation=designation;

    }
    ~article(){}

    int get_code()
    {
        return(code);
    }
    string get_designation()
    {
        return(designation);

    }
    int get_qte_stock()
    {
        return(qte_stock);
    }
    void set_code(int code)
    {
        this->code=code;

    }
    void set_designation(string designation)
    {
        this->designation=designation;
    }
    void set_qte_stock(int qte_stock)
    {
        this->qte_stock=qte_stock;
    }
    void view()
    {
        cout<<"code "<<code<<" designation "<<designation<<" quantité stock "<<qte_stock;

    }
};
class produit_fini :public article
{
private:
    string marque;
    float prix;
    int nbre_fabrication;
    char t[10][30];
public:
   produit_fini(int code=0,string designation="",int qte_stock=0,string marque="",float prix=0,int nbre_fabrication=0)
    {int i;
        this->marque=marque;
        this->prix=prix;
        this->nbre_fabrication=nbre_fabrication;
        for(i=0; i<nbre_fabrication; i++)
        {
            cout<<"donner l'operation"<<i<<endl;
            cin>>t[i];
        }}
        ~produit_fini(){}
      void  view()
        {
            article::view();
            cout<<" marque "<<marque<<" prix "<<prix<<endl;
            for(int i=0; i<nbre_fabrication; i++)
            {
                cout<<t[i]<<" ";

            }
        }
        void set_marque(string marque)
        {
            this->marque=marque;

        }
        void set_prix(float prix)
        {
            this->prix=prix;

        }
        void set_nbre_fabrication(int nbre_fabrication)
        {
            this->nbre_fabrication=nbre_fabrication;

        }
        string get_marque()
        {
            return(marque);

        }
        int get_nbre_fabrication()
        {
            return(nbre_fabrication);
        }
        float get_prix()
        {
            return(prix);
        }
    };

class liste_produit_fini
{
private:
    vector<produit_fini> t;
public:
  liste_produit_fini(){}
    liste_produit_fini(produit_fini a)
    {

        t.push_back(a);

    }
    vector<produit_fini> get_t(){

        return t;
    }
    ~liste_produit_fini()
    {
vector<produit_fini>().swap(t);
    }
    int get_taille()
    {return(t.size());
   
        }
   void  insert_liste_produit_fini(produit_fini b)
    {
        t.push_back(b) ;
    }
    void set_t(vector<produit_fini>p){
       t=p;



    }
    liste_produit_fini operator + (liste_produit_fini a)
    {int n;
        liste_produit_fini c;
        for(int i=0; i<n; i++)
        {
            c.insert_liste_produit_fini(t[i]);
        }
        for (int j=0; j<(a.get_taille()); j++)
        {
        c.insert_liste_produit_fini(a.t[j]);
        }

            for(int i=0; i<(c.get_taille())-1; i++)
            {
                for (int j=i+1; j<c.get_taille(); j++)
                   {
                    vector<produit_fini>p=c.get_t();
                    if((p[i].get_code()==p[j].get_code())&&(p[i].get_marque()==p[j].get_marque()))
                    {

                       p[i].set_qte_stock(p[i].get_qte_stock()+p[j].get_qte_stock());

                        p.erase((t.begin()+j),(t.begin()+j));
                        c.set_t(p);
                    }
                   }
            }}
            void view_liste_produit_fini()
            {
                for(int i=0;i<t.size(); i++)
                {
                    t[i].view();
                }

            }
        };




        int main()
        {int x,y,z;
        x=2;
        y=3;
            produit_fini a(100,"parfum",15,"channel",700,1);
            produit_fini b(120,"savon",50,"fa",5,1);
            produit_fini c(100,"parfum",10,"channel",700,1);
            produit_fini d(100,"parfum",25,"Diesel",600,1);
            liste_produit_fini ab(a);
            liste_produit_fini cd(c);
            ab.insert_liste_produit_fini(b);
            cd.insert_liste_produit_fini(d);
            ab.view_liste_produit_fini();
            return(1);}