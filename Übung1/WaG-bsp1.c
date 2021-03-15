#include <stdio.h>
#include <stdlib.h>

void euro2money(int euro){
    int euros[] = {500,200,100,50,20,10,5,2,1};

    printf("Eingegebener Eurobetrag: %d\n",euro);

    for (int i = 0; i<sizeof(euros);i++){ 
        if(euro<1){
            return;
        }

        if(euro >= euros[i]){
            int help = euro/euros[i];
            printf("%d Euroscheine: %d\n",euros[i],help);
        }
        euro = euro%euros[i];

    } 

}

int main (int argc, char* argv[]){
    int euros = 12345;
    euro2money(euros);
    return 0;
}
