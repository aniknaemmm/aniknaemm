#include <stdio.h>
void zad1(void);
void zad2(void);
void zad3(void);
void zad4(void);
void zad5(void);
void zad6(void);
int main(){
    int numb;
    printf("pls enter numb exmapl:");
    scanf("\n%d",&numb);
    if(numb==1){
     zad1();
    }
    else if(numb==2){
      zad2()  ;
    }
    else if(numb==3){
      zad3() ; 
    }
    else if(numb==4){
        
    }
    else if(numb==5){
        zad5();
    }
    else if(numb==6){
        zad6();
    }
    else printf("error");
    
    printf("end");
    return 0;
}
void zad1(void){
    printf("zadanie1\n");
    int rr=137;
    while(rr--){
        printf("helloword%d\n",rr+1);
    }
}
void zad2(void){
    printf("zadanie2");
    int numb;
    int i=0;
    printf("\nvvedite skolko:");
    scanf("\n%d",&numb);
    while(i++<numb){
        printf("%d\n",i);
    }
    
}
void zad3(void){
    printf("zadanie 3\n");
    int sum=1;
    for(int i=0;i<17;++i){
        printf("%d ne chotnoe %d vkube %d\n",i+1,sum,sum*sum*sum);
        sum+=2;
       }
    }
    
   void zad4(void) {
        printf("zadanie4");
        
    }
    
    

void zad5(void){
    int l,x,i,p;
    int rez=1;
    printf("zadanie5\n l>0 && x<=l\n");
    printf("enter L:");
    scanf("%d",&l);
    printf("vvedite x:");
    scanf("%d",&x);
    for(i=0;rez<=l;i++){
        rez=1;
        for(p=0;p<=i;p++){
            rez*=x;
            
        }
        
    }
    //printf("%d\n",p-1);
   printf("%d\n",i-1);
}

void zad6(void){
    printf("malen'ki olia lubit xom9kov!!\n");
    printf("%c",200);
}
