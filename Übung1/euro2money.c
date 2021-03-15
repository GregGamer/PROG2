#include <stdio.h>
#include <stdlib.h>

void euro2money(int euro){
    printf("Eingegebener Eurobetrag: %i\n",euro);

    if(euro >= 500){
        int euro500 = euro/500;
        printf("500 Euroscheine: %i\n",euro500);
    }
    euro = euro%500;

    
}

int main (void){
    euro2money(2000);


}
