#include<vector>
#include "XorCypherBreaker.h"
#include <algorithm>
#include <bits/valarray_before.h>

using std::find;
using std::vector;
using std::string;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,int key_length,const std::vector<string> dictionary) {
    std::string alfabet = "abcdefghijklmnopqrstuvwxyz";
    std::string klucz;
    std::string spacja = {" "};
    std::string word;
    int zliczanie;
    int max;
    int max_i, max_j, max_k;
    std::vector<char> cryptogram2;
    int g;
    for(int i=0;i<26;i++)
    {
        for(int j = 0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                klucz = alfabet[i]+alfabet[j]+alfabet[k];
                for(int h =0;h<cryptogram.size();h++)
                {
                    if(cryptogram[h]==spacja[0])
                    {
                        cryptogram2.push_back(spacja[0]);
                        h++;
                    }
                    g=h%3;
                    if(g==0)
                    {
                        cryptogram2.push_back(cryptogram[h]^alfabet[i]);
                    }
                    if(g==1)
                    {
                        cryptogram2.push_back(cryptogram[h]^alfabet[j]);
                    }
                    if(g==2)
                    {
                        cryptogram2.push_back(cryptogram[h]^alfabet[k]);
                    }
                }
                for(int h =0;h<cryptogram2.size();h++)
                {
                    zliczanie=0;
                    if(cryptogram2[h]==spacja[0]);
                    {
                        for(int b=0;b<100;b++)
                        {
                            if(word==dictionary[b])
                            {
                                zliczanie++;
                                word="";
                                break;
                            }

                        }
                    }
                    if(cryptogram2[h]!=spacja[0])
                    {
                        word.push_back(cryptogram2[h]);
                    }
                }
                if(zliczanie>max)
                {
                    max_i=i;
                    max_j=j;
                    max_k=k;
                }

            }
        }
    }
    klucz= alfabet[max_i]+alfabet[max_j]+alfabet[max_k];
    return klucz;
}