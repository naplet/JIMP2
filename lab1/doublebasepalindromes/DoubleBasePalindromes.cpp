#include <cstdint>
#include "DoubleBasePalindromes.h"
uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    int liczba, odwrotna=0, cyfra,suma=0,c=0;
    std::string alfabet="01",wynik="";
    for(int i=0;i<=max_vaule_exculsive;i++)
    {
        liczba=i;
        while(liczba!=0)
        {
            cyfra=liczba%10;
            odwrotna=(odwrotna*10)+cyfra;
            liczba=(liczba-cyfra)/10;
        }
        liczba=i;
        while(liczba>0){
            wynik=alfabet[liczba%2]+wynik;
            liczba = (liczba/2);//wynik liczba w dwojkowym
        }
        int z,x;
        for (z = 0, x = wynik.length()-1; z < x; z++, x--)
        {
            if (wynik[z] == ' ') z++;
            if (wynik[x] == ' ') x--;
            if (wynik[z] != wynik[x])
                break;
        }
        if (z < x)
        {
            c=1;
        }
        else{
            c=0;
        }

        if(i=odwrotna||c==0)
        {
            suma=suma+i;
        }
        odwrotna=0;

    }


    return suma;
}