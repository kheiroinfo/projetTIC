#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Element Element;
 struct Element 
{ int degre;
 float coef;
  Element *suiv;
};;

Element *lirepol(int n){
 Element *p,*q,*tete;
 int i,m;
 float x;
 m=n;
 printf("donner le premier coefficient ");
 scanf("%f",&x);
  tete=(Element *)malloc(sizeof(Element ));
  tete->degre=n;
 tete->coef=x;
 q=tete;
  
  for( i=2;i<=n+1;i++){
   
  p=(Element *)malloc(sizeof(Element ));
   printf("donner le coefficient [%d] ",i);
   scanf("%f",&x);
   m=m-1;
   p->coef=x;
   p->degre=m;
       q->suiv=p;
   q=p;
   }
 p->suiv=NULL;
   return tete;
  }
  void affichpol(Element *t){
  Element *p;
   p=t;
   while(p!=NULL)
   {
    if(p->coef!=0){
     if(p->coef>0 && p!=t) printf("+");
     if(p->degre==0){
      printf("%.1f",p->coef);}else{
    printf("%.1fx^%d",p->coef,p->degre);}
       
       }
       p=p->suiv;
   }
   
   
   }
   float evaluer(int x,Element *t){
   
    Element *p;float s;
    s=0;
    p=t;
    
    while(p!=NULL){
     s=s+(p->coef)*pow(x,p->degre);
     
     p=p->suiv;
     
     }
     
    return s;
    }
  Element *sompolynomes(Element *l1,Element *l2){
  Element *som,*t1,*t2,*p,*q;
   if(l1==NULL)
   {return l2;
    
   }
   if(l2==NULL)
   {
    return l1;
   }
   som=(Element *)malloc(sizeof(Element ));
   t2=som;
   if(l1->degre>l2->degre)
   {
  p=l1;q=l2;som->degre=p->degre;som->coef=p->coef;
    p=p->suiv;
   }else
   {if(l1->degre<l2->degre)
   {
    
  p=l2;q=l1;som->degre=p->degre;som->coef=p->coef;
    p=p->suiv;
   }
   else
   {
  p=l1;q=l2;som->degre=p->degre;
    som->coef=p->coef+q->coef;
    p=p->suiv;
    q=q->suiv;
    
   }
   }
   while(p->degre>q->degre)
   {
    
    t1=(Element *)malloc(sizeof(Element ));
    t1->coef=p->coef;
    t1->degre=p->degre;
    t2->suiv=t1;
    t2=t1;
    p=p->suiv;
   }
     
while(p!=NULL)
     {
      t1=(Element *)malloc(sizeof(Element ));
      t1->degre=p->degre;
      t1->coef=(p->coef)+(q->coef);
      t2->suiv=t1;
      t2=t1;
      p=p->suiv;
      q=q->suiv;
     }
     t1->suiv=NULL;
     
     return som;
     
     
   }
int main()
{
 Element *t,*p,*s,*somme;
 int x,n,m;float ev;
 printf("donner le degre de pol1 ");
 scanf("%d",&n);
 printf("donner le degre de pol2 ");
 scanf("%d",&m);
 t=lirepol(n);
 s=lirepol(m);
 printf("p(x)=");
 affichpol(t);printf("\n");
 printf("donner x ");
 scanf("%d",&x);
 ev=evaluer(x,t);
 printf("p(%d)=%.1f",x,ev);
 printf("\n");
 somme=sompolynomes(t,s);
 printf("psomme(x)=");
 affichpol(somme);printf("\n");
	
	
 return 0;
}
